# Create a new project directory and navigate into it (Remember toreplace the mern-project with your project name or simply remove the below line)
mkdir mern-project && cd mern-project

# Initialize a new Node.js project for the backend
mkdir backend && cd backend && npm init -y && npm install express cors mongoose dotenv && cd ..

# Create a new Vite React app for the frontend
npm create vite@latest frontend -- --template react
cd frontend && npm install && npm install -D tailwindcss postcss autoprefixer && npx tailwindcss init -p

# Configure Tailwind CSS
echo "/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [
    './index.html',
    './src/**/*.{js,ts,jsx,tsx}',
  ],
  theme: {
    extend: {},
  },
  plugins: [],
}" > tailwind.config.js

# Add Tailwind to your CSS
echo "@tailwind base;
@tailwind components;
@tailwind utilities;" > src/index.css

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
