#ifndef MAP_HPP_
# define MAP_HPP_

# include <algorithm>
# include <limits>
# include <functional>
# include <utility>
# include <cmath>
# include "util.hpp"

namespace ft {

  template <class Key, class T, class Compare = std::less<Key> >
  class tree_node {
    public:
    typedef tree_node<Key, T, Compare> node;
    typedef Key key_type;
    typedef T mapped_type;
    typedef std::pair<const Key, T> value_type;
    typedef Compare key_compare;
    typedef size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    
    protected:
      tree_node     *_parent;
      tree_node     *_left;
      tree_node     *_right;
      int            _height;
      value_type     _value;

      template <typename _Key, typename _T, typename _Compare>
      friend class map;
      template <typename node, typename pointer, typename reference>
      friend class map_iterator;
      template <typename node, typename pointer, typename reference>
      friend class reverse_map_iterator;

    public:
      tree_node(const value_type& value) : _value(value) {
        _left = _right = _parent = NULL;
        _height = 1;
      }

      tree_node() {
        _left = _right = _parent = NULL;
        _height = 1;
      }

      ~tree_node() {
        if (_left != NULL)
          delete _left;
        if (_right != NULL)
          delete _right;
      }

      const key_type& get_key() const {
        return _value.first;
      }

      mapped_type& get_value() {
        return _value.second;
      }

      int get_height() const {
        return _height;
      }

      static node *left_rotate(node *a) {
        node *b = a->_right;
        node *t = b->_left;

        b->_parent = a->_parent;
        b->_left = a;
        a->_parent = b;
        a->_right = t;
        if (t)
          t->_parent = a;
        update_height(a);
        update_height(b);
        return b;
      }

      static node *right_rotate(node *b) {
        node *a = b->_left;
        node *t = a->_right;

        a->_parent = b->_parent;
        b->_left = t;
        if (t)
          t->_parent = b;
        a->_right = b;
        b->_parent = a;
        update_height(a);
        update_height(b);
        return a;
      }

      static int get_height(node *x) {
        if (x == NULL)
          return 0;
        else
          return x->_height;
      }

      static void update_height(node *node) {
        node->_height = std::max(get_height(node->_left), get_height(node->_right)) + 1;
      }

      static int get_balance(node *x) {
        if (x == NULL)
          return 0;
        else
          return get_height(x->_left) - get_height(x->_right);
      }

      static node *rebalance(node *x) {
        int balance = get_balance(x);
        int left_balance = get_balance(x->_left);
        int right_balance = get_balance(x->_right);

        if (balance > 1 && left_balance > 0) {
          return right_rotate(x);
        }

        if (balance < -1 && right_balance < 0) {
          return left_rotate(x);
        }

        if (balance > 1 && right_balance < 0) {
          x->_left = left_rotate(x->_left);
          return right_rotate(x);
        }

        if (balance < -1 && left_balance > 0) {
          x->_right = right_rotate(x->_right);
          return left_rotate(x);
        }
        return x;
      }

      static node *insert(node *x, const value_type& value, const key_compare& cmp, bool *is_successful) {
        key_type key = value.first;

        if (x == NULL) {
          if (is_successful)
            *is_successful = true;
          return new node(value);
        }
        if (cmp(key, x->get_key())) {
          x->_left = insert(x->_left, value, cmp, is_successful);
          x->_left->_parent = x;
        } else if (!cmp(key, x->get_key()) && !cmp(x->get_key(), key)) {
          /* x, y are considered equal when !cmp(x, y) && !cmp(y, x) */
          if (is_successful)
            *is_successful = false;
          return x;
        } else {
          x->_right = insert(x->_right, value, cmp, is_successful);
          x->_right->_parent = x;
        }
        update_height(x);
        return rebalance(x);
      }

      static node *find(node *x, const key_type& key, const key_compare& cmp) {
        if (x == NULL)
          return NULL;
        if (cmp(key, x->get_key())) {
          return find(x->_left, key, cmp);
        } else if (!cmp(x->get_key(), key) && !cmp(key, x->get_key())) {
          return x;
        } else {
          return find(x->_right, key, cmp);
        }
      }

