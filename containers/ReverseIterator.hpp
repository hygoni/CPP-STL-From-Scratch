#ifndef REVERSE_ITERATOR_HPP_
#define REVERSE_ITERATOR_HPP_

# include "list.hpp"

template<typename Iter>
class ReverseIterator {
  protected:
    Iter _iter;

  public:
    typedef typename Iter::Node Node;
    typedef typename Iter::value_type value_type;
    typedef typename Iter::pointer pointer;
    typedef typename Iter::reference reference;
    typedef typename Iter::const_reference const_reference;
    typedef typename Iter::difference_type difference_type; 
   
    ReverseIterator() {
      _iter._node = NULL;
    }

    ReverseIterator(Iter const& it) {
      _iter._node = it._node;
    }

    ReverseIterator(Node *node) {
      _iter._node = node;
    }

    ReverseIterator& operator=(ReverseIterator const& it) {
     _iter._node = it._iter._node;
      return *this;
    }

    /* prefix increment */
    virtual ReverseIterator& operator++() {
      _iter._node = _iter._node->_prev;
      return *this;
    }

    /* postfix increment */
    virtual ReverseIterator operator++(int) {
      ReverseIterator current = *this;
      Iter current_iter = _iter;
      _iter._node = _iter._node->_prev;
      current._iter = current_iter;
      return current;
    }

    /* prefix decrement */
    virtual ReverseIterator& operator--() {
      _iter._node = _iter._node->_next;
      return *this;
    }

    /* postfix decrement */
    virtual ReverseIterator operator--(int) {
      ReverseIterator current = *this;
      Iter current_iter = _iter;
      _iter._node = _iter._node->_next;
      current._iter = current_iter;
      return current;
    }

    reference operator*() {
      return _iter._node->_data;
    }

    pointer operator->() const {
      return &(_iter._node->_data);
    }

    Node* getNode() {
      return _iter._node;
    }

    bool operator!=(const ReverseIterator x) {
      return !(*this == x);
    }

    template <typename _T>
    friend bool operator==(const ReverseIterator<_T> x, const ReverseIterator<_T> y);
};

template <typename _T>
bool operator==(const ReverseIterator<_T> x, const ReverseIterator<_T> y) {
  return (x._iter == y._iter);
}


#endif  // REVERSE_ITERATOR_HPP_
