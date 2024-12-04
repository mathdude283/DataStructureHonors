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

    int list_size = rand() % 20;

    for (int i = 0; i < list_size; i++) {
      int num = rand() % 50;
      your_list.push_front(num);
    }

    if (your_list.size() != list_size) {
      return false;
    }

    return true;
  });
}
