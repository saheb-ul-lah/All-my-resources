
 **Shadcn UI Cheatsheet**
#Reference:
```bash
https://ui.shadcn.com/docs/installation/vite
```

#Issues that may arise:
```bash
https://stackoverflow.com/questions/78934468/shadcn-ui-commands-on-terminal-is-not-working
```

Welcome to your ultimate guide for integrating **Shadcn UI** into your React projects! This cheatsheet provides a step-by-step approach to help you understand and utilize Shadcn UI effectively.

---

## **1. Introduction to Shadcn UI**

**Shadcn UI** is a React component library that offers a collection of customizable components built with Tailwind CSS, enabling the creation of modern and beautiful interfaces.

---

## **2. Installation**

### **Install Shadcn UI**
To start using Shadcn UI, run the following command:
```bash
npm install shadcn
```

### **Install Peer Dependencies**
Ensure that you have Tailwind CSS and its dependencies set up:
```bash
npm install tailwindcss postcss autoprefixer
```

---

## **3. Setup and Configuration**

### **Configure Tailwind CSS**
Ensure you have a `tailwind.config.js` file with the necessary content paths:
```js
module.exports = {
  content: [
    './src/**/*.{js,jsx,ts,tsx}', // Add paths to your components
    './node_modules/@shadcn/ui/**/*.{js,jsx,ts,tsx}', // Include Shadcn UI components
  ],
  theme: {
    extend: {},
  },
  plugins: [],
};
```

### **Create Global CSS File**
In your `styles` directory, create a file `globals.css` and add:
```css
@tailwind base;
@tailwind components;
@tailwind utilities;
```

### **Import Global CSS**
Make sure to import the global CSS in your main entry file (e.g., `index.js` or `main.jsx`):
```js
import './styles/globals.css';
```

---

## **4. Basic Usage**

### **Importing Components**
Shadcn UI offers a variety of components. Here’s how to use a button:
```jsx
import './App.css';
import './globals.css';
import { Button } from './components/ui/button'; // Updated import

const App = () => (
  <div className="text-center mt-5">
    <Button>Click Me</Button>
    <h1>Hello world!</h1>
  </div>
);

export default App;
```

### **Button Variants**
You can choose from different variants:
- `variant="primary"`
- `variant="secondary"`
- `variant="danger"`

### **Customizing Button Size**
Set sizes using the `size` prop:
```jsx
<Button size="large">Large Button</Button>
<Button size="small">Small Button</Button>
```

---

## **5. Styling and Theming**

### **Custom Themes**
You can create custom themes using Tailwind’s configuration:
```js
module.exports = {
  theme: {
    extend: {
      colors: {
        'custom-blue': '#1e40af',
      },
    },
  },
};
```

### **Using Custom Colors in Components**
```jsx
<Button className="bg-custom-blue">Custom Color Button</Button>
```

---

## **6. Layout Components**

### **Grid Layouts**
Create grid layouts easily:
```jsx
import { Grid } from './components/ui/grid'; // Example import

const App = () => (
  <Grid>
    <div className="col-span-4">Column 1</div>
    <div className="col-span-8">Column 2</div>
  </Grid>
);
```

### **Flexbox Layout**
Utilize flex properties:
```jsx
<div className="flex space-x-4">
  <Button>Button 1</Button>
  <Button>Button 2</Button>
</div>
```

---

## **7. Forms and Inputs**

### **Input Components**
Use input components for forms:
```jsx
import { Input } from './components/ui/input';

const Form = () => (
  <form>
    <Input placeholder="Enter your name" />
    <Button type="submit">Submit</Button>
  </form>
);
```

### **Validation States**
Handle validation states using props:
```jsx
<Input error placeholder="This field is required" />
```

---

## **8. Modal Component**

### **Creating a Modal**
Shadcn UI provides a simple modal component:
```jsx
import { Modal } from './components/ui/modal'; // Example import

const App = () => (
  <Modal>
    <Modal.Header>Modal Title</Modal.Header>
    <Modal.Body>Modal Content</Modal.Body>
    <Modal.Footer>
      <Button onClick={closeModal}>Close</Button>
    </Modal.Footer>
  </Modal>
);
```

---

## **9. Toast Notifications**

### **Implementing Toasts**
Easily show toast notifications:
```jsx
import { Toast } from './components/ui/toast'; // Example import

const notify = () => {
  Toast.success("Your action was successful!");
};
```

---

## **10. Responsive Design**

### **Responsive Utilities**
Utilize responsive classes:
```jsx
<Button className="w-full md:w-1/2">Responsive Button</Button>
```

### **Breakpoints**
Shadcn UI components are responsive by default. Adjust layouts as needed using Tailwind's responsive utilities.

---

## **11. Accessibility Features**

### **ARIA Attributes**
Use ARIA attributes when necessary:
```jsx
<Button aria-label="Close Modal">X</Button>
```

---

## **12. Customizing Components**

### **Styling Props**
Pass additional styles using the `className` prop:
```jsx
<Button className="bg-red-500">Custom Style Button</Button>
```

### **Using Slots for Customization**
Allow for additional customization using slots:
```jsx
<Button>
  <span>Custom Text</span>
  <img src="icon.png" alt="Icon" />
</Button>
```

---

## **13. Advanced Features**

### **Combining Components**
Combine different components to create complex UI elements:
```jsx
<Modal>
  <Modal.Header>
    <h2>Header</h2>
  </Modal.Header>
  <Modal.Body>
    <Input placeholder="Type something..." />
  </Modal.Body>
</Modal>
```

### **Theming with Context**
Set up a theme context for global styles:
```jsx
import { ThemeProvider } from './components/ui/theme-provider'; // Example import

const App = () => (
  <ThemeProvider>
    {/* Your Components */}
  </ThemeProvider>
);
```

---

## **14. Troubleshooting and Best Practices**

### **Common Issues**
- **Missing Styles**: Ensure your Tailwind CSS is properly configured and imported.
- **Component Not Rendering**: Verify that the component is correctly imported from Shadcn UI.

### **Best Practices**
- **Use PropTypes**: Validate props using PropTypes for correct usage.
- **Modular Components**: Keep components modular for easier maintenance and testing.

---

## **15. Conclusion**

This cheatsheet provides a comprehensive overview of using **Shadcn UI** in your React projects. With the combination of Tailwind CSS and Shadcn UI, you can create stunning, responsive interfaces efficiently.

--- 
