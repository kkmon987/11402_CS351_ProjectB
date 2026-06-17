# Project B: CSV Mini Database

## 1. Project Overview

This project is **Project B** for the course **CS351/IN321: AI-assisted Software Development**.

The goal of this project is to build a small CSV-based database program using **C++**.

The program can load student data from a CSV file, display records, search records, insert new student data, and save the updated data back to the CSV file.

This project helped me practice CSV file handling, basic database-like operations, input validation, project organization, and GitHub workflow.

---

## 2. Data Design

The project uses a CSV file located at:

```text
Data/students.csv
```

The CSV file stores student information. Each row represents one student record, and each column represents one attribute of the student.

The CSV data uses the following columns:

| Column       | Meaning             |
| ------------ | ------------------- |
| `id`         | Student ID          |
| `name`       | Student name        |
| `department` | Student department  |
| `grade`      | Student grade level |
| `age`        | Student age         |
| `score`      | Student score       |
| `city`       | Student city        |

Example data:

```csv
id,name,department,grade,age,score,city
1,Alice,CS,1,18,85,Taipei
2,Bob,EE,2,19,78,Taichung
3,Charlie,CS,3,20,90,Tainan
```

I designed the data this way because it is simple and easy to understand.

The `id` field is used as the unique identifier for each student. Because of this, the program checks whether an ID already exists before inserting a new student record.

---

## 3. Features

This program currently supports the following functions:

### 1. Load CSV

The program reads student data from:

```text
Data/students.csv
```

Then it stores the data in memory for later operations.

### 2. Display Records

The program can display all student records in a readable format.

This allows the user to check the current data inside the CSV file.

### 3. Search Records

The program can search records based on column values.

For example, the user can search by:

* `id`
* `name`
* `department`
* `grade`
* `age`
* `score`
* `city`

This function helps the user find specific student records more easily.

### 4. Insert Student

The program allows the user to insert a new student record.

During insertion, the program checks:

* whether the student ID already exists;
* whether required fields are empty;
* whether `grade`, `age`, and `score` are valid numbers;
* whether `grade` is in a reasonable range;
* whether `score` is between 0 and 100.

### 5. Save CSV

After inserting new data, the program can save the updated records back to:

```text
Data/students.csv
```

This means the inserted data will still exist after the program closes.

---

## 4. Why I Designed the Insert Function This Way

The insert function is an important part of this project.

I did not only append a new row directly into the CSV file. Instead, I added basic validation before inserting the data.

The reason is that invalid data can make the CSV database difficult to use later.

For example:

* If two students have the same `id`, the program may not know which record is correct.
* If `score` is greater than 100, the data is unreasonable.
* If `name`, `department`, or `city` is empty, the record is incomplete.
* If `grade`, `age`, or `score` is not a number, the program may produce incorrect results.

Because of this, I designed the insert function to check the input first.

Only valid data can be inserted into the database. This makes the program more reliable and closer to a real database system.

---

## 5. Project Structure

The current project is organized as follows:

```text
11402_CS351_ProjectB/
│
├── .github/
│   └── workflows/
│       └── ci.yml
│
├── Data/
│   ├── README.md
│   └── students.csv
│
├── src/
│   ├── README.md
│   └── main.cpp
│
└── README.md
```

### Folder Explanation

| Path                       | Description                          |
| -------------------------- | ------------------------------------ |
| `.github/workflows/ci.yml` | GitHub Actions CI workflow           |
| `Data/students.csv`        | Student CSV data                     |
| `Data/README.md`           | Explanation of the CSV data design   |
| `src/main.cpp`             | Main C++ source code                 |
| `src/README.md`            | Explanation of the source code       |
| `README.md`                | Project introduction and usage guide |

---

## 6. Requirements

To compile and run this project, you need:

* C++ compiler with C++17 support
* `g++` is recommended
* GitHub Actions is used for CI checking

---

## 7. How to Compile

From the project root folder, use the following command:

```bash
g++ -std=c++17 -Wall -Wextra -o csv_database src/main.cpp
```

This command compiles the C++ program and creates an executable file named:

```text
csv_database
```

On Windows, the executable may be:

```text
csv_database.exe
```

---

## 8. How to Run

### Linux / Git Bash / WSL

```bash
./csv_database Data/students.csv
```

### Windows PowerShell

```powershell
.\csv_database.exe Data/students.csv
```

---

## 9. Example Insert Demo

When demonstrating the insert function, I can insert a new student such as:

```text
id: 11
name: Kevin
department: CS
grade: 2
age: 20
score: 87
city: Taipei
```

Expected result:

```text
Student inserted successfully.
```

After saving, the new record will be added to:

```text
Data/students.csv
```

---

## 10. Test Cases

I tested the program with several cases:

| Test Case              | Purpose                                  | Expected Result                      |
| ---------------------- | ---------------------------------------- | ------------------------------------ |
| Display all records    | Check if CSV data can be shown correctly | All records are displayed            |
| Search department = CS | Check search function                    | Only CS students are displayed       |
| Insert valid student   | Check normal insert                      | New student is inserted successfully |
| Insert duplicate ID    | Check ID validation                      | Program shows duplicate ID error     |
| Insert invalid score   | Check score validation                   | Program shows score range error      |
| Insert empty name      | Check required field validation          | Program shows empty field error      |

These test cases help me check whether the program works correctly and whether the insert function handles incorrect input.

---

## 11. GitHub Actions CI

This project includes a GitHub Actions workflow:

```text
.github/workflows/ci.yml
```

The CI workflow is used to check whether the project can build successfully on GitHub.

The CI checks:

* whether important files exist;
* whether `src/main.cpp` can be compiled;
* whether the executable file can be created successfully.

This helps me make sure the project can still build correctly after I push changes to GitHub.

---

## 12. What I Learned

Through this project, I learned how to build a small CSV-based database program.

I practiced:

* reading CSV files;
* storing records in memory;
* displaying data;
* searching records;
* inserting new data;
* validating user input;
* saving data back to CSV;
* organizing project files;
* writing README documentation;
* using GitHub Actions for CI.

The most important thing I learned is that a program should not only work under normal input. It should also handle incorrect input carefully.

---

## 13. AI-Assisted Development Reflection

I used AI tools to help me understand the project requirements, design the program structure, write explanations, and debug some problems.

However, I did not only copy AI-generated results.

I still needed to:

* read the code;
* test the program;
* check whether the output was correct;
* modify the README to match my actual project;
* make sure the insert function fits my CSV data design.

Through this process, I learned that AI can be a useful assistant, but I still need to understand and verify the final result by myself.

---

## 14. Future Improvements

In the future, I would like to improve this project by adding more functions, such as:

* update existing records;
* delete records;
* support more flexible search conditions;
* improve CSV parsing;
* add automatic test scripts;
* improve user interface;
* separate the code into multiple files.

These improvements would make the project closer to a more complete mini database system.
