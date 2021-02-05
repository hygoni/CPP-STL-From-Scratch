#ifndef VECTOR_HPP_
#define VECTOR_HPP_

# include <limits>
# include <algorithm>
# include <functional>
# include <stdexcept>
# include "util.hpp"
# define DEFAULT_CAPACITY (size_type)(512)

namespace ft {

  template<typename T>
  class VectorIterator {
    protected:
      T**         _ptr;
      int         _idx;

      template <typename _T>
      friend class vector;
      template <typename _T>
      friend class ReverseVectorIterator;
      template <typename _T>
      friend class VectorIterator;

    public:
      typedef T value_type;
      typedef T* pointer;
      typedef T& reference;
      typedef T const& const_reference;
      typedef std::ptrdiff_t difference_type; 
      typedef ft::bidirectional_iterator_tag iterator_category;

      VectorIterator() {
        _ptr = NULL;
        _idx = 0;
      }
      template <typename _T>
      VectorIterator(VectorIterator<_T> const& it) {
        _ptr = (T**)it._ptr;
        _idx = it._idx;
      }

      VectorIterator(value_type **ptr, int idx) {
        _ptr = ptr;
        _idx = idx;
      }

      VectorIterator& operator=(VectorIterator const& it) {
       _ptr = it._ptr;
       _idx = it._idx;
        return *this;
      }

      /* prefix increment */
      virtual VectorIterator& operator++() {
        _idx++;
        return *this;
      }

      /* postfix increment */
      virtual VectorIterator operator++(int) {
        VectorIterator current = *this;
        ++(*this);
        return current;
      }

      virtual VectorIterator& operator+(int val) {
        _idx += val;
        return *this;
      }

      virtual VectorIterator& operator-(int val) {
        _idx -= val;
        return *this;
      }
      
      /* prefix decrement */
      virtual VectorIterator& operator--() {
        _idx--;
        return *this;
      }

      /* postfix decrement */
      virtual VectorIterator operator--(int) {
        VectorIterator current = *this;
        --(*this);
        return current;
      }

      reference operator*() {
        return (*_ptr)[_idx];
      }

      pointer operator->() const {
        return &(*_ptr)[_idx];
      }

      bool operator!=(const VectorIterator& x) {
        return !(*this == x);
      }

      template <typename _T>
      friend bool operator==(const VectorIterator<_T>& x, const VectorIterator<_T>& y);
  };
  
  template <typename _T>
  bool operator==(const VectorIterator<_T>& x, const VectorIterator<_T>& y) {
    return (x._ptr == y._ptr) && (x._idx == y._idx);
  }

  template<typename T>
  class ReverseVectorIterator {
    protected:
      T**         _ptr;
      int         _idx;

      template <typename _T>
      friend class vector;

      template <typename _T>
      friend class ReverseVectorIterator;
    public:
      typedef T value_type;
      typedef T* pointer;
      typedef T& reference;
      typedef T const& const_reference;
      typedef std::ptrdiff_t difference_type; 
      typedef ft::bidirectional_iterator_tag iterator_category;

      ReverseVectorIterator() {
        _ptr = NULL;
        _idx = 0;
      }

      template <typename _T>
      ReverseVectorIterator(VectorIterator<_T> const& it) {
        _ptr = (T**)it._ptr;
        _idx = it._idx;
      }

      template <typename _T>
      ReverseVectorIterator(ReverseVectorIterator<_T> const& it) {
        _ptr = (T**)it._ptr;
        _idx = it._idx;
      }

      ReverseVectorIterator(value_type **ptr, int idx) {
        _ptr = ptr;
        _idx = idx;
      }

      ReverseVectorIterator& operator=(ReverseVectorIterator const& it) {
       _ptr = it._ptr;
       _idx = it._idx;
        return *this;
      }

      /* prefix increment */
      ReverseVectorIterator& operator++() {
        _idx--;
        return *this;
      }

