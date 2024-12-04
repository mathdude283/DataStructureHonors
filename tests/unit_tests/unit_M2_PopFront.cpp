#include "MyList.h"
#include "test_utils.hpp"
#include <ctime>
#include <forward_list>
#include <stdlib.h>

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    time_t seed;
    srand(time(&seed));

    MyList<int> your_list;
    std::forward_list<int> test_list;

    for (int i = 0; i < 8; i++) {
      int num = rand() % 50;
      your_list.push_front(num);
      test_list.push_front(num);
    }

    for (int i = 0; i < 3; i++) {
      your_list.pop_front();
      test_list.pop_front();
    }

    LinkedListIterator<int> iter = your_list.begin();
    auto test_iter = test_list.begin();

    if (your_list.size() != 5) {
      return false;
    }

    for (int k = 0; k < 5; k++) {
      if (iter->data != *test_iter++)
        return false;
      iter + 1;
    }

    return true;
  });
}