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
# include <cstddef>
# include <limits>
# include <memory>

namespace ft {

  template<typename T>
  class ListNode {
    private:
        T         _data;
        ListNode  *_prev;
        ListNode  *_next;

        template <typename _T>
        friend class List;
        template <typename _T>
        friend class ListIterator;
    public:
      
      ListNode(T data) {
        _data = data;
      }

      ListNode(ListNode const& node) {
        _data = node._data;
        _prev = node._prev;
        _next = node._next;
      }

  };

  /* Iterator class (bidirectional) */
  template<typename T>
  class ListIterator {
    public:
      typedef ListNode<T> Node;
    
    protected:
      Node *_node;
      template <typename _T>
      friend class List;

    public:
      typedef T value_type;
      typedef T* pointer;
      typedef T& reference;
      typedef T const& const_reference;
      typedef std::ptrdiff_t difference_type; 
     
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
      virtual ListIterator operator--() {
        _node = _node->_prev;
        return *this;
      }

      /* postfix decrement */
      virtual ListIterator& operator--(int) {
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

      template <typename _T>
      friend bool operator==(const ListIterator<_T> x, const ListIterator<_T> y);
  };

  template <typename T>
  class ReverseListIterator : ListIterator {
    public:
      /* prefix increment */
      virtual ListIterator& operator--() {
        _node = _node->_next;
        return *this;
      }

      /* postfix increment */
      virtual ListIterator operator--(int) {
        ListIterator current = *this;
        ++(*this);
        return current;
      }

      /* prefix decrement */
      virtual ListIterator operator++() {
        _node = _node->_prev;
        return *this;
      }

      /* postfix decrement */
      virtual ListIterator& operator++(int) {
        ListIterator current = *this;
        --(*this);
        return current;
      }
  }

  template <typename _T>
  bool operator==(const ListIterator<_T> x, const ListIterator<_T> y) {
    return (x._node == y._node);
  }

  template <typename _T>
  bool operator!=(const ListIterator<_T> x, const ListIterator<_T> y) {
    return !(x == y);
  }

  template<typename T>
  class List {
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
        typedef size_t size_type;
        typedef std::ptrdiff_t difference_type;

        
        explicit List() {
          _size = 0;
          _head = _tail = NULL;
        }

        explicit List(size_type n, value_type const& val = value_type()) {
          _size = 0;
          _head = _tail = NULL;
          insert(begin(), n, val);
        }

        template <class InputIterator>
        List(InputIterator first, InputIterator last) {
          _size = 0;
          _head = _tail = NULL;
          while (first != last) {
            push_back(*first);
            first++;
          }
        }

        List(List const& list) {
          _size = 0;
          _head = _tail = NULL;
          *this = list;
        }

        virtual ~List() {
          Node *current = _head;
          Node *to_free = NULL;
          while (current != NULL) {
            to_free = current;
            current = current->_next;
            delete to_free;
          }
        }

        List& operator=(List const& list) {
          const_iterator it = list.begin();

          while (it != list.end()) {
            push_back(*it);
            it++;
          }
          return *this;
        }

        iterator begin() {
          return iterator(_head);
        }


        iterator end() {
          if (_tail == NULL)
            return iterator();
          return iterator(_tail->_next);
        }

        const_iterator begin() const {
          typedef ListNode<const value_type> const_node;
          return const_iterator(reinterpret_cast<const_node*>(_head));
        }

        const_iterator end() const {
          if (_tail == NULL)
            return const_iterator();
          typedef ListNode<const value_type> const_node;
          return const_iterator(reinterpret_cast<const_node*>(_tail->_next));
        }

        reference front() {
          return _head->_data;
        }

        const_reference front() const {
          return const_cast<const value_type&>(_head->_data);
        }

        reference back() {
          return _tail->_data;
        }

        const_reference back() const {
          return const_cast<const value_type&>(_tail->_data);
        }

        bool empty() const {
          return (_size == 0);
        }

        size_type size() {
          return _size;
        }

        size_type max_size() const {
          return std::numeric_limits<difference_type>::max();
        }

        /* assign */

        void push_front (const value_type& value) {
          Node *copy = new Node(value);
          if (_head == NULL) {
            _head = copy;
            _tail = copy;
            _head->_prev = _tail->_prev =  NULL;
            _head->_next = _tail->_next = NULL;
          } else {
            _head->_prev = copy;
            copy->_next = _head;
            copy->_prev = NULL;
            _head = copy;
          }
          _size++;
        }

        void pop_front() {
          if (_head == NULL)
            return;

          if (_head == _tail) {
            delete _head;
            _head = _tail = NULL;
          } else {
            Node *to_free = _head;
            _head = _head->_next;
            _head->_prev = NULL;
            delete to_free;
          }
          _size--;
        }

