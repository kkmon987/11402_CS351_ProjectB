# Design: What Should I Do?

## 1. Goal

The goal of this small project is to design a simple CSV dataset that can be used to practice SQL `SELECT` queries.

The dataset should be small enough to understand quickly, but still include enough variety to practice common query conditions such as filtering, sorting, grouping, and counting.

## 2. Dataset Topic

The dataset will use a **student information table**.

This topic is easy to understand because each row represents one student, and each column describes one attribute of that student.

The table can be named:

```text
students
```

## 3. What the CSV Should Include

The CSV should include different types of data so that it can support different SQL query examples.

Recommended columns:

| Column | Purpose |
|---|---|
| `id` | Unique student ID |
| `name` | Student name |
| `department` | Department, such as CS, EE, ME, or BA |
| `grade` | Student year level |
| `city` | Student's city |
| `score` | Student score |
| `credits` | Course credits |
| `status` | Whether the student is active or inactive |

## 4. Why These Columns Are Useful

Each column is designed for a specific type of SQL practice.

| Column | Useful For |
|---|---|
| `department` | Practicing filtering and grouping |
| `grade` | Practicing numeric conditions |
| `city` | Practicing text filtering |
| `score` | Practicing comparison, sorting, average, max, and min |
| `credits` | Practicing ordering and numeric grouping |
| `status` | Practicing simple category filtering |

## 5. Query Skills to Practice

This dataset should help practice the following SQL skills:

- Selecting all columns
- Selecting specific columns
- Filtering rows with `WHERE`
- Combining conditions with `AND`
- Sorting results with `ORDER BY`
- Grouping data with `GROUP BY`
- Counting rows with `COUNT`
- Calculating averages with `AVG`
- Finding highest and lowest values with `MAX` and `MIN`

## 6. Suggested Practice Flow

### Step 1: Understand the Data

Start by viewing all records in the table.

The purpose of this step is to understand what columns exist and what kind of values appear in each column.

### Step 2: Select Specific Columns

Practice selecting only the columns needed, such as student names and scores.

This helps avoid showing unnecessary information.

### Step 3: Filter the Data

Use conditions to find specific groups of students.

Examples:

- Students from a specific department
- Students with scores above a certain value
- Students from a certain city
- Students who are active or inactive

### Step 4: Sort the Results

Sort students by score, credits, or grade.

This helps practice how to control the order of query results.

### Step 5: Group and Summarize

Group students by department or city.

This helps practice summary queries, such as finding the average score of each department.

## 7. Example Questions to Answer

The project should include questions like:

1. Which students have a score greater than or equal to 80?
2. Which students are in the CS department?
3. Which students are active and live in Taipei?
4. Which department has the highest average score?
5. How many students are in each department?
6. Which student has the highest score?
7. How many inactive students are there?
8. Which city has the most students?

## 8. Expected Files

The final project can include these files:

```text
students_project/
├── students.csv
└── design.md
```

Optional file:

```text
select_practice.md
```

The `students.csv` file stores the data.

The `design.md` file explains the purpose and design of the dataset.

The `select_practice.md` file can include SQL practice questions and answers.

## 9. Design Principle

The dataset should not be too complicated.

A good small dataset should have:

- Around 10 to 15 rows
- Clear column names
- Different categories
- Different numeric values
- Some repeated values for grouping practice
- Simple values that are easy to check manually

## 10. Summary

This project is designed to help beginners practice SQL `SELECT` queries using a simple CSV file.

The main focus is not writing complex code, but designing clean data that makes query practice meaningful and easy to understand.
