# Data Folder

## Overview

This folder stores the sample CSV dataset used by **Project B: CSV Mini Database - SELECT Query Engine**.

The main data file is:

```text
students.csv
```

The C++ program in `src/main.cpp` reads this CSV file, stores its headers and rows in memory, and allows the user to run simple SQL-like `SELECT` queries.

---

## Dataset File

```text
Data/students.csv
```

The dataset contains student records.
Each row represents one student, and each column represents one attribute.

---

## CSV Columns

| Column       | Description         |
| ------------ | ------------------- |
| `id`         | Student ID          |
| `name`       | Student name        |
| `department` | Student department  |
| `grade`      | Student grade level |
| `age`        | Student age         |
| `score`      | Student score       |
| `city`       | Student city        |

---

## Example Records

| id | name    | department | grade | age | score | city      |
| -- | ------- | ---------- | ----- | --- | ----- | --------- |
| 1  | Alice   | CS         | 1     | 18  | 85    | Taipei    |
| 2  | Bob     | EE         | 2     | 19  | 78    | Taichung  |
| 3  | Charlie | CS         | 3     | 20  | 92    | Taipei    |
| 4  | David   | ME         | 2     | 20  | 66    | Tainan    |
| 5  | Eva     | CS         | 4     | 22  | 95    | Kaohsiung |

The full CSV file contains 10 student records.

---

## How the Program Uses This Data

The program uses the CSV file as one simple table.

The basic workflow is:

```text
Load students.csv
→ Read the first row as headers
→ Read the remaining rows as student records
→ Store the data in memory
→ Execute a user SELECT query
→ Print the query result as a table
```

The suggested table name used in queries is:

```text
students
```

---

## Supported Query Usage

The current program supports `SELECT` queries on this dataset.

### Select all columns

```sql
SELECT * FROM students;
```

### Select specific columns

```sql
SELECT name, score FROM students;
```

### Filter by department

```sql
SELECT * FROM students WHERE department = 'CS';
```

### Filter by score

```sql
SELECT * FROM students WHERE score >= 80;
```

### Sort by score

```sql
SELECT * FROM students ORDER BY score DESC;
```

### Combine column selection, filtering, and sorting

```sql
SELECT name, department, score FROM students WHERE score >= 80 ORDER BY score DESC;
```

---

## Data Features for Demo

This dataset is suitable for demonstrating:

* Column selection
* Text comparison, such as `department = 'CS'`
* Numeric comparison, such as `score >= 80`
* Sorting with `ORDER BY`
* Readable table output

Because the data includes different departments, scores, cities, and grade levels, it can clearly show how filtering and sorting change the query result.

---

## Current Scope

The current program **only reads and queries** the CSV data.

Implemented:

| Feature                      | Status      |
| ---------------------------- | ----------- |
| Load CSV data                | Implemented |
| Use the first row as headers | Implemented |
| Select all columns           | Implemented |
| Select specific columns      | Implemented |
| Filter rows with `WHERE`     | Implemented |
| Sort rows with `ORDER BY`    | Implemented |

Not currently implemented:

* Insert new rows
* Update existing rows
* Delete rows
* Save modified data back to CSV
* `COUNT`
* `AVG`
* `GROUP BY`
* Multi-condition filtering with `AND` / `OR`

---

## Reflection

This dataset helped me practice how a simple CSV file can behave like a small database table.

The current project focuses on querying existing data instead of modifying the file.
Therefore, this README describes the dataset from the perspective of the implemented `SELECT`, `WHERE`, and `ORDER BY` features.
