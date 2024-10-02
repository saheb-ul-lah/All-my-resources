A comprehensive beginner-friendly documentation for the universal PHP template system that you can use to create various forms, such as the menu upload form for a restaurant website. This documentation will guide you step by step through its features and how to use it effectively.

---

# Universal PHP Form Template Documentation

## Table of Contents

1. [Overview](#overview)
2. [System Requirements](#system-requirements)
3. [File Structure](#file-structure)
4. [Database Setup](#database-setup)
5. [Creating a Form](#creating-a-form)
   - [Form Example: Menu Upload](#form-example-menu-upload)
6. [Code Explanation](#code-explanation)
7. [Error Handling](#error-handling)
8. [Testing the Form](#testing-the-form)
9. [Conclusion](#conclusion)

---

## Overview

This documentation describes a universal PHP form template that can be used to create various forms with multiple input types, including text, select, checkbox, and file uploads. The template manages file uploads by organizing them into specific folders based on their types (e.g., PDFs, images) and provides robust error handling.

---

## System Requirements

- **PHP** (7.0 or later)
- **MySQL** (or any compatible database)
- A web server (e.g., Apache, Nginx)
- **XAMPP** or any local server setup (for local development)

---

## File Structure

Here’s the suggested file structure for your project:

```
/restaurant_website
│
├── uploads/
│   ├── images/
│   ├── pdfs/
│   └── other_files/
│
├── db_connect.php
├── process_form.php
└── upload_menu.php
```

- `uploads/`: This folder contains subfolders for different file types.
- `db_connect.php`: Contains the database connection logic.
- `process_form.php`: Contains the logic for processing the form data.
- `upload_menu.php`: The main file for the menu upload form.

---

## Database Setup

### 1. Create a Database

Create a MySQL database named `restaurant_website`.

### 2. Create a Table

Create a table named `menu_uploads` with the following SQL command:

```sql
CREATE TABLE menu_uploads (
    id INT AUTO_INCREMENT PRIMARY KEY,
    menu_name VARCHAR(255) NOT NULL,
    description TEXT,
    file_path VARCHAR(255) NOT NULL,
    category VARCHAR(100),
    is_available BOOLEAN DEFAULT TRUE
);
```

---

## Creating a Form

### Form Example: Menu Upload

Here’s how to create a form for uploading a menu:

1. Open `upload_menu.php`.
2. Copy and paste the following code:

```php
<?php
include 'db_connect.php';
include 'process_form.php';

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $conn = db_connect();
    $fields = [
        'menu_name' => $_POST['menu_name'] ?? null,
        'description' => $_POST['description'] ?? null,
        'file_path' => null // Initialize the file_path field
    ];
    echo process_form($conn, 'menu_uploads', $fields, ['file']);
    $conn->close();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Upload Menu</title>
</head>
<body>
    <h1>Upload Menu</h1>
    <form method="POST" action="upload_menu.php" enctype="multipart/form-data">
        <label>Menu Name: </label><input type="text" name="menu_name" required><br>
        <label>Description: </label><textarea name="description" required></textarea><br>
        <label>Upload Menu File (PDF): </label><input type="file" name="file" required><br>
        <button type="submit">Upload</button>
    </form>
</body>
</html>
```

---

## Code Explanation

### 1. `db_connect.php`

This file handles the database connection.

```php
<?php

function db_connect() {
    $servername = "localhost";
    $username = "root";  // Change this to your DB username
    $password = "";      // Change this to your DB password
    $dbname = "restaurant_website";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    return $conn;
}
?>
```

### 2. `process_form.php`

This file processes the form data and manages file uploads.

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
                // Assign file path to fields array
                $fields['file_path'] = $target_file;
            } else {
                return "Failed to move uploaded file.";
            }
        }
    }

    // Prepare SQL query
    $placeholders = implode(', ', array_fill(0, count($fields), '?'));
    $field_names = implode(', ', array_keys($fields));

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

---

## Error Handling

The template includes basic error handling:

- Errors during file upload or database operations are returned as messages.
- If an error occurs, it is displayed on the screen for the user.

For improved error tracking, consider implementing logging mechanisms in a production environment.

---

## Testing the Form

1. **Run the Server**: Make sure your web server (like XAMPP) is running.
2. **Access the Form**: Open your web browser and go to `http://localhost/restaurant_website/upload_menu.php`.
3. **Fill the Form**: Enter a menu name, description, and upload a PDF file.
4. **Submit the Form**: Click the "Upload" button.
5. **Check Database**: Open your MySQL database and verify that the entry appears in the `menu_uploads` table.

---

## Conclusion

This universal PHP form template provides a robust framework for handling various forms in your application. By following the steps outlined in this documentation, you can easily create forms, process data, and manage file uploads. With this foundation, you can expand and customize your application to meet specific requirements as needed.

If you have further questions or need assistance, feel free to reach out!

--- 

Feel free to adjust this documentation to better fit your needs or the specific requirements of your project!
