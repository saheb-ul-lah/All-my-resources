---

# **JavaScript DOM Manipulation Cheatsheet**

## **1. Selecting Elements**

### **Single Element Selectors**
- `document.getElementById('id')`: Selects element by its `id`.
  ```js
  const element = document.getElementById('header');
  ```

- `document.querySelector('selector')`: Selects the first element matching the selector.
  ```js
  const firstElement = document.querySelector('.btn');
  ```

### **Multiple Element Selectors**
- `document.getElementsByClassName('className')`: Returns a live HTMLCollection of elements.
  ```js
  const buttons = document.getElementsByClassName('btn');
  ```

- `document.getElementsByTagName('tagName')`: Returns a live HTMLCollection by tag name.
  ```js
  const divs = document.getElementsByTagName('div');
  ```

- `document.querySelectorAll('selector')`: Returns a static NodeList of elements matching the selector.
  ```js
  const items = document.querySelectorAll('.item');
  ```

---

## **2. Modifying Element Content**

### **Text Content**
- `element.textContent = 'New Text'`: Updates the text inside an element.
  ```js
  const header = document.getElementById('header');
  header.textContent = 'Updated Title';
  ```

### **HTML Content**
- `element.innerHTML = '<b>HTML Content</b>'`: Sets or gets the HTML inside an element.
  ```js
  const div = document.querySelector('.container');
  div.innerHTML = '<p>New Paragraph</p>';
  ```

---

## **3. Modifying Element Attributes**

### **Getting and Setting Attributes**
- `element.getAttribute('attribute')`: Retrieves the value of an attribute.
  ```js
  const link = document.querySelector('a');
  const href = link.getAttribute('href');
  ```

- `element.setAttribute('attribute', 'value')`: Sets a new value for an attribute.
  ```js
  link.setAttribute('href', 'https://new-link.com');
  ```

### **Modifying Classes**
- `element.classList.add('className')`: Adds a class.
  ```js
  element.classList.add('active');
  ```

- `element.classList.remove('className')`: Removes a class.
  ```js
  element.classList.remove('hidden');
  ```

- `element.classList.toggle('className')`: Toggles a class.
  ```js
  element.classList.toggle('dark-mode');
  ```

---

## **4. Manipulating CSS**

### **Inline Styles**
- `element.style.property = 'value'`: Modifies inline CSS styles.
  ```js
  element.style.color = 'red';
  ```

### **Getting Computed Styles**
- `window.getComputedStyle(element)`: Retrieves computed styles of an element.
  ```js
  const computedStyles = window.getComputedStyle(element);
  const backgroundColor = computedStyles.backgroundColor;
  ```

---

## **5. Event Handling**

### **Adding Event Listeners**
- `element.addEventListener('event', function)`: Attaches an event to an element.
  ```js
  button.addEventListener('click', () => {
    console.log('Button clicked!');
  });
  ```

### **Removing Event Listeners**
- `element.removeEventListener('event', function)`: Removes an event listener.
  ```js
  button.removeEventListener('click', handleClick);
  ```

### **Common Events**
- `click`, `mouseenter`, `mouseleave`, `focus`, `blur`, `keydown`, `keyup`

---

## **6. DOM Traversal**

### **Parent and Child Elements**
- `element.parentElement`: Returns the parent element.
  ```js
  const parent = element.parentElement;
  ```

- `element.children`: Returns a live collection of child elements.
  ```js
  const children = element.children;
  ```

### **Sibling Elements**
- `element.nextElementSibling`: Returns the next sibling element.
  ```js
  const next = element.nextElementSibling;
  ```

- `element.previousElementSibling`: Returns the previous sibling element.
  ```js
  const previous = element.previousElementSibling;
  ```

---

## **7. Creating and Removing Elements**

### **Creating Elements**
- `document.createElement('tag')`: Creates a new element.
  ```js
  const newDiv = document.createElement('div');
  ```

- `document.createTextNode('text')`: Creates a text node.
  ```js
  const text = document.createTextNode('Hello World');
  ```

### **Appending Elements**
- `element.appendChild(child)`: Appends a child to an element.
  ```js
  const container = document.querySelector('.container');
  container.appendChild(newDiv);
  ```

- `element.insertBefore(newNode, referenceNode)`: Inserts a node before another node.
  ```js
  container.insertBefore(newDiv, container.firstChild);
  ```

### **Removing Elements**
- `element.removeChild(child)`: Removes a child element.
  ```js
  container.removeChild(newDiv);
  ```

- `element.remove()`: Removes an element directly.
  ```js
  newDiv.remove();
  ```

---

## **8. Form Handling**

### **Accessing Form Elements**
- `document.forms['formName']`: Accesses a form by its name.
  ```js
  const form = document.forms['loginForm'];
  ```

- `formElement.value`: Retrieves or sets the value of form elements.
  ```js
  const input = form.elements['username'].value;
  ```

### **Form Submission**
- `form.addEventListener('submit', function)`: Handles form submission.
  ```js
  form.addEventListener('submit', (event) => {
    event.preventDefault(); // Prevent page reload
    console.log('Form submitted');
  });
  ```

---

## **9. Local Storage and Session Storage**

### **Storing Data**
- `localStorage.setItem('key', 'value')`: Stores data in local storage.
  ```js
  localStorage.setItem('username', 'JohnDoe');
  ```

- `sessionStorage.setItem('key', 'value')`: Stores data in session storage.
  ```js
  sessionStorage.setItem('token', 'abc123');
  ```

### **Retrieving Data**
- `localStorage.getItem('key')`: Retrieves data from local storage.
  ```js
  const username = localStorage.getItem('username');
  ```

- `sessionStorage.getItem('key')`: Retrieves data from session storage.
  ```js
  const token = sessionStorage.getItem('token');
  ```

### **Removing Data**
- `localStorage.removeItem('key')`: Removes data from local storage.
  ```js
  localStorage.removeItem('username');
  ```

- `sessionStorage.removeItem('key')`: Removes data from session storage.
  ```js
  sessionStorage.removeItem('token');
  ```

---

## **10. Other Common Methods**

### **Getting the Value of Inputs**
- `element.value`: Gets the value of an input field.
  ```js
  const inputValue = document.querySelector('input').value;
  ```

### **Changing Input Values**
- `element.value = 'newValue'`: Sets the value of an input field.
  ```js
  document.querySelector('input').value = 'Updated Value';
  ```

---
