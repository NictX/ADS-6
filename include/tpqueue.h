// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
class TPQueue {
 private:
  struct SYM arr[size];
  int i = 0;
 public:
  void push(SYM item) {
    if (i < size) {
      ++i;
      for (int x = i - 1; x >= 0; x--) {
        if (x && (item.prior <= arr[x - 1].prior)) {
          arr[x] = arr[x - 1];
        } else {
          arr[x] = item;
          break;
        }
      }
    }
  }
  SYM pop() {
    if (i > 0) {
    return arr[--i];
    } else {
    throw "";
    }
  }
};


#endif  // INCLUDE_TPQUEUE_H_
