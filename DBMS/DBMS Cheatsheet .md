

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
