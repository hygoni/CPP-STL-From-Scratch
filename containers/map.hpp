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
    
    protected:
      tree_node     *_parent;
      tree_node     *_left;
      tree_node     *_right;
      int            _height;
      value_type     _value;

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

      static node *rebalance(node *x, const key_compare& cmp) {
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
        return rebalance(x, cmp);
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

  template<typename node, typename pointer, typename reference>
  class map_iterator {
    protected:
      node *_node;
      template <typename _Key, typename _T, typename _Compare>
      friend class map;

      template <typename _node_pointer, typename _pointer, typename _reference>
      friend class reverse_map_iterator;

    public:
      typedef ft::bidirectional_iterator_tag iterator_category;

      map_iterator() {
        _node = NULL;
      }

      map_iterator(map_iterator const& it) {
        _node = it._node;
      }

      map_iterator(node *x) {
        _node = x;
      }

      map_iterator& operator=(map_iterator const& it) {
        _node = it._node;
        return *this;
      }

      virtual map_iterator& operator++() {
        _node = node::next_node(_node);
        return *this;
      }

      virtual map_iterator operator++(int) {
        map_iterator current = *this;
        ++(*this);
        return current;
      }
      
      virtual map_iterator& operator--() {
        _node = node::prev_node(_node);
        return *this;
      }

      virtual map_iterator operator--(int) {
        map_iterator current = *this;
        --(*this);
        return current;
      }

      reference operator*() {
        return _node->_value;
      }

      pointer operator->() const {
        return &(_node->_value);
      }

      bool operator!=(const map_iterator& x) {
        return !(*this == x);
      }

      template <typename _node, typename _pointer, typename _reference>
      friend bool operator==(const map_iterator<_node, _pointer, _reference>& x,
      const map_iterator<_node, _pointer, _reference>& y);
  };

  template <typename _node, typename _pointer, typename _reference>
  bool operator==(const map_iterator<_node, _pointer, _reference>& x,
  const map_iterator<_node, _pointer, _reference>& y) {
    return x._node == y._node;
  }

  /* implemented using AVL-Tree */
  template <class Key, class T, class Compare = std::less<Key> >
  class map {
    protected:
      typedef tree_node<Key, T, Compare> node;
   
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

      map() {
        _size = 0;
        _root = NULL;
      }

      template <typename InputIterator>
      map (InputIterator first, InputIterator last, const Compare& comp = Compare()) {
        _size = 0;
        _root = NULL;
      }

      map (const map& other) {
        _size = 0;
        _root = NULL;
      }

      ~map() {
        if (_root != NULL)
          delete _root;
      }

      mapped_type& operator[](key_type key) {
       _root = node::insert(_root, std::make_pair<const key_type, mapped_type>(key, mapped_type()), _cmp, NULL); 
       return node::find(_root, key, _cmp)->get_value();
      }
     
     iterator begin() {
        node *leftmost = node::min_node(_root);
        return iterator(leftmost);
      }

      const_iterator begin() const {
        node *leftmost = const_cast<node*>(node::min_node(_root));
        return const_iterator(leftmost);
      }

      iterator end() {
        return iterator(&_end_node);
      }

      const_iterator end() const {
        node *end_node = const_cast<node*>(&_end_node);
        return const_iterator(end_node);
      }

      std::pair<iterator, bool> insert(const value_type& value) {
        bool is_successful;
        /* logical error */
        node *inserted = node::insert(_root, value, _cmp, &is_successful);
        return std::make_pair<iterator, bool>(iterator(inserted), is_successful);
      }
      

      iterator insert(iterator hint, const value_type& value) {
        (void)hint;
        return insert(value);
      }

      template <typename InputIterator>
      void insert(InputIterator first, InputIterator last) {
        while (first != last) {
          insert(*first);
        }
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

    protected:
      key_compare _cmp;
      node         *_root;
      node         _end_node;
      size_type    _size;
  };
  
}


#endif  // MAP_HPP_
