## A fantastic challenge! 
#We're going to build a very comprehensive MySQL revision guide.

Let's set up a common database schema that we'll use for many of our examples. This will help you see how different concepts interact.

**Our Sample Database Schema:**

We'll create three main tables: `Departments`, `Employees`, and `Projects`, plus a junction table `EmployeeProjects`.

1.  **`Departments` Table:**
    *   `dept_id` (INT, Primary Key, Auto Increment)
    *   `dept_name` (VARCHAR(100), Unique, Not Null)
    *   `location` (VARCHAR(100))

2.  **`Employees` Table:**
    *   `emp_id` (INT, Primary Key, Auto Increment)
    *   `first_name` (VARCHAR(50), Not Null)
    *   `last_name` (VARCHAR(50), Not Null)
    *   `email` (VARCHAR(100), Unique, Not Null)
    *   `phone_number` (VARCHAR(20), Unique)
    *   `hire_date` (DATE, Not Null)
    *   `job_title` (VARCHAR(100), Not Null)
    *   `salary` (DECIMAL(10, 2), Not Null, Check salary > 0)
    *   `manager_id` (INT, Foreign Key references `Employees(emp_id)`) - for self-referencing
    *   `dept_id` (INT, Foreign Key references `Departments(dept_id)`)

3.  **`Projects` Table:**
    *   `project_id` (INT, Primary Key, Auto Increment)
    *   `project_name` (VARCHAR(150), Not Null)
    *   `start_date` (DATE)
    *   `end_date` (DATE)
    *   `budget` (DECIMAL(12,2))

4.  **`EmployeeProjects` Table (Junction Table for Many-to-Many between Employees and Projects):**
    *   `assignment_id` (INT, Primary Key, Auto Increment)
    *   `emp_id` (INT, Foreign Key references `Employees(emp_id)`)
    *   `project_id` (INT, Foreign Key references `Projects(project_id)`)
    *   `role_in_project` (VARCHAR(50))
    *   `hours_assigned` (INT)
    *   (Composite UNIQUE constraint on `emp_id`, `project_id` to prevent duplicate assignments)

---

**Let's Start the Comprehensive Revision!**

---

**0. Setting up the Environment (MySQL Workbench / Command Line)**

