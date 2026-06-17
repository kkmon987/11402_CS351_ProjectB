# Data Folder

## About This Folder

This folder contains the CSV data used in **Project B: CSV Mini Database**.

The main data file is:

`students.csv`

This CSV file stores student information and is used by the C++ program in `src/main.cpp`.

---

## CSV File

The data file is:

`Data/students.csv`

The CSV file contains student records. Each row represents one student, and each column represents one attribute of the student.

---

## Data Format

The CSV file uses the following columns:

| Column       | Meaning             |
| ------------ | ------------------- |
| `id`         | Student ID          |
| `name`       | Student name        |
| `department` | Student department  |
| `grade`      | Student grade level |
| `age`        | Student age         |
| `score`      | Student score       |
| `city`       | Student city        |

---

## Example Data

Example records:

| id | name    | department | grade | age | score | city     |
| -- | ------- | ---------- | ----- | --- | ----- | -------- |
| 1  | Alice   | CS         | 1     | 18  | 85    | Taipei   |
| 2  | Bob     | EE         | 2     | 19  | 78    | Taichung |
| 3  | Charlie | CS         | 3     | 20  | 90    | Tainan   |

---

## Why I Designed the Data This Way

I designed the CSV data to be simple and easy to understand.

Each row stores one student record, and each column stores one piece of information about the student.

This design is useful for practicing basic database-like operations such as:

* loading data;
* displaying records;
* searching records;
* inserting new data;
* saving data back to the CSV file.

The `id` column is used as the unique identifier for each student. Because of this, the program checks whether an ID already exists before inserting a new record.

---

## Insert Data Rules

When inserting a new student record, the data should follow these rules:

| Field        | Rule                       |
| ------------ | -------------------------- |
| `id`         | Must be unique and numeric |
| `name`       | Cannot be empty            |
| `department` | Cannot be empty            |
| `grade`      | Must be a valid number     |
| `age`        | Must be a valid number     |
| `score`      | Must be between 0 and 100  |
| `city`       | Cannot be empty            |

These rules help keep the CSV data clean and reasonable.

---

## Example Insert Record

A valid inserted record may look like this:

| id | name  | department | grade | age | score | city   |
| -- | ----- | ---------- | ----- | --- | ----- | ------ |
| 11 | Kevin | CS         | 2     | 20  | 87    | Taipei |

After insertion and saving, this new record will be written back to:

`Data/students.csv`

---

## How the Program Uses This Data

The C++ program reads `students.csv` when it starts.

The program stores the data in memory, then allows users to display records, search records, and insert new student data.

After changes are made, the program can save the updated data back to the CSV file.

---

## Reflection

This dataset helped me understand how CSV files can be used as a simple database.

Although CSV is easy to read and edit, the program still needs validation to prevent invalid data. For example, duplicate IDs or invalid scores can make the data unreliable.

Through this project, I learned that good data design is important even for a small CSV-based program.
