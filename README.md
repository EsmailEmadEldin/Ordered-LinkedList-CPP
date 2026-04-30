# 🔗 Ordered Linked List

A **sorted linked list implementation** in C++ with duplicate tracking using a counter-based node design. Supports insertion in sorted order, deletion, descending display, max removal, and bulk generation from arrays.

---

## 📌 About

This project was built as a data structures assignment to demonstrate the practical use of **ordered linked lists** in C++. Instead of storing duplicate values as separate nodes, each node carries a `ctr` (counter) field that tracks how many times a value appears — making insertions and deletions more memory-efficient.

---

## 🛠️ How It Works

Each node stores three fields:

| Field | Role |
|-------|------|
| `info` | The integer value stored in the node |
| `next` | Pointer to the next node in the list |
| `ctr` | Count of how many times this value appears |

### Key Operations

| Function | Description |
|----------|-------------|
| `addinorder(item)` | Inserts in sorted (ascending) position; increments `ctr` if duplicate |
| `display()` | Prints all elements in ascending order (repeats based on `ctr`) |
| `deletevalue(item)` | Decrements `ctr` or removes node if `ctr` reaches 0 |
| `displayDescending()` | Prints all elements in descending order |
| `removemax()` | Finds and fully removes the maximum element |
| `generateFromArray(arr, size)` | Bulk-inserts elements from an array |
| `clearr()` | Frees all nodes and empties the list |

---

## 📁 Project Structure

```
Ordered-LinkedList-CPP/
│
├── src/
│   └── main.cpp        # Node and OrderedLL classes + test cases
├── README.md           # Project documentation
└── .gitignore          # Ignores compiled binaries
```

---

## ▶️ How to Run

### Prerequisites
- A C++ compiler (g++, clang++, MSVC, etc.)

### Compile & Run (Linux / macOS)
```bash
g++ -o ordered_ll src/main.cpp
./ordered_ll
```

### Compile & Run (Windows)
```bash
g++ -o ordered_ll.exe src/main.cpp
ordered_ll.exe
```

---

## 🖥️ Sample Output

```
 CASE ONE ( INSERTION ELEMENTS IN LIST ) :
 ELEMENTS: 1 3 3 5 9

 CASE TWO ( INSERTION DUPLICATES ELEMENTS IN LIST ) :
 ELEMENTS: 1 1 3 3 5 5 9

 CASE THREE ( DELETE AN ELEMENTS FROM THE LIST ) :
 ELEMENTS: 1 1 3 3 5 9  ← one 5 removed, one 9 removed

 CASE FOUR ( DISPLAY THE ELEMENTS IN DESCENDING IN THE LIST ) :
 ELEMENTS: 9 5 3 3 1 1

 CASE FIVE ( REMOVE THE MAXIMUM ELEMENT IN THE LIST ) :
 ELEMENTS: 1 1 3 3 5

 CASE SIX ( GENERATING FROM THE ARRAY ) :
 ELEMENTS: 1 1 3 3 5 5 5 8 10 10 10

 CASE SEVEN ( CLEAR THE ELEMENTS IN THE LIST ) :
 ELEMENTS: EMPTY LIST
```

---

## 🧪 Test Cases Covered

The `main()` function walks through seven test cases:

1. **Basic insertion** — inserts 5 values in unsorted order; list self-sorts
2. **Duplicate handling** — inserting existing values increments their counter
3. **Deletion** — removes one occurrence of a value (or the whole node if `ctr` = 1)
4. **Descending display** — prints all elements from largest to smallest
5. **Remove maximum** — fully removes all occurrences of the largest value
6. **Generate from array** — bulk-loads `{5, 5, 8, 10, 10, 10}` into the list
7. **Clear** — deallocates all nodes and empties the list

---

## 🧠 Concepts Demonstrated

- **Ordered/Sorted Linked List** — maintains ascending order on every insertion
- **Counter-based duplicate tracking** — avoids redundant nodes for repeated values
- **Dynamic memory management** — manual `new`/`delete` with no memory leaks
- **In-place traversal** — all operations run in O(n) without extra data structures (except `displayDescending`)
- **Edge case handling** — empty list checks, head insertion, tail insertion, mid-list operations

---

## 👤 Author

**Esmail Emad El-Din Mohamed**  
Cairo University — Computer Science & Artificial Intelligence

---

## 📜 License

This project is open source and available under the [MIT License](LICENSE).
