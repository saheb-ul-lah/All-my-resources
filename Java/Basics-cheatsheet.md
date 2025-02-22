# **Java & DSA Cheatsheet for LeetCode**

Welcome to your ultimate Java and Data Structures & Algorithms (DSA) cheatsheet! This guide is designed to help you master Java concepts and DSA techniques required to solve LeetCode problems efficiently. It covers everything from basic syntax to advanced algorithms, data structures, and Java Standard Template Library (STL) equivalents.

---

## **1. Java Basics**

### **Hello World**
```java
public class Main {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```

### **Variables and Data Types**
```java
int num = 10;                  // Integer
double decimal = 10.5;         // Double
char letter = 'A';             // Character
boolean flag = true;           // Boolean
String text = "Hello";         // String
```

### **Type Casting**
```java
int num = 10;
double decimal = (double) num; // Explicit casting
int backToInt = (int) decimal; // Explicit casting
```

### **Input and Output**
```java
import java.util.Scanner;

Scanner sc = new Scanner(System.in);
int num = sc.nextInt();        // Read integer
String str = sc.next();        // Read string
System.out.println(num);       // Print integer
System.out.println(str);       // Print string
```

---

## **2. Control Flow**

### **If-Else**
```java
int num = 10;
if (num > 0) {
    System.out.println("Positive");
} else if (num < 0) {
    System.out.println("Negative");
} else {
    System.out.println("Zero");
}
```

### **Switch Case**
```java
int day = 3;
switch (day) {
    case 1:
        System.out.println("Monday");
        break;
    case 2:
        System.out.println("Tuesday");
        break;
    default:
        System.out.println("Invalid day");
}
```

### **Loops**
```java
// For Loop
for (int i = 0; i < 5; i++) {
    System.out.println(i);
}

// While Loop
int i = 0;
while (i < 5) {
    System.out.println(i);
    i++;
}

// Do-While Loop
int j = 0;
do {
    System.out.println(j);
    j++;
} while (j < 5);
```

---

## **3. Arrays**

### **1D Array**
```java
int[] arr = new int[5];        // Declaration
arr[0] = 10;                   // Initialization
int[] arr2 = {1, 2, 3, 4, 5};  // Declaration + Initialization
```

### **2D Array**
```java
int[][] matrix = new int[3][3]; // 3x3 matrix
matrix[0][0] = 1;               // Initialization
int[][] matrix2 = {{1, 2}, {3, 4}}; // Declaration + Initialization
```

### **Array Methods**
```java
int[] arr = {1, 2, 3};
int length = arr.length;       // Length of array
Arrays.sort(arr);              // Sort array
Arrays.fill(arr, 0);           // Fill array with 0
```

---

## **4. Strings**

### **String Basics**
```java
String str = "Hello";
int length = str.length();     // Length of string
char ch = str.charAt(0);       // Access character
String sub = str.substring(1, 3); // Substring
```

### **String Comparison**
```java
String str1 = "Hello";
String str2 = "World";
boolean isEqual = str1.equals(str2); // Compare strings
int compare = str1.compareTo(str2);  // Lexicographical comparison
```

### **String Manipulation**
```java
String str = "Hello";
String upper = str.toUpperCase();    // Convert to uppercase
String lower = str.toLowerCase();    // Convert to lowercase
String trimmed = str.trim();         // Remove leading/trailing spaces
String replaced = str.replace('H', 'h'); // Replace characters
```

---

## **5. Collections Framework**

### **ArrayList**
```java
import java.util.ArrayList;

ArrayList<Integer> list = new ArrayList<>();
list.add(10);                   // Add element
list.get(0);                    // Access element
list.set(0, 20);                // Update element
list.remove(0);                 // Remove element
int size = list.size();         // Size of list
```

### **LinkedList**
```java
import java.util.LinkedList;

LinkedList<Integer> list = new LinkedList<>();
list.add(10);                   // Add element
list.addFirst(5);               // Add at beginning
list.addLast(15);               // Add at end
list.removeFirst();             // Remove first element
list.removeLast();              // Remove last element
```

### **HashMap**
```java
import java.util.HashMap;

HashMap<String, Integer> map = new HashMap<>();
map.put("Alice", 25);           // Add key-value pair
map.get("Alice");               // Get value by key
map.containsKey("Alice");       // Check if key exists
map.remove("Alice");            // Remove key-value pair
```

### **HashSet**
```java
import java.util.HashSet;

HashSet<Integer> set = new HashSet<>();
set.add(10);                    // Add element
set.contains(10);               // Check if element exists
set.remove(10);                 // Remove element
```

---

## **6. Stack and Queue**

### **Stack**
```java
import java.util.Stack;

Stack<Integer> stack = new Stack<>();
stack.push(10);                 // Push element
stack.pop();                    // Pop element
stack.peek();                   // Peek top element
boolean isEmpty = stack.isEmpty(); // Check if stack is empty
```

### **Queue**
```java
import java.util.Queue;
import java.util.LinkedList;

Queue<Integer> queue = new LinkedList<>();
queue.add(10);                  // Add element
queue.poll();                   // Remove element
queue.peek();                   // Peek element
boolean isEmpty = queue.isEmpty(); // Check if queue is empty
```

---

## **7. Sorting and Searching**

### **Sorting Arrays**
```java
import java.util.Arrays;

int[] arr = {5, 3, 1, 4, 2};
Arrays.sort(arr);               // Sort array
Arrays.sort(arr, 1, 4);         // Sort subarray
```