      static node* erase(node *x, const key_type& key, const key_compare& cmp) {
        if (x == NULL)
          return x;
        if (cmp(key, x->get_key())) {
          x->_left = erase(x->_left, key, cmp);
        } else if (!cmp(key, x->get_key()) && !cmp(x->get_key(), key)) {
          /* found node */

          if (x->_left == NULL || x->_right == NULL) {
            node *child = x->_left ? x->_left : x->_right;
            /* has no child */
            if (child == NULL) {
              child = x;
              x = NULL;
            } else {
              /* has one child */
              x->_left = child->_left;
              x->_right = child->_right;
              *const_cast<int*>(&x->_value.first) = child->_value.first; 
              x->_value.second = child->_value.second;
            }
            /* prevent use-after-free */
            child->_left = child->_right = NULL;
            delete child;
          } else {
            /* has two child */
            node *next = min_node(x->_right); /* inorder successor */
            *const_cast<int*>(&x->_value.first) = next->_value.first; 
            x->_value.second = next->_value.second;
            x->_right = erase(x->_right, next->get_key(), cmp);
          }
        } else {
          x->_right = erase(x->_right, key, cmp);
        }
        if (x == NULL)
          return x;
        update_height(x);
        return rebalance(x);
      }

      static node *min_node(node *x) {
        while (x != NULL && x->_left != NULL)
          x = x->_left;
        return x;
      }

      static node *max_node(node *x) {
        while (x != NULL && x->_right != NULL)
          x = x->_right;
        return x;
      }

      /* leftmost child of right subtree, or parents */
      static node *next_node(const node *x) {
        if (x->_right) {
          return min_node(x->_right);
        } else {
          node *parent = x->_parent;
          while (parent != NULL && parent->_right == x) {
            x = parent;
            parent = parent->_parent;
          }
          return parent;
        }
      }

      /* rightmost child of left subtree, or parents */
      static node *prev_node(const node *x) {
        if (x->_left) {
          return max_node(x->_left);
        } else {
          node *parent = x->_parent;
          while (parent != NULL && parent->_left == x) {
            x = parent;
            parent = parent->_parent;
          }
          return parent;
        }
      }

  };

  template<typename node, typename _pointer, typename _reference>
  class map_iterator {
    protected:
      node *_node;
      node *_end_node;
      template <typename _Key, typename _T, typename _Compare>
      friend class map;

      template <typename _node_pointer, typename __pointer, typename __reference>
      friend class reverse_map_iterator;

      template <typename _node_pointer, typename __pointer, typename __reference>
      friend class map_iterator;
    public:
      typedef ft::bidirectional_iterator_tag iterator_category;
      typedef typename node::value_type value_type;
      typedef typename node::key_type key_type;
      typedef typename node::mapped_type mapped_type;
      typedef typename node::key_compare key_compare;
      typedef typename node::difference_type difference_type;
      typedef typename node::reference reference;
      typedef typename node::const_reference const_reference;
      typedef typename node::pointer pointer;
      typedef typename node::const_pointer const_pointer;

      map_iterator() {
        _node = NULL;
      }

      template <typename ptr, typename ref>
      map_iterator(map_iterator<node, ptr, ref> const& it) {
        _node = it._node;
        _end_node = it._end_node;
      }

      map_iterator(node *x, node *end_node) {
        _node = x;
        _end_node = end_node;
      }

      map_iterator& operator=(map_iterator const& it) {
        _node = it._node;
        _end_node = it._end_node;
        return *this;
      }

      virtual map_iterator& operator++() {
        _node = node::next_node(_node);
        if (_node == NULL)
          _node = _end_node;
        return *this;
      }

      virtual map_iterator operator++(int) {
        map_iterator current = *this;
        ++(*this);
        return current;
      }
      
      virtual map_iterator& operator--() {
        _node = node::prev_node(_node);
        if (_node == NULL)
          _node = _end_node;
        return *this;
      }

