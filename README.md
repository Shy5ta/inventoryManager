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

#PROJECT ARCHITECTURE

This project is built on the principles of Polymorphism, allowing the InventoryManager to treat all items generically while ensuring specific behaviors are executed at runtime.
1. Item.h:

   The abstract base class (ABS) defines common attributes and                    declares pure virtual functions such as checkStatus(),                         toFileString etc.

   The technical concept demonstrated is abstraction and                          polymorphism.

3. inventoryManager.h/.cpp:

   This file manages the primary container,                                       *std::vector<Item>, and handles all CRUD logic.                                It includes robust exception handling on file                                  load.

   The technical concept demonstrated is                                          encapsulation and File I/O(fstream).

5. perishableItem.h/.cpp:

   This file is a derived class that overrides                                    virtual functions and includes Date                                            Comparison Logic using <ctime>.

   The technical concepts demonstrated are                                        inheritance, and runtime polymorphism.
                                 
7. main.cpp:

   This file contains the interactive menu, primary application                   loop, and input handling utilities.

   The technical aspect demonstrated is control flow. 

#BUILD AND RUN INSTRUCTIONS

  This project requires a C++ compiler that supports the C++11 standard or       newer (e.g., MinGW, GCC).

#PREREQUISITES

  1. A C++ compiler (g++ recommended)
  2. Make sure all source files (`.cpp` and `.h`) are in the same directory.

#COMPILATION

Navigate to the project root directory in your terminal and compile all source files together using the following command:

    g++ -fdiagnostics-color=always -g -std=c++11 \ main.cpp inventoryManager.cpp nonPerishableItem.cpp perishableItem.cpp \ -o inventoryManager.exe

#EXECUTION

Run the compiled executable:
          ./inventoryManager.exe
