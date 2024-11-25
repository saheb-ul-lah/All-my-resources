Below is a complete `README.md` file for the Northwest Corner Method program written in C.

```markdown
# Northwest Corner Method (NWC) in C

## Overview

The **Northwest Corner Method (NWC)** is a mathematical approach used to find an initial feasible solution for transportation problems. It is named "Northwest Corner" because the allocation process begins at the top-left (northwest) corner of the cost matrix. 

This program implements the NWC method in C to calculate the transportation cost for distributing supplies from sources to meet demands at destinations.

---

## Features

- Accepts a **cost matrix**, **supply array**, and **demand array** as inputs.
- Computes an initial feasible solution using the **Northwest Corner Method**.
- Displays the **allocation matrix** and calculates the **total transportation cost**.

---

## Algorithm Steps

1. **Initialize the problem**:
   - Define the supply and demand arrays.
   - Create a cost matrix representing the cost of transporting from each source to each destination.

2. **Iterate through the cost matrix**:
   - Start at the top-left corner (0,0) of the matrix.
   - Compare the supply and demand at the current position:
     - If the supply is less than the demand, allocate the supply, reduce the demand, and move down to the next row.
     - If the supply is greater than the demand, allocate the demand, reduce the supply, and move right to the next column.
     - If the supply equals the demand, allocate the value and move diagonally (to the next row and column).

3. **Repeat the process**:
   - Continue allocating until all supplies and demands are met.

4. **Compute the total cost**:
   - Multiply the allocated quantities by the respective costs and sum them up.

---

## Program Input and Output

### Input:
1. **Cost Matrix**: A 2D array containing the transportation costs between sources and destinations.
2. **Supply Array**: An array representing the available supply at each source.
3. **Demand Array**: An array representing the required demand at each destination.

### Output:
1. **Cost Matrix with Supply and Demand**: Displays the input matrix alongside the supply and demand values.
2. **Allocation Matrix**: Shows the allocated values at each cell.
3. **Total Transportation Cost**: Outputs the total cost of transportation.

---

## Example

### Problem Setup:
- **Supply**: `[20, 30, 25]`
- **Demand**: `[10, 25, 15, 25]`
- **Cost Matrix**:
  ```
  8   6   10   9
  9   12  13   7
  14  9   16   5
  ```

### Output:
- **Cost Matrix with Supply and Demand**:
  ```
    8    6   10    9   |  20
    9   12   13    7   |  30
   14    9   16    5   |  25
  ----------------------------
   10   25   15   25
  ```

- **Allocation Matrix**:
  ```
   10   10    0    0
    0   15   15    0
    0    0    0   25
  ```

- **Total Transportation Cost**: `665`

---

## Code

Below is the full C implementation of the Northwest Corner Method.

```c
#include <stdio.h>

int main() {
    int c[20][20], i, j, m, n, dem[20], sup[20], sum = 0, al[20][20];

    printf("\nEnter the number of rows (supply) and columns (demand): ");
    scanf("%d%d", &m, &n);

    // Initialize allocation matrix to 0
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            al[i][j] = 0;
        }
    }

    // Input cost matrix
    printf("\nEnter the cost matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    // Input demand and supply arrays
    printf("\nEnter the demand array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &dem[i]);
    }

    printf("\nEnter the supply array:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &sup[i]);
    }

    // Display the input matrix
    printf("\nCost Matrix with Supply and Demand:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", c[i][j]);
        }
        printf("| %3d\n", sup[i]);
    }
    printf("----");
    for (i = 0; i < n; i++) {
        printf("----");
    }
    printf("\n");
    for (j = 0; j < n; j++) {
        printf("%3d ", dem[j]);
    }
    printf("\n");

    // Apply the Northwest Corner Method
    for (i = 0, j = 0; i < m && j < n; ) {
        if (sup[i] < dem[j]) {
            al[i][j] = sup[i];
            sum += c[i][j] * sup[i];
            dem[j] -= sup[i];
            sup[i] = 0;
            i++;
        } else if (sup[i] > dem[j]) {
            al[i][j] = dem[j];
            sum += c[i][j] * dem[j];
            sup[i] -= dem[j];
            dem[j] = 0;
            j++;
        } else {
            al[i][j] = sup[i];
            sum += c[i][j] * sup[i];
            sup[i] = 0;
            dem[j] = 0;
            i++;
            j++;
        }
    }

    // Display allocation matrix
    printf("\nAllocation Matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", al[i][j]);
        }
        printf("\n");
    }

    // Display total cost
    printf("\nTotal transportation cost: %d\n", sum);

    return 0;
}
```

---

## How to Run

1. Copy the code into a file named `nwc.c`.
2. Compile the program using a C compiler:
   ```bash
   gcc nwc.c -o nwc
   ```
3. Run the compiled program:
   ```bash
   ./nwc
   ```
4. Input the cost matrix, supply, and demand as prompted.

---

## Notes

- Ensure the total supply equals the total demand; otherwise, you may need to add a dummy row/column with zero cost.
- This program assumes integer values for simplicity. Modify as needed for floating-point costs.

---

## License

This project is open-source and available under the MIT License.
```
