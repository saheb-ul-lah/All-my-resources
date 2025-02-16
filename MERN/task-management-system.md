---

## **Introduction**

Today, we’re going to build a **Task Management System** using the **MERN stack** (MongoDB, Express, React, and Node.js). This system will allow users to:

1. **Register and log in** (Authentication).
2. **Create, read, update, and delete tasks** (CRUD Operations).
3. **Upload files** related to tasks.
4. **Make payments** for premium features (using Stripe).
5. **Generate task summaries** using AI (OpenAI API).

We’ll start by setting up the project, then move to the frontend, and integrate the backend as needed. I’ll explain everything in simple terms, so even if you’re new to servers, tokens, or cookies, you’ll understand how everything works.

---

## **Step 1: Setting Up the Project**

### **1.1 Install Node.js and npm**

Before we start, make sure you have **Node.js** and **npm** installed. You can download them from [nodejs.org](https://nodejs.org/). To check if they’re installed, run these commands in your terminal:

```bash
node -v
npm -v
```

If you see version numbers, you’re good to go!

---

### **1.2 Create the Project Folder**

Let’s create a folder for our project. Open your terminal and run:

```bash
mkdir task-management-system
cd task-management-system
```

This will create a folder called `task-management-system` and navigate into it.

---

### **1.3 Initialize the Project**

Now, let’s initialize a Node.js project. Run:

```bash
npm init -y
```

This creates a `package.json` file, which will keep track of all the dependencies (libraries) we’ll install.

---

### **1.4 Install Required Dependencies**

We’ll need a few libraries for the backend. Let’s install them:

```bash
npm install express mongoose cors dotenv bcryptjs jsonwebtoken stripe multer openai swagger-jsdoc swagger-ui-express
```

Here’s what each library does:

- **express**: A framework for building the backend server.
- **mongoose**: A library to interact with MongoDB.
- **cors**: Allows the frontend to communicate with the backend.
- **dotenv**: Loads environment variables (like API keys) from a `.env` file.
- **bcryptjs**: Hashes passwords for security.
- **jsonwebtoken**: Generates tokens for user authentication.
- **stripe**: Handles payments.
- **multer**: Handles file uploads.
- **openai**: Integrates with OpenAI’s API for AI features.
- **swagger-jsdoc** and **swagger-ui-express**: Generate API documentation.

---

### **1.5 Create the Project Structure**

Let’s create the folder structure for our project. Run these commands:

```bash
mkdir backend frontend
cd backend
mkdir models routes controllers middleware config utils
touch server.js .env
```

This creates the following structure:

```
task-management-system/
├── backend/
│   ├── models/
│   ├── routes/
│   ├── controllers/
│   ├── middleware/
│   ├── config/
│   ├── utils/
│   ├── server.js
│   └── .env
├── frontend/
└── package.json
```

---

## **Step 2: Backend Development**

### **2.1 Basic Server Setup**

Let’s start by setting up the backend server. Open the `backend/server.js` file and add the following code:

```javascript
// backend/server.js

// Import required libraries
const express = require('express');
const cors = require('cors');
const dotenv = require('dotenv');
const mongoose = require('mongoose');

// Load environment variables
dotenv.config();

// Create an Express app
const app = express();

// Middleware
app.use(cors()); // Enable CORS
app.use(express.json()); // Parse JSON request bodies

// Connect to MongoDB
mongoose.connect(process.env.MONGO_URI, {
  useNewUrlParser: true,
  useUnifiedTopology: true,
})
.then(() => console.log('MongoDB connected'))
.catch((err) => console.error('MongoDB connection error:', err));

// Define a basic route
app.get('/', (req, res) => {
  res.send('Task Management System Backend');
});

// Start the server
const PORT = process.env.PORT || 5000;
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
```

#### **Explanation:**

1. **express**: We use this to create the server.
2. **cors**: This allows the frontend (which will run on a different port) to communicate with the backend.
3. **dotenv**: Loads environment variables from a `.env` file (we’ll create this soon).
4. **mongoose**: Connects to MongoDB, our database.
5. **app.use(express.json())**: This middleware allows the server to parse JSON data sent in requests.

---

### **2.2 Create the `.env` File**

In the `backend` folder, create a `.env` file and add the following:

```env
MONGO_URI=mongodb://localhost:27017/taskmanager
PORT=5000
JWT_SECRET=your_jwt_secret
STRIPE_SECRET_KEY=your_stripe_secret_key
OPENAI_API_KEY=your_openai_api_key
```

#### **Explanation:**

- **MONGO_URI**: The connection string for MongoDB. If you don’t have MongoDB installed locally, you can use [MongoDB Atlas](https://www.mongodb.com/cloud/atlas) for a free cloud database.
- **PORT**: The port the server will run on.
- **JWT_SECRET**: A secret key for generating JSON Web Tokens (used for authentication).
- **STRIPE_SECRET_KEY**: Your Stripe API key (you’ll get this from the Stripe dashboard).
- **OPENAI_API_KEY**: Your OpenAI API key (you’ll get this from the OpenAI dashboard).

---

### **2.3 Start the Server**

Now, let’s start the server. Run:

```bash
node backend/server.js
```

If everything is set up correctly, you should see:

```
MongoDB connected
Server running on port 5000
```

---

## **Step 3: Frontend Development**

### **3.1 Set Up React**

Let’s move to the frontend. In the `task-management-system` folder, run:

```bash
npx create-react-app frontend
cd frontend
npm start
```

This will create a new React app and start it on `http://localhost:3000`.

---

### **3.2 Clean Up the React App**

Open the `frontend/src` folder and delete the following files:

- `App.test.js`
- `logo.svg`
- `reportWebVitals.js`
- `setupTests.js`

Then, update `App.js` to look like this:

```jsx
// frontend/src/App.js

import React from 'react';

function App() {
  return (
    <div className="App">
      <h1>Task Management System</h1>
    </div>
  );
}

export default App;
```

---

### **3.3 Install Frontend Dependencies**

We’ll need a few libraries for the frontend. Run:

```bash
npm install axios react-router-dom
```

- **axios**: For making API calls to the backend.
- **react-router-dom**: For routing in the React app.

---

## **Step 4: Connect Frontend and Backend**

### **4.1 Create a Simple API Call**

Let’s test the connection between the frontend and backend. In `frontend/src/App.js`, add:

```jsx
import React, { useEffect } from 'react';
import axios from 'axios';

function App() {
  useEffect(() => {
    axios.get('http://localhost:5000/')
      .then((response) => {
        console.log(response.data);
      })
      .catch((error) => {
        console.error(error);
      });
  }, []);

  return (
    <div className="App">
      <h1>Task Management System</h1>
    </div>
  );
}

export default App;
```

#### **Explanation:**

- We’re using `axios` to make a GET request to the backend server.
- If the connection is successful, you’ll see `Task Management System Backend` in the browser console.

---

## **Step 5: Authentication**

### **5.1 User Model**

Let’s create a `User` model to store user data. In `backend/models/User.js`, add:

```javascript
// backend/models/User.js

const mongoose = require('mongoose');
const bcrypt = require('bcryptjs');

// Define the user schema
const userSchema = new mongoose.Schema({
  name: { type: String, required: true },
  email: { type: String, required: true, unique: true },
  password: { type: String, required: true },
});

// Hash the password before saving
userSchema.pre('save', async function (next) {
  if (this.isModified('password')) {
    this.password = await bcrypt.hash(this.password, 10);
  }
  next();
});

// Create the User model
const User = mongoose.model('User', userSchema);

module.exports = User;
```

#### **Explanation:**

- We define a `User` schema with `name`, `email`, and `password` fields.
- The `pre('save')` middleware hashes the password before saving it to the database.

---

### **5.2 Authentication Routes**

Let’s create routes for user registration and login. In `backend/routes/auth.js`, add:

```javascript
// backend/routes/auth.js

const express = require('express');
const router = express.Router();
const User = require('../models/User');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');

// Register a new user
router.post('/register', async (req, res) => {
  const { name, email, password } = req.body;
  try {
    const user = new User({ name, email, password });
    await user.save();
    res.status(201).json({ message: 'User registered successfully' });
  } catch (err) {
    res.status(400).json({ error: err.message });
  }
});

// Login a user
router.post('/login', async (req, res) => {
  const { email, password } = req.body;
  try {
    const user = await User.findOne({ email });
    if (!user) throw new Error('User not found');
    const isMatch = await bcrypt.compare(password, user.password);
    if (!isMatch) throw new Error('Invalid credentials');
    const token = jwt.sign({ userId: user._id }, process.env.JWT_SECRET, { expiresIn: '1h' });
    res.json({ token });
  } catch (err) {
    res.status(400).json({ error: err.message });
  }
});

module.exports = router;
```

#### **Explanation:**

- **/register**: Creates a new user in the database.
- **/login**: Checks if the user exists and verifies the password. If successful, it generates a JWT token for authentication.

---

### **5.3 Test Authentication Routes**

Let’s test these routes using **Postman** or any API testing tool.

1. **Register a User**:
   - Method: POST
   - URL: `http://localhost:5000/api/auth/register`
   - Body (JSON):
     ```json
     {
       "name": "John Doe",
       "email": "john@example.com",
       "password": "password123"
     }
     ```

2. **Login a User**:
   - Method: POST
   - URL: `http://localhost:5000/api/auth/login`
   - Body (JSON):
     ```json
     {
       "email": "john@example.com",
       "password": "password123"
     }
     ```

If successful, you’ll receive a token in the response.

---

## **Step 6: Frontend Authentication**

### **6.1 Create a Login Form**

In `frontend/src/components/LoginForm.jsx`, add:

```jsx
// frontend/src/components/LoginForm.jsx

import React, { useState } from 'react';
import axios from 'axios';

const LoginForm = () => {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');

  const handleSubmit = async (e) => {
    e.preventDefault();
    try {
      const response = await axios.post('http://localhost:5000/api/auth/login', { email, password });
      localStorage.setItem('token', response.data.token);
      alert('Login successful!');
    } catch (err) {
      alert('Login failed');
    }
  };

  return (
    <form onSubmit={handleSubmit}>
      <input
        type="email"
        placeholder="Email"
        value={email}
        onChange={(e) => setEmail(e.target.value)}
      />
      <input
        type="password"
        placeholder="Password"
        value={password}
        onChange={(e) => setPassword(e.target.value)}
      />
      <button type="submit">Login</button>
    </form>
  );
};

export default LoginForm;
```

#### **Explanation:**

- This form allows users to log in.
- On successful login, the token is stored in `localStorage`.

---

### **6.2 Add the Login Form to the App**

Update `frontend/src/App.js` to include the `LoginForm`:

```jsx
// frontend/src/App.js

import React from 'react';
import LoginForm from './components/LoginForm';

function App() {
  return (
    <div className="App">
      <h1>Task Management System</h1>
      <LoginForm />
    </div>
  );
}

export default App;
```

---

## **Step 7: Conclusion**

We’ve set up the basic structure of our **Task Management System**, including:

1. **Backend Server**: With Express and MongoDB.
2. **Authentication**: User registration and login with JWT.
3. **Frontend**: A simple React app with a login form.

In the next steps, we’ll add CRUD operations, file uploads, payment integration, and AI features. Let me know if you have any questions so far! 🚀
