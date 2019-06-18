name: linear-data-structures
class: center, middle

# Linear Data Structures

---
name: agenda

## Agenda

- [Agenda](#agenda)
- [Singly Linked Lists](#singly-linked-lists)
- [Stacks](#stacks)
- [Queues](#queues)
- [Memory Management](#memory-management)
- [Circular Singularly Linked Lists](#circular-singularly-linked-lists)
- [Doubly Linked Lists](#doubly-linked-lists)
- [Resources](#resources)

---
name: singly-linked-lists
class: middle

## Singly Linked Lists

---

### SLL: Why we need better ways to store data

Consider the array

.array[

| arr*  | 5   | 4   | 6   | 1   |     |
| ----- | --- | --- | --- | --- | --- |
| index | 0   | 1   | 2   | 3   |     |

]

--

What is the cost to insert into the front? Middle? Rear?

--

$$O(n), O(n), O(1)^*$$

*Using amortization.

--

What about deletions?

--

What if we used **non-contiguous** memory?

---

### SLL: How

- Non-Contiguous storage.
- Nodes are connected by links (pointers).
- Can grow and shrink dynamically.

<div class="mermaid">graph LR
H((Head)) --> A
A("A") -->|next| B("B")
B -->|next| C("C")
C -->|next| Null[" "]
</div>

A linked list is just a collection of sequential data, it can be any type of data, we are no longer limited to primitive types.

---

### SLL: Pseudocode

```c++
int at(index);

int search(value);

void push_back(element);

int pop_front(index);
```

---

### SLL: Pseudocode Answers

```pseudocode
function at(index) -> data:
  temp = head
  for (int i = 0; i < index; ++i)
    iter = iter->next
  return iter->data

function search(value) -> index:
  temp = head
  int i = 0;
  while (temp):
    if (temp->data == value) return i;
    temp = temp->next
    ++i;
  return i;

function push_back(element) -> void:
  temp = head
  while (temp->next is not null):
    temp = temp->next
  temp->next = element

function pop_front(element, index) -> data:
  temp = head
  head = head->next
  delete temp
```

---

### SLL: Implementation

With your teams, implement a Singly Linked List!

The header has been provided under `source/Linear`

[Interactive Visualization](https://visualgo.net/en/list)

---
name: stacks
class: middle

## Stacks

---

### Stacks: Motivation

Consider a stack of magazines on your table.

--

Specifically, consider the way in which you place them down, then pick them back up.

--

If we restrict access to middle elements, we have a last in first out (LIFO) stack!

--

Can you think of other real life uses for stacks? What about computationally

---
name: queues
class: middle

## Queues

---
name: memory-management
class: middle

## Memory Management

---
name: circular-singularly-linked-lists
class: middle

## Circular Singularly Linked Lists

---
name: doubly-linked-lists
class: middle

## Doubly Linked Lists

---
name: Resources
class: middle

## Resources
