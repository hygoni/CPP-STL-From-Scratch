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

}

#endif  // UTIL_HPP_
