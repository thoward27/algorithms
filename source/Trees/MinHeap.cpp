#include "MinHeap.hpp"

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

MinHeap::MinHeap(unsigned int cap) {
  capacity = cap;
  array = new int[cap];
  size = 0;
}

MinHeap::~MinHeap() {
  delete [] array;
}

int MinHeap::count() {
  return size;
}

int MinHeap::peek() {
  if (!size) throw "Attempted to access empty heap";
  return array[0];
}

void MinHeap::swim() {
  int i = size - 1;
  while (array[i] < array[(i-1)/2]) {
    swap(array + i, array + (i-1)/2);
    i = (i-1)/2;
  }
}

void MinHeap::sink(int i) {
  while (2*i + 1 < size) {
    // Heap at i is still greater than children but only has one child
    if (2*i + 2 == size) {
      if (array[i] > array[2*i + 1]) {
        swap(array + i, array + 2 * i + 1);
      }
      break;
    }
    // Heap at i is smaller than both children
    if (array[i] <= array[2*i + 1] && array[i] <= array[2*i + 2]) {
      break;
    }
    // Heap at i is greater than at least one child
    if (array[i] <= array[2*i + 1]) {
      swap(array + i, array + 2*i + 2);
      i = 2*i + 2;
    } else if (array[i] <= array[2*i + 2]) {
      swap(array + i, array + 2*i + 1);
      i = 2*i + 1;
    } else {
      if (array[2*i + 1] < array[2*i + 2]) {
        swap(array + i, array + 2*i + 1);
        i = 2*i + 1;
      } else {
        swap(array + i, array + 2*i + 2);
        i = 2*i + 2;
      }
    }
  }
}

void MinHeap::push(int data) {
  if ((unsigned int) size == capacity) throw "Attempted to push into a full heap";
  array[size++] = data;
  swim();
}

int MinHeap::pop() {
  if (!size) throw "Attempted to extract from an empty heap";
  int rval = array[0];
  array[0] = array[--size];
  sink(0);
  return rval;
}

bool MinHeap::search(int data) {
  return search(0, data);
}

bool MinHeap::search(int i, int data) {
  if (i >= size) return false;
  if (data == array[i]) return true;
  if (data < array[i]) return false;
  return search(2*i + 1, data) || search(2*i + 2, data);
}

int MinHeap::remove(int i) {
  if (i < 0 || i >= size) throw "Attempted to remove from a heap at an invalid location";
  int rval = array[i];
  array[i] = array[--size];
  sink(i);
  return rval;
}

void MinHeap::erase(int data) {
  erase(0, data);
}

void MinHeap::erase(int i, int data) {
  if (i >= size) return;
  if (data < array[i]) return;
  if (data == array[i]) {
    remove(i);
    return;
  }
  erase(2*i + 1, data);
  erase(2*i + 2, data);
}

void MinHeap::print(std::ostream& oss) {
  for (int i = 0; i < size; ++i) {
    oss << array[i] << ", ";
  }
  oss << '\n';
}