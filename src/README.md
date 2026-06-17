# CSV Mini Database - SELECT Feature

## Project Description

This project is a small C++ program that reads data from a CSV file and provides a simple `SELECT` feature.

The CSV file used in this project is `students.csv`.  
The purpose of this project is to simulate a basic database query system using only a CSV file and C++.

## Why I Chose the SELECT Feature

I chose to implement the `SELECT` feature because it is one of the most important and basic functions in a database system.

Before adding, updating, or deleting data, users usually need to search and view the data first.  
Therefore, `SELECT` is a good starting point for building a CSV mini database.

Through this feature, I can practice:

- Reading structured data from a CSV file
- Choosing specific columns
- Filtering records with conditions
- Sorting query results
- Understanding how database queries work at a basic level

## Files

| File | Description |
|---|---|
| `csv_select.cpp` | Main C++ source code |
| `students.csv` | Sample CSV dataset |
| `README.md` | Project explanation |

## Dataset Format

The program reads a CSV file named `students.csv`.

Example data:

```csv
id,name,department,grade,age,score,city
1,Alice,CS,1,18,85,Taipei
2,Bob,EE,2,19,78,Taichung
3,Charlie,CS,3,21,92,Taipei
4,David,ME,2,20,66,Tainan
5,Eva,CS,4,22,95,Kaohsiung
6,Frank,EE,1,18,73,Taipei
7,Grace,BA,3,21,88,Taichung
8,Hank,ME,4,23,59,Tainan
9,Ivy,CS,2,20,81,Kaohsiung
10,Jack,EE,3,21,90,Taipei
```

## Program Design

The program is divided into several parts.

### 1. Load CSV File

The program opens `students.csv`, reads the first row as column headers, and reads the remaining rows as data records.

Main function:

```cpp
CSVTable loadCSV(const string& filename);
```

The data is stored in this structure:

```cpp
struct CSVTable {
    vector<string> headers;
    vector<vector<string>> rows;
};
```

### 2. Parse SELECT Query

The program accepts a SQL-like query from the user.

Supported format:

```sql
SELECT columns FROM students WHERE condition ORDER BY column ASC/DESC;
```

Examples:

```sql
SELECT * FROM students;
```

```sql
SELECT name, score FROM students;
```

```sql
SELECT * FROM students WHERE department = 'CS';
```

```sql
SELECT name, department, score FROM students WHERE score >= 80 ORDER BY score DESC;
```

### 3. Select Columns

If the user enters:

```sql
SELECT * FROM students;
```

the program displays all columns.

If the user enters:

```sql
SELECT name, score FROM students;
```

the program only displays the `name` and `score` columns.

### 4. Filter Records with WHERE

The program supports simple conditions such as:

```sql
WHERE score >= 80
```

```sql
WHERE department = 'CS'
```

Supported operators:

| Operator | Meaning |
|---|---|
| `=` | equal to |
| `==` | equal to |
| `!=` | not equal to |
| `>` | greater than |
| `<` | less than |
| `>=` | greater than or equal to |
| `<=` | less than or equal to |

### 5. Sort Results with ORDER BY

The program can sort query results.

Example:

```sql
SELECT * FROM students ORDER BY score DESC;
```

This sorts students by score from high to low.

## How to Compile

Use `g++` to compile the program.

```bash
g++ csv_select.cpp -o csv_select
```

## How to Run

Make sure `students.csv` and the compiled program are in the same folder.

```bash
./csv_select
```

On Windows, use:

```bash
csv_select.exe
```

## Example Usage

Input:

```sql
SELECT name, department, score FROM students WHERE score >= 80 ORDER BY score DESC;
```

Output:

```text
name     department  score
----     ----------  -----
Eva      CS          95
Charlie  CS          92
Jack     EE          90
Grace    BA          88
Alice    CS          85
Ivy      CS          81

Total rows: 6
```

## What I Learned

Through this project, I learned how to use C++ to process CSV data and simulate a simple database query.

I also learned that a `SELECT` function is not only about printing data.  
It includes several important steps:

1. Reading the file
2. Understanding column names
3. Parsing user input
4. Filtering rows
5. Selecting columns
6. Sorting the result
7. Displaying the result clearly

## AI-Assisted Development Reflection

AI helped me design the structure of the program and think about what functions a simple CSV database should include.

However, I still needed to understand the code by myself, check whether the query examples worked correctly, and make sure the program matched the requirements of my course project.

## Future Improvements

In the future, this project can be improved by adding:

- INSERT function
- UPDATE function
- DELETE function
- More complete SQL syntax
- Better error handling
- Support for multiple CSV files
- Saving query results to another file
