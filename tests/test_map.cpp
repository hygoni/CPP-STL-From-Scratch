#include <assert.h>
#include <iostream>
#include "map.hpp"
#include "vector.hpp"

namespace map_test {
  void test_constructor() {
    /* default constructor */
    ft::map<int, int> map;
    assert(map.empty());

    /* constructor with iterator */
    ft::vector<std::pair<int, int> > vector;
    for (int i = 0; i < 10000; i++) {
      vector.push_back(std::make_pair(i, i));
    }

    ft::map<int, int> map2(vector.begin(), vector.end());
    ft::vector<std::pair<int, int> >::iterator it = vector.begin();
    ft::map<int, int>::iterator it2 = map2.begin();
    while (it != vector.end()) {
      assert(it->first == it2->first && it->second == it2->second);
      it++;
      it2++;
    }

    /* copy constructor */
    ft::map<int, int> map3(map2);
    assert(map2 == map3);
  }

  void test_insert_erase() {
    ft::map<int, int> map;

    map[10] = 10;
    assert(map.find(10) != map.end());
    assert(map.find(100) == map.end());
    assert(map.count(10) == 1);
    assert(map.count(100) == 0); 
    assert(map.size() == 1);
  }
  
  void test_iterator() {
    ft::map<int, int>::iterator it;
    ft::map<int, int> map;

    for (int i = 1000; i >= 1; i--) {
      map[i] = i;
    }

    int n = 1;
    it = map.begin();
    while (it != map.end()) {
      assert(it->first == n);
      assert(it->second == n);
      n++;
      it++;
    }
    assert((--map.end())->first == 1000);
  }

} // namespace map_test

void test_map() {
  map_test::test_constructor();
  map_test::test_iterator();
  map_test::test_insert_erase();
}
