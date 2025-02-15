---

# MERN Project Setup with Vite and Tailwind CSS

This guide will help you set up a MERN (MongoDB, Express, React, Node.js) project using Vite for the React frontend and Tailwind CSS for styling. The guide uses the updated Tailwind CSS setup with Vite.

---

## Prerequisites

- Node.js installed (v16 or higher)
- npm or yarn installed
- MongoDB connection string (for the backend)

---

## Setup Instructions

Copy and paste the following commands into your terminal to set up the project in one go:

```bash
# Create a new project directory and navigate into it
mkdir mern-project && cd mern-project

# Initialize a new Node.js project for the backend
mkdir backend && cd backend && npm init -y && npm install express cors mongoose dotenv && cd ..

# Create a new Vite React app for the frontend
npm create vite@latest frontend -- --template react
cd frontend && npm install && npm install tailwindcss @tailwindcss/vite && npx tailwindcss init

# Configure Tailwind CSS with Vite plugin
echo "import { defineConfig } from 'vite';
import react from '@vitejs/plugin-react';
import tailwindcss from '@tailwindcss/vite';

export default defineConfig({
  plugins: [
    react(),
    tailwindcss(),
  ],
});" > vite.config.js

# Add Tailwind to your CSS
echo "@import 'tailwindcss/base';
@import 'tailwindcss/components';
@import 'tailwindcss/utilities';" > src/index.css

# Go back to the root directory
cd ..

# Create a basic Express server in the backend
echo "const express = require('express');
const cors = require('cors');
const dotenv = require('dotenv');

dotenv.config();
const app = express();
const PORT = process.env.PORT || 5000;

app.use(cors());
app.use(express.json());

app.get('/', (req, res) => {
  res.send('Hello from the backend!');
});

app.listen(PORT, () => {
  console.log(\`Server running on port \${PORT}\`);
});" > backend/server.js

# Create a .env file for environment variables
echo "PORT=5000
MONGO_URI=your_mongodb_connection_string_here" > backend/.env

# Create a basic folder structure for the backend
mkdir backend/models backend/routes backend/controllers

# Create a basic React frontend structure
echo "import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App';
import './index.css';

ReactDOM.createRoot(document.getElementById('root')).render(
  <React.StrictMode>
    <App />
  </React.StrictMode>
);" > frontend/src/main.jsx

echo "function App() {
  return (
    <h1 className='text-3xl font-bold underline text-center'>
      Hello from the frontend!
    </h1>
  );
}

export default App;" > frontend/src/App.jsx

# Install concurrently to run both frontend and backend together
npm install -g concurrently

# Create a script to run both frontend and backend
echo '{
  "name": "mern-project",
  "version": "1.0.0",
  "scripts": {
    "start": "concurrently \"npm run server\" \"npm run client\"",
    "server": "cd backend && node server.js",
    "client": "cd frontend && npm run dev"
  }
}' > package.json

# Run the project
npm start
```

---

## Project Structure

After running the commands, your project structure will look like this:

```
mern-project/
├── backend/
│   ├── models/
│   ├── routes/
│   ├── controllers/
│   ├── server.js
│   ├── .env
│   └── package.json
├── frontend/
│   ├── public/
│   ├── src/
│   │   ├── App.jsx
│   │   ├── main.jsx
│   │   └── index.css
│   ├── vite.config.js
│   ├── tailwind.config.js
│   └── package.json
└── package.json
```

---

## Running the Project

1. Replace `your_mongodb_connection_string_here` in the `backend/.env` file with your actual MongoDB connection string.
2. Run the project using the following command:

   ```bash
   npm start
   ```

3. The frontend will run on `http://localhost:5173`, and the backend will run on `http://localhost:5000`.

---

## Customization

- Add your MongoDB models in the `backend/models` folder.
- Create API routes in the `backend/routes` folder.
- Build your React components in the `frontend/src` folder.

---

## Dependencies

- **Backend**: Express, Mongoose, CORS, dotenv
- **Frontend**: React, Vite, Tailwind CSS

---

## Troubleshooting

- If the frontend or backend fails to start, ensure all dependencies are installed by running `npm install` in both the `frontend` and `backend` folders.
- Make sure MongoDB is running and the connection string in `.env` is correct.

---

Happy coding! 🚀

---
