/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 03:43:00 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/10/04 04:48:48 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP
# include <cstddef>
# include <limits>
# include <memory>

template<typename T, typename Alloc_ = std::allocator<T> >
struct ListNode {
    private:
        ListNode<T, Alloc_> *prev;
        ListNode<T, Alloc_> *next;
        T data;
    public:
        ListNode(T data);
};

template<typename T, typename _Alloc = std::allocator<T> >
class List {
    public:
        typedef T value_type;
        typedef typename _Alloc::pointer pointer;
        typedef typename _Alloc::const_pointer const_pointer;
        typedef typename _Alloc::reference reference;
        typedef typename _Alloc::const_reference const_reference;
        /* iterator, const_iterator, reverse_iterator, const_reverse_iterator */
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef _Alloc allocator_type;

        List() {
            _head = nullptr;
            _tail = nullptr;
            _size = 0;
        }

        virtual ~List() {

        }

        reference front() {
            return _head;
        }

        const_reference front() const {
            return const_cast<const value_type&>(_head);
        }

        reference back() {
            return _tail;
        }

        const_reference back() const {
            return const_cast<const value_type&>(_tail);
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

        void push_back (const value_type& value) {
            if (_head == nullptr) {

            } else {

            }
        }

        void push_front (const value_type& value) {
            
        }

    protected:
        typedef ListNode<value_type, allocator_type> Node;
    private:
        Node *_head;
        Node *_tail;
        size_type _size;
};

#endif
