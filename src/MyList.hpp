/*
 * Implementation file for a clean and simple linked list
 * using std::forward_list syntax
 */

// These are freebies, touch only if attempting doubly-linked list
// Tests may depend on these working!
template <typename T> LinkedListIterator<T> MyList<T>::begin() {
  return LinkedListIterator<T>(head);
}

template <typename T> MyList<T>::MyList() {
  num_elements = 0;
  head = new ListNode<T>;
  head->next = nullptr;
}

template <typename T> int MyList<T>::size() { return num_elements; }

template <typename T> T &MyList<T>::front() { return head->data; }

template <typename T> void MyList<T>::push_front(const T &value) {
  ListNode<T> *tmp = new ListNode<T>;
  tmp->data = value;
  tmp->next = head;
  head = tmp;
  num_elements++;
}

template <typename T> void MyList<T>::pop_front() {

  if (num_elements > 0) {
    ListNode<T> *tmp = head->next;
    delete head;
    head = tmp;
    num_elements--;
  }
}

// Implement each of the functions below
// PLEASE READ MyList.h carefully for details on each!
// Check out unit_tests/ and mem_tests/ for grading details

template <typename T>
void MyList<T>::insert(LinkedListIterator<T> iter, const T &value) {
  ListNode<T> *tmp = new ListNode<T>;
  tmp->data = iter->data;
  tmp->next = iter->next;
  iter->data = value;
  iter->next = tmp;
  ++iter;
  num_elements++;
}

template <typename T> void MyList<T>::erase(LinkedListIterator<T> iter) {
  ListNode<T> *tmp = iter->next;
  iter->data = tmp->data;
  iter->next = tmp->next;
  delete tmp;
  num_elements--;
}

template <typename T> void MyList<T>::clear() {
  ListNode<T> *tmp = nullptr;
  while (head->next != nullptr) {
    tmp = head;
    head = head->next;
    delete tmp;
  }
  num_elements = 0;
}

template <typename T> MyList<T>::~MyList() {
  clear();
  delete head;
  head = nullptr;
}

template <typename T> MyList<T> &MyList<T>::operator=(const MyList<T> &rhs) {
  LinkedListIterator<T> iter = begin();
  ListNode<T> *pos = rhs.head;
  // Finish Me!
  for (int i = 0; i < rhs.num_elements; i++) {
    iter->data = pos->data;
    iter->next = new ListNode<T>;
    ++iter;
    pos = pos->next;
  }
  iter->next = nullptr;
  num_elements = rhs.num_elements;
  return *this;
}

template <typename T> MyList<T>::MyList(const MyList<T> &rhs) {
  num_elements = 0;
  head = new ListNode<T>;
  head->next = nullptr;
  *this = rhs;
}

template <typename T> LinkedListIterator<T> MyList<T>::find(const T &value) {
  ListNode<T> *found_ptr = nullptr;
  for (LinkedListIterator<T> iter = begin(); iter->next != nullptr; ++iter) {
    if (iter->data == value) {
      return iter;
    }
  }
  return found_ptr;

  // Finish Me!

  return LinkedListIterator<T>(found_ptr);
}

template <typename T> void MyList<T>::assign(int count, const T &value) {
  clear();
  for (int i = 0; i < count; i++) {
    push_front(value);
  }
}

template <typename T> void MyList<T>::reverse() {
  ListNode<T> *moving_elem = head;
  while (moving_elem->next->next != nullptr) {
    ListNode<T> *tmp = moving_elem->next;
    moving_elem->next = tmp->next;
    tmp->next = head;
    head = tmp;
  }
}

template <typename T>
void MyList<T>::splice_after(ListNode<T> *splice_point, MyList<T> &source) {
  ListNode<T> *splice_end = splice_point->next;
  while (source.head->next != nullptr) {
    splice_point->next = source.head;
    splice_point = splice_point->next;
    source.head = splice_point->next;
  }
  splice_point->next = splice_end;
}
