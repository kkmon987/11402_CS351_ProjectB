# Source Code

## About This Folder

This folder contains the main C++ source code for **Project B: CSV Mini Database**.

The main program file is:

`main.cpp`

This program is designed to work with the student CSV data stored in:

`Data/students.csv`

---

## Program Purpose

The purpose of this program is to build a small CSV-based database system using C++.

The program can:

* load student data from a CSV file;
* display all records;
* search records by column values;
* insert a new student record;
* validate user input;
* save the updated data back to the CSV file.

This project helps me practice file handling, data processing, input validation, and basic database-like operations.

---

## Main Functions

### 1. Load CSV

The program reads `Data/students.csv` and stores the data in memory.

The first row of the CSV file is treated as the header, and the remaining rows are treated as student records.

---

### 2. Display Records

The program can display all student records in a readable format.

This helps users check the current data inside the CSV file.

---

### 3. Search Records

The program allows users to search data based on column values.

For example, users can search by:

* name;
* department;
* grade;
* city;
* score.

This makes it easier to find specific student records.

---

### 4. Insert Student

The insert function allows users to add a new student record.

Before inserting the data, the program checks whether the input is valid.

The program checks:

* whether the ID already exists;
* whether required fields are empty;
* whether grade, age, and score are numbers;
* whether the score is between 0 and 100;
* whether the grade is in a reasonable range.

This prevents invalid data from being inserted into the CSV file.

---

### 5. Save CSV

After inserting a new record, the program can save the updated data back to `Data/students.csv`.

This makes the inserted data persistent, so the new record will still exist after the program closes.

---

## Why I Designed the Program This Way

I designed the program to first load the CSV data into memory, then perform operations such as display, search, and insert.

This design makes the program easier to manage because all records can be processed in memory before saving them back to the CSV file.

For the insert function, I added validation because directly appending data without checking may cause problems.

For example:

* duplicate IDs may make records confusing;
* empty names or departments make records incomplete;
* invalid scores make the data unreasonable;
* non-number values in grade, age, or score may cause errors.

Because of this, the program checks the input before adding a new record.

---

## How to Compile

From the project root folder, use:

`g++ -std=c++17 -Wall -Wextra -o csv_database src/main.cpp`

This will create an executable file named:

`csv_database`

---

## How to Run

### Linux / Git Bash / WSL

`./csv_database Data/students.csv`

### Windows PowerShell

`.\csv_database.exe Data/students.csv`

---

## Reflection

Through this source code, I learned that a program should not only work with correct input. It should also handle incorrect input carefully.

I also learned that code organization and clear function design are important. When a project becomes larger, separating different tasks into different functions makes the program easier to read, debug, and explain.

AI tools helped me design and improve the program, but I still needed to test the program by myself and make sure the output was correct.
