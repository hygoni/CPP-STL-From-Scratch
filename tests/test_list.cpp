#include "list.hpp"
#include <list>
#include <assert.h>
#include <iostream>


namespace list_test {
  template <typename T>
  bool assert_equal(ft::list<T> left, std::list<T> right) {
    typename ft::list<T>::iterator it;
    typename std::list<T>::iterator it2;
    
    assert(left.size() == right.size());
    it = left.begin();
    it2 = right.begin();
    while (it != left.end()) {
      assert(*it == *it2);
      it++;
      it2++;
    }
    return true;
  }

  void test_constructor() {
    ft::list<int> my_list1;
    ft::list<int> my_list2(10, 10);
    ft::list<int> my_list3(my_list2);
    ft::list<int> my_list4(42);
    std::list<int> std_list1;
    std::list<int> std_list2(10, 10);
    std::list<int> std_list3(std_list2);
    std::list<int> std_list4(42);

    assert_equal(my_list1, std_list1);
    assert_equal(my_list2, std_list2);
    assert_equal(my_list3, std_list3);
    assert_equal(my_list4, std_list4);
  }

  void test_front_back() {
    ft::list<int> lst;

    lst.push_back(10);
    assert(lst.front() == 10);
    lst.push_back(20);
    assert(lst.front() == 10);
    assert(lst.back() == 20);
  }

  void test_push_pop_front_back() {
    ft::list<int> lst;
    for (int i = 1; i <= 10; i++) {
      lst.push_front(i);
      assert(lst.front() == i);
    }
    for (int i = 10; i >= 1; i--) {
      assert(lst.front() == i);
      lst.pop_front();
    }

    for (int i = 1; i <= 10; i++) {
      lst.push_back(i);
      assert(lst.back() == i);
    }
    for (int i = 10; i >= 1; i--) {
      assert(lst.back() == i);
      lst.pop_back();
    }
  }

  void test_insert_erase() {
    ft::list<int> one;
    ft::list<int> two;

    for (int i = 1; i <= 10; i++)
      one.push_back(i);
    two.insert(two.begin(), one.begin(), one.end());
    assert(one == two);

    one.clear();
    two.clear();
    assert(one.empty());
    assert(two.empty());
    one.insert(one.begin(), 10, 10);
    two.insert(two.begin(), one.begin(), one.end());
    assert(one == two);
    assert(!(one < two));
    assert(!(one > two));
    assert(!(one != two));

    one.erase(one.begin(), one.end());
    assert(one.empty());
  }

  void test_resize_swap() {
    ft::list<int> one;
    ft::list<int> two;

    for (int i = 1; i <= 5; i++) {
      one.push_back(i);
    }

    one.resize(3);
    assert(one.size() == 3);
    assert(one.front() == 1);
    assert(one.back() == 3);
    one.resize(4);
    assert(one.back() == 0);
    one.resize(0);
    assert(one.empty());
    
    /* test swap */
    for (int i = 1; i <= 10; i++) {
      one.insert(one.begin(), i);
    }
    one.swap(two);
    assert(one.empty());
    for (int i = 10; i >= 1; i--) {
      assert(two.front() == i);
      two.pop_front();
    }
  }

  template <typename InputIt>
  bool is_sorted(InputIt first, InputIt last) {
    InputIt prev = first;
    first++;
    while (first != last) {
      if (*prev > *first) {
        return false;
      }
      prev = first;
      first++;
    }
    return true;
  }

  void  test_splice_merge_sort() {
    ft::list<int> one;

    for (int i = 500; i >= 1; i--) {
      one.push_back(i);
      one.push_back(1000 - i + 1);
    }
    one.sort();
    assert(is_sorted(one.begin(), one.end()));
  }

  void test_unique() {
    ft::list<int> one;

    for (int n = 1; n <= 10; n++) {
      for (int cnt = 1; cnt <= 10; cnt++) {
        one.push_back(n);
      }
    }
    one.unique();
    assert(one.size() == 10);
  }

  void test_reverse() {
    ft::list<int> one;
    ft::list<int> two;
    for (int i = 1; i <= 10; i++) {
      one.push_back(i);
      two.push_front(i);
    }

    one.reverse();
    assert(one == two);
  }

  bool unary_predicate(const int& val) {
    return val > 1;
  }

  void test_remove() {
    ft::list<int> one;

    for (int cnt = 1; cnt <= 10; cnt++) {
      one.push_back(1);
      one.push_back(2);
    }

    one.remove(1);
    assert (one.front() == one.back() && one.front() == 2);
    one.unique();
    assert(one.size() == 1 && one.front() == 2);

    one.clear();
    for (int i = 1; i <= 100; i++) {
      one.push_back(i);
    }
    one.remove_if(unary_predicate);
    assert(one.front() == 1 && one.size() == 1);
  }

}
void test_list() {
  list_test::test_constructor();
  list_test::test_front_back();
  list_test::test_push_pop_front_back();
  list_test::test_insert_erase();
  list_test::test_resize_swap();
  list_test::test_splice_merge_sort();
  list_test::test_unique();
  list_test::test_reverse();
  list_test::test_remove();
}
