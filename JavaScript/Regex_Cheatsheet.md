A **comprehensive regex (regular expression) cheat sheet** to help you handle pattern matching for different scenarios. Regular expressions are powerful tools for string searching, pattern matching, and data validation.

---

## **Regex Syntax Overview**

### **Basic Syntax:**
| **Pattern**   | **Description**                         |
|---------------|-----------------------------------------|
| `.`           | Matches any single character except newline |
| `^`           | Anchors the pattern to the start of the string |
| `$`           | Anchors the pattern to the end of the string |
| `*`           | Matches 0 or more occurrences of the preceding element |
| `+`           | Matches 1 or more occurrences of the preceding element |
| `?`           | Matches 0 or 1 occurrence of the preceding element |
| `|`           | Alternation (OR) between patterns |
| `()`          | Groups expressions (used for capturing) |
| `[]`          | Matches a character set (e.g., `[abc]` matches `a`, `b`, or `c`) |
| `{}`          | Quantifier specifying how many occurrences (e.g., `{2,4}` means between 2 and 4 times) |
| `\`           | Escapes special characters (e.g., `\.` matches a literal `.`) |

---

## **Character Classes**
| **Pattern**   | **Description**                         |
|---------------|-----------------------------------------|
| `[abc]`       | Matches any one of `a`, `b`, or `c`     |
| `[^abc]`      | Matches any character except `a`, `b`, or `c` |
| `[a-z]`       | Matches any lowercase letter            |
| `[A-Z]`       | Matches any uppercase letter            |
| `[0-9]`       | Matches any digit (0 to 9)              |
| `\d`          | Matches any digit (same as `[0-9]`)     |
| `\D`          | Matches any non-digit                   |
| `\w`          | Matches any word character (alphanumeric and underscore) |
| `\W`          | Matches any non-word character          |
| `\s`          | Matches any whitespace character (space, tab, newline) |
| `\S`          | Matches any non-whitespace character    |

---

## **Quantifiers**
| **Pattern**   | **Description**                             |
|---------------|---------------------------------------------|
| `*`           | Matches 0 or more occurrences               |
| `+`           | Matches 1 or more occurrences               |
| `?`           | Matches 0 or 1 occurrence                   |
| `{n}`         | Matches exactly `n` occurrences             |
| `{n,}`        | Matches `n` or more occurrences             |
| `{n,m}`       | Matches between `n` and `m` occurrences     |

---

## **Anchors & Boundaries**
| **Pattern**   | **Description**                             |
|---------------|---------------------------------------------|
| `^`           | Matches the start of the string             |
| `$`           | Matches the end of the string               |
| `\b`          | Matches a word boundary (e.g., space or punctuation) |
| `\B`          | Matches non-word boundary                   |
| `(?=...)`     | Positive lookahead (matches if the following pattern is found) |
| `(?!...)`     | Negative lookahead (matches if the following pattern is **not** found) |

---

## **Grouping & Backreferences**
| **Pattern**   | **Description**                             |
|---------------|---------------------------------------------|
| `(...)`       | Captures matched text into a group          |
| `(?:...)`     | Non-capturing group                         |
| `\1`, `\2`, ... | Refers to the first, second, etc. capturing group |
| `(?<name>...)`| Named capturing group (e.g., `(?<year>\d{4})`) |

---

## **Common Regex Patterns**

### **Email Validation:**
```regex
^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$
```

### **Phone Number Validation (US Format):**
```regex
^\(?\d{3}\)?[-.\s]?\d{3}[-.\s]?\d{4}$
```

### **URL Validation:**
```regex
^(https?|ftp):\/\/[^\s/$.?#].[^\s]*$
```

### **IPv4 Address Validation:**
```regex
^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$
```

### **Date (YYYY-MM-DD) Validation:**
```regex
^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$
```

### **Time (HH:MM) Validation:**
```regex
^([01]?[0-9]|2[0-3]):[0-5][0-9]$
```

### **HTML Tags Matching:**
```regex
<([a-zA-Z][a-zA-Z0-9]*)\b[^>]*>(.*?)<\/\1>
```

### **Username Validation (Alphanumeric, 3-16 characters):**
```regex
^[a-zA-Z0-9_]{3,16}$
```

---

## **Advanced Examples**

### **Match any 3-digit number:**
```regex
\d{3}
```

### **Match HTML comments:**
```regex
<!--(.*?)-->
```

### **Match words with capital letters:**
```regex
\b[A-Z][a-z]*\b
```

### **Extract a specific date from text:**
```regex
(?<=\bDate:\s)(\d{4}-\d{2}-\d{2})
```

### **Lookahead to ensure "cat" is followed by "dog":**
```regex
cat(?=dog)
```

### **Negative Lookahead to exclude patterns:**
```regex
^(?!.*badword).*
```

---

## **Flags**
| **Flag**    | **Description**                           |
|-------------|-------------------------------------------|
| `g`         | Global search (finds all matches)         |
| `i`         | Case-insensitive search                   |
| `m`         | Multiline mode (anchors `^` and `$` match start and end of lines) |
| `s`         | Dotall mode (dot `.` matches newline as well) |
| `x`         | Free-spacing mode (ignores unescaped spaces and comments) |

---

## **Practice Examples**

### **Extract domain from an email:**
```regex
(?<=@)[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}
```

### **Validate password (At least 1 uppercase, 1 lowercase, 1 number, 1 special character, 8-20 characters):**
```regex
^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,20}$
```

### **Find all duplicate words in a sentence:**
```regex
\b(\w+)\b(?=.*\b\1\b)
```

---

## **Resources**

- **Regex101**: [https://regex101.com](https://regex101.com) – A helpful tool to test regex patterns.
- **Regular Expressions Info**: [https://www.regular-expressions.info](https://www.regular-expressions.info) – Detailed regex documentation.

---

This cheat sheet should cover a wide range of scenarios for regex, from basic string searches to complex validations. Happy pattern matching!
