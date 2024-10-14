```markdown
# 📝 Blog App

## 🚀 Project Description
This is a full-stack blog application built with **Next.js** for both the frontend and backend, **MongoDB** for the database, and **JWT** for authentication. 

### ✨ Features:
- 🔐 **User Authentication**: Signup and login with JWT-based authentication.
- 📝 **CRUD Operations**: Create, read, update, and delete blog posts.
- 🔒 **Protected Routes**: Certain actions (e.g., creating/deleting posts) are only available to logged-in users.
- 📡 **Backend API**: RESTful APIs for user authentication and managing blog posts.

---

## 🛠️ Tech Stack
- **Next.js**: A powerful React framework for building web applications.
- **MongoDB**: NoSQL database for storing users and posts.
- **Mongoose**: ODM library for MongoDB, making data modeling easy.
- **JWT (JSON Web Token)**: Secure, token-based authentication system.

---

## 🗂️ Folder Structure

```plaintext
📦 blog-app/
├── 📁 components/       # Reusable components (e.g., forms, buttons)
├── 📁 models/           # MongoDB models (Mongoose schemas)
├── 📁 pages/
│   ├── 📁 api/          # API routes (CRUD, authentication)
│   │   ├── 📁 auth/     # Login & Signup routes
│   │   └── 📁 posts/    # Post CRUD operations (create, read, delete)
│   ├── 📄 login.js      # Login page
│   ├── 📄 signup.js     # Signup page
│   └── 📄 index.js      # Home page (displays all blog posts)
├── 📁 utils/            # Utility functions (e.g., JWT verification)
└── 📄 README.md         # Project documentation
```

---

## 💻 How to Get Started

### 1. 🧬 Clone the Repository

```bash
git clone https://github.com/yourusername/blog-app
cd blog-app
```

### 2. 📦 Install Dependencies

```bash
npm install
```

### 3. 🔑 Set Up Environment Variables

Create a `.env` file in the root of your project with the following values:

```plaintext
MONGO_URI=your-mongodb-connection-uri
JWT_SECRET=your-secret-key
```

### 4. 🚀 Run the Development Server

```bash
npm run dev
```

The app will be live at **[http://localhost:3000](http://localhost:3000)** 🎉

---

## 📜 API Endpoints

Here’s a summary of the main backend API routes:

### 🔐 Authentication Routes (`/api/auth`)
- `POST /api/auth/signup` - Sign up a new user.
- `POST /api/auth/login` - Log in an existing user.

### 📝 Blog Post Routes (`/api/posts`)
- `GET /api/posts` - Fetch all blog posts.
- `POST /api/posts` - Create a new post (Protected).
- `DELETE /api/posts/[id]` - Delete a specific post (Protected).

---

## 🔨 Key Concepts and Code Breakdown

### 🔑 **JWT Authentication**

**JWT** (JSON Web Token) is used to protect routes, ensuring only authenticated users can create or delete posts. In the backend, the token is generated during login and then verified in the middleware before allowing access to protected routes.

```js
// Example middleware to protect routes
export const requireAuth = (handler) => {
  return async (req, res) => {
    const token = req.headers.authorization;  // Get token from request

    if (!token) {
      return res.status(401).json({ error: 'Unauthorized' });
    }

    try {
      const decoded = jwt.verify(token, process.env.JWT_SECRET);  // Verify token
      req.user = decoded;  // Attach user data to request
      return handler(req, res);  // Proceed with the request
    } catch (error) {
      return res.status(401).json({ error: 'Invalid token' });
    }
  };
};
```

### 🌐 **Frontend Fetch Example (Fetching Posts)**

Here’s how you can fetch posts from the backend using `fetch()` in **Next.js**:

```js
useEffect(() => {
  async function fetchPosts() {
    const res = await fetch('/api/posts');  // Make API request to backend
    const data = await res.json();          // Parse response as JSON
    setPosts(data);                         // Update state with fetched posts
  }
  fetchPosts();  // Call fetch function when component loads
}, []);
```

---

## ⚙️ Future Enhancements
- 📱 **Responsive Design**: Enhance mobile responsiveness using Tailwind CSS.
- 🏷️ **Tagging System**: Allow users to tag posts and filter them by tags.
- 💬 **Comments**: Add a comment system for users to engage with posts.

---

## 📝 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

### 🙏 Contributions & Feedback

Feel free to open issues or submit pull requests to improve this project! Contributions are always welcome.

---

### 🛠️ Setup Summary for Contributors

1. **Clone & Install**: Fork and clone the repo, then run `npm install`.
2. **Database Setup**: Add MongoDB connection URI in `.env`.
3. **Authentication**: Ensure `JWT_SECRET` is set in `.env`.

Happy coding! 👨‍💻👩‍💻
```