### **Binary Search**
```java
int[] arr = {1, 2, 3, 4, 5};
int index = Arrays.binarySearch(arr, 3); // Binary search
```

---

## **8. Recursion**

### **Factorial**
```java
public int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
```

### **Fibonacci**
```java
public int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

---

## **9. Dynamic Programming**

### **Memoization**
```java
import java.util.HashMap;

HashMap<Integer, Integer> memo = new HashMap<>();

public int fib(int n) {
    if (n <= 1) return n;
    if (memo.containsKey(n)) return memo.get(n);
    memo.put(n, fib(n - 1) + fib(n - 2));
    return memo.get(n);
}
```

### **Tabulation**
```java
public int fib(int n) {
    int[] dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
```

---

## **10. Graph Algorithms**

### **BFS**
```java
import java.util.*;

public void bfs(Map<Integer, List<Integer>> graph, int start) {
    Queue<Integer> queue = new LinkedList<>();
    Set<Integer> visited = new HashSet<>();
    queue.add(start);
    visited.add(start);

    while (!queue.isEmpty()) {
        int node = queue.poll();
        System.out.println(node);
        for (int neighbor : graph.get(node)) {
            if (!visited.contains(neighbor)) {
                queue.add(neighbor);
                visited.add(neighbor);
            }
        }
    }
}
```

### **DFS**
```java
import java.util.*;

public void dfs(Map<Integer, List<Integer>> graph, int start, Set<Integer> visited) {
    visited.add(start);
    System.out.println(start);
    for (int neighbor : graph.get(start)) {
        if (!visited.contains(neighbor)) {
            dfs(graph, neighbor, visited);
        }
    }
}
```

---

## **11. Backtracking**

### **N-Queens**
```java
public List<List<String>> solveNQueens(int n) {
    List<List<String>> result = new ArrayList<>();
    char[][] board = new char[n][n];
    for (char[] row : board) Arrays.fill(row, '.');
    backtrack(result, board, 0);
    return result;
}

private void backtrack(List<List<String>> result, char[][] board, int row) {
    if (row == board.length) {
        result.add(constructBoard(board));
        return;
    }
    for (int col = 0; col < board.length; col++) {
        if (isValid(board, row, col)) {
            board[row][col] = 'Q';
            backtrack(result, board, row + 1);
            board[row][col] = '.';
        }
    }
}

private boolean isValid(char[][] board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.length; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

private List<String> constuctBoard(char[][] board) {
    List<String> res = new ArrayList<>();
    for (char[] row : board) {
        res.add(new String(row));
    }
    return res;
}
```

---

## **12. Advanced Data Structures**

### **Trie**
```java
class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    boolean isEndOfWord = false;
}

class Trie {
    private TrieNode root = new TrieNode();

    public void insert(String word) {
        TrieNode current = root;
        for (char ch : word.toCharArray()) {
            current = current.children.computeIfAbsent(ch, c -> new TrieNode());
        }
        current.isEndOfWord = true;
    }

    public boolean search(String word) {
        TrieNode current = root;
        for (char ch : word.toCharArray()) {
            current = current.children.get(ch);
            if (current == null) return false;
        }
        return current.isEndOfWord;
    }

    public boolean startsWith(String prefix) {
        TrieNode current = root;
        for (char ch : prefix.toCharArray()) {
            current = current.children.get(ch);
            if (current == null) return false;
        }
        return true;
    }
}
```

### **Segment Tree**
```java
class SegmentTree {
    int[] tree;
    int n;

    public SegmentTree(int[] nums) {
        n = nums.length;
        tree = new int[4 * n];
        build(nums, 0, 0, n - 1);
    }

    private void build(int[] nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            build(nums, 2 * node + 1, start, mid);
            build(nums, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    public void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }

    private void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, val);
            } else {
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    public int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    private int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, l, r) + query(2 * node + 2, mid + 1, end, l, r);
    }
}
```

---

## **13. Java STL Equivalents**

### **Priority Queue**
```java
import java.util.PriorityQueue;

PriorityQueue<Integer> minHeap = new PriorityQueue<>();
PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
minHeap.add(10);               // Add element
minHeap.poll();                // Remove and return smallest element
minHeap.peek();                // Peek smallest element
```

### **Deque**
```java
import java.util.ArrayDeque;

ArrayDeque<Integer> deque = new ArrayDeque<>();
deque.addFirst(10);            // Add at front
deque.addLast(20);             // Add at end
deque.removeFirst();           // Remove from front
deque.removeLast();            // Remove from end
deque.peekFirst();             // Peek front element
deque.peekLast();              // Peek end element
```

---

## **14. Miscellaneous**

### **Bit Manipulation**
```java
int num = 5;
int shifted = num << 1;        // Left shift
int andResult = num & 3;       // Bitwise AND
int orResult = num | 3;        // Bitwise OR
int xorResult = num ^ 3;       // Bitwise XOR
int notResult = ~num;          // Bitwise NOT
```

### **Math Utilities**
```java
int max = Math.max(10, 20);    // Maximum of two numbers
int min = Math.min(10, 20);    // Minimum of two numbers
double sqrt = Math.sqrt(16);   // Square root
double pow = Math.pow(2, 3);   // Power
```

---

This cheatsheet is your one-stop resource for mastering Java and DSA concepts. Use it to revise, practice, and solve LeetCode problems efficiently. Happy coding! 🚀