*   **Connecting to MySQL:**
    *   Command Line: `mysql -u your_username -p` (You'll be prompted for your password)
    *   MySQL Workbench: Use the GUI to create a connection.
*   **Creating a Database (if needed):**
    ```sql
    CREATE DATABASE IF NOT EXISTS company_db;
    USE company_db;
    ```
    *   **Explanation:** `CREATE DATABASE` creates a new database. `IF NOT EXISTS` prevents an error if it already exists. `USE` selects the database to work with for subsequent commands.

---

**1. Basics of SQL**

**A. DDL (Data Definition Language)**
*Purpose: Used to define and manage database structure (schemas, tables, indexes, etc.).*

*   **`CREATE TABLE`**
    *   **Concept:** Defines a new table, its columns, data types for each column, and constraints.
    *   **Data Types (Common ones):**
        *   `INT` or `INTEGER`: Whole numbers.
        *   `DECIMAL(precision, scale)`: Fixed-point numbers (e.g., `DECIMAL(10,2)` for money).
        *   `VARCHAR(length)`: Variable-length strings.
        *   `CHAR(length)`: Fixed-length strings.
        *   `TEXT`: Long strings.
        *   `DATE`: Stores date (YYYY-MM-DD).
        *   `DATETIME` or `TIMESTAMP`: Stores date and time.
        *   `BOOLEAN` or `BOOL`: True/False (MySQL often uses `TINYINT(1)`).
        *   `ENUM('val1', 'val2', ...)`: A string object that can have only one value, chosen from a list of allowed values.
        *   `AUTO_INCREMENT`: Automatically generates a unique number when a new record is inserted (usually for primary keys).
    *   **Examples:**

        ```sql
        -- Creating the Departments table
        CREATE TABLE Departments (
            dept_id INT AUTO_INCREMENT PRIMARY KEY,
            dept_name VARCHAR(100) NOT NULL UNIQUE,
            location VARCHAR(100),
            establishment_date DATE DEFAULT (CURDATE()) -- Using a function for default
        );
        ```
        **Explanation:**
        *   `dept_id INT AUTO_INCREMENT PRIMARY KEY`: `dept_id` is an integer, automatically increments, and is the primary key (uniquely identifies each row, cannot be NULL).
        *   `dept_name VARCHAR(100) NOT NULL UNIQUE`: `dept_name` is a string up to 100 chars, cannot be empty, and must be unique across all departments.
        *   `location VARCHAR(100)`: `location` is a string, can be NULL.
        *   `establishment_date DATE DEFAULT (CURDATE())`: `establishment_date` is a date, and if not provided, defaults to the current date.

        ```sql
        -- Creating the Employees table (with Foreign Keys and Check constraint)
        CREATE TABLE Employees (
            emp_id INT AUTO_INCREMENT PRIMARY KEY,
            first_name VARCHAR(50) NOT NULL,
            last_name VARCHAR(50) NOT NULL,
            email VARCHAR(100) NOT NULL UNIQUE,
            phone_number VARCHAR(20) UNIQUE,
            hire_date DATE NOT NULL,
            job_title VARCHAR(100) NOT NULL,
            salary DECIMAL(10, 2) NOT NULL CHECK (salary > 20000.00),
            manager_id INT,
            dept_id INT,
            status ENUM('Active', 'On Leave', 'Terminated') DEFAULT 'Active',
            FOREIGN KEY (dept_id) REFERENCES Departments(dept_id) ON DELETE SET NULL ON UPDATE CASCADE,
            FOREIGN KEY (manager_id) REFERENCES Employees(emp_id) ON DELETE SET NULL ON UPDATE CASCADE
        );
        ```
        **Explanation:**
        *   `salary DECIMAL(10, 2) NOT NULL CHECK (salary > 20000.00)`: Salary must be greater than 20000.
        *   `status ENUM(...) DEFAULT 'Active'`: Employee status can only be one of the specified values.
        *   `FOREIGN KEY (dept_id) REFERENCES Departments(dept_id) ON DELETE SET NULL ON UPDATE CASCADE`:
            *   Links `dept_id` in `Employees` to `dept_id` in `Departments`.
            *   `ON DELETE SET NULL`: If a department is deleted, the `dept_id` for employees in that department becomes `NULL`.
            *   `ON UPDATE CASCADE`: If a `dept_id` in `Departments` is updated, the change cascades to `Employees`.
        *   `FOREIGN KEY (manager_id) REFERENCES Employees(emp_id)`: Self-referencing FK for manager-employee relationship.

        ```sql
        -- Creating the Projects table
        CREATE TABLE Projects (
            project_id INT AUTO_INCREMENT PRIMARY KEY,
            project_name VARCHAR(150) NOT NULL,
            start_date DATE,
            end_date DATE,
            budget DECIMAL(12,2),
            CONSTRAINT chk_project_dates CHECK (end_date IS NULL OR start_date IS NULL OR end_date >= start_date)
        );
        ```
        **Explanation:**
        *   `CONSTRAINT chk_project_dates CHECK (...)`: Named check constraint ensuring `end_date` is after `start_date` if both are provided.

        ```sql
        -- Creating the EmployeeProjects junction table
        CREATE TABLE EmployeeProjects (
            assignment_id INT AUTO_INCREMENT PRIMARY KEY,
            emp_id INT NOT NULL,
            project_id INT NOT NULL,
            role_in_project VARCHAR(50) DEFAULT 'Team Member',
            hours_assigned INT CHECK (hours_assigned > 0 AND hours_assigned <= 40),
            FOREIGN KEY (emp_id) REFERENCES Employees(emp_id) ON DELETE CASCADE,
            FOREIGN KEY (project_id) REFERENCES Projects(project_id) ON DELETE CASCADE,
            UNIQUE (emp_id, project_id) -- An employee can't be assigned to the same project twice
        );
        ```
        **Explanation:**
        *   `ON DELETE CASCADE`: If an employee or project is deleted, corresponding assignments are also deleted.
        *   `UNIQUE (emp_id, project_id)`: Composite unique key.

*   **`ALTER TABLE`**
    *   **Concept:** Modifies an existing table structure.
    *   **Use Cases & Examples:**
        1.  **Add a new column:**
            ```sql
            ALTER TABLE Employees ADD COLUMN annual_bonus DECIMAL(8,2) DEFAULT 0.00;
            ALTER TABLE Departments ADD COLUMN contact_email VARCHAR(100);
            ```
        2.  **Drop a column:**
            ```sql
            ALTER TABLE Employees DROP COLUMN annual_bonus;
            ALTER TABLE Departments DROP COLUMN contact_email;
            ```
        3.  **Modify column data type or constraints:**
            ```sql
            ALTER TABLE Employees MODIFY COLUMN phone_number VARCHAR(25); -- Change length
            ALTER TABLE Employees MODIFY COLUMN job_title VARCHAR(120) NOT NULL; -- Change length and add NOT NULL
            ALTER TABLE Projects MODIFY COLUMN budget DECIMAL(14,2);
            ```
            *Note: Be cautious when changing data types, as it can lead to data loss if new type is incompatible.*
        4.  **Rename a column (MySQL specific syntax):**
            ```sql
            ALTER TABLE Employees RENAME COLUMN phone_number TO contact_phone;
            ALTER TABLE Departments RENAME COLUMN location TO office_location;
            ```
        5.  **Add a constraint:**
            ```sql
            ALTER TABLE Employees ADD CONSTRAINT chk_hire_date CHECK (hire_date <= CURDATE());
            ALTER TABLE Projects ADD UNIQUE (project_name);
            ```
        6.  **Drop a constraint (you need to know its name, or the PK/FK/Unique name):**
            *   For primary key: `ALTER TABLE Employees DROP PRIMARY KEY;` (Usually not done unless replacing)
            *   For foreign key: First, find the constraint name: `SHOW CREATE TABLE Employees;` (Look for `CONSTRAINT \`constraint_name\` FOREIGN KEY ...`)
                ```sql
                -- Example: If the constraint name for dept_id FK is 'employees_ibfk_1'
                ALTER TABLE Employees DROP FOREIGN KEY employees_ibfk_1;
                ```
            *   For unique constraint: `SHOW CREATE TABLE Departments;` (to find unique constraint name for `dept_name`)
                ```sql
                -- Example: If the unique key for dept_name is named 'dept_name' (often the column name itself if not specified)
                ALTER TABLE Departments DROP INDEX dept_name; -- For unique constraint, you drop the associated index
                ```
            *   For check constraint (MySQL 8.0.16+):
                ```sql
                ALTER TABLE Employees DROP CONSTRAINT chk_hire_date;
                ```
        7.  **Rename a table:**
            ```sql
            ALTER TABLE Departments RENAME TO OrgDepartments;
            ALTER TABLE OrgDepartments RENAME TO Departments; -- Renaming back
            ```

*   **`DROP TABLE`**
    *   **Concept:** Deletes an entire table structure and all its data. This action is irreversible!
    *   **Examples:**
        ```sql
        -- First drop tables with foreign keys pointing to the table you want to drop,
        -- or drop the FK constraints from child tables.
        -- For our schema, to drop Departments, you might first need to alter Employees to remove the FK,
        -- or drop Employees first (which in turn might require dropping EmployeeProjects).

        -- Let's assume we want to drop a temporary table:
        CREATE TABLE TempData (id INT, data VARCHAR(10));
        DROP TABLE TempData;

        -- To drop with a check if it exists (avoids error if it doesn't):
        DROP TABLE IF EXISTS TempData;
        ```
        **Caution:** Be extremely careful with `DROP TABLE` in a production environment.

*   **`TRUNCATE TABLE`**
    *   **Concept:** Removes all rows from a table very quickly. It's like `DELETE` without a `WHERE` clause, but usually faster and doesn't log individual row deletions (so can't be easily rolled back in a transaction like `DELETE`). It also resets `AUTO_INCREMENT` counters.
    *   **Examples:**
        ```sql
        -- Let's assume EmployeeProjects has data and we want to clear it
        TRUNCATE TABLE EmployeeProjects;
        ```
    *   **Difference between `DELETE` and `TRUNCATE`:**
        *   `DELETE`: DML command, can use `WHERE`, logs row deletions, can be rolled back (if not autocommitted), doesn't reset `AUTO_INCREMENT`. Slower for large tables.
        *   `TRUNCATE`: DDL command, no `WHERE`, typically doesn't log row deletions (or logs minimally), often cannot be rolled back (depends on RDBMS and transaction settings), resets `AUTO_INCREMENT`. Faster for clearing all data.

---

**B. DML (Data Manipulation Language)**
*Purpose: Used to insert, update, delete, and retrieve data from tables.*

*   **`INSERT INTO`**
    *   **Concept:** Adds new rows (records) to a table.
    *   **Syntax Variations & Examples:**

        1.  **Inserting a full row, specifying column order implicitly (order must match table definition):**
            ```sql
            -- Inserting into Departments
            INSERT INTO Departments VALUES (NULL, 'Human Resources', 'New York HQ', '2000-01-15');
            INSERT INTO Departments VALUES (NULL, 'Engineering', 'Silicon Valley Campus', '1995-06-10');
            INSERT INTO Departments VALUES (NULL, 'Marketing', 'Chicago Office', '2005-03-01');
            INSERT INTO Departments VALUES (NULL, 'Finance', 'New York HQ', '2000-01-20');
            INSERT INTO Departments VALUES (DEFAULT, 'Research & Development', 'Boston Lab', DEFAULT); -- Using DEFAULT for auto-increment and default date
            ```
            *Explanation: `NULL` or `DEFAULT` can be used for the `dept_id` (AUTO_INCREMENT). `DEFAULT` for `establishment_date` uses `CURDATE()`.*

        2.  **Inserting a row, specifying column names explicitly (recommended for clarity and robustness):**
            ```sql
            INSERT INTO Departments (dept_name, location, establishment_date)
            VALUES ('Sales', 'Dallas Hub', '2002-07-22');

            INSERT INTO Departments (dept_name, location) -- establishment_date will use its DEFAULT
            VALUES ('Customer Support', 'Phoenix Center');
            ```

        3.  **Inserting multiple rows at once:**
            ```sql
            INSERT INTO Departments (dept_name, location, establishment_date) VALUES
                ('Legal', 'Washington D.C.', '2010-09-01'),
                ('Operations', 'Austin Facility', '2008-11-05');
            ```

        4.  **Inserting into Employees:**
            *(Assuming dept_id for 'Human Resources' is 1, 'Engineering' is 2, 'Marketing' is 3, 'Finance' is 4, 'Research & Development' is 5)*
            ```sql
            INSERT INTO Employees (first_name, last_name, email, phone_number, hire_date, job_title, salary, dept_id, manager_id, status) VALUES
            ('Alice', 'Smith', 'alice.smith@company.com', '555-0101', '2015-07-01', 'HR Manager', 75000.00, 1, NULL, 'Active'), -- Alice is a top manager
            ('Bob', 'Johnson', 'bob.johnson@company.com', '555-0102', '2016-08-15', 'Software Engineer Lead', 95000.00, 2, NULL, 'Active'), -- Bob is a top manager
            ('Carol', 'Williams', 'carol.w@company.com', '555-0103', '2017-09-20', 'HR Specialist', 60000.00, 1, 1, 'Active'), -- Carol reports to Alice (emp_id 1)
            ('David', 'Brown', 'david.b@company.com', '555-0104', '2018-03-10', 'Software Engineer', 80000.00, 2, 2, 'Active'), -- David reports to Bob (emp_id 2)
            ('Eve', 'Davis', 'eve.davis@company.com', '555-0105', '2019-05-25', 'Marketing Specialist', 65000.00, 3, NULL, 'On Leave'),
            ('Frank', 'Miller', 'frank.m@company.com', '555-0106', '2020-11-30', 'Junior Developer', 70000.00, 2, 2, 'Active'),
            ('Grace', 'Wilson', 'grace.w@company.com', '555-0107', '2021-02-15', 'Accountant', 72000.00, 4, NULL, 'Active'),
            ('Henry', 'Moore', 'henry.m@company.com', '555-0108', '2017-06-01', 'Senior Software Engineer', 110000.00, 2, 2, 'Terminated');
            ```

        5.  **Inserting into Projects:**
            ```sql
            INSERT INTO Projects (project_name, start_date, end_date, budget) VALUES
            ('Alpha Launch', '2023-01-15', '2023-09-30', 150000.00),
            ('Beta Platform', '2023-03-01', '2024-02-28', 300000.00),
            ('Gamma Initiative', '2023-06-01', NULL, 75000.00), -- Ongoing project
            ('Delta Upgrade', '2024-01-01', '2024-06-30', 120000.00);
            ```

        6.  **Inserting into EmployeeProjects (junction table):**
            *(Assuming emp_id 2 is Bob, emp_id 4 is David, emp_id 6 is Frank. Project_id 1 is Alpha, 2 is Beta.)*
            ```sql
            INSERT INTO EmployeeProjects (emp_id, project_id, role_in_project, hours_assigned) VALUES
            (2, 1, 'Project Lead', 20),    -- Bob on Alpha Launch
            (4, 1, 'Developer', 30),       -- David on Alpha Launch
            (2, 2, 'Architect', 15),       -- Bob on Beta Platform
            (4, 2, 'Senior Developer', 35),-- David on Beta Platform
            (6, 2, 'Junior Developer', 40); -- Frank on Beta Platform
            ```

*   **`UPDATE`**
    *   **Concept:** Modifies existing rows in a table. **Crucially important: Always use a `WHERE` clause unless you intend to update ALL rows!**
    *   **Examples:**
        1.  **Update a single column for a specific record:**
            ```sql
            UPDATE Employees
            SET salary = 80000.00
            WHERE email = 'alice.smith@company.com';
            ```
        2.  **Update multiple columns for a specific record:**
            ```sql
            UPDATE Employees
            SET job_title = 'Senior HR Manager', salary = 82000.00
            WHERE emp_id = 1; -- Assuming Alice's emp_id is 1
            ```
        3.  **Update based on a condition affecting multiple rows:**
            ```sql
            -- Give a 5% raise to all Software Engineers in department 2 (Engineering)
            UPDATE Employees
            SET salary = salary * 1.05
            WHERE job_title = 'Software Engineer' AND dept_id = 2;
            ```
        4.  **Update with a calculation:**
            ```sql
            UPDATE Projects
            SET budget = budget + 10000.00
            WHERE project_name = 'Beta Platform';
            ```
        5.  **Updating phone number and status for an employee:**
            ```sql
            UPDATE Employees
            SET phone_number = '555-0110', status = 'Active'
            WHERE first_name = 'Eve' AND last_name = 'Davis';
            ```
        6.  **Update a project's end date and mark it as completed (hypothetical `status` column):**
            ```sql
            -- ALTER TABLE Projects ADD COLUMN status ENUM('Planning', 'In Progress', 'Completed', 'On Hold') DEFAULT 'Planning';
            -- UPDATE Projects SET status = 'In Progress' WHERE start_date <= CURDATE() AND (end_date IS NULL OR end_date >= CURDATE());

            UPDATE Projects
            SET end_date = '2023-10-15' -- , status = 'Completed' -- if status column existed
            WHERE project_name = 'Alpha Launch' AND end_date IS NULL; -- Only if not already set
            ```
        7.  **Update all rows (USE WITH EXTREME CAUTION!):**
            ```sql
            -- Example: Change a default value for a newly added column across all existing records
            -- ALTER TABLE Employees ADD COLUMN performance_review_due DATE;
            -- UPDATE Employees SET performance_review_due = DATE_ADD(hire_date, INTERVAL 1 YEAR);
            ```

*   **`DELETE`**
    *   **Concept:** Removes rows from a table. **Crucially important: Always use a `WHERE` clause unless you intend to delete ALL rows!**
    *   **Examples:**
        1.  **Delete a specific record:**
            ```sql
            -- Let's say we added a test employee and want to remove them
            INSERT INTO Employees (first_name, last_name, email, hire_date, job_title, salary, dept_id, status)
            VALUES ('Test', 'User', 'test.user@company.com', CURDATE(), 'Intern', 25000.00, 1, 'Active');

            DELETE FROM Employees
            WHERE email = 'test.user@company.com';
            ```
        2.  **Delete records based on a condition:**
            ```sql
            -- Delete all projects that ended before 2023 and have a budget less than 50000
            DELETE FROM Projects
            WHERE end_date < '2023-01-01' AND budget < 50000.00;

            -- Delete all 'Terminated' employees
            DELETE FROM Employees
            WHERE status = 'Terminated';
            -- (Note: This might have FK implications if ON DELETE RESTRICT is used elsewhere and these employees are referenced)
            -- For our setup, `ON DELETE SET NULL` for manager_id and `ON DELETE CASCADE` for EmployeeProjects will handle this.
            ```
        3.  **Delete all records from a table (BE VERY CAREFUL!):**
            ```sql
            -- This deletes all employees, but keeps the table structure.
            -- Unlike TRUNCATE, this can be rolled back if within a transaction (usually).
            -- DELETE FROM Employees;
            ```
            *If you need to delete all rows, `TRUNCATE TABLE Employees;` is often more efficient.*
        4.  **Deleting an employee and cascading effects:**
            *If Carol Williams (emp_id 3) leaves the company, and FKs are set with `ON DELETE CASCADE` or `ON DELETE SET NULL`:*
            *   Assignments in `EmployeeProjects` for Carol will be deleted (due to `ON DELETE CASCADE` on `EmployeeProjects.emp_id`).
            *   If other employees reported to Carol, their `manager_id` would become `NULL` (due to `ON DELETE SET NULL` on `Employees.manager_id`).
            ```sql
            -- Assuming Carol's emp_id is 3 (after re-inserting terminated employees, her ID might be different)
            -- Let's assume we identify her by email for this example if IDs are dynamic from re-runs.
            -- DELETE FROM Employees WHERE email = 'carol.w@company.com';
            ```
            *(For now, let's ensure we have enough data for SELECT queries. We can re-insert if needed.)*

---

**C. DQL (Data Query Language)**
*Purpose: Used to retrieve data from the database. The `SELECT` statement is the cornerstone.*

*   **`SELECT`**
    *   **Concept:** Fetches data from one or more tables.
    *   **Basic Syntax:** `SELECT column1, column2, ... FROM table_name;`

    *   **Examples:**
        1.  **Select all columns from a table:**
            ```sql
            SELECT * FROM Departments;
            SELECT * FROM Employees;
            SELECT * FROM Projects;
            SELECT * FROM EmployeeProjects;
            ```
            *Note: `SELECT *` is convenient for exploration but generally discouraged in production code for performance and stability reasons (if table structure changes).*

        2.  **Select specific columns:**
            ```sql
            SELECT dept_name, location FROM Departments;
            SELECT first_name, last_name, email, salary FROM Employees;
            SELECT project_name, start_date, budget FROM Projects;
            ```

        3.  **`DISTINCT` - Select unique values:**
            ```sql
            SELECT DISTINCT location FROM Departments; -- Shows only unique locations
            SELECT DISTINCT job_title FROM Employees; -- Shows all unique job titles
            SELECT DISTINCT status FROM Employees;
            ```

*   **`WHERE` Clause**
    *   **Concept:** Filters rows based on specified conditions.
    *   **Operators:** `=`, `>`, `<`, `>=`, `<=`, `!=` or `<>` (not equal), `AND`, `OR`, `NOT`, `BETWEEN`, `IN`, `LIKE`, `IS NULL`, `IS NOT NULL`.
    *   **Examples:**
        1.  **Equality:**
            ```sql
            SELECT first_name, last_name, job_title FROM Employees WHERE job_title = 'Software Engineer';
            SELECT * FROM Departments WHERE location = 'New York HQ';
            SELECT * FROM Employees WHERE status = 'On Leave';
            ```
        2.  **Comparison:**
            ```sql
            SELECT first_name, last_name, salary FROM Employees WHERE salary > 90000.00;
            SELECT project_name, start_date FROM Projects WHERE start_date >= '2023-06-01';
            SELECT first_name, last_name, hire_date FROM Employees WHERE hire_date < '2018-01-01';
            ```
        3.  **`AND` (both conditions true):**
            ```sql
            SELECT first_name, last_name, salary FROM Employees
            WHERE job_title = 'Software Engineer' AND salary < 85000.00;
            SELECT project_name, budget FROM Projects
            WHERE start_date >= '2023-01-01' AND budget > 100000;
            ```
        4.  **`OR` (at least one condition true):**
            ```sql
            SELECT first_name, last_name, job_title FROM Employees
            WHERE job_title = 'HR Manager' OR job_title = 'Marketing Specialist';
            SELECT * FROM Departments WHERE location = 'New York HQ' OR dept_name = 'Engineering';
            ```
        5.  **`NOT` (negates a condition):**
            ```sql
            SELECT first_name, last_name, dept_id FROM Employees
            WHERE NOT dept_id = 2; -- Employees not in Engineering (dept_id 2)
            SELECT * FROM Employees WHERE NOT status = 'Active';
            ```
        6.  **`BETWEEN ... AND ...` (inclusive range):**
            ```sql
            SELECT first_name, last_name, salary FROM Employees
            WHERE salary BETWEEN 70000.00 AND 90000.00;
            SELECT project_name, budget FROM Projects
            WHERE budget BETWEEN 100000 AND 200000;
            SELECT first_name, last_name, hire_date FROM Employees
            WHERE hire_date BETWEEN '2017-01-01' AND '2018-12-31';
            ```
        7.  **`IN (...)` (matches any value in a list):**
            ```sql
            SELECT first_name, last_name, job_title FROM Employees
            WHERE job_title IN ('Software Engineer', 'Senior Software Engineer', 'Junior Developer');

            SELECT * FROM Departments
            WHERE location IN ('New York HQ', 'Silicon Valley Campus', 'Boston Lab');
            ```
        8.  **`LIKE` (pattern matching):**
            *   `%`: Matches any sequence of zero or more characters.
            *   `_`: Matches any single character.
            ```sql
            SELECT first_name, last_name, email FROM Employees WHERE email LIKE '%@company.com'; -- Ends with
            SELECT first_name, last_name FROM Employees WHERE first_name LIKE 'A%'; -- Starts with A
            SELECT first_name, last_name FROM Employees WHERE last_name LIKE 'Smit_'; -- Smith, Smits, etc.
            SELECT project_name FROM Projects WHERE project_name LIKE '%Platform%'; -- Contains 'Platform'
            SELECT first_name FROM Employees WHERE first_name LIKE '__r%'; -- Third letter is 'r'
            ```
        9.  **`IS NULL` / `IS NOT NULL` (checking for missing values):**
            ```sql
            SELECT first_name, last_name FROM Employees WHERE manager_id IS NULL; -- Top-level managers
            SELECT project_name FROM Projects WHERE end_date IS NULL; -- Ongoing projects
            SELECT emp_id, phone_number FROM Employees WHERE phone_number IS NOT NULL;
            SELECT first_name, last_name FROM Employees WHERE manager_id IS NOT NULL; -- Employees who have a manager
            ```
        10. **Combining multiple conditions with parentheses for precedence:**
            ```sql
            SELECT first_name, last_name, job_title, salary, dept_id FROM Employees
            WHERE (job_title LIKE '%Engineer%' OR job_title LIKE '%Developer%')
              AND salary > 75000
              AND dept_id = 2; -- Engineers/Developers in Dept 2 earning > 75k

            SELECT * FROM Projects
            WHERE (project_name LIKE 'Alpha%' OR budget > 200000) AND start_date < '2023-06-01';
            ```

*   **`ORDER BY` Clause**
    *   **Concept:** Sorts the result set by one or more columns.
    *   **`ASC` (ascending, default), `DESC` (descending).**
    *   **Examples:**
        1.  **Sort by one column:**
            ```sql
            SELECT first_name, last_name, salary FROM Employees ORDER BY salary DESC; -- Highest salary first
            SELECT dept_name, location FROM Departments ORDER BY dept_name ASC; -- Alphabetical by department name
            SELECT project_name, start_date FROM Projects ORDER BY start_date DESC; -- Newest projects first
            ```
        2.  **Sort by multiple columns:**
            ```sql
            SELECT first_name, last_name, dept_id, salary FROM Employees
            ORDER BY dept_id ASC, salary DESC; -- Sort by dept, then within each dept by salary descending

            SELECT location, dept_name FROM Departments
            ORDER BY location ASC, dept_name ASC;
            ```
        3.  **Sort by column position (less readable, generally avoid in production code):**
            ```sql
            SELECT first_name, last_name, hire_date FROM Employees ORDER BY 3 DESC; -- Sort by hire_date (3rd column) descending
            ```
        4.  **Sorting with `NULL` values:** By default, `NULL`s are sorted first in `ASC` and last in `DESC` in MySQL.
            ```sql
            SELECT project_name, end_date FROM Projects ORDER BY end_date ASC; -- Projects with NULL end_date first
            SELECT project_name, end_date FROM Projects ORDER BY end_date DESC; -- Projects with NULL end_date last
            ```

*   **Aggregate Functions with `GROUP BY` Clause**
    *   **Concept:** Aggregate functions perform calculations on a set of rows and return a single summary value. `GROUP BY` groups rows that have the same values in specified columns into summary rows.
    *   **Common Aggregate Functions:**
        *   `COUNT(*)`: Number of rows in a group.
        *   `COUNT(column_name)`: Number of non-NULL values in that column within a group.
        *   `COUNT(DISTINCT column_name)`: Number of unique non-NULL values.
        *   `SUM(column_name)`: Sum of values.
        *   `AVG(column_name)`: Average of values.
        *   `MIN(column_name)`: Minimum value.
        *   `MAX(column_name)`: Maximum value.
        *   `GROUP_CONCAT(column_name)`: Concatenates values from a group into a single string.
    *   **Examples:**
        1.  **Count total employees:**
            ```sql
            SELECT COUNT(*) AS total_employees FROM Employees;
            SELECT COUNT(phone_number) AS employees_with_phone FROM Employees;
            SELECT COUNT(DISTINCT dept_id) AS num_depts_with_employees FROM Employees WHERE dept_id IS NOT NULL;
            ```
        2.  **Count employees in each department:**
            ```sql
            SELECT dept_id, COUNT(*) AS num_employees
            FROM Employees
            WHERE dept_id IS NOT NULL
            GROUP BY dept_id
            ORDER BY num_employees DESC;
            ```
            *(To make this more readable, we'll need a JOIN later to get `dept_name`.)*
        3.  **Average salary per job title:**
            ```sql
            SELECT job_title, AVG(salary) AS average_salary, COUNT(*) AS count_employees, MIN(salary) as min_salary_for_title, MAX(salary) as max_salary_for_title
            FROM Employees
            GROUP BY job_title
            ORDER BY average_salary DESC;
            ```
        4.  **Total budget for projects starting each year:**
            ```sql
            SELECT YEAR(start_date) AS project_start_year, SUM(budget) AS total_budget_for_year, COUNT(*) AS num_projects_this_year
            FROM Projects
            WHERE start_date IS NOT NULL
            GROUP BY YEAR(start_date)
            ORDER BY project_start_year;
            ```
        5.  **Min and Max salary in the company, and average hire tenure (in days):**
            ```sql
            SELECT
                MIN(salary) AS min_company_salary,
                MAX(salary) AS max_company_salary,
                AVG(DATEDIFF(CURDATE(), hire_date)) AS avg_tenure_days
            FROM Employees;
            ```
        6.  **Number of projects and list of project names per start year:**
            ```sql
            SELECT
                YEAR(start_date) AS project_start_year,
                COUNT(*) AS num_projects,
                GROUP_CONCAT(project_name ORDER BY project_name SEPARATOR '; ') AS project_list
            FROM Projects
            WHERE start_date IS NOT NULL
            GROUP BY YEAR(start_date)
            ORDER BY project_start_year;
            ```
        7.  **Total hours assigned per project and number of employees on each project:**
            ```sql
            SELECT
                project_id,
                SUM(hours_assigned) AS total_hours_on_project,
                COUNT(DISTINCT emp_id) AS num_employees_on_project
            FROM EmployeeProjects
            GROUP BY project_id
            ORDER BY total_hours_on_project DESC;
            ```

*   **`HAVING` Clause**
    *   **Concept:** Filters groups created by `GROUP BY`. `WHERE` filters rows *before* grouping; `HAVING` filters groups *after* aggregate functions have been computed.
    *   **Examples:**
        1.  **Departments with more than 2 employees:**
            ```sql
            SELECT dept_id, COUNT(*) AS num_employees
            FROM Employees
            WHERE dept_id IS NOT NULL
            GROUP BY dept_id
            HAVING COUNT(*) > 1 -- Changed from 2 to 1 to get more results with current small dataset
            ORDER BY num_employees DESC;
            ```
        2.  **Job titles with an average salary greater than $70,000 AND having at least 1 employee:**
            ```sql
            SELECT job_title, AVG(salary) AS average_salary, COUNT(*) as employee_count
            FROM Employees
            GROUP BY job_title
            HAVING AVG(salary) > 70000.00 AND COUNT(*) >= 1
            ORDER BY average_salary DESC;
            ```
        3.  **Projects with total assigned hours exceeding 50 and at least 2 people assigned:**
            ```sql
            SELECT
                project_id,
                SUM(hours_assigned) AS total_project_hours,
                COUNT(DISTINCT emp_id) AS num_assigned_employees
            FROM EmployeeProjects
            GROUP BY project_id
            HAVING SUM(hours_assigned) > 40 AND COUNT(DISTINCT emp_id) >= 2;
            ```
        4.  **Locations from `Departments` table having more than one department:**
            ```sql
            SELECT location, COUNT(dept_id) as number_of_departments, GROUP_CONCAT(dept_name) as department_names
            FROM Departments
            WHERE location IS NOT NULL
            GROUP BY location
            HAVING COUNT(dept_id) > 1;
            ```

*   **`LIMIT` and `OFFSET`**
    *   **Concept:** `LIMIT` restricts the number of rows returned. `OFFSET` skips a specified number of rows before starting to return rows. Useful for pagination.
    *   **Examples:**
        1.  **Top 3 highest paid active employees:**
            ```sql
            SELECT first_name, last_name, salary, status
            FROM Employees
            WHERE status = 'Active'
            ORDER BY salary DESC
            LIMIT 3;
            ```
        2.  **Employees hired most recently (top 5):**
            ```sql
            SELECT first_name, last_name, hire_date
            FROM Employees
            ORDER BY hire_date DESC
            LIMIT 5;
            ```
        3.  **Pagination: Get employees 3 through 4 (page 2 if page size is 2):**
            ```sql
            -- Page 1: LIMIT 2 OFFSET 0 (or LIMIT 0, 2)
            -- Page 2: LIMIT 2 OFFSET 2 (or LIMIT 2, 2)
            SELECT emp_id, first_name, last_name
            FROM Employees
            ORDER BY emp_id
            LIMIT 2 OFFSET 2; -- Skip first 2, take next 2
            ```
            *Alternative syntax: `LIMIT offset, row_count`*
            ```sql
            SELECT emp_id, first_name, last_name
            FROM Employees
            ORDER BY emp_id
            LIMIT 2, 2; -- Skip 2, take 2
            ```
        4.  **Find the Nth highest salary (e.g., 2nd highest):**
            ```sql
            -- This gives the salary value
            SELECT DISTINCT salary
            FROM Employees
            ORDER BY salary DESC
            LIMIT 1 OFFSET 1; -- OFFSET 0 for 1st, 1 for 2nd, etc.

            -- To get employees with the 2nd highest salary:
            SELECT first_name, last_name, salary
            FROM Employees
            WHERE salary = (
                SELECT DISTINCT salary
                FROM Employees
                ORDER BY salary DESC
                LIMIT 1 OFFSET 1
            );
            ```
        5.  **Projects with the smallest budgets (bottom 3):**
            ```sql
            SELECT project_name, budget
            FROM Projects
            WHERE budget IS NOT NULL
            ORDER BY budget ASC
            LIMIT 3;
            ```

---

**D. TCL (Transaction Control Language)**
*Purpose: Manages transactions in the database to ensure data integrity (ACID properties: Atomicity, Consistency, Isolation, Durability).*

*   **`START TRANSACTION` or `BEGIN`**
    *   **Concept:** Marks the beginning of a database transaction. Subsequent DML statements are part of this transaction.
*   **`COMMIT`**
    *   **Concept:** Saves all changes made during the current transaction permanently to the database.
*   **`ROLLBACK`**
    *   **Concept:** Discards all changes made during the current transaction, restoring the database to its state before the transaction began.
*   **`SAVEPOINT savepoint_name`**
    *   **Concept:** Creates a point within a transaction to which you can later roll back.
*   **`ROLLBACK TO SAVEPOINT savepoint_name`**
    *   **Concept:** Rolls back the transaction to a specific savepoint, without undoing the entire transaction.

*   **Examples:**
    *(Note: By default, many SQL clients operate in "autocommit" mode, where each statement is its own transaction. You must explicitly start a transaction to group operations by using `START TRANSACTION;` or by setting `SET autocommit = 0;` for the session.)*

    1.  **Successful Transaction:**
        ```sql
        START TRANSACTION;

        -- Example: Transferring an employee to a new department and updating job title
        -- Assume Eve Davis (emp_id 5) moves from Marketing (dept_id 3) to R&D (dept_id 5)
        -- and becomes 'Research Scientist'.
        UPDATE Employees
        SET dept_id = 5, job_title = 'Research Scientist', status = 'Active'
        WHERE emp_id = 5; -- Assuming emp_id 5 is Eve

        -- Log this change (hypothetical AuditLog table)
        -- INSERT INTO AuditLog (emp_id, change_description, change_date, performed_by)
        -- VALUES (5, 'Moved to R&D as Research Scientist', NOW(), USER());

        COMMIT; -- All changes are saved
        ```
        **Explanation:** Both the `UPDATE` (and any `INSERT` for logging) are treated as a single atomic unit. If the `COMMIT` is reached, all changes are permanent. If an error occurred before `COMMIT`, nothing would be saved.

    2.  **Transaction with Rollback due to an error or condition:**
        ```sql
        START TRANSACTION;

        -- Attempt to give a large bonus to Frank Miller (emp_id 6)
        UPDATE Employees SET salary = salary + 50000 WHERE emp_id = 6;

        -- Check if the new salary exceeds a policy limit (e.g., $150,000)
        -- (Using a variable for clarity, can be done in a subquery too)
        SET @frank_new_salary = (SELECT salary FROM Employees WHERE emp_id = 6);

        IF @frank_new_salary > 150000.00 THEN
            ROLLBACK;
            SELECT 'Transaction Rolled Back: Salary for emp_id 6 exceeded policy limit.' AS status_message;
        ELSE
            -- Perhaps an additional check: ensure department budget allows this
            -- For simplicity, we commit here
            COMMIT;
            SELECT 'Transaction Committed: Salary for emp_id 6 updated.' AS status_message;
        END IF;

        -- To see the outcome:
        SELECT emp_id, first_name, salary FROM Employees WHERE emp_id = 6;
        ```
        **Explanation:** If Frank's new salary (after the attempted update within the transaction) exceeds 150,000, the `UPDATE` is undone by `ROLLBACK`. Otherwise, it's committed.

    3.  **Transaction with Savepoint:**
        ```sql
        START TRANSACTION;

        -- Action 1: Insert a new project
        INSERT INTO Projects (project_name, start_date, budget)
        VALUES ('Phoenix Initiative', CURDATE(), 60000.00);
        SET @last_project_id = LAST_INSERT_ID();
        SELECT CONCAT('New project Phoenix Initiative created with ID: ', @last_project_id) AS info;

        SAVEPOINT sp_project_created;

        -- Action 2: Assign an employee to this new project
        -- Assume emp_id 7 (Grace Wilson) is assigned
        INSERT INTO EmployeeProjects (emp_id, project_id, role_in_project, hours_assigned)
        VALUES (7, @last_project_id, 'Lead Analyst', 25);
        SELECT CONCAT('Assigned emp_id 7 to project_id ', @last_project_id) AS info;


        -- Suppose we realize Grace is actually on extended leave and cannot be assigned.
        -- We want to keep the project but remove this specific assignment.
        ROLLBACK TO SAVEPOINT sp_project_created;
        SELECT 'Rolled back to savepoint sp_project_created. Grace Wilson assignment removed.' AS info;

        -- Now we can assign someone else or do other things
        -- Action 3: Assign a different employee, emp_id 4 (David Brown)
        INSERT INTO EmployeeProjects (emp_id, project_id, role_in_project, hours_assigned)
        VALUES (4, @last_project_id, 'Senior Analyst', 30);
        SELECT CONCAT('Assigned emp_id 4 to project_id ', @last_project_id) AS info;

        COMMIT;
        SELECT 'Transaction committed. Project Phoenix created with David Brown assigned.' AS info;

        -- Verify:
        SELECT * FROM Projects WHERE project_name = 'Phoenix Initiative';
        SELECT ep.*, e.first_name, e.last_name FROM EmployeeProjects ep JOIN Employees e ON ep.emp_id = e.emp_id WHERE ep.project_id = @last_project_id;
        ```
        **Explanation:** `SAVEPOINT sp_project_created` allows us to undo only the actions performed after it (the `INSERT` into `EmployeeProjects` for Grace) while keeping the actions before it (the `INSERT` into `Projects`). Then, a new assignment is made, and the entire transaction (new project + David's assignment) is committed.

---

**E. DCL (Data Control Language)**
*Purpose: Manages access rights and permissions to the database and its objects.*

*   **`CREATE USER`** (Often a prerequisite)
    *   **Concept:** Creates a new MySQL user account.
    *   **Syntax:** `CREATE USER 'username'@'hostname' IDENTIFIED BY 'password';`
        *   `hostname`: `localhost` (local connections), `%` (any host), specific IP/hostname.
    *   **Examples:**
        ```sql
        CREATE USER 'report_viewer'@'localhost' IDENTIFIED BY 'ReportPass123!';
        CREATE USER 'app_connector'@'192.168.1.100' IDENTIFIED BY 'AppConnectP@ss!';
        CREATE USER 'generic_user'@'%' IDENTIFIED BY 'GenericP@ssword';
        ```

*   **`GRANT`**
    *   **Concept:** Gives specific privileges to a database user.
    *   **Common Privileges:** `SELECT`, `INSERT`, `UPDATE`, `DELETE`, `CREATE`, `DROP`, `ALTER`, `INDEX`, `REFERENCES`, `CREATE VIEW`, `SHOW VIEW`, `EXECUTE` (for stored procedures/functions), `ALL PRIVILEGES`.
    *   **Syntax:** `GRANT privilege_type [, privilege_type] ... ON object_type object_name TO 'user'@'host';`
    *   **Object Types:** `TABLE`, `DATABASE` (e.g., `dbname.*` for all tables in dbname), `PROCEDURE`, `FUNCTION`, `VIEW`.
    *   **Examples:**
        1.  **Grant SELECT on a specific table to a user:**
            ```sql
            GRANT SELECT ON company_db.Employees TO 'report_viewer'@'localhost';
            GRANT SELECT ON company_db.Projects TO 'report_viewer'@'localhost';
            ```
        2.  **Grant multiple DML privileges on all tables in a specific database:**
            ```sql
            GRANT SELECT, INSERT, UPDATE, DELETE ON company_db.* TO 'app_connector'@'192.168.1.100';
            ```
        3.  **Grant all privileges on a database (powerful, use with caution, typically for admin roles):**
            ```sql
            -- CREATE USER 'db_admin'@'localhost' IDENTIFIED BY 'AdminPassSecure';
            -- GRANT ALL PRIVILEGES ON company_db.* TO 'db_admin'@'localhost' WITH GRANT OPTION;
            -- 'WITH GRANT OPTION' allows this user to grant their privileges to others.
            ```
        4.  **Grant EXECUTE on a specific stored procedure:**
            ```sql
            -- Assuming a procedure 'GetEmployeeById' exists in company_db
            -- GRANT EXECUTE ON PROCEDURE company_db.GetEmployeeById TO 'app_connector'@'192.168.1.100';
            ```
        5.  **Grant usage on a database (allows connection but no specific object rights yet):**
            ```sql
            GRANT USAGE ON company_db.* TO 'generic_user'@'%';
            -- Then grant specific table/view rights:
            GRANT SELECT ON company_db.Departments TO 'generic_user'@'%';
            ```

*   **`REVOKE`**
    *   **Concept:** Removes specific privileges from a database user.
    *   **Syntax:** `REVOKE privilege_type [, privilege_type] ... ON object_type object_name FROM 'user'@'host';`
    *   **Examples:**
        1.  **Revoke INSERT privilege on Employees table from app_connector:**
            ```sql
            REVOKE INSERT ON company_db.Employees FROM 'app_connector'@'192.168.1.100';
            ```
        2.  **Revoke all privileges on a database from a user (opposite of `GRANT ALL`):**
            ```sql
            -- REVOKE ALL PRIVILEGES, GRANT OPTION FROM 'db_admin'@'localhost';
            -- Note: You revoke GRANT OPTION separately if it was granted.
            ```
        3.  **Revoke SELECT privilege from report_viewer on a specific table:**
            ```sql
            REVOKE SELECT ON company_db.Projects FROM 'report_viewer'@'localhost';
            ```
        4.  **Revoke a specific privilege while leaving others:**
            ```sql
            -- If app_connector has SELECT, INSERT, UPDATE, DELETE and we want to remove only DELETE on Projects:
            REVOKE DELETE ON company_db.Projects FROM 'app_connector'@'192.168.1.100';
            ```

*   **`SHOW GRANTS`**
    *   **Concept:** Displays the privileges granted to a user.
    *   **Syntax:** `SHOW GRANTS FOR 'user'@'host';`
    *   **Example:**
        ```sql
        SHOW GRANTS FOR 'report_viewer'@'localhost';
        SHOW GRANTS FOR 'app_connector'@'192.168.1.100';
        SHOW GRANTS FOR CURRENT_USER(); -- Shows grants for the currently logged-in user
        ```

*   **`FLUSH PRIVILEGES`**
    *   **Concept:** Reloads the grant tables from disk. This is sometimes necessary for `GRANT`/`REVOKE`/`CREATE USER` changes to take effect immediately, especially if user tables were modified directly (not recommended) or on older MySQL versions. Modern MySQL versions often handle this dynamically.
    *   **Example:**
        ```sql
        FLUSH PRIVILEGES;
        ```

*   **`DROP USER`**
    *   **Concept:** Deletes a MySQL user account.
    *   **Syntax:** `DROP USER 'username'@'hostname';`
    *   **Example:**
        ```sql
        DROP USER IF EXISTS 'generic_user'@'%';
        ```

---

**(End of Part 1: Basics of SQL with Improved Formatting)**

This covers the foundational DDL, DML, DQL, TCL, and DCL commands. I've tried to make the Markdown cleaner for better rendering.

**Self-Practice for Part 1:**

1.  Create a new table `Interns` with columns:
    *   `intern_id` (INT AUTO_INCREMENT PRIMARY KEY)
    *   `full_name` (VARCHAR(100) NOT NULL)
    *   `university` (VARCHAR(150))
    *   `program` (VARCHAR(100))
    *   `start_date` (DATE NOT NULL)
    *   `end_date` (DATE)
    *   `mentor_emp_id` (INT, FOREIGN KEY REFERENCES Employees(emp_id) ON DELETE SET NULL)
2.  Insert 3-4 intern records, ensuring some have mentors from the `Employees` table and some have `NULL` `end_date`.
3.  Update the `university` and `program` for one intern.
4.  Select all interns who are currently active (assume `end_date` is NULL or in the future).
5.  Select all interns mentored by 'Alice Smith' (you'll need her `emp_id`).
6.  Delete an intern record for an intern whose `end_date` has passed.
7.  Create a new user `intern_manager_user@localhost`. Grant this user `SELECT`, `INSERT`, `UPDATE` on the `Interns` table.
8.  Verify the grants for `intern_manager_user`. Then, revoke the `INSERT` privilege. Verify again.
9.  Use a transaction:
    *   Start a transaction.
    *   Update the `end_date` for an active intern to `CURDATE()`.
    *   Insert a new intern record.
    *   If the new intern's `start_date` is before '2023-01-01', rollback the transaction. Otherwise, commit.
    *   Check the `Interns` table to see the result.
























Now moving into **scalar functions** (also called **single-row functions**), which are **not aggregate functions** — instead, they work on **individual rows or values**, not on a group.

---

## 🔠 1. **String Functions**

These work on text (VARCHAR, CHAR, TEXT).

| Function                                      | Description                           | Example Result                     |
| --------------------------------------------- | ------------------------------------- | ---------------------------------- |
| `SUBSTRING(str, start, length)` or `SUBSTR()` | Extract part of a string              | `SUBSTRING('hello', 2, 3)` → `ell` |
| `LENGTH(str)`                                 | Number of characters/bytes in string  | 5                                  |
| `LOWER(str)`                                  | Convert to lowercase                  | `hello`                            |
| `UPPER(str)`                                  | Convert to uppercase                  | `HELLO`                            |
| `TRIM(str)`                                   | Remove spaces from both sides         | `hello`                            |
| `LTRIM(str)`                                  | Remove left-side spaces               | `hello`                            |
| `RTRIM(str)`                                  | Remove right-side spaces              | `hello`                            |
| `CONCAT(str1, str2)`                          | Join strings                          | `hello world`                      |
| `REPLACE(str, from, to)`                      | Replace part of string                | `heLLo` → `heXXo`                  |
| `INSTR(str, sub)`                             | Position of substring (1-based index) | 3                                  |
| `LEFT(str, n)`                                | First n characters                    | `he`                               |
| `RIGHT(str, n)`                               | Last n characters                     | `lo`                               |
| `REVERSE(str)`                                | Reverse the string                    | `olleh`                            |

---

## 🔢 2. **Math/Numeric Functions**

These work on numbers.

| Function                      | Description                    | Example Result             |
| ----------------------------- | ------------------------------ | -------------------------- |
| `ROUND(num, decimals)`        | Round number to given decimals | `ROUND(5.678, 2)` → `5.68` |
| `FLOOR(num)`                  | Largest integer ≤ num          | 5                          |
| `CEIL(num)` or `CEILING(num)` | Smallest integer ≥ num         | 6                          |
| `ABS(num)`                    | Absolute value                 | 5                          |
| `POWER(x, y)` or `POW()`      | x raised to the power y        | `2^3 = 8`                  |
| `MOD(x, y)` or `%`            | Modulo (remainder)             | `10 % 3 = 1`               |
| `SQRT(x)`                     | Square root                    | `√9 = 3`                   |
| `RAND()`                      | Random number between 0 and 1  | 0.5731                     |
| `SIGN(x)`                     | -1 if x<0, 0 if x=0, 1 if x>0  | 1                          |

---

## 📆 3. **Date & Time Functions**

Work with dates and times.

| Function                          | Description                 | Example Result        |
| --------------------------------- | --------------------------- | --------------------- |
| `CURDATE()`                       | Current date (YYYY-MM-DD)   | `2025-05-26`          |
| `NOW()`                           | Current date and time       | `2025-05-26 14:30:00` |
| `YEAR(date)`                      | Extract year                | 2025                  |
| `MONTH(date)`                     | Extract month               | 5                     |
| `DAY(date)`                       | Extract day                 | 26                    |
| `DATE_ADD(date, INTERVAL x UNIT)` | Add interval to date        | `+ 5 DAYS`            |
| `DATE_SUB(date, INTERVAL x UNIT)` | Subtract interval from date | `- 1 MONTH`           |
| `DATEDIFF(date1, date2)`          | Days between two dates      | 10                    |
| `STR_TO_DATE(str, format)`        | Convert string to date      | `'2024-12-25'`        |
| `DATE_FORMAT(date, format)`       | Format a date               | `'25 Dec 2024'`       |

---

## 🔄 4. **Control/Conversion Functions**

| Function              | Description                     | Example Result                 |
| --------------------- | ------------------------------- | ------------------------------ |
| `IF(condition, a, b)` | If condition true → a, else → b | `IF(1=1, 'Yes', 'No')` → `Yes` |
| `IFNULL(a, b)`        | If `a` is NULL, return `b`      | `IFNULL(NULL, 'N/A')` → `N/A`  |
| `NULLIF(a, b)`        | Returns NULL if a = b, else a   | `NULLIF(5, 5)` → `NULL`        |
| `CAST(expr AS TYPE)`  | Convert value to another type   | `CAST('5' AS INT)` → 5         |
| `CONVERT(expr, TYPE)` | Same as CAST (MySQL)            |                                |

---

## 🎯 Practical Examples

```sql
SELECT
  UPPER(name) AS uppercase_name,
  ROUND(salary / 12, 2) AS monthly_salary,
  DATE_FORMAT(join_date, '%d %b %Y') AS formatted_date
FROM employees;
```

---

## ✅ Summary Mind Map

```
String      → SUBSTRING, CONCAT, UPPER, LOWER, LENGTH
Math        → ROUND, FLOOR, CEIL, ABS, POWER, MOD
Date/Time   → NOW, CURDATE, YEAR, DATE_ADD, DATEDIFF
Conversion  → IF, IFNULL, CAST, CONVERT, NULLIF
```



---

# ✅ SQL `LIKE` Operator — Pattern Matching Guide

---

## 🔹 What is `LIKE`?

`LIKE` is used in SQL to **search for a specified pattern** in a column using **wildcards**.

---

## 🔑 Syntax:

```sql
SELECT column1, column2
FROM table_name
WHERE column_name LIKE 'pattern';
```

---

## 🎯 Main Wildcards in LIKE:

| Wildcard | Meaning                           |
| -------- | --------------------------------- |
| `%`      | **Zero, one, or many characters** |
| `_`      | **Exactly one character**         |

---

## 🧪 Examples with `%` (multi-character match):

### 1. Starts with something

```sql
SELECT * FROM employees WHERE name LIKE 'A%';
```

➡ Matches: "Alice", "Andrew", "Amit", but **not** "Sam"

---

### 2. Ends with something

```sql
SELECT * FROM employees WHERE name LIKE '%son';
```

➡ Matches: "Jackson", "Emerson", but **not** "Samuel"

---

### 3. Contains something (anywhere)

```sql
SELECT * FROM employees WHERE name LIKE '%li%';
```

➡ Matches: "Alice", "Charlie", but **not** "Ben"

---

## 🧪 Examples with `_` (single-character match):

### 1. Exactly 4 letters, starting with 'J'

```sql
SELECT * FROM employees WHERE name LIKE 'J___';
```

➡ Matches: "Jack", "John", "Jane"

---

### 2. Second letter is 'a'

```sql
SELECT * FROM employees WHERE name LIKE '_a%';
```

➡ Matches: "Sam", "Jack", "Max", but not "Ben"

---

## 📌 Combining `%` and `_`:

```sql
SELECT * FROM books WHERE title LIKE '_at%';
```

➡ Matches: "Cat", "Rate", "Batch", etc. (must have 'a' as 2nd and 't' as 3rd letter)

---

## ⚠ Case Sensitivity

* **MySQL**: Case-insensitive by default (unless using binary collation).
* **PostgreSQL**: Case-sensitive by default.
* Use `ILIKE` in PostgreSQL for case-insensitive search.

---

## 🔄 Opposite of `LIKE`: Use `NOT LIKE`

```sql
SELECT * FROM users WHERE username NOT LIKE 'admin%';
```

---

## 🧱 Escape Special Characters (`%`, `_`)

To match a literal `%` or `_`, use `ESCAPE`:

```sql
SELECT * FROM files WHERE name LIKE '%\%%' ESCAPE '\';
```

---

## 📋 Practical Use Cases

| Use Case                                   | Example                          |
| ------------------------------------------ | -------------------------------- |
| Search all emails ending with `@gmail.com` | `WHERE email LIKE '%@gmail.com'` |
| Find names with 'an' in them               | `WHERE name LIKE '%an%'`         |
| Names starting with capital 'A'            | `WHERE name LIKE 'A%'`           |
| 5-letter usernames                         | `WHERE username LIKE '_____'`    |

---

## 🧠 Tips to Master LIKE

* `%` is greedy: it matches **any number of characters**, including zero.
* `_` is precise: it matches **one and only one character**.
* Combine both for complex patterns.
* Use `ESCAPE` when searching for wildcards as **literal characters**.
* Use `LOWER()` or `UPPER()` for consistent case-insensitive searches in SQL engines that are case-sensitive:

```sql
WHERE LOWER(name) LIKE 'a%'
```

---

## 🧾 Summary Table:

| Pattern  | Matches                         |
| -------- | ------------------------------- |
| `'A%'`   | Strings starting with "A"       |
| `'%son'` | Strings ending with "son"       |
| `'%in%'` | Strings containing "in"         |
| `'____'` | Any 4-character string          |
| `'B_o%'` | Strings where 2nd letter is 'o' |

---

# ✅ `DECIMAL(12,2)` — Full Explanation

This is a **fixed-point numeric data type** used in SQL to **store exact numeric values**, especially for **money, financial, or budget-related fields**.

---

## 🔢 Syntax:

```sql
DECIMAL(precision, scale)
```

* `precision` → Total number of **digits** (before + after the decimal point).
* `scale` → Number of **digits after the decimal point** (i.e., decimal places).

---

## 🧠 So, `DECIMAL(12,2)` means:

| Component | Value     | Meaning                                                         |
| --------- | --------- | --------------------------------------------------------------- |
| `12`      | Precision | Total of **12 digits**, including digits before & after decimal |
| `2`       | Scale     | **2 digits after** the decimal point                            |

### ➕ That means:

* **Up to 10 digits before** the decimal (because 12 - 2 = 10)
* **Exactly 2 digits after** the decimal

---

## 🔍 Examples of valid values for `DECIMAL(12,2)`:

| Value             | Valid? | Why?                                    |
| ----------------- | ------ | --------------------------------------- |
| `1234567890.12`   | ✅      | 10 digits before + 2 after = 12 total   |
| `0.01`            | ✅      | 0 before, 2 after = OK                  |
| `100000000000.00` | ❌      | 12 digits before decimal = too big      |
| `123.456`         | ❌      | 3 digits after decimal — violates scale |

---

## 💡 Why use `DECIMAL(12,2)` instead of FLOAT or DOUBLE?

| Feature  | DECIMAL                   | FLOAT/DOUBLE             |
| -------- | ------------------------- | ------------------------ |
| Accuracy | Exact (perfect for money) | Approximate (may round)  |
| Storage  | Uses more space           | More compact             |
| Use Case | Money, Prices, Budgets    | Scientific calcs, Speed  |
| Example  | Budget, salary            | Temperature, coordinates |

---

## 📦 Storage Info (MySQL Example)

* The storage required for `DECIMAL` depends on the precision.
* MySQL uses roughly:

  * 4 bytes for every 9 digits.
  * So `DECIMAL(12,2)` = needs \~5–6 bytes.

(You don’t need to worry about this in most cases unless optimizing performance.)

---

## 🔐 Constraints with `DECIMAL(12,2)`:

* If you insert a value **with more than 2 decimal places**, it will round or throw error based on the SQL engine.

  ```sql
  INSERT INTO budgets (amount) VALUES (123.456);  -- becomes 123.46
  ```
* Values outside of allowed range (more than 10 digits before decimal) will raise errors.

---

## 🧾 Practical Examples:

```sql
CREATE TABLE budgets (
    id INT AUTO_INCREMENT PRIMARY KEY,
    department VARCHAR(100),
    budget DECIMAL(12,2)
);
```

### ➕ Sample inserts:

```sql
INSERT INTO budgets (department, budget) VALUES ('HR', 1200000.50);
INSERT INTO budgets (department, budget) VALUES ('IT', 9876543210.99); -- valid
```

---

## 🧠 Remember:

> `DECIMAL(12,2)` = Max 9999999999.99

Because:

* Max 10 digits before decimal → `9999999999`
* Exactly 2 digits after decimal → `.99`

---



### The SQL column definition flow.

---



### 🔤 Flow :

```
column_name 
→ data_type (e.g., INT, VARCHAR(n), ENUM(...)) 
→ AUTO_INCREMENT (only for integers) 
→ PRIMARY KEY (if applicable) 
→ NOT NULL 
→ UNIQUE 
→ DEFAULT value 
→ CHECK (optional) 
→ REFERENCES (if foreign key)
```

---



### 🧠 Mnemonic update (with ENUM included):

> "**C**ats **D**rink **A**pple **P**ie **N**ightly, **U**nless **D**ogs **C**rash **R**oofs"

* **C** = Column Name
* **D** = Data Type (`INT`, `VARCHAR`, `ENUM`, etc.)
* **A** = AUTO\_INCREMENT
* **P** = PRIMARY KEY
* **N** = NOT NULL
* **U** = UNIQUE
* **D** = DEFAULT
* **C** = CHECK
* **R** = REFERENCES

---
