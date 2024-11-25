# R Programming Notes: An Interactive Introduction

Welcome to this interactive guide for exploring the basics of **R Programming**! Below, you'll find notes on using R as a calculator, performing vector operations, working with matrices, and tackling specific tasks.

---

## Part 1: **R as an Interactive Calculator**
R can be used to perform simple arithmetic calculations. Try the following examples in your R console:

```R
# Basic Arithmetic
2 + 3        # Addition
6 / 3        # Division
(3 * 8) / (2 * 3)  # Combined operations
log(12)      # Natural logarithm
sqrt(121)    # Square root

# Variables and Assignments
x <- 8 + 7   # Assigning a value to x
x            # Display x
x <- 5
y <- 16

# Operations with Variables
x + y        # Addition
x - y        # Subtraction
x * y        # Multiplication
y / x        # Division
y %/% x      # Integer Division
y %% x       # Modulus
y ^ x        # Power

# Logical Comparisons
x < y        # Less than
x > y        # Greater than
x <= 5       # Less than or equal to
y >= 20      # Greater than or equal to
y == 16      # Equality check
x != 5       # Not equal to
```

---

## **Operations on Vectors**
Vectors in R are created using the `c()` function (concatenate). Operations are performed element-wise.

```R
# Example Vectors
x <- c(2, 8, 3)
y <- c(6, 4, 1)

# Operations on Vectors
x + y        # Element-wise addition
x > y        # Element-wise comparison
```

---

## Part 2: **Matrices in R**
Matrices are 2D arrays of elements with the same type. Use the `matrix()` function to create them.

### **Creating Matrices**
```R
# Creating a Matrix
B <- matrix(c(1, 2, 3, 4, 5, 6), nrow = 2, ncol = 3)
C <- matrix(c(7, 8, 9, 10, 11, 12), nrow = 2, ncol = 3)

# Access Rows and Columns
nrow(B)      # Number of rows
ncol(B)      # Number of columns

# Creating by Rows
B <- matrix(c(1, 2, 3, 4, 5, 6), nrow = 2, ncol = 3, byrow = TRUE)
C <- matrix(c(7, 8, 9, 10, 11, 12), nrow = 2, ncol = 3, byrow = TRUE)
```

### **Operations on Matrices**
```R
# Matrix Addition
B <- matrix(c(1, 2 + 3i, 5.4, 3, 4, 5), nrow = 2, ncol = 3)
C <- matrix(c(2, 0i, 0.1, 3, 4, 5), nrow = 2, ncol = 3)
print(B + C)
```

---

## **Tasks**
### 1. **Prepare Two 4×4 Matrices and Show Addition and Subtraction**
```R
P <- matrix(1:16, nrow = 4)
Q <- matrix(17:32, nrow = 4)

# Addition and Subtraction
P + Q
P - Q
```

### 2. **Prepare a 3×4 Matrix**
```R
A <- matrix(1:12, nrow = 3, ncol = 4)
A
```

### 3. **Prepare a 4×2 Matrix**
```R
B <- matrix(13:20, nrow = 4, ncol = 2)
B
```

### 4. **Show the Multiplication of A and B**
```R
# Matrix Multiplication
A %*% B
```

### 5. **Prepare Two 4×4 Matrices with Imaginary Numbers**
```R
M1 <- matrix(c(1 + 1i, 2 + 2i, 3 + 3i, 4 + 4i, 5 + 5i, 6 + 6i, 7 + 7i, 8 + 8i,
                9 + 9i, 10 + 10i, 11 + 11i, 12 + 12i, 13 + 13i, 14 + 14i, 15 + 15i, 16 + 16i),
             nrow = 4)
M2 <- matrix(c(16 + 1i, 15 + 2i, 14 + 3i, 13 + 4i, 12 + 5i, 11 + 6i, 10 + 7i, 9 + 8i,
                8 + 9i, 7 + 10i, 6 + 11i, 5 + 12i, 4 + 13i, 3 + 14i, 2 + 15i, 1 + 16i),
             nrow = 4)
```

### 6. **Prepare a Matrix with First 36 Natural Numbers (6×6)**
```R
NaturalMatrix <- matrix(1:36, nrow = 6, ncol = 6)
NaturalMatrix
```

### 7. **Find the Determinant of Matrices**
```R
# Determinant of a 3×3 Matrix
M3 <- matrix(c(3, 2, 1, 2, 3, 1, 1, 2, 3), nrow = 3)
det(M3)

# Determinant of a 4×4 Matrix
M4 <- matrix(c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16), nrow = 4)
det(M4)
```

### 8. **Find the Transpose of a 3×4 Matrix**
```R
# Transpose
TransposeMatrix <- t(A)
TransposeMatrix
```

---

### **Happy Coding in R!**
