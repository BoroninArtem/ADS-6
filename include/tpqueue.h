// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
template<typename T, int size = 0>
class TPQueue {
private:
    T mas[size] = { 0 };
    int head, tail, count;
public:
    TPQueue() : head(0), tail(0), count(0) {}
    void push(const T& sm) {
        if (count == 0) {
            mas[0] = sm;
            ++tail;
            ++count;
        }
        else {
            for (int i = tail; i > head; --i) {
                if (mas[(i - 1) % size].prior >= sm.prior) {
                    mas[i % size] = sm;
                    break;
                }
                else {
                    mas[i % size] = mas[(i - 1) % size];
                    mas[(i - 1) % size] = sm;
                }
            }
            ++tail;
        }
    }
    const T& pop() {
        return mas[(head++ % size)];
    }
};
struct SYM {
    char ch;
    int prior;
};
#endif
