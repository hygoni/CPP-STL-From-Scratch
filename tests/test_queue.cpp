#include "test.hpp"
#include "queue.hpp"
#include <queue>
#include <assert.h>

namespace queue_test {

  void test_push_pop_top_swap() {
    ft::queue<int> one;
    ft::queue<int> two;
   
    for (int i = 1; i <= 10; i++) {
      one.push(i);
      assert(one.back() == i);
    }
    assert(one.size() == 10);
    one.swap(two);

    assert(two.size() == 10);
    assert(one.empty());
    for (int i = 1; i <= 10; i++) {
      assert(two.front() == i);
      two.pop();
    }
    assert(two.empty());
  }

  void test_copy_constructor() {
    ft::list<int> lst(10, 10);
    ft::queue<int> queue(lst);
    ft::queue<int> queue2(queue);

    assert(queue == queue2);
    while (lst.size() > 0) {
      assert(lst.front() == queue.front());
      lst.pop_front();
      queue.pop();
    }
  }

  void test_relational_operator() {
    ft::queue<int> my1;
    ft::queue<int> my2;
    std::queue<int> std1;
    std::queue<int> std2;

    my1.push(10);
    std1.push(10);
    assert((my1 > my2) == (std1 > std2));
    assert((my1 < my2) == (std1 < std2));
  }
};

void test_queue() {
  queue_test::test_copy_constructor();
  queue_test::test_push_pop_top_swap();
  queue_test::test_relational_operator();
}
