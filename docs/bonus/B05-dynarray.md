# Bonus 05: Dynamic Array

For this assignment you will be implementing a Dynamic Array capable of accepting any primitive type.

## The Header

```c++
#pragma once

#include <memory>

template <class T> class Vec {
 public:
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef size_t size_type;
  typedef T value_type;

  Vec();
  explicit Vec(size_type n, const T& t = T());

  Vec(const Vec& v);
  Vec& operator=(const Vec&);
  ~Vec()

  T& operator[](size_type i)
  const T& operator[](size_type i) const;

  void push_back(const T& t);
  void push_front(const T& t);
  
  const T pop_back();
  const T pop_front();

  size_type size() const;

  // Iterators
  iterator begin();
  const_iterator begin();

  iterator end();
  const_iterator end() const;

  // Clear the vector
  void clear();
  bool empty() const;

  void erase(iterator position);
  void remove(const T& t);

 private:
  iterator data;
  iterator size;
  iterator capacity;

  // facilities for memory allocation
  std::allocator<T> alloc;
};
```

## Instructions

This assignment will be hosted on Github Classroom.

1. Register for the assignment on our Github Classroom using [this link](https://classroom.github.com/a/veyFoobr)
2. Clone the repository to your machine
   1. Open a terminal
   2. Navigate to your algorithms folder
   3. Go to the parent directory (`cd ..`)
   4. Clone the repository to this location (`git clone <your repository link here>`)
3. Getting things in order
   1. Open your new folder in VS Code
4. Implement a Generic Dynamic Array **Commit and Push your work after each task**
   1. Create the folder necessary to complete the class (`Array`)
   2. Create and populate the header file `Array.hpp` (Copy and paste the header content from above)
   3. Create the unit tests file `Array.test.cpp` (Refer to other test files for guidance)
   4. Create the source file `Array.cpp`
   5. Populate the source file with all the requisite methods
   6. Repeat the following steps, committing and pushing after each cycle
      1. Select a method to implement
      2. Write a unit test for that method
      3. Implement the method such that it passes your unit tests, adding additional tests along the way as you think of new possible scenarios
5. Submit your work (`git add . && git commit -m "Done" && git push`

## Grading

| Criteria               | Points |
| ---------------------- | ------ |
| Functional Correctness | 90     |
| Quality                | 10     |

## Submission

Submissions are handled by Github Classroom.
Submissions after the deadline are not graded.
