#include "vector.hpp"
#include <vector>
#include <assert.h>
#include <iostream>


namespace vector_test {
  template <typename T>
  bool assert_equal(ft::vector<T> left, std::vector<T> right) {
    typename ft::vector<T>::iterator it;
    typename std::vector<T>::iterator it2;
    
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
    ft::vector<int> my_vector1;
    ft::vector<int> my_vector2(10, 10);
    ft::vector<int> my_vector3(my_vector2);
    ft::vector<int> my_vector4(42);
    std::vector<int> std_vector1;
    std::vector<int> std_vector2(10, 10);
    std::vector<int> std_vector3(std_vector2);
    std::vector<int> std_vector4(42);

    assert_equal(my_vector1, std_vector1);
    assert_equal(my_vector2, std_vector2);
    assert_equal(my_vector3, std_vector3);
    assert_equal(my_vector4, std_vector4);
  }

  void test_front_back() {
    ft::vector<int> lst;

    lst.push_back(10);
    assert(lst.front() == 10);
    lst.push_back(20);
    assert(lst.front() == 10);
    assert(lst.back() == 20);
  }

  void test_push_pop_front_back() {
    ft::vector<int> lst;

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
    ft::vector<int> one;
    ft::vector<int> two;

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

  void test_reserve() {
    ft::vector<int> v;

    for (int i = 0 ; i < 100000; i++) {
      v.push_back(i);
    }

    for (int i = 0 ; i < 100000; i++) {
      assert(v[i] == i);
    }

  }

};

void test_vector() {
  vector_test::test_constructor();
  vector_test::test_front_back();
  vector_test::test_push_pop_front_back();
  vector_test::test_insert_erase();
  vector_test::test_reserve();
}
