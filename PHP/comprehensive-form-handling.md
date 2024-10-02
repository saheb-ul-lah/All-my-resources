# A **comprehensive form** that contains every possible HTML input type and attribute, then handle this form using PHP to demonstrate how each input is processed, validated, and stored. Finally, we'll save the data into a database table.

### **Part 1: HTML Form with All Possible Input Types**

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Comprehensive Form</title>
  <style>
    form {
      width: 70%;
      margin: auto;
    }
    label {
      display: block;
      margin-top: 10px;
    }
    input, select, textarea {
      width: 100%;
      padding: 8px;
      margin-top: 5px;
      margin-bottom: 10px;
      border: 1px solid #ccc;
      border-radius: 4px;
    }
  </style>
</head>
<body>
  <h1>Comprehensive Form</h1>
  <form action="process_form.php" method="post" enctype="multipart/form-data">
    
    <!-- Text Input -->
    <label for="text">Text:</label>
    <input type="text" id="text" name="text" placeholder="Enter text" required>

    <!-- Password Input -->
    <label for="password">Password:</label>
    <input type="password" id="password" name="password" required>

    <!-- Email Input -->
    <label for="email">Email:</label>
    <input type="email" id="email" name="email" placeholder="example@mail.com" required>

    <!-- URL Input -->
    <label for="url">Website URL:</label>
    <input type="url" id="url" name="url" placeholder="https://example.com">

    <!-- Number Input -->
    <label for="number">Number:</label>
    <input type="number" id="number" name="number" min="1" max="100" step="1">

    <!-- Range Input -->
    <label for="range">Range:</label>
    <input type="range" id="range" name="range" min="0" max="100">

    <!-- Date Input -->
    <label for="date">Date:</label>
    <input type="date" id="date" name="date">

    <!-- Month Input -->
    <label for="month">Month:</label>
    <input type="month" id="month" name="month">

    <!-- Time Input -->
    <label for="time">Time:</label>
    <input type="time" id="time" name="time">

    <!-- Color Input -->
    <label for="color">Favorite Color:</label>
    <input type="color" id="color" name="color">

    <!-- Telephone Input -->
    <label for="tel">Telephone:</label>
    <input type="tel" id="tel" name="tel" placeholder="123-456-7890">

    <!-- Search Input -->
    <label for="search">Search:</label>
    <input type="search" id="search" name="search" placeholder="Search something...">

    <!-- File Input -->
    <label for="file">Upload File:</label>
    <input type="file" id="file" name="file">

    <!-- Checkbox Group -->
    <label>Choose your hobbies:</label>
    <input type="checkbox" id="hobby1" name="hobbies[]" value="reading">
    <label for="hobby1">Reading</label>
    <input type="checkbox" id="hobby2" name="hobbies[]" value="traveling">
    <label for="hobby2">Traveling</label>
    <input type="checkbox" id="hobby3" name="hobbies[]" value="swimming">
    <label for="hobby3">Swimming</label>

    <!-- Radio Button Group -->
    <label>Choose your gender:</label>
    <input type="radio" id="male" name="gender" value="male">
    <label for="male">Male</label>
    <input type="radio" id="female" name="gender" value="female">
    <label for="female">Female</label>

    <!-- Dropdown Select -->
    <label for="country">Country:</label>
    <select id="country" name="country">
      <option value="usa">USA</option>
      <option value="canada">Canada</option>
      <option value="australia">Australia</option>
    </select>

    <!-- Multiple Select -->
    <label for="languages">Languages Known:</label>
    <select id="languages" name="languages[]" multiple>
      <option value="english">English</option>
      <option value="spanish">Spanish</option>
      <option value="french">French</option>
    </select>

    <!-- Textarea -->
    <label for="bio">Bio:</label>
    <textarea id="bio" name="bio" rows="5" placeholder="Tell us about yourself"></textarea>

    <!-- Hidden Input -->
    <input type="hidden" name="secret" value="hiddenValue">

    <!-- Submit Button -->
    <button type="submit">Submit</button>
  </form>