      virtual map_iterator operator--(int) {
        map_iterator current = *this;
        --(*this);
        return current;
      }

      _reference operator*() {
        return _node->_value;
      }

      _pointer operator->() const {
        return &(_node->_value);
      }

      bool operator!=(const map_iterator& x) {
        return !(*this == x);
      }

      template <typename _node, typename __pointer, typename __reference>
      friend bool operator==(const map_iterator<_node, __pointer, __reference>& x,
      const map_iterator<_node, __pointer, __reference>& y);
  };

  template <typename _node, typename __pointer, typename __reference>
  bool operator==(const map_iterator<_node, __pointer, __reference>& x,
  const map_iterator<_node, __pointer, __reference>& y) {
    return x._node == y._node;
  }

  template<typename node, typename _pointer, typename _reference>
  class reverse_map_iterator {
    protected:
      node *_node;
      node *_end_node;
      template <typename _Key, typename _T, typename _Compare>
      friend class map;

      template <typename _node, typename __pointer, typename __reference>
      friend class reverse_map_iterator;

    public:
      typedef ft::bidirectional_iterator_tag iterator_category;
      typedef typename node::value_type value_type;
      typedef typename node::key_type key_type;
      typedef typename node::mapped_type mapped_type;
      typedef typename node::key_compare key_compare;
      typedef typename node::difference_type difference_type;
      typedef typename node::reference reference;
      typedef typename node::const_reference const_reference;
      typedef typename node::pointer pointer;
      typedef typename node::const_pointer const_pointer;

      reverse_map_iterator() {
        _node = NULL;
      }

      template <typename ptr, typename ref>
      reverse_map_iterator(map_iterator<node, ptr, ref> const& it) {
        _node = it._node;
        _end_node = it._end_node;
      }

      template <typename ptr, typename ref>
      reverse_map_iterator(reverse_map_iterator<node, ptr, ref> const& it) {
        _node = it._node;
        _end_node = it._end_node;
      }

      reverse_map_iterator(node *x, node *end_node) {
        _node = x;
        _end_node = end_node;
      }

      reverse_map_iterator& operator=(reverse_map_iterator const& it) {
        _node = it._node;
        _end_node = it._end_node;
        return *this;
      }

      virtual reverse_map_iterator& operator++() {
        _node = node::prev_node(_node);
        if (_node == NULL)
          _node = _end_node;
        return *this;
      }

      virtual reverse_map_iterator operator++(int) {
        reverse_map_iterator current = *this;
        ++(*this);
        return current;
      }
      
      virtual reverse_map_iterator& operator--() {
        _node = node::next_node(_node);
        if (_node == NULL)
          _node = _end_node;
        return *this;
      }

      virtual reverse_map_iterator operator--(int) {
        reverse_map_iterator current = *this;
        --(*this);
        return current;
      }

      _reference operator*() {
        return _node->_value;
      }

      _pointer operator->() const {
        return &(_node->_value);
      }

      bool operator!=(const reverse_map_iterator& x) {
        return !(*this == x);
      }

      template <typename _node, typename __pointer, typename __reference>
      friend bool operator==(const reverse_map_iterator<_node, __pointer, __reference>& x,
      const reverse_map_iterator<_node, __pointer, __reference>& y);
  };

  template <typename _node, typename __pointer, typename __reference>
  bool operator==(const reverse_map_iterator<_node, __pointer, __reference>& x,
  const reverse_map_iterator<_node, __pointer, __reference>& y) {
    return x._node == y._node;
  }

  /* implemented using AVL-Tree */
  template <class Key, class T, class Compare = std::less<Key> >
  class map {
    protected:
      typedef tree_node<const Key, T, Compare> node;
   
