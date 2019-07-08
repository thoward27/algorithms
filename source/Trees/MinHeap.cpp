#include "MinHeap.hpp"

inline void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

MinHeap::MinHeap(unsigned int cap) {
  capacity = cap;
  array = new int[cap + 1];
  size = 0;
}

MinHeap::~MinHeap() {
  delete[] array;
}

int MinHeap::count() {
  return size;
}

int MinHeap::peek() {
  if (!size)
    throw "Attempted to access empty heap";
  return array[1];
}

void MinHeap::swim() {
  int i = size;
  while (i > 1 && array[i] < array[i / 2]) {
    swap(array + i, array + i / 2);
    i = i / 2;
  }
}

void MinHeap::sink(int i) {
  while (2 * i <= size) {
    int j = 2 * i;
    if (j < size && array[j] > array[j + 1])
      j += 1;
    if (array[i] < array[j])
      break;
    swap(array + i, array + j);
    i = j;
  }
}

void MinHeap::push(int data) {
  if ((unsigned int)size == capacity) {
    capacity = (capacity + 1) * 2;
    int* temp = new int[capacity + 1];
    for (int i = 0; i <= size; ++i)
      temp[i] = array[i];
    delete[] array;
    array = temp;
  }
  array[++size] = data;
  swim();
}

int MinHeap::pop() {
  if (!size)
    throw "Attempted to extract from an empty heap";
  int rval = array[1];
  array[1] = array[size--];
  sink(1);
  return rval;
}

bool MinHeap::search(int data) {
  return search(1, data);
}

bool MinHeap::search(int i, int data) {
  if (i > size)
    return false;
  if (data == array[i])
    return true;
  if (data < array[i])
    return false;
  return search(2 * i, data) || search(2 * i + 1, data);
}

int MinHeap::remove(int i) {
  if (i <= 0 || i > size)
    throw "Attempted to remove from a heap at an invalid location";
  int rval = array[i];
  array[i] = array[size--];
  sink(i);
  return rval;
}

void MinHeap::erase(int data) {
  erase(1, data);
}

void MinHeap::erase(int i, int data) {
  if (i > size)
    return;
  if (data < array[i])
    return;
  if (data == array[i]) {
    remove(i);
    return;
  }
  erase(2 * i, data);
  erase(2 * i + 1, data);
}

void MinHeap::print(std::ostream& oss) {
  for (int i = 1; i <= size; ++i) {
    oss << array[i] << ", ";
  }
  oss << '\n';
}