Inventory Manager (C++ console application)
This is a command-line inventory tracking system developed in C++ to demonstrate my skills gained in first year computer science. 
It includes core Object-Oriented Programming (OOP) concepts, file persistence, and efficient data handling.

#FEATURES IMPLEMENTED
1. Object-Orientated Design (Polymorphism):
           Uses a base class (`Item`) with derived classes (`nonPerishableItem`, `perishableItem`) to handle specific item attributes and behaviors.
   
2. File Persistence (CRUD):
           All inventory data is saved to and loaded from `inventory.txt` using C++ file streams (`fstream`). The application safely loads the previous state on
           startup and saves the current state upon exit.
   
3. Command Menu:
           Provides a simple menu interface in the console for all operations (Create, Read, Update, Delete).

4. Perishable Status Check:
           The `perishableItem` class includes logic to parse the expiry date (DD-MM-YYYY format) and compare it against the system's current date, outputting a
           warning when necessary.
   
5. Input Handling (UX):
           Uses `std::getline` and input buffer cleaning (`cin.ignore`) to safely handle user input, including item names that contain spaces.

#BUILD AND RUN INSTRUCTIONS
  This project requires a C++ compiler that supports the C++11 standard or newer (e.g., MinGW, GCC).

#PREREQUISITES
  1. A C++ compiler (g++ recommended)
  2. Make sure all source files (`.cpp` and `.h`) are in the same directory.

#COMPILATION
Navigate to the project root directory in your terminal and compile all source files together using the following command:

    g++ -fdiagnostics-color=always -g -std=c++11 \ main.cpp inventoryManager.cpp nonPerishableItem.cpp perishableItem.cpp \ -o inventoryManager.exe
