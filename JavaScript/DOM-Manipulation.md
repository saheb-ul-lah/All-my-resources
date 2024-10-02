---

# 📜 JavaScript DOM Manipulation Cheatsheet

Welcome to the **JavaScript DOM Manipulation Cheatsheet** repository! This is a handy reference for all developers who want to efficiently handle HTML elements, manipulate the DOM, and enhance web applications using vanilla JavaScript.

## 🚀 Quick Overview

This cheatsheet covers all the core aspects of DOM manipulation in JavaScript, including element selection, modification, event handling, form interactions, and much more.

---

## 📝 Table of Contents
- [Selecting Elements](#selecting-elements)
- [Modifying Content](#modifying-content)
- [Attributes and Classes](#attributes-and-classes)
- [CSS Manipulation](#css-manipulation)
- [Event Handling](#event-handling)
- [DOM Traversal](#dom-traversal)
- [Creating and Removing Elements](#creating-and-removing-elements)
- [Form Handling](#form-handling)
- [Storage Handling (Local & Session)](#storage-handling)
- [Common Methods](#common-methods)

---

## 🔍 Selecting Elements

### **Single Element Selection**
- **`document.getElementById('id')`**  
  Select an element by `id`.
  ```js
  const element = document.getElementById('header');
  ```

- **`document.querySelector('selector')`**  
  Select the first element matching a selector.
  ```js
  const element = document.querySelector('.btn');
  ```

### **Multiple Element Selection**
- **`document.getElementsByClassName('className')`**  
  Select elements by class name.
  ```js
  const elements = document.getElementsByClassName('item');
  ```

- **`document.querySelectorAll('selector')`**  
  Select all elements matching a selector.
  ```js
  const items = document.querySelectorAll('.item');
  ```

---

## ✏️ Modifying Content

### **Text Content**
- **`element.textContent = 'New Text'`**  
  Update or get the text inside an element.
  ```js
  element.textContent = 'Updated Title';
  ```

### **HTML Content**
- **`element.innerHTML = '<b>HTML Content</b>'`**  
  Insert or get HTML content inside an element.
  ```js
  element.innerHTML = '<p>New paragraph!</p>';
  ```

---

## 🏷️ Attributes and Classes

### **Modifying Attributes**
- **`element.getAttribute('attribute')`**  
  Get the value of an attribute.
  ```js
  const href = element.getAttribute('href');
  ```

- **`element.setAttribute('attribute', 'value')`**  
  Set or update an attribute's value.
  ```js
  element.setAttribute('href', 'https://new-link.com');
  ```

### **Modifying Classes**
- **`element.classList.add('class')`**  
  Add a class to an element.
  ```js
  element.classList.add('active');
  ```

- **`element.classList.remove('class')`**  
  Remove a class from an element.
  ```js
  element.classList.remove('hidden');
  ```

- **`element.classList.toggle('class')`**  
  Toggle a class on or off.
  ```js
  element.classList.toggle('dark-mode');
  ```

---

## 🎨 CSS Manipulation

### **Inline Styles**
- **`element.style.property = 'value'`**  
  Modify inline CSS styles.
  ```js
  element.style.color = 'red';
  ```

### **Computed Styles**
- **`window.getComputedStyle(element)`**  
  Retrieve the computed styles of an element.
  ```js
  const styles = window.getComputedStyle(element);
  console.log(styles.backgroundColor);
  ```

---

## 🎯 Event Handling

### **Adding Events**
- **`element.addEventListener('event', callback)`**  
  Attach an event listener to an element.
  ```js
  element.addEventListener('click', () => {
    console.log('Element clicked!');
  });
  ```

### **Removing Events**
- **`element.removeEventListener('event', callback)`**  
  Remove an attached event listener.
  ```js
  element.removeEventListener('click', handleClick);
  ```

### **Common Events**
- `click`, `mouseover`, `mouseout`, `keyup`, `keydown`, `focus`, `blur`

---

## 🌲 DOM Traversal

### **Parent and Children**
- **`element.parentElement`**  
  Get the parent of an element.
  ```js
  const parent = element.parentElement;
  ```

- **`element.children`**  
  Get child elements of an element.
  ```js
  const children = element.children;
  ```

### **Siblings**
- **`element.nextElementSibling`**  
  Get the next sibling of an element.
  ```js
  const next = element.nextElementSibling;
  ```

- **`element.previousElementSibling`**  
  Get the previous sibling of an element.
  ```js
  const prev = element.previousElementSibling;
  ```

---

## 🏗️ Creating and Removing Elements

### **Creating Elements**
- **`document.createElement('tagName')`**  
  Create a new element.
  ```js
  const newDiv = document.createElement('div');
  ```

### **Adding Elements**
- **`element.appendChild(childElement)`**  
  Append a child element.
  ```js
  element.appendChild(newDiv);
  ```

### **Removing Elements**
- **`element.remove()`**  
  Remove an element from the DOM.
  ```js
  newDiv.remove();
  ```

---

## 🧾 Form Handling

### **Accessing Form Inputs**
- **`document.forms['formName']`**  
  Access a form by its name.
  ```js
  const form = document.forms['loginForm'];
  ```

### **Handling Form Submissions**
- **`form.addEventListener('submit', function)`**  
  Prevent form submission from refreshing the page.
  ```js
  form.addEventListener('submit', (e) => {
    e.preventDefault();
    console.log('Form Submitted!');
  });
  ```

---

## 💾 Storage Handling

### **Local Storage**
- **`localStorage.setItem('key', 'value')`**  
  Store data in local storage.
  ```js
  localStorage.setItem('username', 'JohnDoe');
  ```

- **`localStorage.getItem('key')`**  
  Retrieve data from local storage.
  ```js
  const username = localStorage.getItem('username');
  ```

- **`localStorage.removeItem('key')`**  
  Remove data from local storage.
  ```js
  localStorage.removeItem('username');
  ```

### **Session Storage**
- Same methods as `localStorage`, but stores data for the session only.

---

## 🔧 Common Methods

### **Getting Input Values**
- **`element.value`**  
  Get or set the value of an input element.
  ```js
  const value = document.querySelector('input').value;
  ```

### **Changing Input Values**
- **`element.value = 'newValue'`**  
  Change the value of an input field.
  ```js
  document.querySelector('input').value = 'Updated Value';
  ```

---

## 👨‍💻 Contribute

Feel free to contribute to this repository by suggesting more snippets or improvements!

---

## 📚 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

With this cheatsheet, you’ll have a powerful reference for mastering DOM manipulation with vanilla JavaScript! 🎉

---
