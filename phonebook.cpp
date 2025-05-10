// Developed by Prasun Parasar
// Simple C++ Phonebook Project - terminal based, expandable to GUI/DB
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <thread>
#include <string>
#include <mutex>

using namespace std;

mutex file_mutex;

class Contact {
public:
    string name;
    string phone;
    string email;

    Contact() = default;

    Contact(string n, string p, string e) : name(n), phone(p), email(e) {}

    void display() const {
        cout << "Name: " << name << "\nPhone: " << phone << "\nEmail: " << email << "\n---\n";
    }
};

class Phonebook {
private:
    vector<Contact> contacts;
    const string filename = "contacts.txt";

public:
    Phonebook() {
        loadFromFile();
    }

    void addContact(const Contact& c) {
        contacts.push_back(c);
        saveToFile();
    }

    void searchByName(const string& name) const {
        bool found = false;
        for (const auto& c : contacts) {
            if (c.name.find(name) != string::npos) {
                c.display();
                found = true;
            }
        }
        if (!found) cout << "No contact found with that name.\n";
    }

    void searchByPhone(const string& phone) const {
        bool found = false;
        for (const auto& c : contacts) {
            if (c.phone.find(phone) != string::npos) {
                c.display();
                found = true;
            }
        }
        if (!found) cout << "No contact found with that number.\n";
    }

    void sortContacts() {
        sort(contacts.begin(), contacts.end(), [](Contact a, Contact b) {
            return a.name < b.name;
        });
        cout << "Contacts sorted by name.\n";
    }

    void listContacts() const {
        if (contacts.empty()) {
            cout << "Phonebook is empty.\n";
            return;
        }
        for (const auto& c : contacts) {
            c.display();
        }
    }

private:
    void loadFromFile() {
        ifstream fin(filename);
        if (!fin) return;

        string name, phone, email;
        while (getline(fin, name) && getline(fin, phone) && getline(fin, email)) {
            contacts.emplace_back(name, phone, email);
        }
        fin.close();
    }

    void saveToFile() {
        thread t([&]() {
            lock_guard<mutex> lock(file_mutex);
            ofstream fout(filename);
            for (const auto& c : contacts) {
                fout << c.name << '\n' << c.phone << '\n' << c.email << '\n';
            }
            fout.close();
        });
        t.detach();
    }
};

void showMenu() {
    cout << "\n==== PHONEBOOK MENU ====\n";
    cout << "1. Add Contact\n";
    cout << "2. Search by Name\n";
    cout << "3. Search by Phone\n";
    cout << "4. View All Contacts\n";
    cout << "5. Sort Contacts\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Phonebook pb;
    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                string name, phone, email;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone: ";
                getline(cin, phone);
                cout << "Enter email: ";
                getline(cin, email);
                pb.addContact(Contact(name, phone, email));
                break;
            }
            case 2: {
                string name;
                cout << "Enter name to search: ";
                getline(cin, name);
                pb.searchByName(name);
                break;
            }
            case 3: {
                string phone;
                cout << "Enter phone to search: ";
                getline(cin, phone);
                pb.searchByPhone(phone);
                break;
            }
            case 4:
                pb.listContacts();
                break;
            case 5:
                pb.sortContacts();
                break;
            case 6:
                cout << "Exiting Phonebook.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
