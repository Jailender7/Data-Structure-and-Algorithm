# Singly Linked List in C++

This project demonstrates the implementation of a **Singly Linked List** in C++. The program provides basic operations like insertion, deletion, and traversal of nodes in the list.

## 🔧 Features

- Insert node at the **beginning**
- Insert node at the **end**
- Insert node at a **specific position**
- Delete node from the **beginning**
- Delete node from the **end**
- Delete node from a **specific position**
- **Traverse and display** the entire linked list

---

## 📁 File Structure

- `main.cpp`: Contains the full implementation of the linked list operations along with a demonstration in the `main()` function.

---

## 🧠 Class Structure

### `node` Class

Represents a single element (node) in the linked list.

```cpp
class node {
public:
    int data;
    node* next;

    node() {
        next = NULL;
    }
};
