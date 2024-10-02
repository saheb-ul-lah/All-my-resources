---

# Magical Universal PHP Form Template

## Introduction

Welcome to the **Magical Universal PHP Form Template**! This project provides a comprehensive, beginner-friendly template to handle any kind of form submission in PHP. It supports various form elements including text inputs, file uploads, checkboxes, radio buttons, dropdowns, and much more.

The template also handles reserved SQL keywords, file uploads, and database operations while ensuring security through parameterized queries.

## Features

- **Universal Form Handling**: Accepts any form field type, from text inputs to file uploads and complex form structures.
- **File Upload Support**: Handles different file types such as images, PDFs, and more, storing their paths in the database.
- **Dynamic Field Handling**: Automatically adjusts to any number of form fields, making the template flexible.
- **Security**: SQL injection protection via prepared statements.
- **Easy to Extend**: Add new form fields or modify existing ones with ease.

---

## Table of Contents

1. [Folder Structure](#folder-structure)
2. [Requirements](#requirements)
3. [Installation](#installation)
4. [Database Setup](#database-setup)
5. [Files Overview](#files-overview)
6. [How It Works](#how-it-works)
7. [Extending the Template](#extending-the-template)
8. [FAQ](#faq)

---

## Folder Structure

```
|-- project_root/
    |-- uploads/
        |-- pdfs/
        |-- images/
        |-- other_files/
    |-- db_connect.php
    |-- process_form.php
    |-- submit_form.php
    |-- index.html (or your form file)
    |-- README.md
```

- `uploads/`: Directory where uploaded files are stored, categorized by type.
- `db_connect.php`: Handles the database connection.
- `process_form.php`: Processes the form data, including file uploads and saving form submissions to the database.
- `submit_form.php`: A script that handles form submissions.
- `index.html`: Your form's HTML structure.

---

## Requirements

- **XAMPP / WAMP**: For local PHP and MySQL environment.
- **PHP 7.4+**: Ensure your PHP version supports `mysqli`.
- **MySQL 5.7+**: For database storage.

---

## Installation

1. **Clone or Download** the repository.
2. Place the project folder in your local server directory (`htdocs` for XAMPP).
3. Ensure **file upload directories** (`uploads/pdfs`, `uploads/images`, `uploads/other_files`) are writable.

---

## Database Setup

1. **Create Database**: Open `phpMyAdmin` or any SQL client and run the following SQL commands:

   ```sql
   CREATE DATABASE form_template;
   USE form_template;

   CREATE TABLE form_submissions (
     id INT AUTO_INCREMENT PRIMARY KEY,
     text VARCHAR(255) NOT NULL,
     password VARCHAR(255) NOT NULL,
     email VARCHAR(255) NOT NULL,
     url VARCHAR(255),
     number INT,
     `range` INT, -- Use backticks to avoid conflicts with reserved keywords
     date DATE,
     `month` VARCHAR(7),
     `time` TIME,
     color VARCHAR(7),
     tel VARCHAR(20),
     search VARCHAR(255),
     file_path VARCHAR(255), -- Store uploaded file path
     hobbies VARCHAR(255), -- Checkbox group, stored as comma-separated values
     gender ENUM('male', 'female'),
     country VARCHAR(50),
     languages VARCHAR(255), -- Multi-select, stored as comma-separated values
     bio TEXT,
     secret VARCHAR(255),
     submitted_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
   );
   ```

2. **Database Connection**: Update the database credentials in `db_connect.php` to match your setup.

---

## Files Overview

### 1. **db_connect.php**

This file handles the connection to your MySQL database.

```php
<?php
function db_connect() {
    $servername = "localhost";  // Replace with your servername
    $username = "root";         // Replace with your username
    $password = "";             // Replace with your password
    $dbname = "form_template";  // Replace with your database name

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    return $conn;
}
?>
```

### 2. **process_form.php**

The main form processing logic, including file upload handling and SQL injection protection.

```php
<?php
function process_form($conn, $table_name, $fields, $file_fields = []) {
    // Handle file uploads
    foreach ($file_fields as $file_field) {
        if (isset($_FILES[$file_field]) && $_FILES[$file_field]['error'] == 0) {
            $file_type = $_FILES[$file_field]['type'];
            $file_name = $_FILES[$file_field]['name'];
            
            // Sanitize file name
            $safe_file_name = preg_replace("/[^a-zA-Z0-9.-]/", "_", $file_name);

            // Choose folder based on file type
            if (strpos($file_type, 'pdf') !== false) {
                $target_dir = "uploads/pdfs/";
            } elseif (strpos($file_type, 'image') !== false) {
                $target_dir = "uploads/images/";
            } else {
                $target_dir = "uploads/other_files/";
            }

            // Automatically create folder if it doesn't exist
            if (!is_dir($target_dir)) {
                mkdir($target_dir, 0755, true);
            }

            $target_file = $target_dir . $safe_file_name;
            if (move_uploaded_file($_FILES[$file_field]['tmp_name'], $target_file)) {
                $fields['file_path'] = $target_file;  // Assign file path to fields array
            } else {
                return "Failed to move uploaded file.";
            }
        }
    }

    // Prepare SQL query
    $placeholders = implode(', ', array_fill(0, count($fields), '?'));
    $field_names = implode(', ', array_map(function ($field) {
        // Use backticks to avoid reserved keyword conflicts
        return "`$field`";
    }, array_keys($fields)));

    $stmt = $conn->prepare("INSERT INTO $table_name ($field_names) VALUES ($placeholders)");

    if ($stmt === false) {
        return "Error preparing statement: " . $conn->error;
    }

    // Bind parameters
    $types = str_repeat('s', count($fields));
    if (!$stmt->bind_param($types, ...array_values($fields))) {
        return "Error binding parameters: " . $stmt->error;
    }

    // Execute the statement
    if ($stmt->execute()) {
        $stmt->close();
        return "Form submitted successfully!";
    } else {
        $error = "Error: " . $stmt->error;
        $stmt->close();
        return $error;
    }
}
?>
```

### 3. **submit_form.php**

Handles the form submission and passes the form data to `process_form.php`.

```php
<?php
include 'db_connect.php';
include 'process_form.php';

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $conn = db_connect();

    // Prepare the fields
    $fields = [
        'text' => $_POST['text'] ?? null,
        'password' => $_POST['password'] ?? null,
        'email' => $_POST['email'] ?? null,
        'url' => $_POST['url'] ?? null,
        'number' => $_POST['number'] ?? null,
        'range' => $_POST['range'] ?? null,
        'date' => $_POST['date'] ?? null,
        'month' => $_POST['month'] ?? null,
        'time' => $_POST['time'] ?? null,
        'color' => $_POST['color'] ?? null,
        'tel' => $_POST['tel'] ?? null,
        'search' => $_POST['search'] ?? null,
        'hobbies' => isset($_POST['hobbies']) ? implode(",", $_POST['hobbies']) : null,
        'gender' => $_POST['gender'] ?? null,
        'country' => $_POST['country'] ?? null,
        'languages' => isset($_POST['languages']) ? implode(",", $_POST['languages']) : null,
        'bio' => $_POST['bio'] ?? null,
        'secret' => $_POST['secret'] ?? null,
    ];

    // Process form
    $file_fields = ['file'];  // Handle file uploads
    $result = process_form($conn, 'form_submissions', $fields, $file_fields);

    echo $result;
    $conn->close();
}
?>
```

---

## How It Works

1. **User Submits the Form**: When the user submits the form, data is sent to `submit_form.php`.
2. **Form Processing**: In `submit_form.php`, the form data is validated and passed to `process_form.php`.
3. **File Uploads**: If there are any file uploads, they are handled and stored in the appropriate folder.
4. **Database Insertion**: All the form data is saved into the `form_submissions` table 