    public:
      typedef Key key_type;
      typedef T mapped_type;
      typedef std::pair<const Key, T> value_type;
      typedef Compare key_compare;
      typedef size_t size_type;
      typedef std::ptrdiff_t difference_type;
      typedef value_type& reference;
      typedef const value_type& const_reference;
      typedef value_type* pointer;
      typedef const value_type* const_pointer;
      typedef map_iterator<node, pointer, reference> iterator;
      typedef map_iterator<node, const_pointer, const_reference> const_iterator;
      typedef reverse_map_iterator<node, pointer, reference> reverse_iterator;
      typedef reverse_map_iterator<node, const_pointer, const_reference> const_reverse_iterator;

      class value_compare {
        protected:
          Compare _cmp;

        public:
          typedef bool result_type;
          typedef value_type first_argument_type;
          typedef value_type second_argument_type;

          value_compare(Compare c) {
            _cmp = c;
          }

          result_type operator()(value_type x, value_type y) {
            return _cmp(x.first, y.first);
          }
      };

      map() {
        _size = 0;
        _root = NULL;
        _end_node = new node();
      }

      explicit map(const Compare& comp) {
        _size = 0;
        _root = NULL;
        _end_node = new node();
        _cmp = comp;
      }

      template <typename InputIterator>
      map (InputIterator first, InputIterator last, const Compare& comp = Compare()) {
        _size = 0;
        _root = NULL;
        _end_node = new node();
        _cmp = comp;
        insert(first, last);
      }

      map (const map& other) {
        _size = 0;
        _root = NULL;
        _end_node = new node();
        insert(other.begin(), other.end());
      }

      ~map() {
        if (_root != NULL)
          delete _root;
        if (_end_node != NULL) {
          /* prevent double free */
          _end_node->_left = _end_node->_right = NULL;
          delete _end_node;
        }
      }

      mapped_type& operator[](key_type key) {
       insert(std::make_pair<const key_type, mapped_type>(key, mapped_type()));
       return node::find(_root, key, _cmp)->get_value();
      }
     
     iterator begin() {
       if (_size == 0)
         return end();
        node *leftmost = node::min_node(_root);
        return iterator(leftmost, _end_node);
      }

      const_iterator begin() const {
        if (_size == 0)
          return end();
        node *leftmost = const_cast<node*>(node::min_node(_root));
        return const_iterator(leftmost, _end_node);
      }

      reverse_iterator rbegin() {
        if (_size == 0)
          return rend();
        return ++reverse_iterator(_end_node, _end_node);
      }

      const_reverse_iterator rbegin() const {
        if (_size == 0)
          return rend();
        return ++const_reverse_iterator(_end_node, _end_node);
      }

      iterator end() {
        return iterator(_end_node, _end_node);
      }

      const_iterator end() const {
        return const_iterator(_end_node, _end_node);
      }

      reverse_iterator rend() {
        return reverse_iterator(_end_node, _end_node);
      }

      const_reverse_iterator rend() const {
        return const_reverse_iterator(_end_node, _end_node);
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
      
      void clear() {
        if (_root != NULL)
          delete _root;
        _root = NULL;
        _size = 0;
      }

      std::pair<iterator, bool> insert(const value_type& value) {
        bool is_successful;
        /* logical error */
        node *inserted = node::insert(_root, value, _cmp, &is_successful);
        if (is_successful) {
          _root = inserted;
          _root->_parent = NULL;
          _size++;
          _end_node->_left = node::max_node(_root);
          _end_node->_right = node::min_node(_root);
        }
        return std::make_pair<iterator, bool>(iterator(inserted, _end_node), is_successful);
      }
      

      iterator insert(iterator hint, const value_type& value) {
        (void)hint;
        return insert(value).first;
      }

      template <typename InputIterator>
      void insert(InputIterator first, InputIterator last) {
        while (first != last) {
          insert(*first);
          first++;
        }
      }

      void erase(iterator pos) {
        _erase(pos);
      }

      void erase(iterator first, iterator last) {
        while (first != last) {
          first = _erase(first);
        }
      }

      size_type erase(const key_type& key) {
        iterator found = find(key);
        if (found == end())
          return 0;
        else {
          erase(found);
          return 1;
        }
      }

      void swap(map& other) {
        std::swap(_size, other._size);
        std::swap(_root, other._root);
        std::swap(_end_node, other._end_node);
        std::swap(_cmp, other._cmp);
      }

      size_type count(const key_type& key) {
        if (find(key) != end())
          return 1;
        else
          return 0;
      }

      iterator find(const key_type& key) {
        node *x = node::find(_root, key, _cmp);
        if (x == NULL)
          return end();
        else
          return iterator(x, _end_node);
      }

      const_iterator find(const key_type& key) const {
        node *x = node::find(_root, key, _cmp);
        if (x == NULL)
          return end();
        else
          return const_iterator(x, _end_node);
      }

      std::pair<iterator, iterator> equal_range(const key_type& key) {
        iterator first, last;

        first = lower_bound(key);
        last = upper_bound(key);
        return std::make_pair(first, last);
      }

      std::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
        const_iterator first, last;
        
        first = lower_bound(key);
        last = upper_bound(key);
        return std::make_pair(first, last);
      }

