## **Step 1: What is Context API and Why is it Needed?**

### **1.1 The Problem Context API Solves**

In React, data is passed from parent to child components via **props**. This works fine for small apps, but as your app grows, passing props through multiple levels of components (called **prop drilling**) becomes messy and hard to manage.

For example:
```jsx
<App>
  <Header user={user} />
  <Main user={user} />
  <Footer user={user} />
</App>
```

Here, the `user` prop is being passed down to multiple components. If you have 10 levels of nesting, this becomes a nightmare.

### **1.2 The Solution: Context API**

Context API allows you to **share data globally** across your app without passing props manually at every level. It’s like a “global state” that any component can access.

---

## **Step 2: Basic Usage of Context API**

### **2.1 Create a Context**

First, create a context using `React.createContext()`.

```jsx
// context/AuthContext.js
import React from 'react';

const AuthContext = React.createContext();
export default AuthContext;
```

#### **Explanation:**
- `React.createContext()` creates a new context object.
- This context will hold the global data (e.g., user authentication state).

---

### **2.2 Provide the Context**

Wrap your app (or a part of it) with the `Provider` component. This makes the context available to all child components.

```jsx
// App.js
import React, { useState } from 'react';
import AuthContext from './context/AuthContext';
import Header from './components/Header';
import Main from './components/Main';

function App() {
  const [user, setUser] = useState(null);

  return (
    <AuthContext.Provider value={{ user, setUser }}>
      <Header />
      <Main />
    </AuthContext.Provider>
  );
}

export default App;
```

#### **Explanation:**
- The `Provider` component wraps the app and provides the `value` (in this case, `user` and `setUser`) to all child components.
- Any component inside the `Provider` can access this value.

---

### **2.3 Consume the Context**

Use the `useContext` hook to access the context in any component.

```jsx
// components/Header.js
import React, { useContext } from 'react';
import AuthContext from '../context/AuthContext';

const Header = () => {
  const { user } = useContext(AuthContext);

  return (
    <header>
      <h1>Welcome, {user ? user.name : 'Guest'}</h1>
    </header>
  );
};

export default Header;
```

#### **Explanation:**
- `useContext(AuthContext)` gives you access to the `value` provided by the `Provider`.
- Here, we’re accessing the `user` object to display the user’s name.

---

## **Step 3: Intermediate Usage of Context API**

### **3.1 Multiple Contexts**

You can use multiple contexts in your app. For example, one for authentication and another for theme.

```jsx
// context/ThemeContext.js
import React from 'react';

const ThemeContext = React.createContext();
export default ThemeContext;
```

```jsx
// App.js
import React, { useState } from 'react';
import AuthContext from './context/AuthContext';
import ThemeContext from './context/ThemeContext';
import Header from './components/Header';

function App() {
  const [user, setUser] = useState(null);
  const [theme, setTheme] = useState('light');

  return (
    <AuthContext.Provider value={{ user, setUser }}>
      <ThemeContext.Provider value={{ theme, setTheme }}>
        <Header />
      </ThemeContext.Provider>
    </AuthContext.Provider>
  );
}

export default App;
```

#### **Explanation:**
- Now, you have two contexts: `AuthContext` and `ThemeContext`.
- You can access both contexts in any component using `useContext`.

---

### **3.2 Custom Context Hook**

To make your code cleaner, create a custom hook for accessing the context.

```jsx
// context/useAuth.js
import { useContext } from 'react';
import AuthContext from './AuthContext';

export const useAuth = () => {
  return useContext(AuthContext);
};
```

Now, instead of `useContext(AuthContext)`, you can use `useAuth()`.

```jsx
// components/Header.js
import React from 'react';
import { useAuth } from '../context/useAuth';

const Header = () => {
  const { user } = useAuth();

  return (
    <header>
      <h1>Welcome, {user ? user.name : 'Guest'}</h1>
    </header>
  );
};

export default Header;
```

#### **Explanation:**
- Custom hooks make your code more reusable and easier to read.

---

## **Step 4: Advanced Usage of Context API**

### **4.1 Context with Reducer**

For complex state management, combine Context API with `useReducer`.

