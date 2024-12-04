/* Clean and simple version of std::forward_list
 * This is your h file. Do not edit it!
 * If you want to know what the functions do,
 * Read the links in the assignment description from en.cppreference.
 */

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

// new
template <typename T> class MyList;

// modified
template <typename T> class LinkedListIterator {
  MyList<T> *ptr;

public:
  // modified
  LinkedListIterator(MyList<T> *p) { ptr = p; } // constructor
  T &operator*() {
    return ptr->data;
  } // de-referencing iterator gives access to the data in the current node
  // modified
  MyList<T> *operator->() { return ptr; }
  LinkedListIterator<T> &operator+(int increment) {
    int hops = 0;
    while (hops < increment && ptr != nullptr) {
      ptr = ptr->next; // "advance" the pointer to next node
      hops++;
    }
    return *this;
  }
  LinkedListIterator<T> &operator++() { // pre-fix increment
    ptr = ptr->next;
    return *this;
  }
  LinkedListIterator<T> operator++(int) { // post-fix increment
    LinkedListIterator<T> temp = *this;
    ptr = ptr->next;
    return temp;
  }
  bool is_null() { return ptr == nullptr; }
};

template <typename T> class MyList {
private:
  // ListNode<T> *head = nullptr;

  // int num_elements;

  // new
  void assign_helper(int count, const T &value);

  // new
  LinkedListIterator<T> reverse_helper();

public:
  T data;

  MyList<T> *next;
  LinkedListIterator<T> begin();

  MyList();

  ~MyList();

  MyList<T> &operator=(const MyList<T> &rhs);

  MyList(const MyList<T> &rhs);

  T &front();

  int size();

  // Turn list into 'count' copies of 'value'
  // ex. my_list.assign(5, 3)
  // should produce a list containing <3, 3, 3>
  // Any existing data should be safely removed if necessary
  void assign(int count, const T &value);

  // Default list size of 0, with one sentinel node
  void clear();

  // Insert `value` to the head of the list
  void push_front(const T &value);

  // Erase the value at the head of the list, if size > 0
  void pop_front();

  // Insert 'value' to the position pointed to by 'iter'
  // The element pointed to by 'iter' should come after 'value' when finished
  void insert(LinkedListIterator<T> iter, const T &value);

  // Removes all elements in list that are equal to value.
  // You do NOT need a special case for 0-big lists (i.e., no if size == 0).
  // void remove(const T &value); not assigned this semester

  // Removes element at position pointed to by 'iter'
  void erase(LinkedListIterator<T> iter);

  // If 'value' is in the list, return iterator to first node containing 'value'
  // If 'value' is not in the list, return nullptr
  LinkedListIterator<T> find(const T &value);

  // Reverse the order of elements in the list
  // The sentinel node should still be at the end (tail) of the reversed list
  // COMMON INTERVIEW CHALLENGE
  // Can be done with clever manipulation of pointers, no new/delete needed!
  void reverse();

  // READ CAREFULLY
  // Moves data elements from 'source' into list
  // 'source' should be an empty list afterwards
  // Data from 'source should go after the position pointed to by 'splice_point'
  // Ex:
  // list - [1, 2, 3(splice_point), 4], source - [5, 6]
  // list.splice_after(splice_point, source)
  // list - [1, 2, 3, 5, 6, 4], source - []
  // Can be done with precision pointer surgery, no new/delete needed!

  // modified
  void splice_after(MyList<T> *splice_point, MyList &source);
};

#include "MyList.hpp"

#endif
