# Project B: CSV Mini Database - SELECT Query Engine

## 1. Project Overview

This project is Project B for the course **CS351 / IN321: AI-assisted Software Development**.

The goal of this project is to build a small CSV-based mini database using **C++17**.
The current implementation focuses on a SQL-like **SELECT query engine** for student data stored in a CSV file.

The program can:

* Load student data from a CSV file
* Store CSV headers and rows in memory
* Select all columns or specific columns
* Filter records using `WHERE`
* Sort query results using `ORDER BY`
* Print the selected result as a readable table

This project helped me practice CSV file handling, simple query parsing, conditional filtering, sorting, output formatting, project organization, GitHub workflow, and AI-assisted development verification.

---

## 2. Current Implementation Scope

The current source code focuses on the following query features:

| Feature                 | Status      | Description                                                      |
| ----------------------- | ----------- | ---------------------------------------------------------------- |
| Load CSV file           | Implemented | Reads `Data/students.csv` and stores the data in memory          |
| `SELECT *`              | Implemented | Displays all columns                                             |
| Select specific columns | Implemented | Displays only selected columns, such as `name` and `score`       |
| `WHERE` filtering       | Implemented | Filters rows by a condition, such as department or score         |
| `ORDER BY` sorting      | Implemented | Sorts query results in ascending or descending order             |
| Table output            | Implemented | Prints query results in a readable table format                  |
| GitHub Actions CI       | Implemented | Automatically checks required files and compiles the C++ program |

The following features are **not the current main implementation** and are listed as future improvements:

* Insert new records
* Update existing records
* Delete records
* Save modified data back to CSV
* `COUNT`
* `AVG`
* `GROUP BY`
* More complete SQL syntax support

---

## 3. Data Design

The project uses a CSV file located at:

```text
Data/students.csv
```

The CSV data is designed with the following columns:

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
3,Charlie,CS,3,21,92,Taipei
```

Each row represents one student record, and each column represents one attribute of the student.
The dataset is simple enough for demonstration, but it is also useful for practicing basic database-like operations such as selecting, filtering, and sorting data.

---

## 4. Supported Query Examples

### Select all records

```sql
SELECT * FROM students;
```

### Select specific columns

```sql
SELECT name, score FROM students;
```

### Filter records with `WHERE`

```sql
SELECT * FROM students WHERE department = 'CS';
```

```sql
SELECT * FROM students WHERE score >= 80;
```

```sql
SELECT * FROM students WHERE city = 'Taipei';
```

### Sort records with `ORDER BY`

```sql
SELECT * FROM students ORDER BY score DESC;
```

```sql
SELECT name, department, score FROM students WHERE score >= 80 ORDER BY score DESC;
```

---

## 5. Query Workflow

The program follows this basic workflow:

```text
Load CSV
   ↓
Read SELECT query
   ↓
Parse selected columns
   ↓
Apply WHERE condition if provided
   ↓
Apply ORDER BY sorting if provided
   ↓
Print result table
```

Key implementation ideas:

* CSV lines are split into fields.
* The first row is treated as the header row.
* Column names are used to find column indexes.
* `WHERE` conditions are parsed into column, operator, and value.
* Numeric values can be compared numerically.
* Text values can be compared as strings.
* `ORDER BY` supports ascending and descending sorting.

---

## 6. Project Structure

The project is organized as follows:

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

| Path                       | Description                               |
| -------------------------- | ----------------------------------------- |
| `.github/workflows/ci.yml` | GitHub Actions CI workflow                |
| `Data/students.csv`        | Sample student dataset                    |
| `Data/README.md`           | Dataset description and query examples    |
| `src/main.cpp`             | Main C++ source code                      |
| `src/README.md`            | Source-code feature description           |
| `README.md`                | Root project introduction and usage guide |

---

## 7. Requirements

To compile and run this project, you need:

* A C++ compiler with C++17 support
* `g++` recommended
* Git or GitHub Codespaces / local terminal
* GitHub Actions is used for automatic CI build checking

---

## 8. How to Compile

Use the following command from the project root directory:

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra src/main.cpp -o build/csv_database
```

