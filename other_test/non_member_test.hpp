/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_member_test.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsokim <minsokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:18:06 by minsokim          #+#    #+#             */
/*   Updated: 2020/11/15 19:00:52 by minsokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Deque.hpp"
#include <iostream>
#include "../Queue.hpp"
#include "../Stack.hpp"
#include "../List.hpp"
#include "../Vector.hpp"
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <list>
#include "utils.hpp"
#ifndef NON_MEMBER_TEST_HPP
# define NON_MEMBER_TEST_HPP
void non_member_test()
{
	ft::vector<int> a1;
	ft::deque<int> a2;
	ft::list<int> a3;
	ft::stack<int> a4;
	ft::queue<int> a5;
	ft::vector<int> c1;
	ft::deque<int> c2;
	ft::list<int> c3;
	ft::stack<int> c4;
	ft::queue<int> c5;
	std::vector<int> b1;
	std::deque<int> b2;
	std::list<int> b3;
	std::stack<int> b4;
	std::queue<int> b5;
	std::vector<int> d1;
	std::deque<int> d2;
	std::list<int> d3;
	std::stack<int> d4;
	std::queue<int> d5;
	for (int i = 0 ; i < 10; i++)
	{
		a1.push_back(i);
		a2.push_back(i);
		a3.push_back(i);
		a4.push(i);
		a5.push(i);
		b1.push_back(i);
		b2.push_back(i);
		b3.push_back(i);
		b4.push(i);
		b5.push(i);
	}
	for (int i = 0 ; i < 10; i++)
	{
		c1.push_back(i);
		c2.push_back(i);
		c3.push_back(i);
		c4.push(i);
		c5.push(i);
		d1.push_back(i);
		d2.push_back(i);
		d3.push_back(i);
		d4.push(i);
		d5.push(i);
	}
	std::cout << "check is equal(vector)\n";
	if (a1==c1 && b1==d1)
		std::cout << "same stl\n";
	else
		std::cout << "diff stl\n";
	std::cout << "check is equal(deque)\n";
	if (a2==c2 && b2==d2)
		std::cout << "same stl\n";
	else
		std::cout << "diff stl\n";
	std::cout << "check is equal(list)\n";
	if (a3==c3 && b3==d3)
		std::cout << "same stl\n";
	else
		std::cout << "diff stl\n";
	std::cout << "check is equal(stack)\n";
	if (a4==c4 && b4==d4)
		std::cout << "same stl\n";
	else
		std::cout << "diff stl\n";
	std::cout << "check is equal(queue)\n";
	if (a5==c5 && b5==d5)
		std::cout << "same stl\n";
	else
		std::cout << "diff stl\n";


	a1.push_back(3);
	a2.push_back(3);
	a3.push_back(3);
	a4.push(3);
	a5.push(3);
	b1.push_back(3);
	b2.push_back(3);
	b3.push_back(3);
	b4.push(3);
	b5.push(3);
	std::cout << "\ncheck is big(vector)\n";
	if (a1>c1 && b1>d1)
		std::cout << "same stl\n";
	else
		std::cout << "diff stl\n";
	std::cout << "check is big(deque)\n";
	if (a2>c2 && b2>d2)
		std::cout << "same stl\n";
	else
		std::cout << "diff stl\n";
	std::cout << "check is big(list)\n";
	if (a3>c3 && b3>d3)
		std::cout << "same stl\n";
	else
		std::cout << "diff stl\n";
	std::cout << "check is big(stack)\n";
	if (a4>c4 && b4>d4)
		std::cout << "same stl\n";
	else
		std::cout << "diff stl\n";
	std::cout << "check is big(queue)\n";
	if (a5>c5 && b5>d5)
		std::cout << "same stl\n";
	else
		std::cout << "diff stl\n";


}
#endif
