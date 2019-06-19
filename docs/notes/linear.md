name: linear-data-structures
class: center, middle

# Linear Data Structures

---
name: agenda

## Agenda

- [Agenda](#Agenda)
- [Singly Linked Lists](#Singly-Linked-Lists)
- [Circular Singularly Linked Lists](#Circular-Singularly-Linked-Lists)
- [Doubly Linked Lists](#Doubly-Linked-Lists)
- [Stacks & Queues](#Stacks--Queues)
- [Memory Management](#Memory-Management)
- [Resources](#Resources)

---
name: Singly-Linked-Lists
class: middle

## Singly Linked Lists

---

### SLL: Arrays Aren't Perfect

Consider the array

.array[

| arr*  | 5   | 4   | 6   | 1   | ... |
| ----- | --- | --- | --- | --- | --- |
| index | 0   | 1   | 2   | 3   | ... |

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

Each node holds `int data` and, `Node* next`

--

A linked list is data structure that holds sequential information non-contiguously.

---

### SLL: Pseudocode

```c++
// Returns the data
//at the given index.
int at(index);



// Returns first index of
// value in list, else -1
int search(value);



// Pushes an element onto
// the back of the list.
void push_back(element);



// Removes and returns the
// first value in the list
int pop_front(index);
```

---

### SLL: Pseudocode Answers

.two-columns[
  
```pseudocode
// O(n)
func at(index):
  temp = head
  for (i = 0; i < index; ++i)
    iter = iter->next
  return iter->data

// O(n)
func search(value):
  temp = head
  int i = 0;
  while (temp):
    if (temp->data == value):
      return i;
    temp = temp->next
    ++i;
  return i;

// O(n)
func push_back(element):
  temp = head
  while (temp->next):
    temp = temp->next
  temp->next = element
  return

// O(1)
func pop_front():
  temp = head
  head = head->next
  ret = temp->data
  delete temp
  return ret
```

]

---

### SLL: Implementation

With your teams, implement a Singly Linked List!

The header has been provided under `source/Linear`

[Interactive Visualization](https://visualgo.net/en/list)

[Assignment Link](https://classroom.github.com/g/_D7D_Rxt)

---
name: Circular-Singularly-Linked-Lists

## Circular Singularly Linked Lists

What if the last element didn't point to null, but to `head`?

<div class="mermaid">graph LR
H((Head)) --> A
A("A") -->|next| B("B")
B -->|next| C("C")
C -->|next| A
</div>

---
name: Doubly-Linked-Lists

## Doubly Linked Lists

Instead of just storing the `next` element, also store the `previous` one.

<div class="mermaid">graph LR
H((Head)) --> A
Null2[" "] ---|prev| A
A("A") -->|next| B("B")
B -->|prev| A
B -->|next| C("C")
C -->|prev| B
C -->|next| Null[" "]
</div>

--

This can also be made circular

---
name: Stacks--Queues
class: middle

## Stacks & Queues

---

### Stacks: LIFO (Last In First Out)

Consider a stack of magazines on your table.

--

Specifically, consider the way in which you place them down, then pick them back up.

--

If we restrict access to middle elements, we have a last in first out (LIFO) stack!

--

Can you think of other real life uses for stacks? What about computationally

--

Undo in applications, language execution, expression parsing, ...

---

### Stacks: API

There are two few crucial methods to any stack:

- Push: Add an element to the stack
- Pop: Removes and returns the topmost element

--

What other methods would you want to use in a Stack?

--

isEmpty, reverse, peak, clear, ...

---

### Stacks: Array Based

Take a moment to discuss with your teams how an array-based stack could be implemented.

Where should we push and pop to / from?

--

The end is much easier to work with, by simply maintaining a "top" placeholder:

.array[
| arr*  | 4   | 5   | 1   | 9   |         |     | ... |
| ----- | --- | --- | --- | --- | ------- | --- | --- |
| index | 0   | 1   | 2   | 3   | 4 (TOP) | 5   | ... |
]

---

### Stacks: Linked List Based

If we use a linked list, should we still push and pop from the back?

--

It doesn't really matter, so long as we choose the fastest methods!

We need to look at the underlying implementation, and try to use the fastest subset of methods.

---

### Stacks: Implementation

Wait! We are going to be be building both stacks **and** queues today, so let's talk about those first as well.

---

### Queues: FIFO (First In First Out)

Consider any line you've ever waited in, that was a First In First Out queue!

What are some applications that may use a queue internally?

--

Tasks, processor scheduling, playlists, simulations, ...

---

### Queues: API

Again, there are two crucial methods

- Enqueue: Inserts one element into the queue (also called push)
- Dequeue: Removes and returns the next element in the queue (also called push)

Can you think of some other helpful methods a queue may need?

--

isEmpty, reverse, peak, clear, ... (same as stacks!)

---

### Queues: Array Based

What is the easiest way to push/pop from a queue if it is array-based?

--

Keep two helper addresses, base and top!

.array[
| arr*  |     | 5        | 1   | 9   |         |     | ... |
| ----- | --- | -------- | --- | --- | ------- | --- | --- |
| index | 0   | 1 (BASE) | 2   | 3   | 4 (TOP) | 5   | ... |
]

---

### Queues: Linked List Based

Based on our class Linked List Implementation, what is the best way to build a queue from the SLL class?

--

<!-- TODO -->

---

### Implementation Time

Today you must build both a Stack and Queue using the SLL class we built yesterday.

Helpful visualizations:

- [Visualgo](https://visualgo.net/en/list)
- [Stack](https://www.cs.usfca.edu/~galles/visualization/StackLL.html)
- [Queue](https://www.cs.usfca.edu/~galles/visualization/QueueLL.html)

---
name: Memory-Management
class: middle

## Memory Management

---
name: Resources
class: middle

## Resources