      /* postfix increment */
      ReverseVectorIterator operator++(int) {
        ReverseVectorIterator current = *this;
        ++(*this);
        return current;
      }

      ReverseVectorIterator& operator+(int val) {
        _idx -= val;
        return *this;
      }

      ReverseVectorIterator& operator-(int val) {
        _idx += val;
        return *this;
      }
      
      /* prefix decrement */
      ReverseVectorIterator& operator--() {
        _idx++;
        return *this;
      }

      /* postfix decrement */
      ReverseVectorIterator operator--(int) {
        ReverseVectorIterator current = *this;
        --(*this);
        return current;
      }

      reference operator*() {
        return (*_ptr)[_idx];
      }

      pointer operator->() const {
        return &(*_ptr)[_idx];
      }

      bool operator!=(const ReverseVectorIterator& x) {
        return !(*this == x);
      }

      template <typename _T>
      friend bool operator==(const ReverseVectorIterator<_T>& x, const ReverseVectorIterator<_T>& y);
  };

  template <typename _T>
  bool operator==(const ReverseVectorIterator<_T>& x, const ReverseVectorIterator<_T>& y) {
    return (x._ptr == y._ptr) && (x._idx == y._idx);
  }

  template <typename T>
  class vector {
    private:
      T                 *_array;
      size_t            _capacity;
      size_t            _length;
      double            _factor;

    public:
      typedef T value_type;
      typedef size_t size_type;
      typedef std::ptrdiff_t difference_type;
      typedef T& reference;
      typedef const T& const_reference;
      typedef T* pointer;
      typedef const T* const_pointer;
      typedef VectorIterator<value_type> iterator;
      typedef VectorIterator<const value_type> const_iterator;
      typedef ReverseVectorIterator<value_type> reverse_iterator;
      typedef ReverseVectorIterator<const value_type> const_reverse_iterator;

      vector() {
        _capacity = DEFAULT_CAPACITY;
        _length = 0;
        _array = new value_type[_capacity];
        _factor = 0.75;
      }

      explicit vector(size_type count, const value_type& value = value_type()) {
        _capacity = std::max(DEFAULT_CAPACITY, count);
        _length = 0;
        _array = new value_type[_capacity];
        _factor = 0.75;

        while (count--) {
          push_back(value);
        }
      }

      template <class InputIterator, typename ft::enable_if<typename InputIterator::value_type>::type*>
      vector(InputIterator first, InputIterator last) : _factor(0.75) {
        _capacity = DEFAULT_CAPACITY;
        _length = 0;
        _array = new value_type[_capacity];
        _factor = 0.75;

        while (first != last) {
          push_back(*first);
          first++;
        }
      }

      vector(const vector& other) {
        _array = NULL;
        _factor = 0.75;
        *this = other;
      }

      vector& operator=(const vector& other) {
        _capacity = other._capacity;
        _length = other._length;
        if (_array != NULL) {
          delete[] _array;
        }
        _array = new value_type[_capacity];
        std::copy(other._array, other._array + other._length, _array);
        return *this;
      }

      virtual ~vector() {
        delete[] _array;
      }

      reference at(size_type pos) {
        if (pos >= size()) {
          throw std::out_of_range("vector index out of range");
        }
        return _array[pos];
      }

      const_reference at(size_type pos) const {
        if (pos >= size()) {
          throw std::out_of_range("vector index out of range");
        }
        return _array[pos];
      }

      reference operator[](size_type pos) {
        return _array[pos];
      }

      const_reference operator[](size_type pos) const {
        return _array[pos];
      }

      reference front() {
        return *begin();
      }

      const_reference front() const {
        return *begin();
      }

      reference back() {
        return *(--end()); 
      }
      
      const_reference back() const {
        return *(--end());
      }

      iterator begin() {
        return iterator(&_array, 0);
      }

      const_iterator begin() const {
        return const_iterator((const T**)&_array, 0);
      }

      iterator end() {
        return iterator(&_array, _length);
      }