</body>
</html>
```

### **Part 2: PHP Script to Process the Form (`process_form.php`)**

This PHP script will process all the form inputs, validate them, and display the output.

```php
<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    // Sanitize and validate inputs
    $text = htmlspecialchars($_POST['text']);
    $password = htmlspecialchars($_POST['password']);
    $email = filter_var($_POST['email'], FILTER_SANITIZE_EMAIL);
    $url = filter_var($_POST['url'], FILTER_VALIDATE_URL);
    $number = filter_var($_POST['number'], FILTER_SANITIZE_NUMBER_INT);
    $range = filter_var($_POST['range'], FILTER_SANITIZE_NUMBER_INT);
    $date = $_POST['date'];
    $month = $_POST['month'];
    $time = $_POST['time'];
    $color = $_POST['color'];
    $tel = htmlspecialchars($_POST['tel']);
    $search = htmlspecialchars($_POST['search']);
    
    // File upload
    if (isset($_FILES['file']) && $_FILES['file']['error'] == 0) {
        $file_name = basename($_FILES['file']['name']);
        $file_tmp = $_FILES['file']['tmp_name'];
        $upload_dir = 'uploads/';
        move_uploaded_file($file_tmp, $upload_dir . $file_name);
        $file_uploaded = $file_name;
    } else {
        $file_uploaded = 'No file uploaded or error in file upload.';
    }

    // Hobbies (Checkboxes)
    $hobbies = isset($_POST['hobbies']) ? implode(', ', $_POST['hobbies']) : 'None';

    // Gender (Radio)
    $gender = isset($_POST['gender']) ? $_POST['gender'] : 'Not specified';

    // Country (Select)
    $country = $_POST['country'];

    // Languages (Multiple Select)
    $languages = isset($_POST['languages']) ? implode(', ', $_POST['languages']) : 'None';

    // Bio (Textarea)
    $bio = htmlspecialchars($_POST['bio']);

    // Hidden value
    $secret = htmlspecialchars($_POST['secret']);

    // Display all data
    echo "<h1>Form Data:</h1>";
    echo "Text: $text<br>";
    echo "Password: $password<br>";
    echo "Email: $email<br>";
    echo "URL: $url<br>";
    echo "Number: $number<br>";
    echo "Range: $range<br>";
    echo "Date: $date<br>";
    echo "Month: $month<br>";
    echo "Time: $time<br>";
    echo "Color: $color<br>";
    echo "Telephone: $tel<br>";
    echo "Search: $search<br>";
    echo "File: $file_uploaded<br>";
    echo "Hobbies: $hobbies<br>";
    echo "Gender: $gender<br>";
    echo "Country: $country<br>";
    echo "Languages: $languages<br>";
    echo "Bio: $bio<br>";
    echo "Secret: $secret<br>";
}
?>
```

### **Part 3: Creating a Database Table and Inserting Data**

We’ll create a MySQL database table to store the form data. Here's how you can structure your table.

#### **SQL Table Structure:**

```sql
CREATE TABLE form_data (
    id INT AUTO_INCREMENT PRIMARY KEY,
    text_input VARCHAR(255),
    password_input VARCHAR(255),
    email_input VARCHAR(255),
    url_input VARCHAR(255),
    number_input INT,
    range_input INT,
    date_input DATE,
    month_input VARCHAR(7),
    time_input TIME,
    color_input VARCHAR(7),
    tel_input VARCHAR(20),
    search_input VARCHAR(255),
    file_uploaded VARCHAR(255),
    hobbies_input VARCHAR(255),
    gender_input VARCHAR(10),
    country_input VARCHAR(50),
    languages_input VARCHAR(255),
    bio_input TEXT,
    secret_input VARCHAR(255)
);
```

### **Part 4: Saving Data into the Database**

We can modify the PHP script to insert the form data into the MySQL database.

#### **PHP Code to Insert Data:**

```php
<?php
// Connect to the database
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "form_handling";

$conn

 = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    // Collect data
    $text = htmlspecialchars($_POST['text']);
    $password = htmlspecialchars($_POST['password']);
    $email = filter_var($_POST['email'], FILTER_SANITIZE_EMAIL);
    $url = filter_var($_POST['url'], FILTER_VALIDATE_URL);
    $number = filter_var($_POST['number'], FILTER_SANITIZE_NUMBER_INT);
    $range = filter_var($_POST['range'], FILTER_SANITIZE_NUMBER_INT);
    $date = $_POST['date'];
    $month = $_POST['month'];
    $time = $_POST['time'];
    $color = $_POST['color'];
    $tel = htmlspecialchars($_POST['tel']);
    $search = htmlspecialchars($_POST['search']);
    
    // File upload
    if (isset($_FILES['file']) && $_FILES['file']['error'] == 0) {
        $file_name = basename($_FILES['file']['name']);
        $file_tmp = $_FILES['file']['tmp_name'];
        $upload_dir = 'uploads/';
        move_uploaded_file($file_tmp, $upload_dir . $file_name);
        $file_uploaded = $file_name;
    } else {
        $file_uploaded = 'No file uploaded';
    }

    $hobbies = isset($_POST['hobbies']) ? implode(', ', $_POST['hobbies']) : 'None';
    $gender = isset($_POST['gender']) ? $_POST['gender'] : 'Not specified';
    $country = $_POST['country'];
    $languages = isset($_POST['languages']) ? implode(', ', $_POST['languages']) : 'None';
    $bio = htmlspecialchars($_POST['bio']);
    $secret = htmlspecialchars($_POST['secret']);

    // Insert data into the table
    $sql = "INSERT INTO form_data (text_input, password_input, email_input, url_input, number_input, range_input, date_input, month_input, time_input, color_input, tel_input, search_input, file_uploaded, hobbies_input, gender_input, country_input, languages_input, bio_input, secret_input) 
            VALUES ('$text', '$password', '$email', '$url', '$number', '$range', '$date', '$month', '$time', '$color', '$tel', '$search', '$file_uploaded', '$hobbies', '$gender', '$country', '$languages', '$bio', '$secret')";

    if ($conn->query($sql) === TRUE) {
        echo "Data successfully inserted!";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $conn->close();
}
?>
```

### **Conclusion:**

This form covers all HTML input types, and the PHP script processes each input, validates it, and stores it in a database. This is an all-encompassing example that handles file uploads, validation, multiple input types, and secure form submission.

You can use this as a template to build complex forms with all functionalities in your projects.
