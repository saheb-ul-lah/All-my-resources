## **Linear Programming in R with `lpSolve`**

Linear programming (LP) is a mathematical method used to achieve the best outcome (like maximum profit or minimum cost) given a set of constraints. The `lpSolve` package in R is commonly used to solve LP problems. Below, we’ll discuss:
1. **Setting Up `lpSolve` in R**: Installing and using the package.
2. **Understanding Key Components**: How to define the objective function, constraints, and constraint directions.
3. **Two Worked Examples**: Code explanations for two specific linear programming problems.

---

### **1. Setting Up `lpSolve`**

First, install and load `lpSolve`:

```r
install.packages("lpSolve")  # Install lpSolve (if not installed)
library(lpSolve)  # Load the package
```

`lpSolve` allows us to define an objective function, set constraints, and solve LP problems by maximizing or minimizing the objective.

---

### **2. Key Components of an LP Code in R**

In any LP problem, we generally need the following:

- **Objective Function (`obj.fun`)**: The equation we want to maximize or minimize.
- **Constraints (`constr`)**: A matrix that includes the coefficients of each variable in each constraint.
- **Constraint Directions (`constr.dir`)**: A vector specifying if each constraint is `<=`, `>=`, or `=` to the right-hand side.
- **Right-Hand Side (`rhs`)**: The vector that provides the right-hand side values for each constraint.

Now, let’s see how these components work in each problem.

---

### **3. Example 1 Code Explanation**

This example demonstrates an LP problem where the goal is to **maximize the objective function**.

#### **Problem Definition**
- **Objective Function**: \( z = 20x_1 + 60x_2 \)
- **Constraints**:
  1. \( 30x_1 + 20x_2 \leq 2700 \)
  2. \( 5x_1 + 10x_2 \leq 850 \)
  3. \( x_1 + x_2 \leq 95 \)
  4. \( x_1, x_2 \geq 0 \)

#### **Code**:
```r
install.packages("lpSolve")      # Install lpSolve (if not installed)
library("lpSolve")               # Load lpSolve package

obj.fun <- c(20, 60)             # Objective function: maximize 20x1 + 60x2

constr <- matrix(c(30, 20,       # Coefficients for constraint 1
                   5, 10,        # Coefficients for constraint 2
                   1, 1),        # Coefficients for constraint 3
                 ncol = 2, byrow = TRUE)

constr.dir <- c("<=", "<=", "<=")  # Constraint directions: all are "<="

rhs <- c(2700, 850, 95)            # Right-hand side values for each constraint

prod.sol <- lp("max", obj.fun, constr, constr.dir, rhs, compute.sens=TRUE)

cat("Success: the objective function is", prod.sol$objval, "\n")
prod.sol$solution                 # Display solution values for x1 and x2
```

#### **Explanation of Each Line**:
1. `obj.fun <- c(20, 60)`: Specifies the coefficients of \(x_1\) and \(x_2\) in the objective function.
2. `constr <- matrix(...)`: Creates a matrix to define the constraint equations.
3. `constr.dir <- c("<=", "<=", "<=")`: Defines the direction (`<=`) for each constraint.
4. `rhs <- c(2700, 850, 95)`: Specifies the right-hand side values for each constraint.
5. `prod.sol <- lp(...)`: Solves the LP problem, with `"max"` specifying maximization.
6. `prod.sol$objval`: Prints the optimal value of the objective function.
7. `prod.sol$solution`: Shows the values of \(x_1\) and \(x_2\) that maximize \( z \).

---

### **4. Example 2 Code Explanation**

This example also demonstrates an LP problem aiming to **maximize the objective function**.

#### **Problem Definition**
- **Objective Function**: \( z = 20x_1 + 10x_2 \)
- **Constraints**:
  1. \( x_1 + 2x_2 \leq 40 \)
  2. \( 3x_1 + x_2 \leq 30 \)
  3. \( 4x_1 + 3x_2 \geq 60 \)
  4. \( x_1, x_2 \geq 0 \)

#### **Code**:
```r
install.packages("lpSolve")      # Install lpSolve (if not installed)
library("lpSolve")               # Load lpSolve package

obj.fun <- c(20, 10)             # Objective function: maximize 20x1 + 10x2

constr <- matrix(c(1, 2,         # Coefficients for constraint 1
                   3, 1,         # Coefficients for constraint 2
                   -4, -3),      # Coefficients for constraint 3 (inequality reversed)
                 ncol = 2, byrow = TRUE)

constr.dir <- c("<=", "<=", ">=")  # Constraint directions

rhs <- c(40, 30, -60)              # Right-hand side values for constraints

prod.sol <- lp("max", obj.fun, constr, constr.dir, rhs, compute.sens=TRUE)

cat("Success: the objective function is", prod.sol$objval, "\n")
prod.sol$solution                 # Display solution values for x1 and x2
```

#### **Explanation of Each Line**:
1. `obj.fun <- c(20, 10)`: Specifies the coefficients for the objective function.
2. `constr <- matrix(...)`: Defines the constraint coefficients matrix.
3. `constr.dir <- c("<=", "<=", ">=")`: Defines the directions of each constraint.
4. `rhs <- c(40, 30, -60)`: Provides the right-hand side values (note the negative sign for `>=` constraint).
5. `prod.sol <- lp(...)`: Solves the LP problem with `"max"` to specify maximization.
6. `prod.sol$objval`: Prints the maximum value of \( z \).
7. `prod.sol$solution`: Shows the optimal values of \( x_1 \) and \( x_2 \).

---

### **Summary**

Each code example illustrates how to:
- Define an objective function (`obj.fun`).
- Set up constraint coefficients (`constr`), directions (`constr.dir`), and right-hand sides (`rhs`).
- Use `lp("max", ...)` to solve the maximization problem.

The results will show the **optimal value** of the objective function and the **values of variables** that achieve this optimum while meeting all constraints.

