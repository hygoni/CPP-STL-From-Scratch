/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 03:43:00 by hyeyoo            #+#    #+#             */
/*   Updated: 2021/01/22 04:48:48 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP
# include <algorithm>
# include <cstddef>
# include <limits>
# include <functional>
# include <memory>
# include "util.hpp"

namespace ft {

  template<typename T>
  struct ListNode {
        T         _data;
        ListNode  *_prev;
        ListNode  *_next;
      
      ListNode() {
        _prev = _next = NULL;
      }

      ListNode(T data) {
        ListNode();
        _data = data;
      }

      ListNode(ListNode const& node) {
        _data = node._data;
        _prev = node._prev;
        _next = node._next;
      }

  };

  template<typename T>
  struct ListIterator {
      typedef ListNode<T> Node;
      Node *_node;
      typedef T value_type;
      typedef T* pointer;
      typedef T& reference;
      typedef T const& const_reference;
      typedef std::ptrdiff_t difference_type; 
      typedef ft::bidirectional_iterator_tag iterator_category;

      ListIterator() {
        _node = NULL;
      }

      ListIterator(ListIterator const& it) {
        _node = it._node;
      }

      ListIterator(Node *node) {
        _node = node;
      }

      ListIterator& operator=(ListIterator const& it) {
       _node = it._node;
        return *this;
      }

      /* prefix increment */
      virtual ListIterator& operator++() {
        _node = _node->_next;
        return *this;
      }

      /* postfix increment */
      virtual ListIterator operator++(int) {
        ListIterator current = *this;
        ++(*this);
        return current;
      }

      /* prefix decrement */
      virtual ListIterator& operator--() {
        _node = _node->_prev;
        return *this;
      }

      /* postfix decrement */
      virtual ListIterator operator--(int) {
        ListIterator current = *this;
        --(*this);
        return current;
      }

      reference operator*() {
        return _node->_data;
      }

      pointer operator->() const {
        return &(_node->_data);
      }

      Node* getNode() {
        return _node;
      }
      bool operator!=(const ListIterator& x) {
        return !(*this == x);
      }

      template <typename _T>
      friend bool operator==(const ListIterator<_T>& x, const ListIterator<_T>& y);
  };

  template <typename _T>
  bool operator==(const ListIterator<_T>& x, const ListIterator<_T>& y) {
    return x._node == y._node;
  }
  
  template<typename T>
  struct ReverseListIterator {
      typedef ListNode<T> Node;
      Node *_node;

    public:
      typedef T value_type;
      typedef T* pointer;
      typedef T& reference;
      typedef T const& const_reference;
      typedef std::ptrdiff_t difference_type; 
      typedef ft::bidirectional_iterator_tag iterator_category;

      ReverseListIterator() {
        _node = NULL;
      }

      template <typename _T>
      ReverseListIterator(ListIterator<_T> const& it) {
        _node = it._node;
      }

      template <typename _T>
      ReverseListIterator(ReverseListIterator<_T> const& it) {
        _node = (Node*)it._node;
      }

      ReverseListIterator(Node *node) {
        _node = node;
      }

      ReverseListIterator& operator=(ReverseListIterator const& it) {
       _node = it._node;
        return *this;
      }

      /* prefix increment */
      ReverseListIterator& operator++() {
        _node = _node->_prev;
        return *this;
      }

      /* postfix increment */
      ReverseListIterator operator++(int) {
        ReverseListIterator current = *this;
        ++(*this);
        return current;
      }

      /* prefix decrement */
      ReverseListIterator& operator--() {
        _node = _node->_next;
        return *this;
      }

      /* postfix decrement */
      ReverseListIterator operator--(int) {
        ReverseListIterator current = *this;
        --(*this);
        return current;
      }

      reference operator*() {
        return _node->_data;
      }

      pointer operator->() const {
        return &(_node->_data);
      }

      Node* getNode() {
        return _node;
      }
      bool operator!=(const ReverseListIterator& x) {
        return !(*this == x);
      }

      template <typename _T>
      friend bool operator==(const ReverseListIterator<_T>& x, const ReverseListIterator<_T>& y);
  };

  template <typename _T>
  bool operator==(const ReverseListIterator<_T>& x, const ReverseListIterator<_T>& y) {
    return x._node == y._node;
  }


  template<typename T>
  class list {
    public:
        typedef ListNode<T> Node;
        typedef T value_type;
        typedef T* pointer;
        typedef T* const_pointer;
        typedef T& reference;
        typedef T const& const_reference;
        
        /* iterator, const_iterator, reverse_iterator, const_reverse_iterator */
        typedef ListIterator<value_type> iterator;
        typedef ListIterator<const value_type> const_iterator;
        typedef ReverseListIterator<value_type> reverse_iterator;
        typedef ReverseListIterator<const value_type> const_reverse_iterator;
        typedef size_t size_type;
        typedef std::ptrdiff_t difference_type;

        
        explicit list() {
          _size = 0;
          _head = _tail = new Node();
          _head->_prev = NULL;
          _head->_next = NULL;
        }

        explicit list(size_type n, const value_type& val = value_type()) {
          _size = 0;
          _head = _tail = new Node();
          _head->_prev = NULL;
          _head->_next = NULL;
          while (n--) {
            insert(begin(), val);
          }
        }


        template <class InputIterator, typename ft::enable_if<typename InputIterator::value_type>::type*>
        list(InputIterator first, InputIterator last) {
          _size = 0;
          _head = _tail = new Node();
          _head->_prev = NULL;
          _head->_next = NULL;
          while (first != last) {
            push_back(*first);
            first++;
          }
        }

        list(list const& other) {
          _size = 0;
          _head = _tail = new Node();
          _head->_prev = NULL;
          _head->_next = NULL;
          *this = other;
        }

        virtual ~list() {
          Node *current = _head;
          Node *to_free = NULL;
          while (current != NULL) {
            to_free = current;
            current = current->_next;
            delete to_free;
          }
        }

        list& operator=(list const& other) {
          clear();
          const_iterator it = other.begin();

          while (it != other.end()) {
            push_back(*it);
            it++;
          }
          return *this;
        }

        iterator begin() {
          if (_size == 0)
            return end();
          return iterator(_head);
        }

        iterator end() {
          if (_tail == NULL)
            return iterator();
          return iterator(_tail);
        }

        const_iterator begin() const {
          if (_size == 0)
            return end();
          typedef ListNode<const value_type> const_node;
          return const_iterator(reinterpret_cast<const_node*>(_head));
        }

        const_iterator end() const {
          if (_tail == NULL)
            return const_iterator();
          typedef ListNode<const value_type> const_node;
          return const_iterator(reinterpret_cast<const_node*>(_tail));
        }

        reverse_iterator rbegin() {
          if (_size == 0)
            return rend();
          return reverse_iterator(--end());
        }

        const_reverse_iterator rbegin() const {
          if (_size == 0)
            return rend();
          return const_reverse_iterator(--end());
        }

        reverse_iterator rend() {
          return const_reverse_iterator((ListNode<const T>*)_head->_prev);
        }

        const_reverse_iterator rend() const {
          return reverse_iterator(_head->_prev);
        }

        reference front() {
          return _head->_data;
        }

        const_reference front() const {
          return const_cast<const value_type&>(_head->_data);
        }

        reference back() {
          return _tail->_prev->_data;
        }

        const_reference back() const {
          return const_cast<const value_type&>(_tail->_prev->_data);
        }

        bool empty() const {
          return (_size == 0);
        }

        size_type size() const {
          return _size;
        }

        size_type max_size() const {
          return std::numeric_limits<difference_type>::max();
        }

        template <typename InputIterator>
        void assign(InputIterator first, InputIterator last) {
          clear();
          insert(begin(), first, last);
        }

        void assign(size_type n, const value_type& val) {
          clear();
          insert(begin(), n, val);
        }

        void push_front (const value_type& value) {
          Node *copy = new Node(value);
          insert(begin(), copy);
        }

        void pop_front() {
          erase(begin());
        }

        void push_back(const value_type& value) {
          Node *copy = new Node(value);
          insert(end(), copy);
        }

        void pop_back() {
          erase(--end());
        }

        iterator insert(iterator position, const value_type& val) {
          Node *copy = new Node(val);
          return insert(position, copy);
        }

        void insert(iterator position, size_type n, const value_type& val) {
          while (n--) {
            insert(position, val);
          }
        }

        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last,
        typename ft::enable_if<typename InputIterator::value_type>::type* = 0) {
          while (first != last) {
            insert(position, *first);
            first++;
          }
        }

        iterator erase(iterator position) {
          return erase(position, true);
        }

        iterator erase(iterator first, iterator last) {
          iterator ret = last;

          while (first != last) {
            first = erase(first);
          }
          return ret;
        }

        void swap(list& other) {
          std::swap(_head, other._head);
          std::swap(_tail, other._tail);
          std::swap(_size, other._size);
        }

        void resize(size_type n, value_type val = value_type()) {
          while (_size > n) {
            pop_back();
          }

          while (_size < n) {
            push_back(val);
          }
        }

        void clear() {
          Node *to_free;

          while (_head != NULL) {
            to_free = _head;
            _head = _head->_next;
            delete to_free;
          }
          _head = _tail = new Node();
          _head->_prev = _head->_next = NULL;
          _size = 0;
        }

        /* Operations */

        void splice(const_iterator position, list& other) {
          iterator it = other.begin();
          Node *node;

          while (it != other.end()) {
            node = it._node;
            it = erase(it, false);
            insert(position, node);
          }
        }

        void splice(iterator position, list& other, iterator i) {
          Node *node = i._node;

          other.erase(node, false);
          insert(position, node);
        }

        void splice(iterator position, list& other, iterator first, iterator last) {
          while (first != last) {
           Node *node = first._node;
           first = other.erase(node, false);
           insert(position, node);
          }
        }

        void remove(value_type const& val) {
          iterator it = begin();
          
          while (it != end()) {
            if (*it == val) {
              it = erase(it);
            } else {
              it++;
            }
          }
        }

        template <class Predicate>
        void remove_if(Predicate pred) {
          iterator it = begin();
          
          while (it != end()) {
            if (pred(*it)) {
              it = erase(it);
            } else {
              it++;
            }
          }
        }

        void unique() {
          iterator it = begin();
          iterator prev;

          prev = it;
          if (it != end())
            it++;

          while (it != end()) {
            if (*prev == *it) {
              it = erase(it);
            } else {
              it++;
              prev++;
            }
          }
        }

        template <class BinaryPredicate>
        void unique(BinaryPredicate binary_pred) {
          iterator it = begin();
          iterator prev;

          prev = it;
          if (it != end())
            it++;

          while (it != end()) {
            if (binary_pred(*it, *prev)) {
              it = erase(it);
            } else {
              it++;
            }
          }
        }

        void merge(list& lst) {
          merge(lst, std::less<value_type>());
        }

        template <class Compare>
        void merge(list& lst, Compare comp) {
          iterator x = begin();
          iterator y = lst.begin();

          while (y != lst.end()) {
            Node *node = y._node;
            
            while (x != end() && comp(*x, *y)) {
              x++;
            }

            y = lst.erase(y, false);
            insert(x, node);
          }
        }

        void sort() {
          merge_sort(*this, std::less<value_type>());
        }

        template <class Compare>
        void sort(Compare comp) {
          merge_sort(*this, comp);
        }

        void reverse() {
          list reversed;
          iterator it = begin();
          while (it != end()) {
            reversed.push_front(*it);
            it = erase(it);
          }
          swap(reversed);
        }

    
    protected:
        Node *_head;
        Node *_tail;
        size_t _size;

        iterator insert(iterator position, Node *copy) {
          Node *node = position.getNode();

          copy->_prev = node->_prev;
          copy->_next = node;
          if (node->_prev)
            node->_prev->_next = copy;
          else
            _head = copy;
          node->_prev = copy;
          _size++;
          return iterator(copy);
        }

        iterator erase(iterator position, bool delete_node) {
          Node *node = position.getNode();
          Node *ret = node->_next;

          if (node->_prev) {
            node->_prev->_next = node->_next;
          } else {
            _head = node->_next;
          }
          if (node->_next)
            node->_next->_prev = node->_prev;
          _size--;
          if (delete_node)
            delete node;

          return iterator(ret);
        }

        template <typename Compare>
        void merge_sort(list& lst, Compare comp) {
          list left, right;
          size_t mid = lst.size() / 2;
          iterator lst_mid = lst.begin();
          while (mid--)
            lst_mid++;
          
          if (lst.size() <= 1) {
            return ;
          }

          /* split list recursively  */
          left.splice(left.end(), lst, lst.begin(), lst_mid);
          right.splice(right.end(), lst, lst_mid, lst.end());
          /* sort left and right */
          merge_sort(left, comp);
          merge_sort(right, comp);
          /* merge splitted list into one */
          left.merge(right);
          lst.swap(left);
        }
  };

  template <typename T>
  void swap(list<T>& x, list<T>& y) {
    x.swap(y);
  }

  template <typename T>
  bool operator==(const list<T>& lhs, const list<T>& rhs) {
    if (lhs.size() == rhs.size()) {
      return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    } else {
      return false;
    }
  }

  template <typename T>
  bool operator<(list<T> lhs, list<T> rhs) {
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
  }

  template <typename T>
  bool operator>(list<T> lhs, list<T> rhs) {
    return !(lhs == rhs) && !(lhs < rhs);
  }

  template <typename T>
  bool operator<=(list<T> lhs, list<T> rhs) {
    return !(lhs > rhs);
  }
  
  template <typename T>
  bool operator>=(list<T> lhs, list<T> rhs) {
    return !(lhs < rhs);
  }

  template <typename T>
  bool operator!=(list<T> lhs, list<T> rhs) {
    return !(lhs == rhs);
  }

}  // namespace ft

#endif