      const_iterator end() const {
        return const_iterator((const T**)&_array, _length);
      }

      reverse_iterator rbegin() {
        return reverse_iterator(iterator(&_array, _length - 1));
      }

      const_reverse_iterator rbegin() const {
        return const_reverse_iterator(iterator(&_array, _length - 1));
      }

      reverse_iterator rend() {
        return reverse_iterator(iterator(&_array, -1));
      }

      const_reverse_iterator rend() const {
        return const_reverse_iterator(iterator(&_array, -1));
      }

      bool empty() const {
        return (_length == 0);
      }

      size_type size() const {
        return _length;
      }

      size_type max_size() const {
        return std::numeric_limits<difference_type>::max();
      }

      void reserve(size_type new_cap) {
        if (_capacity < new_cap) {
          T *new_array = new T[new_cap];
          std::copy(_array, _array + _length, new_array);
          delete[] _array;
          _array = new_array;
          _capacity = new_cap;
        }
      }

      size_type capacity() const {
        return _capacity;
      }

      void clear() {
        _length = 0;
      }

      iterator insert(iterator pos, const value_type& value) {
        /* if usage is above factor, reserve vector */
        if (((double)_length / (double)_capacity) >= _factor) {
          reserve(_capacity * 2);
        }
        
        _length++;
        value_type tmp = value;
        while (pos != end()) {
          std::swap(tmp, *pos);
          pos++;
        }
        return pos;
      }

      iterator insert(iterator pos, size_type count, const value_type& value) {
        iterator ret = pos;
        while (count--) {
          ret = insert(pos, value);
        }
        return ret;
      }
      
      template <class InputIterator>
      iterator insert(iterator pos, InputIterator first, InputIterator last,
      typename ft::enable_if<typename InputIterator::value_type>::type* = 0) {
        while (first != last) {
          insert(pos, *first);
          first++;
          pos++;
        }
        return pos;
      }

      iterator erase(iterator pos) {
        iterator ret = pos + 1;
        while (pos != end()) {
          value_type value = *(pos + 1);
          std::swap(value, *pos);
          pos++;
        }
        _length--;
        return ret;
      }

      iterator erase(iterator first, iterator last) {
        iterator ret = last;

        size_t amount = 0;
        while (last != end()) {
          *first = *last;
          first++;
          last++;
          amount++;
        }
        _length -= amount;

        while (first != last) {
          last--;
          _length--;
        }
        return ret;
      }

      void push_back(const value_type& value) {
        insert(end(), value);
      }

      void pop_back() {
        erase(--end());
      }

      void resize(size_type count, value_type value = value_type()) {
        if (_length > count) {
          _length = count;
        } else {
          reserve(2 * count);
          while (size() < count) {
            push_back(value);
          }
        }
      }

      void swap(vector& other) {
        std::swap(_length, other._length);
        std::swap(_capacity, other._capacity);
        std::swap(_array, other._array);
      }
  };

  template <typename T>
  bool operator==(const vector<T>& lhs, const vector<T>& rhs) {
    if (lhs.size() == rhs.size()) {
      return std::equal(lhs.begin(), lhs.end(), rhs.begin());
    } else {
      return false;
    }
  }

  template <typename T>
  bool operator<(vector<T> lhs, vector<T> rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
  }

  template <typename T>
  bool operator>(vector<T> lhs, vector<T> rhs) {
    return !(lhs == rhs) && !(lhs < rhs);
  }

  template <typename T>
  bool operator<=(vector<T> lhs, vector<T> rhs) {
    return !(lhs > rhs);
  }
  
  template <typename T>
  bool operator>=(vector<T> lhs, vector<T> rhs) {
    return !(lhs < rhs);
  }

  template <typename T>
  bool operator!=(vector<T> lhs, vector<T> rhs) {
    return !(lhs == rhs);
  }
}  // namespace ft

#endif  // VECTOR_HPP_
