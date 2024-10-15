

# 📚 Comprehensive DBMS Cheatsheet with Analogies

## 🌐 Types of Databases
### 1. **Relational Databases (RDBMS)**
   - **Definition**: In relational databases, data is stored in tables, where each table has rows and columns. Each row represents a record, and each column represents an attribute of the data.
   - **Examples**: `MySQL`, `PostgreSQL`, `SQL Server`.
   - **Analogy**: Imagine you’re keeping records of books in a library. Each book has a record (row) in a table, and each detail of the book (title, author, ISBN) is stored in columns.
   - **Key Terms**:
     - **Table**: A collection of related data (e.g., `books`, `authors`).
     - **Row (Tuple)**: A single record (like a book entry in the `books` table).
     - **Column (Attribute)**: A specific field for each record (e.g., `title`, `author`, `ISBN`).
     - **Primary Key**: A unique identifier for each row (e.g., a book's `ISBN` number).
     - **Foreign Key**: A link between rows in different tables (e.g., `author_id` in `books` linking to the `authors` table).

### 2. **NoSQL Databases**
   - **Definition**: NoSQL databases store data in formats other than traditional rows and columns. They're designed for flexibility and scalability, handling large amounts of unstructured data.
   - **Types**:
     - **Document-based** (`MongoDB`): Stores data in flexible, JSON-like documents.
     - **Key-Value Stores** (`Redis`): Data stored as key-value pairs (like a dictionary).
     - **Column Family Stores** (`Cassandra`): Data stored in column families, designed for large-scale queries.
     - **Graph Databases** (`Neo4j`): Data is stored as nodes and edges, useful for social networks or relationship-driven data.
   - **Analogy**: Think of NoSQL as a collection of flexible filing cabinets. Each cabinet (collection) can hold papers (documents) of different formats. You can easily add or remove fields (data) without affecting the other papers.
   - **Examples**: `MongoDB`, `Cassandra`, `Redis`.

---

## 🌟 Key Concepts & Terms (Across Databases)

### 1. **Schema** – *The Blueprint of Data Structure*
   - **MySQL (RDBMS)**: A schema is a predefined structure that defines what tables exist in the database and what fields (columns) each table has. You must follow the schema strictly when adding data (e.g., all books must have a title, author, and ISBN).
     - **Analogy**: A schema in MySQL is like a rigid blueprint for building a house. You cannot suddenly decide to add a room without planning it beforehand.
     - **Example**:
       ```sql
       CREATE TABLE books (
           id INT AUTO_INCREMENT,
           title VARCHAR(255),
           author VARCHAR(255),
           isbn VARCHAR(13),
           PRIMARY KEY (id)
       );
       ```

   - **MongoDB (NoSQL)**: No predefined schema exists. Each document in a collection can have a different structure. You can add fields on the fly.
     - **Analogy**: MongoDB’s schema-less structure is like a flexible scrapbook where each page (document) can have different information. One page might have pictures and notes, another might have only text, and that’s okay.
     - **Example**:
       ```json
       {
         "title": "The Great Gatsby",
         "author": "F. Scott Fitzgerald",
         "isbn": "1234567890123"
       }
       // Another document might look like this:
       {
         "name": "To Kill a Mockingbird",
         "author": "Harper Lee",
         "publishedYear": 1960
       }
       ```

   - **Mongoose (ODM for MongoDB)**: In Mongoose, you can define schemas to impose some structure on MongoDB documents.
     - **Analogy**: Mongoose is like providing a loose guide or template when writing a story. You still have freedom, but certain elements are expected.
     - **Example**:
       ```javascript
       const bookSchema = new mongoose.Schema({
         title: String,
         author: String,
         isbn: String
       });

       const Book = mongoose.model('Book', bookSchema);
       ```

### 2. **Collections vs. Tables** – *The Container for Data*

   - **Table (MySQL/PostgreSQL)**: A structured, predefined set of rows and columns. Each row follows the same format, enforced by the schema.
     - **Analogy**: A table is like a spreadsheet. Each row is a new record (like a person), and each column is a detail about that person (name, age, etc.).
     - **Example**:
       ```sql
       SELECT * FROM users;
       ```

   - **Collection (MongoDB)**: A collection is a group of documents. Each document can have a different structure.
     - **Analogy**: A collection is like a folder with flexible sheets. Each sheet might have different content, but they're all part of the same folder.
     - **Example**:
       ```javascript
       db.books.find(); // Retrieves all documents (books) in the collection
       ```

### 3. **Row vs. Document** – *The Actual Data Entry*

   - **Row (MySQL/PostgreSQL)**: A single record in a table.
     - **Analogy**: A row is like a single entry in an address book where each field (column) is a detail about that entry (name, address, phone number).
     - **Example**:
       ```sql
       INSERT INTO users (name, email) VALUES ('Alice', 'alice@example.com');
       ```

   - **Document (MongoDB)**: A document is a JSON-like object stored in a collection.
     - **Analogy**: A document is like a page in a journal. It has its own structure and can have different content from other pages.
     - **Example**:
       ```json
       {
         "name": "Alice",
         "email": "alice@example.com",
         "age": 30
       }
       ```

### 4. **Primary Key & Foreign Key** – *Unique Identifiers and Links Between Data*

   - **Primary Key (RDBMS)**: A unique identifier for each row in a table (e.g., `id` in `users` table). No two rows can have the same primary key.
     - **Analogy**: The primary key is like a social security number. It's unique to each person.
     - **Example**:
       ```sql
       CREATE TABLE users (
           id INT PRIMARY KEY,
           name VARCHAR(100)
       );
       ```

   - **Foreign Key (RDBMS)**: A key that links one table to another, creating a relationship between the two.
     - **Analogy**: A foreign key is like a reference in a bibliography linking to another document.
     - **Example**:
       ```sql
       CREATE TABLE orders (
           id INT PRIMARY KEY,
           user_id INT,
           FOREIGN KEY (user_id) REFERENCES users(id)
       );
       ```

   - **MongoDB**: MongoDB doesn't have foreign keys by default. Instead, you reference documents using their `_id` field.
     - **Example**:
       ```json
       {
         "name": "Alice",
         "orders": [
           { "order_id": 1, "total": 100 },
           { "order_id": 2, "total": 200 }
         ]
       }
       ```

### 5. **Indexes** – *Speeding Up Data Retrieval*

   - **MySQL**: Indexes are used to speed up queries by creating an ordered list of key fields.
     - **Analogy**: An index in a book helps you quickly find the page number for a specific topic.
     - **Example**:
       ```sql
       CREATE INDEX idx_name ON users(name);
       ```

   - **MongoDB**: Indexes work similarly by creating an ordered list of document fields for faster search.
     - **Example**:
       ```javascript
       db.users.createIndex({ name: 1 }); // 1 for ascending order
       ```

---

## 🚀 Working with SQL Databases (MySQL, PostgreSQL)

### 1. **SQL (Structured Query Language)** – *Talking to Relational Databases*
   - **Definition**: SQL is the language used to interact with relational databases. You use SQL to query, insert, update, and delete data.
   - **Example**:
     ```sql
     SELECT * FROM users WHERE age > 30;
     ```

### 2. **Joins** – *Connecting Data Across Tables*
   - **Purpose**: To combine data from two or more tables using relationships (primary key/foreign key).
   - **Types**:
     - **INNER JOIN**: Returns only matching rows from both tables.
     - **LEFT JOIN**: Returns all rows from the left table and matching rows from the right table.
   - **Analogy**: Joining tables is like connecting the dots between two related lists. 
   - **Example**:
     ```sql
     SELECT users.name, orders.total
     FROM users
     INNER JOIN orders ON users.id = orders.user_id;
     ```



---

## 🚀 Working with NoSQL Databases (MongoDB)

### 1. **CRUD Operations** – *Basic Operations in MongoDB*
   - **Create**: Insert a new document.
     ```javascript
     db.users.insert({ name: "Alice", age: 30 });
     ```
   - **Read**: Find documents.
     ```javascript
     db.users.find({ age: { $gt: 25 } });
     ```
   - **Update**: Update existing documents.
     ```javascript
     db.users.update({ name: "Alice" }, { $set: { age: 31 } });
     ```
   - **Delete**: Remove documents.
     ```javascript
     db.users.remove({ name: "Alice" });
     ```

### 2. **Aggregation** – *Processing Data in MongoDB*
   - **Purpose**: To perform operations like counting, summing, and averaging over documents.
   - **Example**:
     ```javascript
     db.orders.aggregate([
       { $match: { status: "shipped" } },
       { $group: { _id: "$user_id", total: { $sum: "$total" } } }
     ]);
     ```

---

## 🎨 Diagram of Database Relationships

```plaintext
+----------------+            +----------------+
|     Users      |            |     Orders     |
+----------------+            +----------------+
| id (PK)        |            | id (PK)        |
| name           |            | user_id (FK)   |
| email          |            | total          |
+----------------+            +----------------+
          |                           |
          +---------------------------+
                      JOIN
```

---

## Conclusion

- **RDBMS (MySQL/PostgreSQL)** is best when data structure is well-defined and relationships are important.
- **NoSQL (MongoDB)** is ideal for flexible, large-scale, schema-less data storage, especially when handling unstructured data.

---

# 🚀 DBMS Query Cheatsheet

## 📝 SQL Queries (MySQL/PostgreSQL)

### 1. **Basic Queries**

#### Select All Rows from a Table
```sql
SELECT * FROM users;
/* Selects all columns and rows from the 'users' table */
```

#### Select Specific Columns from a Table
```sql
SELECT name, email FROM users;
/* Selects only the 'name' and 'email' columns from the 'users' table */
```

#### Insert a New Row into a Table
```sql
INSERT INTO users (name, email, age) 
VALUES ('Alice', 'alice@example.com', 30);
/* Inserts a new user 'Alice' with email and age into the 'users' table */
```

#### Update a Record in a Table
```sql
UPDATE users 
SET age = 31 
WHERE name = 'Alice';
/* Updates 'Alice's age to 31 in the 'users' table where name matches */
```

#### Delete a Record from a Table
```sql
DELETE FROM users 
WHERE name = 'Alice';
/* Deletes the record where 'name' is 'Alice' */
```

---

### 2. **Conditions & Filtering**

#### Select Rows with a Condition (WHERE Clause)
```sql
SELECT * FROM users 
WHERE age > 25;
/* Selects all users where the age is greater than 25 */
```

#### Multiple Conditions (AND, OR)
```sql
SELECT * FROM users 
WHERE age > 25 AND city = 'New York';
/* Selects users where age is greater than 25 and city is 'New York' */

SELECT * FROM users 
WHERE age > 25 OR city = 'New York';
/* Selects users where age is greater than 25 or city is 'New York' */
```

#### Sorting Results (ORDER BY)
```sql
SELECT * FROM users 
ORDER BY age DESC;
/* Selects all users and sorts them by 'age' in descending order */
```

#### Limiting the Number of Results (LIMIT)
```sql
SELECT * FROM users 
LIMIT 10;
/* Selects only the first 10 rows from the 'users' table */
```

---

### 3. **Aggregate Functions**

#### Count the Number of Records
```sql
SELECT COUNT(*) FROM users;
/* Returns the total number of rows in the 'users' table */
```

#### Get the Average of a Column
```sql
SELECT AVG(age) FROM users;
/* Returns the average age of all users */
```

#### Sum Values in a Column
```sql
SELECT SUM(salary) FROM employees;
/* Returns the sum of all salaries in the 'employees' table */
```

#### Group By a Column (GROUP BY)
```sql
SELECT city, COUNT(*) FROM users 
GROUP BY city;
/* Groups users by their 'city' and counts how many users live in each city */
```

#### Having Clause (Filter Groups)
```sql
SELECT city, COUNT(*) FROM users 
GROUP BY city 
HAVING COUNT(*) > 10;
/* Returns only those cities where more than 10 users live */
```

---

### 4. **Joins (Combining Data)**

#### Inner Join (Return Only Matching Rows)
```sql
SELECT users.name, orders.total 
FROM users
INNER JOIN orders ON users.id = orders.user_id;
/* Joins the 'users' and 'orders' tables and returns names and order totals where a match exists */
```

#### Left Join (Return All Rows from the Left Table)
```sql
SELECT users.name, orders.total 
FROM users
LEFT JOIN orders ON users.id = orders.user_id;
/* Returns all users and their order totals, even if they haven't placed any orders (null in 'orders') */
```

#### Right Join (Return All Rows from the Right Table)
```sql
SELECT users.name, orders.total 
FROM users
RIGHT JOIN orders ON users.id = orders.user_id;
/* Returns all orders, even if no matching user is found (null in 'users') */
```

---

### 5. **Subqueries**

#### Subquery in WHERE Clause
```sql
SELECT name FROM users 
WHERE id IN (SELECT user_id FROM orders WHERE total > 100);
/* Selects users who have placed orders with a total greater than 100 */
```

#### Subquery as a Column
```sql
SELECT name, (SELECT COUNT(*) FROM orders WHERE orders.user_id = users.id) AS order_count 
FROM users;
/* Selects users and the number of orders they've placed using a subquery */
```

---

### 6. **Advanced Queries**

#### Case Statement (Conditional Logic)
```sql
SELECT name, 
CASE 
    WHEN age < 18 THEN 'Minor' 
    WHEN age >= 18 AND age <= 65 THEN 'Adult' 
    ELSE 'Senior'
END AS age_group
FROM users;
/* Categorizes users into 'Minor', 'Adult', and 'Senior' based on their age */
```

#### Union (Combine Results from Two Queries)
```sql
SELECT name FROM users 
UNION 
SELECT name FROM customers;
/* Combines names from 'users' and 'customers' without duplicates */
```

#### Full-Text Search (MATCH AGAINST)
```sql
SELECT * FROM articles 
WHERE MATCH (title, body) AGAINST ('database' IN NATURAL LANGUAGE MODE);
/* Searches for the word 'database' in the 'title' and 'body' columns of the 'articles' table */
```

---

## 📝 NoSQL Queries (MongoDB)

### 1. **Basic Queries**

#### Find All Documents in a Collection
```javascript
db.users.find();
/* Returns all documents in the 'users' collection */
```

#### Find Specific Fields
```javascript
db.users.find({}, { name: 1, email: 1 });
/* Returns only the 'name' and 'email' fields for all users */
```

#### Insert a Document
```javascript
db.users.insert({ name: "Alice", email: "alice@example.com", age: 30 });
/* Inserts a new document for 'Alice' into the 'users' collection */
```

#### Update a Document
```javascript
db.users.update({ name: "Alice" }, { $set: { age: 31 } });
/* Updates 'Alice's age to 31 in the 'users' collection */
```

#### Delete a Document
```javascript
db.users.remove({ name: "Alice" });
/* Deletes the document where 'name' is 'Alice' */
```

---

### 2. **Query with Conditions**

#### Find Documents with a Condition
```javascript
db.users.find({ age: { $gt: 25 } });
/* Returns users where the age is greater than 25 */
```

#### Multiple Conditions (AND, OR)
```javascript
db.users.find({ age: { $gt: 25 }, city: "New York" });
/* Returns users where the age is greater than 25 and city is 'New York' */

db.users.find({ $or: [ { age: { $gt: 25 } }, { city: "New York" } ] });
/* Returns users where age is greater than 25 or city is 'New York' */
```

#### Sorting Results
```javascript
db.users.find().sort({ age: -1 });
/* Sorts the documents by 'age' in descending order */
```

#### Limiting Results
```javascript
db.users.find().limit(10);
/* Limits the result to 10 documents */
```

---

### 3. **Aggregations (Data Processing)**

#### Group by a Field and Count
```javascript
db.users.aggregate([
  { $group: { _id: "$city", count: { $sum: 1 } } }
]);
/* Groups users by 'city' and counts how many users live in each city */
```

#### Match, Group, and Sort
```javascript
db.orders.aggregate([
  { $match: { status: "shipped" } },
  { $group: { _id: "$user_id", total: { $sum: "$total" } } },
  { $sort: { total: -1 } }
]);
/* Filters orders by 'shipped' status, groups by 'user_id', sums the totals, and sorts by total amount in descending order */
```

---

### 4. **Indexes**

#### Create an Index
```javascript
db.users.createIndex({ name: 1 });
/* Creates an index on the 'name' field in ascending order */
```

#### Use Index in Query
```javascript
db.users.find({ name: "Alice" }).hint({ name: 1 });
/* Forces the query to use the index on the 'name' field */
```

---

## 🚀 Bonus: Complex SQL Queries

### 1. **Recursive Query (CTE - Common Table Expression)**
```sql
WITH RECURSIVE employee_hierarchy AS (
    SELECT id, name, manager_id
    FROM employees
    WHERE manager_id IS NULL
    UNION
    SELECT e.id, e.name, e.manager_id
    FROM employees e
    INNER JOIN employee_hierarchy eh ON e.manager_id = eh.id
)
SELECT * FROM employee_hierarchy;
/* This query retrieves the entire employee hierarchy from the 'employees' table, starting with top-level managers */
```

### 2. **Window Functions**
```sql
SELECT name, salary, 
RANK()

 OVER (ORDER BY salary DESC) AS salary_rank
FROM employees;
/* Uses a window function to rank employees based on their salary */
```

---

### 11. Normalization
- **Definition:** Normalization is the process of organizing data in a database to reduce redundancy and improve data integrity.
- **Purpose:** It ensures that each piece of data is stored only once, minimizing the chances of data anomalies and inconsistencies.
- **Forms of Normalization:**
  - **First Normal Form (1NF):** 
    - **Criteria:** Eliminate duplicate columns from the same table.
    - **Example:** Consider a table with student information:
      ```plaintext
      | StudentID | Name    | Courses          |
      |-----------|---------|-------------------|
      | 1         | Alice   | Math, Science     |
      | 2         | Bob     | Science, History   |
      ```
      - **Normalization to 1NF:** Split the Courses into separate rows.
      ```plaintext
      | StudentID | Name  | Course   |
      |-----------|-------|----------|
      | 1         | Alice | Math     |
      | 1         | Alice | Science  |
      | 2         | Bob   | Science  |
      | 2         | Bob   | History  |
      ```
  - **Second Normal Form (2NF):** 
    - **Criteria:** Remove subsets of data that apply to multiple rows and place them in separate tables.
    - **Example:** Continuing with the 1NF example:
      ```plaintext
      | StudentID | Course   | Instructor  |
      |-----------|----------|-------------|
      | 1         | Math     | Dr. Smith   |
      | 1         | Science  | Dr. Johnson |
      | 2         | Science  | Dr. Johnson |
      | 2         | History  | Dr. Brown   |
      ```
      - **Normalization to 2NF:** Create a separate table for Instructors.
      ```plaintext
      | Course   | Instructor  |
      |----------|-------------|
      | Math     | Dr. Smith   |
      | Science  | Dr. Johnson |
      | History  | Dr. Brown   |
      ```
  - **Third Normal Form (3NF):** 
    - **Criteria:** Remove columns that are not dependent on the primary key.
    - **Example:** If the Instructor's department is added to the previous Instructor table:
      ```plaintext
      | Course   | Instructor  | Department  |
      |----------|-------------|-------------|
      | Math     | Dr. Smith   | Math Dept.  |
      | Science  | Dr. Johnson | Science Dept. |
      ```
      - **Normalization to 3NF:** Create a separate table for Departments.
      ```plaintext
      | Instructor  | Department    |
      |-------------|---------------|
      | Dr. Smith   | Math Dept.    |
      | Dr. Johnson | Science Dept. |
      ```

### 12. Denormalization
- **Definition:** Denormalization is the process of combining tables to improve read performance by reducing the number of joins needed in queries.
- **Purpose:** While normalization reduces redundancy, denormalization improves performance for read-heavy applications.
- **Use Cases:** Useful in reporting databases, data warehouses, or when the application requires frequent read operations over complex joins.
- **Example:**
  - **Before Denormalization:**
    ```plaintext
    | OrderID | CustomerID | ProductID | Quantity |
    |---------|------------|-----------|----------|
    | 1       | 101        | 501       | 2        |
    | 1       | 101        | 502       | 1        |
    ```
  - **After Denormalization:**
    - Combine relevant data into a single table to avoid joins.
    ```plaintext
    | OrderID | CustomerName | ProductNames             | TotalQuantity |
    |---------|--------------|--------------------------|---------------|
    | 1       | Alice        | "Product A, Product B"   | 3             |
    ```

### 13. Transactions
- **Definition:** A transaction is a sequence of operations performed as a single logical unit of work, ensuring data integrity.
- **Properties (ACID):**
  - **Atomicity:** All operations in a transaction are completed; if one fails, the whole transaction fails.
  - **Consistency:** The database must remain in a consistent state before and after the transaction.
  - **Isolation:** Transactions must not interfere with each other.
  - **Durability:** Once a transaction is committed, it will remain so, even in the event of a system failure.
- **Example:**
  - **Bank Transfer Scenario:**
    ```sql
    START TRANSACTION;

    UPDATE Accounts SET balance = balance - 100 WHERE account_id = 1;  -- Deduct from Account 1
    UPDATE Accounts SET balance = balance + 100 WHERE account_id = 2;  -- Add to Account 2

    COMMIT;  -- If both operations succeed, commit the transaction.
    ```
  - If the first update fails, the second will not execute, ensuring atomicity.

### 14. Indexing
- **Definition:** Indexing is a data structure that improves the speed of data retrieval operations on a database table at the cost of additional space.
- **Types of Indexes:**
  - **Unique Index:** Ensures that all values in the index are different.
    ```sql
    CREATE UNIQUE INDEX idx_email ON Users(email);
    ```
  - **Composite Index:** An index on multiple columns, useful for queries that filter by more than one column.
    ```sql
    CREATE INDEX idx_order_customer ON Orders(CustomerID, OrderDate);
    ```
  - **Full-Text Index:** Designed for searching text in large columns, enabling efficient searching of text data.
    ```sql
    CREATE FULLTEXT INDEX idx_description ON Products(description);
    ```
- **Analogy:** Think of indexes as a table of contents in a book that helps you quickly locate specific information.
- **Example:** 
  - Without an index, querying customers by name could require a full table scan.
    ```sql
    SELECT * FROM Customers WHERE Name = 'Alice';
    ```
  - With an index, this query can be executed much faster.

### 15. Sharding
- **Definition:** Sharding is a method of distributing data across multiple servers or databases to improve performance and scalability.
- **Purpose:** Allows queries to be processed in parallel across multiple machines, reducing the load on any single server.
- **Use Case:** Large applications with high write and read throughput, such as social networks or large e-commerce platforms.
- **Example:**
  - If an e-commerce application has millions of users, sharding could distribute users across different databases based on geographical location.
  ```plaintext
  | Shard1: US Users      | Shard2: EU Users     | Shard3: ASIA Users   |
  |-----------------------|----------------------|-----------------------|
  | User1 (US)           | User4 (EU)          | User7 (Asia)         |
  | User2 (US)           | User5 (EU)          | User8 (Asia)         |
  ```

### 16. SQL Functions
- **User-Defined Functions (UDFs):**
  - **Definition:** Custom functions created by users to encapsulate complex queries or calculations, enabling code reuse.
  - **Example:**
    ```sql
    CREATE FUNCTION CalculateTax(subtotal DECIMAL)
    RETURNS DECIMAL
    BEGIN
      RETURN subtotal * 0.1;  -- Returns 10% tax
    END;
    ```
- **Window Functions:**
  - **Definition:** Functions that perform calculations across a set of table rows that are related to the current row.
  - **Example:**
    ```sql
    SELECT 
      EmployeeID, 
      Salary, 
      AVG(Salary) OVER (PARTITION BY Department) AS AvgSalary
    FROM Employees;
    ```
- **Analogy:** Functions are like reusable recipes in cooking; you can use them multiple times without starting from scratch.

### 17. Query Optimization
- **Definition:** The process of making your SQL queries run faster and more efficiently.
- **Strategies:**
  - **Use of Indexes:** To speed up data retrieval.
  - **Avoiding SELECT *:** Only select the columns you need to minimize data transfer.
    ```sql
    SELECT Name, Email FROM Users;  -- More efficient than SELECT *
    ```
  - **Limiting Rows:** Using LIMIT and WHERE clauses to reduce the number of rows processed.
    ```sql
    SELECT * FROM Orders WHERE OrderDate > '2024-01-01' LIMIT 100;
    ```
- **Analogy:** Optimizing queries is like packing your suitcase efficiently; you want to carry what you need without wasting space.

### 18. Common SQL Functions
- **String Functions:** 
  - **CONCAT:** Joins two or more strings together.
    ```sql
    SELECT CONCAT(FirstName, ' ', LastName) AS FullName FROM Users;
    ```
  - **SUBSTRING:** Extracts a portion of a string.
    ```sql
    SELECT SUBSTRING(Description, 1, 100) FROM Products;  -- First 100 characters
    ```
  - **LENGTH:** Returns the length of a string.
    ```sql
    SELECT LENGTH(Description) FROM Products;
    ```
- **Date Functions:**
  - **NOW():** Returns the current date and time.
    ```sql
    SELECT NOW();  -- Current timestamp
    ```
  - **DATEDIFF():** Calculates the difference between two

 dates.
    ```sql
    SELECT DATEDIFF('2024-10-15', '2024-01-01');  -- Days between two dates
    ```
  - **DATE_FORMAT():** Formats a date based on a specified format.
    ```sql
    SELECT DATE_FORMAT(OrderDate, '%Y-%m-%d') FROM Orders;
    ```
- **Mathematical Functions:**
  - **ROUND():** Rounds a number to the nearest integer.
    ```sql
    SELECT ROUND(Price, 2) FROM Products;  -- Round to 2 decimal places
    ```
  - **FLOOR():** Returns the largest integer value less than or equal to the given number.
    ```sql
    SELECT FLOOR(Price) FROM Products;
    ```
  - **CEIL():** Returns the smallest integer value greater than or equal to the given number.
    ```sql
    SELECT CEIL(Price) FROM Products;
    ```
- **Analogy:** SQL functions are like tools in a toolbox; each serves a specific purpose to help you accomplish your task.

---

## Database Selection Guide

When deciding which database technology to use, consider the following scenarios:

| Database    | Use Case                                             | Why Choose It?                                                                                            | Example Use Cases                                                |
|-------------|-----------------------------------------------------|----------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------|
| **MySQL**   | Traditional applications, web apps                  | ACID compliance, rich ecosystem, mature technology.                                                      | E-commerce, blogging platforms, content management systems.     |
| **PostgreSQL** | Complex queries, analytical workloads                | Advanced features (JSONB, full-text search), strong consistency.                                        | Data analytics, GIS applications, financial applications.       |
| **MongoDB** | Schema-less data, high write load                    | Flexible schema, horizontal scalability, high availability.                                              | Real-time analytics, content management systems, IoT applications.|
| **Mongoose** | Schema-based MongoDB interactions                     | Simplifies MongoDB interactions with schema validation and middleware.                                   | Node.js applications using MongoDB.                            |
| **Redis**   | Caching, real-time analytics                          | Extremely fast, in-memory data store, supports various data structures.                                 | Session management, real-time analytics, leaderboard systems.    |
| **Cassandra**| High write throughput, distributed systems            | Excellent scalability, high availability, and fault tolerance.                                           | Large-scale applications, IoT data storage, messaging systems.  |
| **Neo4j**   | Graph-based data                                     | Highly optimized for graph queries, natural representation of interconnected data.                       | Social networks, recommendation engines, fraud detection.       |

### Choosing the Right Database:
1. **Use MySQL** when you need a relational database with strong consistency and ACID compliance for traditional applications.
2. **Use PostgreSQL** when dealing with complex queries and analytical workloads that require advanced features.
3. **Use MongoDB** when you need a flexible schema for rapidly changing data and high write throughput.
4. **Use Mongoose** in Node.js applications for easier interaction with MongoDB and data validation.
5. **Use Redis** for caching and real-time data processing to improve application performance.
6. **Use Cassandra** when you need high availability and scalability for applications with massive write loads.
7. **Use Neo4j** for applications that heavily rely on relationships between entities, such as social networks or recommendation systems.

---
