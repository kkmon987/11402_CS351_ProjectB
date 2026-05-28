# CSV Mini Database - Students Dataset

## Project Description

This project is a simple CSV mini database system using a small student dataset.  
The dataset is stored in a CSV file named `students.csv`.

The goal of this project is to practice basic database-like operations on CSV data, especially the `SELECT` function.

## Dataset

The CSV file contains student information.

File name:

```bash
students.csv
```

## CSV Format

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

## Columns

| Column | Description |
|---|---|
| `id` | Student ID |
| `name` | Student name |
| `department` | Student department |
| `grade` | School year |
| `age` | Student age |
| `score` | Student score |
| `city` | City where the student is from |

## Example SELECT Queries

### Select all data

```sql
SELECT * FROM students;
```

### Select specific columns

```sql
SELECT name, score FROM students;
```

### Select students from CS department

```sql
SELECT * FROM students WHERE department = 'CS';
```

### Select students with score greater than or equal to 80

```sql
SELECT * FROM students WHERE score >= 80;
```

### Select students from Taipei

```sql
SELECT * FROM students WHERE city = 'Taipei';
```

### Order students by score from high to low

```sql
SELECT * FROM students ORDER BY score DESC;
```

### Count students by department

```sql
SELECT department, COUNT(*) FROM students GROUP BY department;
```

### Average score by city

```sql
SELECT city, AVG(score) FROM students GROUP BY city;
```

## Features

This project can be used to practice the following functions:

- Load CSV file
- Display all records
- Select specific columns
- Filter records with conditions
- Sort records
- Count records
- Calculate average values
- Group records by a column

## How to Use

1. Put `students.csv` in the project folder.
2. Run the program.
3. Enter a SELECT query.
4. The program reads the CSV file and displays the matching result.

Example:

```sql
SELECT name, department, score FROM students WHERE score >= 80;
```

Expected result:

```text
Alice, CS, 85
Charlie, CS, 92
Eva, CS, 95
Grace, BA, 88
Ivy, CS, 81
Jack, EE, 90
```

## Project Purpose

This project helps me understand how a simple database works.  
Although the data is stored in a CSV file instead of a real database, I can still practice basic database concepts such as selecting data, filtering records, sorting results, and grouping data.

## Reflection

Through this project, I learned how to organize structured data in a CSV file and how to design simple query functions.  
I also learned that even a small dataset can be used to simulate basic database operations.

In the future, I would like to improve this project by adding more functions such as:

- Insert new records
- Update existing records
- Delete records
- Save query results
- Support more SQL-like syntax
- Improve error handling
