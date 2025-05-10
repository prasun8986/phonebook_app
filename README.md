# C++ Phonebook Project

## Developed by: **Prasun Parasar**

### Description
This is a **Simple C++ Phonebook Application**, designed as a terminal-based program to store, search, and manage contacts. The application allows you to:

- Add contacts
- Search contacts by name or phone number
- List all contacts
- Sort contacts alphabetically by name
- The data is stored persistently in a file `contacts.txt`.

The project can be expanded in the future with a graphical user interface (GUI) or connected to a database for more advanced features.

---

## Features
- **Add Contact**: Allows the user to add a new contact with a name, phone number, and email address.
- **Search by Name**: Search for contacts by their name.
- **Search by Phone**: Search for contacts by their phone number.
- **List All Contacts**: Display all stored contacts.
- **Sort Contacts**: Sort contacts alphabetically by name.
- **Persistent Storage**: Contacts are saved and loaded from a text file (`contacts.txt`).

---

## Technologies Used
- **C++**: The core programming language used for building the project.
- **File I/O**: Used to read from and write to the `contacts.txt` file.
- **Threading**: Utilizes multithreading to save contacts asynchronously using the `std::thread` and `std::mutex` for thread safety.
- **Standard Template Library (STL)**: Utilizes `std::vector`, `std::string`, and `std::algorithm` for efficient data handling.

---

## How to Run the Project

### Prerequisites
1. A C++ compiler that supports C++11 or later (e.g., `g++` or `clang++`).
2. Basic knowledge of how to run a C++ program on your system.

### Steps
1. Clone the repository or copy the C++ code to your local machine.
2. Open a terminal and navigate to the folder where the file is located.
3. Compile the program using the following command:
    ```bash
    g++ -std=c++11 phonebook.cpp -o phonebook
    ```
4. Run the program:
    ```bash
    ./phonebook
    ```

---

## Example Usage

### Menu Options
1. **Add Contact**: 
    - Prompts you to enter a name, phone number, and email.
    - Adds the contact to the phonebook and saves it to `contacts.txt`.
  
2. **Search by Name**: 
    - You can search for a contact by entering part or all of the contact's name.
    - Displays matching contacts with their name, phone, and email.
  
3. **Search by Phone**: 
    - Search for a contact using their phone number.
  
4. **View All Contacts**: 
    - Displays all stored contacts.

5. **Sort Contacts**: 
    - Sorts the contacts alphabetically by name.

6. **Exit**: 
    - Exits the program.

---

## Code Structure

### Main Components
1. **Contact Class**:
    - Represents a contact with `name`, `phone`, and `email`.
    - Includes a `display` method to print contact information.

2. **Phonebook Class**:
    - Manages the collection of contacts.
    - Provides methods to add, search, list, and sort contacts.
    - Saves contacts to and loads from the `contacts.txt` file.

3. **Menu and User Interaction**:
    - Displays a simple menu and allows the user to choose actions via a terminal interface.

---

## Future Enhancements
- **GUI Integration**: Create a user-friendly graphical interface using libraries such as Qt or GTK.
- **Database Support**: Migrate the phonebook data to a database like SQLite or MySQL for better scalability.
- **Mobile Version**: Convert this application into a mobile app using a cross-platform framework like Flutter or React Native.

---

## Contributing
Feel free to fork this repository, make improvements, and submit pull requests. Contributions are always welcome!

---

## License
This project is open-source and available under the MIT License.
