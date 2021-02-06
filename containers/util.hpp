#ifndef UTIL_HPP_
#define UTIL_HPP_

namespace ft {

  template <class>
  struct enable_if { typedef void type; };
  class iterator_category {};
  class input_iterator_tag {};
  class output_iterator_tag {};
  class bidirectional_iterator_tag : public input_iterator_tag {};
  class random_access_iterator_tag : public bidirectional_iterator_tag {};

  template <typename InputIt1, typename InputIt2>
  bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
    while (first1 != last1) {
      if (*first1 != *first2)
        return false;
      first1++;
      first2++;
    }
    return true;
  }

  template <typename InputIt1, typename InputIt2>
  bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
    for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2) {
      if (*first1 < *first2) return true;
      if (*first2 < *first1) return false;
    }
    return (first1 == last1) && (first2 != last2);
  }

  template <typename K, typename V>
  struct pair {
      K first;
      V second;
      
      pair() : first(), second() {}
      
      pair(K x, V y) : first(x), second(y) {}
      
      pair(const pair& other) : first(other.first), second(other.second) {}
      
      template <typename _K, typename _V>
      pair(const pair<_K, _V> other) : first(other.first), second(other.second) {}

      pair& operator=(const pair& other) {
        first = other.first;
        second = other.second;
        return *this;
      }

      template <typename _K, typename _V>
      friend bool operator==(const pair<_K, _V>& x, const pair<_K, _V>& y);
      template <typename _K, typename _V>
      friend bool operator<(const pair<_K, _V>& x, const pair<_K, _V>& y);
      template <typename _K, typename _V>
      friend bool operator<=(const pair<_K, _V>& x, const pair<_K, _V>& y);
      template <typename _K, typename _V>
      friend bool operator>(const pair<_K, _V>& x, const pair<_K, _V>& y);
      template <typename _K, typename _V>
      friend bool operator>=(const pair<_K, _V>& x, const pair<_K, _V>& y);
      template <typename _K, typename _V>
      friend bool operator!=(const pair<_K, _V>& x, const pair<_K, _V>& y);
      
  };

  template <typename _K, typename _V>
  bool operator==(const pair<_K, _V>& x, const pair<_K, _V>& y) {
    return (x.first == y.first) && (x.second == y.second);
  }

  template <typename _K, typename _V>
  bool operator<(const pair<_K, _V>& x, const pair<_K, _V>& y) {
    if (x.first == y.first) {
      return (x.second < y.second);
    } else {
      return (x.first < y.first);
    }
  }

  template <typename _K, typename _V>
  bool operator<=(const pair<_K, _V>& x, const pair<_K, _V>& y) {
    return (x < y) || (x == y);
  }

  template <typename _K, typename _V>
  bool operator>(const pair<_K, _V>& x, const pair<_K, _V>& y) {
    return (y < x);
  }

  template <typename _K, typename _V>
  bool operator>=(const pair<_K, _V>& x, const pair<_K, _V>& y) {
    return !(x < y);
  }
  
  template <typename _K, typename _V>
  bool operator!=(const pair<_K, _V>& x, const pair<_K, _V>& y) {
    return !(x == y);
  }

  template <typename _K, typename _V>
  pair<_K, _V> make_pair(_K key, _V value) {
    return pair<_K, _V>(key, value);
  }
}

#endif  // UTIL_HPP_
