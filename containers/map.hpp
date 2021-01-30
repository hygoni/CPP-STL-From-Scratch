#ifndef MAP_HPP_
# define MAP_HPP_

# include <algorithm>
# include <limits>
# include <functional>
# include <utility>
# include <cmath>

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
      tree_node     *_left;
      tree_node     *_right;
      int            _height;
      value_type     _value;

    public:
      tree_node(const value_type& value) : _value(value) {
        _left = _right = NULL;
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
        a->_right = t;
        update_height(a);
        update_height(b);
        return b;
      }

      static node *right_rotate(node *b) {
        node *a = b->_left;
        node *t = a->_right;

        b->_left = t;
        a->_right = b;
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

      static node *insert(node *x, const value_type& value, const key_compare& cmp) {
        key_type key = value.first;
        mapped_type val = value.second;

        if (x == NULL)
          return new node(value);
        if (cmp(key, x->get_key())) {
          x->_left = insert(x->_left, value, cmp);
        } else if (!cmp(key, x->get_key()) && !cmp(x->get_key(), key)) {
          /* x, y are considered equal when !cmp(x, y) && !cmp(y, x) */
          x->get_value() = val;
          return x;
        } else {
          x->_right = insert(x->_right, value, cmp);
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

  };

  /* implemented using AVL-Tree */
  template <class Key, class T, class Compare = std::less<Key> >
  class map {
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
      
      /*
      iterators
      */

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

      int height() const {
        return _root->get_height();
      }
      mapped_type& operator[](key_type key) {
        if (node::find(_root, key, _cmp) == NULL)
          _root = node::insert(_root, std::make_pair<const key_type, mapped_type>(key, mapped_type()), _cmp);  
       return node::find(_root, key, _cmp)->get_value();
      }

      /*std::pair<iterator, bool>*/ void insert(const value_type& value) {
        node::insert(_root, value, _cmp);
      }
      

      /*
      iterator insert(iterator hint, const value_type& value) {

      }

      template <typename InputIterator>
      void insert(InputIterator first, InputIterator last) {
        while (first != last) {

        }
      }
      */

    protected:
      typedef tree_node<Key, T, Compare> node;
      key_compare _cmp;
      node         *_root;
      size_type    _size;
  };
}

/*  
  template<typename T>
  class map_iterator {
    public:
    
    protected:
      template <typename _T>
      friend class map;

      template <typename _T>
      friend class reverse_map_iterator;

    public:
      typedef Key key_type;
      typedef T mapped_type;
      typedef std::pair<const Key, T> value_type;
      typedef size_t size_type;
      typedef std::ptrdiff_t difference_type;
      typedef Compare key_compare;
      typedef value_type& reference;
      typedef const value_type& const_reference;
      typedef value_type* pointer;
      typedef const value_type* const_pointer;
      typedef ft::bidirectional_iterator_tag iterator_category;

      map_iterator() {

      }

      map_iterator(map_iterator const& it) {

      }

      map_iterator(Node *node) {

      }

      map_iterator& operator=(map_iterator const& it) {
        return *this;
      }

      virtual map_iterator& operator++() {
        return *this;
      }

      virtual map_iterator operator++(int) {
        return current;
      }
      
      virtual map_iterator& operator--() {
        return *this;
      }

      virtual map_iterator operator--(int) {
        return current;
      }

      reference operator*() {
      }

      pointer operator->() const {
      
      }

      Node* getNode() {

      }

      bool operator!=(const map_iterator& x) {
        return (x.)
      }

      template <typename _T>
      friend bool operator==(const map_iterator<_T>& x, const map_iterator<_T>& y);
  };

  template <typename _T>
  bool operator==(const map_iterator<_T>& x, const map_iterator<_T>& y) {
    return x._node == y._node;
  }
*/

#endif  // MAP_HPP_
