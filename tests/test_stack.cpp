#include "test.hpp"
#include "stack.hpp"
#include <stack>
#include <assert.h>

void test_push_pop_top_swap() {
  ft::stack<int> one;
  ft::stack<int> two;
  
  for (int i = 10; i >= 1; i--) {
    one.push(i);
    assert(one.top() == i);
  }
  assert(one.size() == 10);
  one.swap(two);
  assert(two.size() == 10);
  assert(one.empty());

  for (int i = 1; i <= 10; i++) {
    assert(two.top() == i);
    two.pop();
  }
  assert(two.empty());
}

void test_copy_constructor() {
  ft::list<int> lst(10, 10);
  ft::stack<int> stack(lst);
  ft::stack<int> stack2(stack);

  assert(stack == stack2);
  while (lst.size() > 0) {
    assert(lst.back() == stack.top());
    lst.pop_back();
    stack.pop();
  }
}

void test_relational_operator() {
  ft::stack<int> my1;
  ft::stack<int> my2;
  std::stack<int> std1;
  std::stack<int> std2;

  my1.push(10);
  std1.push(10);
  assert((my1 > my2) == (std1 > std2));
  assert((my1 < my2) == (std1 < std2));
}

void test_stack() {
  test_copy_constructor();
  test_push_pop_top_swap();
  test_relational_operator();
}
