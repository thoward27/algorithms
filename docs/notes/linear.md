name: linear-data-structures
class: center, middle

# Linear Data Structures

---
name: agenda

## Agenda

- [Agenda](#agenda)
- [Singularly Linked Lists](#singularly-linked-lists)
- [Stacks](#stacks)
- [Queues](#queues)
- [Memory Management](#memory-management)
- [Circular Singularly Linked Lists](#circular-singularly-linked-lists)
- [Doubly Linked Lists](#doubly-linked-lists)
- [Resources](#resources)

---
name: singularly-linked-lists
class: middle

## Singularly Linked Lists

---

### SLL: Motivation

Consider the array

.array[

| arr*  | 5   | 4   | 6   | 1   |     |
| ----- | --- | --- | --- | --- | --- |
| index | 0   | 1   | 2   | 3   |     |

]

--

What is the cost to insert into the front? Middle? Rear?

--

What about deletions?

--

What if we used **non-contiguous** memory?

---

### SLL: A Depiction


<div class="mermaid">graph LR
H((Head)) --> A
A -->|next| B
B -->|next| C
C -->|next| Null
</div>


- Non-Contiguous storage.
- Nodes are connected by links (pointers).
- Can grow and shrink dynamically.

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
