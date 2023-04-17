// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>
template<typename T, int size>
class TPQueue {
 private:
  T* box;
  int capacity;
  int left, right;
  int cSize;
 public:
  TPQueue() :capacity(size), left(0), right(0), cSize(0) {
    box = new T[capacity + 1];
  }
  void push(const T& value) {
    assert(cSize < capacity);
    if (cSize == 0) {
      box[right++] = value;
      cSize++;
    } else {
      int i = right - 1;
      bool f = 0;
      while (i >= left && value.prior > container[i].prior) {
      while (i >= left && value.prior > box[i].prior) {
        f = 1;
        box[i + 1] = box[i];
        box[i] = value;
        i--;
      }
      if (f == 0) {
        box[right] = value;
      }
      right++;
      cSize++;
    }
    if (right > capacity) {
      right -= capacity + 1;
    }
  }
  const T& pop() {
    assert(cSize > 0);
    cSize--;
    if (left > capacity) {
      left -= capacity + 1;
    }
    return box[left++];
  }
  char get() {
    assert(cSize > 0);
    return box[left].ch;
  }
  bool isFull() const {
    return cSize == capacity;
  }
  bool isEmpty() const {
    return cSize == 0;
  }
  ~TPQueue() {
    delete[] box;
  }
};
