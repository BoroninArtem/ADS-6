// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
template<typename T, int size = 0>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    T mas[size] = {0};
    int left, right, count;

 public:
    TPQueue(): left(0), right(0), count(0) {}
    void push(const T& sm) {
        if (count == 0) {
            mas[0] = sm;
            ++right;
            ++count;
        } else {
            for (int i = right; i > left; --i) {
                if (mas[(i - 1) % size].prior >= sm.prior) {
                    mas[i % size] = sm;
                    break;
                } else {
                    mas[i % size] = mas[(i - 1) % size];
                    mas[(i - 1)%size] = sm;
                }
            }
            ++right;
        }
    }
    const T& pop() {
        return mas[(left++ % size)];
    }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
