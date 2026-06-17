# Source Code Folder

## Overview

This folder contains the main C++ source code for **Project B: CSV Mini Database - SELECT Query Engine**.

The main source file is:

```text
main.cpp
```

The program is written in **C++17** and reads student data from:

```text
Data/students.csv
```

The current implementation focuses on a SQL-like `SELECT` query system for CSV data.

---

## What the Program Actually Does

The program does the following tasks:

1. Reads a CSV file.
2. Stores the first row as column headers.
3. Stores the remaining rows as data records.
4. Shows the available column names.
5. Lets the user enter one SQL-like `SELECT` query.
6. Parses selected columns.
7. Applies a `WHERE` condition if one is provided.
8. Applies `ORDER BY` sorting if one is provided.
9. Prints the result as a formatted table.

This is a read-only query program.
It does not currently insert, update, delete, or save data back to the CSV file.

---

## Main Data Structure

The program stores the CSV data using this idea:

```cpp
struct CSVTable {
    vector<string> headers;
    vector<vector<string>> rows;
};
```

* `headers` stores the first row of the CSV file.
* `rows` stores all student records after the header row.

---

## Main Functions

### `trim`

Removes extra spaces, tabs, and newline characters from the beginning and end of a string.

### `toLower`

Converts a string to lowercase.
This helps the program compare query keywords and column names without being case-sensitive.

### `removeQuotes`

Removes single quotes or double quotes from a value.

For example:

```text
'CS' → CS
"Taipei" → Taipei
```

### `splitCSVLine`

Splits one CSV line into separate cells.
It also handles simple quoted text while splitting by commas.

### `splitByComma`

Splits selected column names in the `SELECT` part.

Example:

```sql
SELECT name, score FROM students;
```

The column part `name, score` is split into:

```text
name
score
```

### `getColumnIndex`

Finds the index of a column name from the CSV headers.

For example, if the headers are:

```text
id, name, department, grade, age, score, city
```

then `score` is found as one of the available columns.

### `isNumber`

Checks whether a string can be treated as a number.

This is used when comparing values in `WHERE` and sorting values in `ORDER BY`.

### `compareValues`

Compares two values using an operator.

Supported operators:

| Operator | Meaning               |
| -------- | --------------------- |
| `=`      | Equal                 |
| `==`     | Equal                 |
| `!=`     | Not equal             |
| `>`      | Greater than          |
| `<`      | Less than             |
| `>=`     | Greater than or equal |
| `<=`     | Less than or equal    |

If both values are numbers, the program compares them numerically.
Otherwise, it compares them as strings.

### `loadCSV`

Reads the CSV file.

The first line becomes `headers`.
The remaining non-empty lines become `rows`.

### `showColumns`

Prints the available column names so the user knows which fields can be used in the query.

### `parseCondition`

Parses a simple `WHERE` condition.

Example:

```sql
WHERE score >= 80
```

This is parsed into:

```text
column: score
operator: >=
value: 80
```

### `executeSelect`

This is the main function for the SELECT query feature.

It handles:

* `SELECT`
* `FROM`
* Selected columns
* `WHERE`
* `ORDER BY`
* Result generation
* Error messages for invalid columns or invalid query format

### `printResultTable`

Prints the selected result in a readable table format.
It also prints the total number of result rows.

---

## Supported Query Examples

### Select all data

```sql
SELECT * FROM students;
```

### Select specific columns

```sql
SELECT name, score FROM students;
```

### Filter with WHERE

```sql
SELECT * FROM students WHERE department = 'CS';
```

```sql
SELECT * FROM students WHERE score >= 80;
```

### Sort with ORDER BY

```sql
SELECT * FROM students ORDER BY score DESC;
```

### Combined query

```sql
SELECT name, department, score FROM students WHERE score >= 80 ORDER BY score DESC;
```

This combined query is a good live demo example because it shows column selection, filtering, sorting, and table output at the same time.

---

## Query Workflow

The internal workflow is:

```text
User enters query
→ Check SELECT and FROM format
→ Parse selected columns
→ Check whether selected columns exist
→ Parse WHERE condition if provided
→ Filter matching rows
→ Parse ORDER BY if provided
→ Sort rows
→ Build selected result rows
→ Print result table
```

---

## Compile Command

From the project root folder, compile the program with:

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra src/main.cpp -o build/csv_database
```

---

## Run Command

### Linux / Git Bash / WSL

```bash
./build/csv_database Data/students.csv
```

### Windows PowerShell

```powershell
.\build\csv_database.exe Data\students.csv
```

After running the program, enter a supported `SELECT` query.

---

## Important Note About the Default File Name

In `main.cpp`, the default filename is currently:

```cpp
string filename = "students(1)(1).csv";
```

However, if the user provides a command-line argument, the program uses that file path instead.

Therefore, the recommended way to run the program is:

```bash
./build/csv_database Data/students.csv
```

This ensures the program reads the correct CSV file from the `Data` folder.

A possible future improvement is to change the default filename in the code to:

```cpp
string filename = "Data/students.csv";
```

---

## Current Implementation Scope

Implemented:

| Feature                       | Status      |
| ----------------------------- | ----------- |
| Read CSV file                 | Implemented |
| Store headers and rows        | Implemented |
| Display available columns     | Implemented |
| `SELECT *`                    | Implemented |
| Select specific columns       | Implemented |
| `WHERE` filtering             | Implemented |
| Numeric and string comparison | Implemented |
| `ORDER BY ASC`                | Implemented |
| `ORDER BY DESC`               | Implemented |
| Formatted result table        | Implemented |

Not implemented:

* `INSERT`
* `UPDATE`
* `DELETE`
* Saving modified data back to CSV
* `COUNT`
* `AVG`
* `GROUP BY`
* `JOIN`
* Multiple `WHERE` conditions using `AND` or `OR`
* Full SQL syntax parsing

---

## Manual Test Cases

| Test Query                                                                            | Purpose                             |
| ------------------------------------------------------------------------------------- | ----------------------------------- |
| `SELECT * FROM students;`                                                             | Check all rows and all columns      |
| `SELECT name, score FROM students;`                                                   | Check selected columns              |
| `SELECT * FROM students WHERE department = 'CS';`                                     | Check text filtering                |
| `SELECT * FROM students WHERE score >= 80;`                                           | Check numeric filtering             |
| `SELECT * FROM students ORDER BY score DESC;`                                         | Check descending sorting            |
| `SELECT name, department, score FROM students WHERE score >= 80 ORDER BY score DESC;` | Check combined query behavior       |
| `SELECT abc FROM students;`                                                           | Check invalid column handling       |
| `SELECT * FROM students WHERE unknown = 1;`                                           | Check invalid WHERE column handling |

---

## Reflection

This source code helped me practice implementing a small query engine in C++.

The most important lesson is that documentation must match the actual program behavior.
Since the current program focuses on the SELECT feature, the README should describe `SELECT`, `WHERE`, and `ORDER BY` clearly instead of claiming unsupported insert or save features.

AI tools helped me review the program and rewrite the documentation, but I still needed to check the real C++ source code to make sure the README was accurate.
::: 
