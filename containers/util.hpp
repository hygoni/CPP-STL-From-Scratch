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
}

#endif  // UTIL_HPP_