        void push_back(const value_type& value) {
          Node *copy = new Node(value);
          if (_head == NULL) {
            _head = copy;
            _tail = copy;
            _head->_prev = _tail->_prev =  NULL;
            _head->_next = _tail->_next = NULL;
          } else {
            _tail->_next = copy;
            copy->_prev = _tail;
            copy->_next = NULL;
            _tail = copy;
          }
          _size++;
        }

        void pop_back() {
          if (_head == NULL)
            return;

          if (_head == _tail) {
            delete _head;
            _head = _tail = NULL;
          } else {
            Node *to_free = _tail;
            _tail = _tail->_prev;
            delete to_free;
            _tail->_next = NULL;
          }
          _size--;
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

        void insert(iterator position, iterator first, iterator last) {
          while (first != last) {
            insert(position, *first);
            first++;
            position++;
          }
        }

        iterator erase(iterator position) {
          return erase(position, true);
        }

        void erase(iterator first, iterator last) {
          iterator ret = last;

          while (first != last) {
            ret = erase(first);
            first++;
          }
          return ret;
        }

        void swap(List& list) {
          std::swap(_head, list._head);
          std::swap(_tail, list._tail);
          std::swap(_size, list._size);
        }

        void resize(size_type n, value_type val = value_type()) {
          while (_size > n) {
            pop_back();
          }

          while (_size < n) {
            push_back(new Node(val));
          }
        }

        void clear() {
          Node *to_free;

          while (_head != NULL) {
            to_free = _head;
            _head = _head->_next;
            delete to_free;
          }
          _head = _tail = NULL;
          _size = 0;
        }

        /* Operations */

        void splice(iterator position, List& list) {
          iterator it = list.begin();

          while (it != list.end()) {
            splice(position, it);
            it++;
            position++;
          }
        }

        void splice(iterator position, List& list, iterator i) {
          Node *node = *i;

          list.erase(node, false);
          insert(position, node);
        }

        void splice(iterator position, List& list, iterator first, iterator last) {
          while (first != last) {
           Node *node = *first;

           list.erase(node, false);
           insert(position, node);
           position++;
           first++;
          }
        }

        void remove(value_type const& val) {
          iterator it = begin();
          
          while (it != end()) {
            if (it->_data == val) {
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

        void merge(List& list) {
          iterator x = begin();
          iterator y = list.begin();

          while (y != list.end()) {
            Node *node = *y;
            
            while (x != end() && *x > *y) {
              x++;
            }

            list.erase(y, false);
            if (x == end()) {
              push_back(node);
            } else {
              insert((x + 1), node);
            }
            y++;
          }
        }

        template <class Compare>
        void merge(List& list, Compare comp) {
          iterator x = begin();
          iterator y = list.begin();

          while (y != list.end()) {
            Node *node = *y;
            
            while (x != end() && comp(*x, *y)) {
              x++;
            }

            list.erase(y, false);
            if (x == end()) {
              push_back(node);
            } else {
              iterator x_plus_one = x;
              x_plus_one++;
              /* TODO */
              insert(x_plus_one, node);
            }
            y++;
          }
        }

        void sort() {
          merge_sort(*this);
        }

        template <class Compare>
        void sort(Compare comp) {
          merge_sort(*this, comp);
        }

        void reverse() {
        
        }

    
    protected:
        Node *_head;
        Node *_tail;
        size_t _size;

        iterator insert(iterator position, Node *copy) {
          Node *node = position.getNode();

          /* position == end() */
          if (node == NULL) {
            copy->_prev = copy->_next = NULL;
            _head = _tail = copy;
          } else {
            if (node->_prev) {
              node->_prev->_next = copy;
            } else {
              _head = copy;
            }
            copy->_prev = node->_prev;
            copy->_next = node;
            node->_prev = copy;
          }
          _size++;
          return iterator(copy);
        }

        iterator erase(iterator position, bool delete_node) {
          Node *node = position.getNode();
          Node *ret = node->_next;

          if (node->_prev) {
            node->_prev->_next = node->_next;
            if (delete_node)
              delete node;
            return iterator(ret);
          } else {
            if (delete_node)
              delete node;
            _head = _tail = NULL;
            _size--;
            return iterator();
          }
        }

        template <typename Compare>
        void merge_sort(List &list, Compare comp) {
          List left, right;
          size_t mid = list.size() / 2;
          
          if (list.size() == 1) {
            return ;
          }
          left.splice(left.begin(), list.begin(), list.begin() + mid);
          right.splice(right.begin(), list.begin() + mid, list.end());
          merge_sort(left);
          merge_sort(right);
          list.merge(left, comp);
          list.merge(right, comp);
        }
  };

  template <typename T>
  void swap(List<T> &x, List<T>& y) {
    x.swap(y);
  }

}  // namespace ft

#endif
