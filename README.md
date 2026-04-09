# Project B: CSV Mini Database & Query Engine

## Overview

This project implements a lightweight, in-memory database engine that can load and query CSV (Comma-Separated Values) files using a simplified SQL-like query language. The system provides basic database operations such as data loading, querying, filtering, joining, and aggregation, making it suitable for small-scale data analysis and educational purposes.

## Features

- **CSV Data Loading**: Load CSV files into in-memory tables with automatic type inference
- **SQL-like Query Language**: Support for SELECT, FROM, WHERE, JOIN, GROUP BY, and ORDER BY clauses
- **Data Types**: Support for integers, floats, strings, and dates
- **Aggregation Functions**: COUNT, SUM, AVG, MIN, MAX
- **Query Optimization**: Basic query planning and execution optimization
- **Result Output**: Export query results to CSV or display in console
- **Error Handling**: Comprehensive error reporting for malformed queries and data issues

## Requirements

- Python 3.8 or higher
- No external dependencies (uses only standard library)

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/kkmon987/11402_CS351_ProjectB.git
   cd 11402_CS351_ProjectB
   ```

2. Ensure Python 3.8+ is installed:
   ```bash
   python --version
   ```

## Usage

### Loading Data

```python
from csv_db import Database

db = Database()
db.load_table('users', 'data/users.csv')
db.load_table('orders', 'data/orders.csv')
```

### Running Queries

```python
# Simple SELECT
result = db.query("SELECT name, age FROM users WHERE age > 25")

# JOIN operation
result = db.query("""
    SELECT u.name, o.product, o.amount
    FROM users u
    JOIN orders o ON u.id = o.user_id
    WHERE o.amount > 100
""")

# Aggregation
result = db.query("""
    SELECT department, COUNT(*), AVG(salary)
    FROM employees
    GROUP BY department
""")
```

### Exporting Results

```python
result.save_to_csv('output/results.csv')
```

## Architecture

The system consists of several key components:

- **Parser**: Converts SQL-like strings into abstract syntax trees
- **Query Planner**: Optimizes query execution plans
- **Executor**: Executes queries on in-memory data structures
- **Storage Engine**: Manages CSV file loading and in-memory table storage
- **Type System**: Handles data type inference and conversion

## Project Structure

```
11402_CS351_ProjectB/
├── csv_db/
│   ├── __init__.py
│   ├── parser.py
│   ├── planner.py
│   ├── executor.py
│   ├── storage.py
│   └── types.py
├── tests/
│   ├── test_parser.py
│   ├── test_executor.py
│   └── test_integration.py
├── data/
│   └── sample_data.csv
├── examples/
│   └── demo.py
├── README.md
└── requirements.txt
```

## Testing

Run the test suite:

```bash
python -m pytest tests/
```

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests for new functionality
5. Submit a pull request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Course Information

- **Course**: CS351 - Database Systems
- **Project**: B
- **Due Date**: [Insert due date]
- **Team Members**: [Insert team members]
