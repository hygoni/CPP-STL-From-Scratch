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
    ft::vector<std::pair<int, int> >::const_iterator it = vector.begin();
    ft::map<int, int>::const_iterator it2 = map2.begin();
    while (it != vector.end()) {
      assert(it->first == it2->first && it->second == it2->second);
      it++;
      it2++;
    }

    /* copy constructor */
    ft::map<int, int> map3(map2);
    assert(map2 == map3);
    map2.clear();
    map3.clear();
    assert(map2 == map3 && map2.size() == 0);
  }

  void test_insert_erase() {
    ft::map<int, int> map;

    map[10] = 10;
    assert(map.find(10) != map.end());
    assert(map.find(100) == map.end());
    assert(map.count(10) == 1);
    assert(map.count(100) == 0); 
    assert(map.size() == 1);
    
    map.erase(map.begin());
    assert(map.insert(std::make_pair<int, int>(1000, 1000)).second == true);
    assert(map.insert(std::make_pair<int, int>(1000, 1000)).second == false);
    assert(map.insert(std::make_pair<int, int>(1000, 1000)).first->first == 1000);
    
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

    it = --map.end();
    ft::map<int, int>::reverse_iterator rit = map.rbegin();
    while (rit != map.rend()) {
      assert(rit->first == it->first);
      assert(rit->second == it->second);
      it--;
      rit++;
    }
  }

  void test_equal_lower_upper() {
    ft::map<int, int> map;
    ft::map<int, int>::iterator it;

    for (int i = 1; i <= 100; i++) {
      map[i] = i;
    }
    assert(map.lower_bound(10)->first == 10);
    assert(map.upper_bound(10)->first == 11);
    assert(map.lower_bound(1000) == map.end());
    assert(map.upper_bound(1000) == map.end());
    assert(map.equal_range(10).first == map.lower_bound(10));
    assert(map.equal_range(10).second == map.upper_bound(10));
  }

  void test_key_value_comp() {
    ft::map<int, int> map;
    ft::map<int, int>::value_compare value_comp = map.value_comp();
    ft::map<int, int>::key_compare key_comp = map.key_comp();

    assert(key_comp(1, 10));
    assert(!key_comp(10, 1));
    assert(value_comp(std::make_pair<const int, int>(10, 10), std::make_pair<const int, int>(100, 100)));
  }

} // namespace map_test

void test_map() {
  map_test::test_constructor();
  map_test::test_iterator();
  map_test::test_insert_erase();
  map_test::test_equal_lower_upper();
  map_test::test_key_value_comp();
}
