/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsokim <minsokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:51:59 by minsokim          #+#    #+#             */
/*   Updated: 2020/11/16 17:16:21 by minsokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iostream>
#include <string>
#include "vector_tester.hpp"
#include "non_member_test.hpp"
#include "stack_tester.hpp"
#include "map_tester.hpp"
#include "queue_tester.hpp"
#include "list_tester.hpp"

int main()
{
	std::string a ="0";
	srand(time(0));
	while (a != "exit")
	{
		system("clear");
		std::cout << "1 : vector test\n2 : list test\n3 : map test\n4 : stack test\n5 : queue test\n6 : deque test\n7 : multimap test\n8 : set test\n9 : multiset test\n";
		std::cin >> a;
		if (a == "1")
			vector_test();
		else if (a == "2")
			list_test();
		else if (a == "3")
			map_test();
		else if (a == "4")
			stack_test();
		else if (a == "5")
			queue_test();
		else
			break;
	}
	non_member_test();
}
