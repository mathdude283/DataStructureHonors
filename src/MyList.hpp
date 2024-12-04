/*
 * Implementation file for a clean and simple linked list
 * using std::forward_list syntax
 */

// These are freebies, touch only if attempting doubly-linked list
// Tests may depend on these working!

// modified
template <typename T> LinkedListIterator<T> MyList<T>::begin() {
  return LinkedListIterator<T>(this);
}

// modified
template <typename T> MyList<T>::MyList() { next = nullptr; }

// modified
template <typename T> MyList<T>::~MyList() { delete next; }

// modified
template <typename T> int MyList<T>::size() {
  if (next == nullptr) {
    return 0;
  }
  return 1 + next->size();
}

// modified
template <typename T> T &MyList<T>::front() { return *data; }

// modified
template <typename T> void MyList<T>::push_front(const T &value) {
  MyList<T> *tmp = new MyList<T>;
  tmp->data = data;
  tmp->next = next;
  data = value;
  next = tmp;
}

// modified
template <typename T> void MyList<T>::pop_front() {

  if (next != nullptr) {
    MyList<T> *tmp_next = next->next;
    T tmp_data = next->data;
    next->next = nullptr;
    delete next;
    data = tmp_data;
    next = tmp_next;
  }
}

// Implement each of the functions below
// PLEASE READ MyList.h carefully for details on each!
// Check out unit_tests/ and mem_tests/ for grading details

// modified
template <typename T>
void MyList<T>::insert(LinkedListIterator<T> iter, const T &value) {
  MyList<T> *tmp = new MyList<T>;
  tmp->data = iter->data;
  tmp->next = iter->next;
  iter->data = value;
  iter->next = tmp;
}

// modified
template <typename T> void MyList<T>::erase(LinkedListIterator<T> iter) {
  MyList<T> *tmp = iter->next;
  iter->data = tmp->data;
  iter->next = tmp->next;
  tmp->next = nullptr;
  delete tmp;
}

// modified
template <typename T> void MyList<T>::clear() {
  delete next;
  next = nullptr;
}

// removed
/* template <typename T> MyList<T>::~MyList() {
  clear();
  delete head;
  head = nullptr;
} */

// modified
template <typename T> MyList<T> &MyList<T>::operator=(const MyList<T> &rhs) {

  clear();
  if (rhs.next == nullptr) {
    next = nullptr;
  } else {
    next = new MyList<T>();
    data = rhs.data;
    *next = *(rhs.next);
  }
  return *this;
}

// modified
template <typename T> MyList<T>::MyList(const MyList<T> &rhs) {
  next = nullptr;
  *this = rhs;
}

// modified
template <typename T> LinkedListIterator<T> MyList<T>::find(const T &value) {
  if (next == nullptr) {
    return nullptr;
  }
  if (data == value) {
    return LinkedListIterator<T>(this);
  }
  return next->find(value);
}

// new
template <typename T> void MyList<T>::assign_helper(int count, const T &value) {
  if (count > 0) {
    push_front(value);
    assign_helper(count - 1, value);
  }
}

// modified
template <typename T> void MyList<T>::assign(int count, const T &value) {
  clear();
  assign_helper(count, value);
}

// new
template <typename T> LinkedListIterator<T> MyList<T>::reverse_helper() {
  if (next->next == nullptr) {
    return LinkedListIterator<T>(this);
  }
  LinkedListIterator<T> loc = next->reverse_helper();

  T temp_data = data;
  MyList<T> *temp = next;
  data = temp->data;
  temp->data = temp_data;
  if (temp->next->next == nullptr) {
    return loc;
  }
  next = temp->next;

  temp->next = loc->next;
  loc->next = temp;
  return ++loc;
}

// modified
template <typename T> void MyList<T>::reverse() {
  if (next != nullptr) {
    reverse_helper();
  }
}

// modified
template <typename T>
void MyList<T>::splice_after(MyList<T> *splice_point, MyList<T> &source) {
  if (source.next == nullptr) {
    return;
  }
  MyList<T> *temp = source.next;
  T temp_data = source.data;
  source.next = temp->next;
  source.data = temp->data;
  temp->data = temp_data;
  temp->next = splice_point->next;
  splice_point->next = temp;
  splice_after(temp, source);
}
