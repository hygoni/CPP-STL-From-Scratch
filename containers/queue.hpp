#ifndef queue_HPP_
# define queue_HPP_

# include "list.hpp"

namespace ft {
  template <typename T, typename Container = ft::list<T> >
  class queue {
    private:
      Container _container;

    public:
      typedef Container container_type;
      typedef typename Container::value_type value_type;
      typedef typename Container::size_type size_type;
      typedef typename Container::reference reference;
      typedef typename Container::const_reference const_reference;

      explicit queue (const Container& cont = Container()) {
        _container = cont;
      }

      queue (const queue& other) {
        *this = other;
      }

      queue& operator=(const queue& other) {
        _container = other._container;
        return *this;
      }

      reference front() {
        return _container.front();
      }

      const_reference front() const {
        return _container.front();
      }

      reference back() {
        return _container.back();
      }

      const_reference back() const {
        return _container.back();
      }

      bool empty() const {
        return _container.empty();
      }

      size_type size() const {
        return _container.size();
      }

      void push(const value_type& value) {
        _container.push_back(value);
      }

      void pop() {
        _container.pop_front();
      }

      void swap(queue& other) {
        Container tmp = _container;
        _container = other._container;
        other._container = tmp;
      }

      template <typename _T, typename _Container>
      friend bool operator==(const ft::queue<_T, _Container>& lhs, const ft::queue<_T, _Container>& rhs);
      template <typename _T, typename _Container>
      friend bool operator!=(const ft::queue<_T, _Container>& lhs, const ft::queue<_T, _Container>& rhs);
      template <typename _T, typename _Container>
      friend bool operator<(const ft::queue<_T, _Container>& lhs, const ft::queue<_T, _Container>& rhs);
      template <typename _T, typename _Container>
      friend bool operator<=(const ft::queue<_T, _Container>& lhs, const ft::queue<_T, _Container>& rhs);
      template <typename _T, typename _Container>
      friend bool operator>(const ft::queue<_T, _Container>& lhs, const ft::queue<_T, _Container>& rhs);
      template <typename _T, typename _Container>
      friend bool operator>=(const ft::queue<_T, _Container>& lhs, const ft::queue<_T, _Container>& rhs);
  };

  template <typename _T, typename _Container>
  bool operator==(const ft::queue<_T, _Container>& lhs, const ft::queue<_T, _Container>& rhs) {
    return lhs._container == rhs._container;
  }

  template <typename _T, typename _Container>
  bool operator!=(const ft::queue<_T, _Container>& lhs, const ft::queue<_T, _Container>& rhs) {
    return lhs._container != rhs._container;
  }

  template <typename _T, typename _Container>
  bool operator<(const ft::queue<_T, _Container>& lhs, const ft::queue<_T, _Container>& rhs) {
    return lhs._container < rhs._container;
  }

  template <typename _T, typename _Container>
  bool operator<=(const ft::queue<_T, _Container>& lhs, const ft::queue<_T, _Container>& rhs) {
    return lhs._container <= rhs._container;
  }

  template <typename _T, typename _Container>
  bool operator>(const ft::queue<_T, _Container>& lhs, const ft::queue<_T, _Container>& rhs) {
    return lhs._container > rhs._container;
  }

  template <typename _T, typename _Container>
  bool operator>=(const ft::queue<_T, _Container>& lhs, const ft::queue<_T, _Container>& rhs) {
    return lhs._container >= rhs._container;
  }
};

#endif  // queue_HPP_
