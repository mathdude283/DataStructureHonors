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

    int list_size = (rand() % 20) + 3;

    for (int i = 0; i < list_size; i++) {
      int num = rand() % 50;
      your_list.push_front(num);
      test_list.push_front(num);
      if (your_list.front() != test_list.front()) {
        return false;
      }
    }

    for (int i = 0; i < list_size - 1; i++) {
      your_list.pop_front();
      test_list.pop_front();

      if (your_list.front() != test_list.front()) {
        return false;
      }
    }

    return true;
  });
}
