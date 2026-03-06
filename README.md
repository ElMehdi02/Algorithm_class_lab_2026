# Algorithm_class_lab_2026
# COSC 300 – Advanced C++ Programming Projects

**Author:** El Mehdi Bensouda  
**Course:** COSC 300  
**Language:** C++  
**Semester:** Spring 2026  

---

## 📌 Overview

This repository contains a collection of programming projects completed for **COSC 300**.  

The purpose of these projects was to strengthen understanding of:

- Object-Oriented Programming (OOP)
- Dynamic memory management
- Pointers and pointer arithmetic
- C-strings
- Operator overloading
- Copy constructors & destructors
- Linked lists (custom DLL implementation)
- STL containers (std::list)
- Algorithm simulation (loan amortization, fraction sequences)

Each program demonstrates both conceptual understanding and practical implementation of core C++ principles.

---

## 📂 Projects Included

### 1️⃣ Loan Payment Simulation
- Simulates loan payoff month-by-month
- Applies interest before payment
- Prevents infinite loops when payment is too small
- Calculates total interest paid

**Concepts used:**  
loops, conditionals, floating-point calculations, simulation logic

---

### 2️⃣ Dynamic Array Processing
- Inserts integers while keeping array sorted
- Removes integers from dynamic array
- Manages memory using `new[]` and `delete[]`
- Uses pointer references (`int*&`) for resizing

**Concepts used:**  
dynamic memory, pointer manipulation, array resizing, algorithm logic

---

### 3️⃣ C-String Functions (Pointer-Based)
Custom implementations of:

- `strCmp` – compares two C-strings
- `strPbrk` – finds first matching character
- `ItoA` – converts integer to C-string

**Restrictions:**  
Only pointer notation used (no indexing).

**Concepts used:**  
pointer arithmetic, null-termination, manual string traversal

---

### 4️⃣ BigInteger Class
- Handles very large non-negative integers
- Stores numbers as dynamically allocated C-strings
- Implements:

  - `+`
  - `+=`
  - `++` (prefix & postfix)
  - `==`
  - `<`
  - Copy constructor
  - Destructor

**Concepts used:**  
deep copy, operator overloading, manual digit-by-digit arithmetic

---

### 5️⃣ F-Fractions (Stern-Brocot Style Sequence)
- Builds fraction sequence level-by-level
- Two implementations:

  - Custom Doubly Linked List (DLL)
  - `std::list` from STL

- Inserts mediant fraction between neighbors:
  \[
  \frac{a}{b}, \frac{c}{d} \rightarrow \frac{a+c}{b+d}
  \]

**Concepts used:**  
inheritance, templates, linked lists, iterators, algorithm simulation

---

## 🛠 Skills Demonstrated

- Manual memory management
- Deep vs shallow copy handling
- Proper Rule of Three implementation
- Debugging segmentation faults
- Understanding constructor/destructor order
- Operator overloading correctness
- Pointer safety and references
- Data structure design

---

## 🚀 How to Compile

Example (g++):

```bash
g++ filename.cpp -o program
./program