This command compiles the C++ program and creates an executable file at:

```text
build/csv_database
```

---

## 9. How to Run

### Linux / Git Bash / WSL

```bash
./build/csv_database Data/students.csv
```

### Windows PowerShell

```powershell
.\build\csv_database.exe Data\students.csv
```

After running the program, enter a supported `SELECT` query.

Example:

```sql
SELECT name, department, score FROM students WHERE score >= 80 ORDER BY score DESC;
```

---

## 10. Example Demo

Input query:

```sql
SELECT name, department, score FROM students WHERE score >= 80 ORDER BY score DESC;
```

Expected behavior:

* Load the student CSV file
* Select only the `name`, `department`, and `score` columns
* Keep only students whose score is greater than or equal to 80
* Sort the result by score from high to low
* Print the result as a table

This is the strongest live demo case because it shows column selection, filtering, sorting, and formatted output in one query.

---

## 11. Test Cases

The project can be tested with the following manual test cases:

| Test Case                                         | Purpose                                    | Expected Result                           |
| ------------------------------------------------- | ------------------------------------------ | ----------------------------------------- |
| `SELECT * FROM students;`                         | Check whether all records can be displayed | All rows and columns are shown            |
| `SELECT name, score FROM students;`               | Check column selection                     | Only `name` and `score` are shown         |
| `SELECT * FROM students WHERE department = 'CS';` | Check text filtering                       | Only CS students are shown                |
| `SELECT * FROM students WHERE score >= 80;`       | Check numeric comparison                   | Only students with score >= 80 are shown  |
| `SELECT * FROM students ORDER BY score DESC;`     | Check sorting                              | Rows are sorted by score from high to low |
| Invalid column name                               | Check error handling                       | Program shows a column-not-found message  |
| Invalid query format                              | Check query validation                     | Program shows an invalid-query message    |

These test cases help verify that the SELECT query engine works correctly for normal cases and basic error cases.

---

## 12. GitHub Actions CI

This project includes a GitHub Actions workflow:

```text
.github/workflows/ci.yml
```

The CI workflow runs automatically when code is pushed to GitHub or when a pull request is created for the configured branches.

The CI workflow checks:

* Whether `src/main.cpp` exists
* Whether `Data/students.csv` exists
* Whether `README.md` exists
* Whether the C++ program can be compiled with `g++ -std=c++17 -Wall -Wextra`
* Whether the executable file is created successfully

This helps make sure the project can still build correctly after changes.

---

## 13. What I Learned

Through this project, I learned how to build a small CSV-based query program.

I practiced:

* Reading CSV files
* Storing structured data in memory
* Parsing simple SQL-like commands
* Selecting specific columns
* Filtering rows with conditions
* Sorting query results
* Formatting output tables
* Organizing project files
* Writing README documentation
* Using GitHub Actions for CI

The most important thing I learned is that a software project should match its documentation.
If the code only supports SELECT queries, the README should clearly explain the SELECT feature instead of claiming unsupported functions.

---

## 14. AI-Assisted Development Reflection

I used AI tools to help me understand the project requirements, design the README structure, explain the program workflow, and review whether the documentation matched the actual source code.

However, I did not only copy AI-generated results.

I still needed to:

* Read the source code
* Check the actual implemented functions
* Compare the README with the program behavior
* Run or review test cases
* Correct documentation that did not match the implementation

Through this process, I learned that AI can be a useful assistant, but I still need to verify the final result by myself.

---

## 15. Future Improvements

In the future, I would like to improve this project by adding more functions, such as:

* Insert new records
* Update existing records
* Delete records
* Save modified data back to CSV
* Support `COUNT`
* Support `AVG`
* Support `GROUP BY`
* Improve CSV parsing for quoted fields and commas inside text
* Add automatic test scripts
* Improve error handling
* Separate the code into multiple files

These improvements would make the project closer to a more complete mini database system.