```jsx
// context/AuthContext.js
import React, { useReducer } from 'react';

const AuthContext = React.createContext();

const initialState = { user: null };

function authReducer(state, action) {
  switch (action.type) {
    case 'LOGIN':
      return { user: action.payload };
    case 'LOGOUT':
      return { user: null };
    default:
      return state;
  }
}

export const AuthProvider = ({ children }) => {
  const [state, dispatch] = useReducer(authReducer, initialState);

  return (
    <AuthContext.Provider value={{ state, dispatch }}>
      {children}
    </AuthContext.Provider>
  );
};

export default AuthContext;
```

#### **Explanation:**
- `useReducer` is used to manage complex state logic.
- The `authReducer` handles actions like `LOGIN` and `LOGOUT`.

---

### **4.2 Using the Reducer Context**

```jsx
// App.js
import React from 'react';
import { AuthProvider } from './context/AuthContext';
import Header from './components/Header';

function App() {
  return (
    <AuthProvider>
      <Header />
    </AuthProvider>
  );
}

export default App;
```

```jsx
// components/Header.js
import React, { useContext } from 'react';
import AuthContext from '../context/AuthContext';

const Header = () => {
  const { state, dispatch } = useContext(AuthContext);

  const handleLogin = () => {
    dispatch({ type: 'LOGIN', payload: { name: 'John Doe' } });
  };

  const handleLogout = () => {
    dispatch({ type: 'LOGOUT' });
  };

  return (
    <header>
      <h1>Welcome, {state.user ? state.user.name : 'Guest'}</h1>
      {state.user ? (
        <button onClick={handleLogout}>Logout</button>
      ) : (
        <button onClick={handleLogin}>Login</button>
      )}
    </header>
  );
};

export default Header;
```

#### **Explanation:**
- The `dispatch` function is used to trigger state changes (e.g., login/logout).
- This is a more scalable way to manage state in large apps.

---

## **Step 5: Most Advanced Context API Usage**

### **5.1 Context with Async Actions**

Sometimes, you need to perform async operations (e.g., fetching data) in your context. Here’s how:

```jsx
// context/AuthContext.js
import React, { useReducer, useEffect } from 'react';
import axios from 'axios';

const AuthContext = React.createContext();

const initialState = { user: null, loading: true };

function authReducer(state, action) {
  switch (action.type) {
    case 'LOGIN':
      return { ...state, user: action.payload };
    case 'LOGOUT':
      return { ...state, user: null };
    case 'LOAD_USER':
      return { ...state, user: action.payload, loading: false };
    default:
      return state;
  }
}

export const AuthProvider = ({ children }) => {
  const [state, dispatch] = useReducer(authReducer, initialState);

  useEffect(() => {
    const fetchUser = async () => {
      try {
        const response = await axios.get('/api/user');
        dispatch({ type: 'LOAD_USER', payload: response.data });
      } catch (error) {
        console.error('Failed to fetch user', error);
      }
    };

    fetchUser();
  }, []);

  return (
    <AuthContext.Provider value={{ state, dispatch }}>
      {children}
    </AuthContext.Provider>
  );
};

export default AuthContext;
```

#### **Explanation:**
- The `useEffect` hook fetches the user data when the app loads.
- The `LOAD_USER` action updates the state with the fetched data.

---

### **5.2 Using Async Context**

```jsx
// components/Header.js
import React, { useContext } from 'react';
import AuthContext from '../context/AuthContext';

const Header = () => {
  const { state, dispatch } = useContext(AuthContext);

  if (state.loading) {
    return <div>Loading...</div>;
  }

  return (
    <header>
      <h1>Welcome, {state.user ? state.user.name : 'Guest'}</h1>
    </header>
  );
};

export default Header;
```

#### **Explanation:**
- The `loading` state ensures the app doesn’t render until the user data is fetched.

---

Now that you’ve mastered Context API from basic to advanced, you can explain:

1. **Why Context API is needed** (to avoid prop drilling).
2. **How to create and use contexts** (basic to advanced).
3. **How to combine Context API with `useReducer`** for complex state management.
4. **How to handle async operations** in Context API.