      iterator lower_bound(const key_type& key) {
        iterator it = begin();
        while (it != end()) {
          if (!_cmp(it->first, key)) {
            break;
          }
          it++;
        }
        return it;
      }
      
      const_iterator lower_bound(const key_type& key) const {
        const_iterator it = begin();
        while (it != end()) {
          if (!_cmp(it->first, key)) {
            break;
          }
          it++;
        }
        return it;
      }

      iterator upper_bound(const key_type& key) {
        iterator it = begin();
        while (it != end()) {
          if (_cmp(key, it->first)) {
            break;
          }
          it++;
        }
        return it;
      }

      const_iterator upper_bound(const key_type& key) const {
        const_iterator it = begin();
        while (it != end()) {
          if (_cmp(key, it->first)) {
            break;
          }
          it++;
        }
        return it;
      }

      key_compare key_comp() const {
        return _cmp;
      }

      value_compare value_comp() const {
        return value_compare(_cmp);
      }
    
    protected:
      key_compare _cmp;
      node         *_root;
      node         *_end_node;
      size_type    _size;
      
      iterator _erase(iterator pos) {
        key_type key = pos->first;
        _root = node::erase(_root, key, _cmp);
        _end_node->_left = node::max_node(_root);
        _end_node->_right = node::min_node(_root);
        _size--;
        return lower_bound(key);
      }
  };

  template <typename _Key, typename _T, typename _Compare>
  bool operator==(const map<_Key, _T, _Compare>& lhs, const map<_Key, _T, _Compare>& rhs) {
    if (lhs.size() == rhs.size()) {
      return std::equal(lhs.begin(), lhs.end(), rhs.begin());
    } else {
      return false;
    }
  }

  template <typename _Key, typename _T, typename _Compare>
  bool operator!=(const map<_Key, _T, _Compare>& lhs, const map<_Key, _T, _Compare>& rhs) {
    return !(lhs == rhs);
  }

  template <typename _Key, typename _T, typename _Compare>
  bool operator<(const map<_Key, _T, _Compare>& lhs, const map<_Key, _T, _Compare>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
  }

  template <typename _Key, typename _T, typename _Compare>
  bool operator<=(const map<_Key, _T, _Compare>& lhs, const map<_Key, _T, _Compare>& rhs) {
    return (lhs < rhs) || (lhs == rhs);
  }
  
  template <typename _Key, typename _T, typename _Compare>
  bool operator>(const map<_Key, _T, _Compare>& lhs, const map<_Key, _T, _Compare>& rhs) {
    return !((lhs < rhs) && (lhs == rhs));
  }
  
  template <typename _Key, typename _T, typename _Compare>
  bool operator>=(const map<_Key, _T, _Compare>& lhs, const map<_Key, _T, _Compare>& rhs) {
    return !(lhs < rhs);
  }

  template <typename _Key, typename _T, typename _Compare>
  void swap(map<_Key, _T, _Compare>& lhs, map<_Key, _T, _Compare>& rhs) {
    lhs.swap(rhs);
  }

}


#endif  // MAP_HPP_
