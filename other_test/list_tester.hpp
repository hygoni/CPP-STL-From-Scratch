/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tester.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsokim <minsokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 06:09:39 by minsokim          #+#    #+#             */
/*   Updated: 2020/11/17 09:47:48 by minsokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "utils.hpp"
#include "list.hpp"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#ifndef LIST_TESTER_HPP
# define LIST_TESTER_HPP
void	list_test()
{
	system("clear");

	std::cout<<"██▓     ██▓  ██████ ▄▄▄█████▓   ▄▄▄█████▓▓█████   ██████ ▄▄▄█████▓\n";
	std::cout<<"▓██▒    ▓██▒▒██    ▒ ▓  ██▒ ▓▒   ▓  ██▒ ▓▒▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒\n";
	std::cout<<"▒██░    ▒██▒░ ▓██▄   ▒ ▓██░ ▒░   ▒ ▓██░ ▒░▒███   ░ ▓██▄   ▒ ▓██░ ▒░\n";
	std::cout<<"▒██░    ░██░  ▒   ██▒░ ▓██▓ ░    ░ ▓██▓ ░ ▒▓█  ▄   ▒   ██▒░ ▓██▓ ░ \n";
	std::cout<<"░██████▒░██░▒██████▒▒  ▒██▒ ░      ▒██▒ ░ ░▒████▒▒██████▒▒  ▒██▒ ░ \n";
	std::cout<<"░ ▒░▓  ░░▓  ▒ ▒▓▒ ▒ ░  ▒ ░░        ▒ ░░   ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░  \n";
	std::cout<<"░ ░ ▒  ░ ▒ ░░ ░▒  ░ ░    ░           ░     ░ ░  ░░ ░▒  ░ ░    ░  \n";
	std::cout<<"░ ░    ▒ ░░  ░  ░    ░           ░         ░   ░  ░  ░    ░     \n";
	std::cout<<"░  ░ ░        ░                          ░  ░      ░           \n";


	std::list<for_test> random_b;
	ft::list<for_test> random_a;
	for (int i = 0; i < 10; i++)
	{
		for_test temp = gen_test();
		random_a.push_back(temp);
		random_b.push_back(temp);
	}
	color_black();
	std::cout << "\ndefalut constructor test\n";
	ft::list<for_test> a1;
	std::list<for_test> b1;
	color_blue();
	std::cout << "my : size = " << a1.size() << " max_size = " << a1.max_size() << " back = " <<a1.back().a << " front = " << a1.front().a << std::endl;
	color_red();
	std::cout << "or : size = " << b1.size() << " max_size = " << b1.max_size() << " back = " << b1.back().a << " front = " << b1.front().a << std::endl;
	color_black();
	std::cout << "\nfill constructor test\n";
	for_test temp1 =gen_test();
	ft::list<for_test> a2(7,temp1);
	std::list<for_test> b2(7, temp1);
	color_blue();
	std::cout << "my : size = " << a1.size() << " max_size = " << a1.max_size() << " back = " <<a1.back().a << " front = " << a1.front().a << std::endl;
	color_red();
	std::cout << "or : size = " << b1.size() << " max_size = " << b1.max_size() << " back = " << b1.back().a << " front = " << b1.front().a << std::endl;
	color_blue();
	std::cout << "my\n";
	for (ft::list<for_test>::iterator it = a2.begin(); it != a2.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_red();
	std::cout <<"or\n";
	for (std::list<for_test>::iterator it = b2.begin(); it != b2.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_black();
	wait_input();
	std::cout << "\nrange constructor test\n";
	ft::list<for_test> a3(random_a.begin(), random_a.end());
	std::list<for_test> b3(random_b.begin(), random_b.end());
	color_blue();
	std::cout << "my : size = " << a3.size() << " max_size = " << a3.max_size() << " back = " <<a3.back().a << " front = " << a3.front().a << std::endl;
	color_red();
	std::cout << "or : size = " << b3.size() << " max_size = " << b3.max_size() << " back = " << b3.back().a << " front = " << b3.front().a << std::endl;
	color_blue();
	std::cout << "my\n";
	for (ft::list<for_test>::iterator it = a3.begin(); it != a3.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_red();
	std::cout <<"or\n";
	for (std::list<for_test>::iterator it = b3.begin(); it != b3.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_black();
	std::cout << "\ncopy constructor test\n";
	ft::list<for_test> a4(a3);
	std::list<for_test> b4(b3);
	color_blue();
	std::cout << "my : size = " << a4.size() << " max_size = " << a4.max_size() << " back = " <<a4.back().a << " front = " << a4.front().a << std::endl;
	color_red();
	std::cout << "or : size = " << b4.size() << " max_size = " << b4.max_size() << " back = " << b4.back().a << " front = " << b4.front().a << std::endl;
	color_blue();
	std::cout << "my\n";
	for (ft::list<for_test>::iterator it = a4.begin(); it != a4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_red();
	std::cout <<"or\n";
	for (std::list<for_test>::iterator it = b4.begin(); it != b4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_black();
	wait_input();
	std::cout << "\nrange assign test\n";
	ft::vector<for_test> v1;
	std::vector<for_test> v2;
	for (int i = 0; i < 10; i++)
	{
		for_test temp = gen_test();
		v1.push_back(temp);
		v2.push_back(temp);
	}
	color_blue();
	std::cout << "my base vector : \n";
	for (ft::vector<for_test>::iterator it = v1.begin(); it != v1.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_red();
	std::cout << "or base vector : \n";
	for (std::vector<for_test>::iterator it = v2.begin(); it != v2.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_black();
	std::cout << "assign list using vector\n";
	a4.assign(v1.begin(), v1.end());
	b4.assign(v2.begin(), v2.end());
	color_blue();
	std::cout << "my : size = " << a4.size() << " max_size = " << a4.max_size() << " back = " <<a4.back().a << " front = " << a4.front().a << std::endl;
	color_red();
	std::cout << "or : size = " << b4.size() << " max_size = " << b4.max_size() << " back = " << b4.back().a << " front = " << b4.front().a << std::endl;
	color_blue();
	std::cout << "my\n";
	for (ft::list<for_test>::iterator it = a4.begin(); it != a4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_red();
	std::cout <<"or\n";
	for (std::list<for_test>::iterator it = b4.begin(); it != b4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_black();
	wait_input();
	std::cout << "\nfill assign test\n";
	for_test zero;
	zero.a = 0;
	zero.b = "0";
	zero.c = 0;
	zero.d = 0;
	a4.assign(5, zero);
	b4.assign(5, zero);
	color_blue();
	std::cout << "my : size = " << a4.size() << " max_size = " << a4.max_size() << " back = " <<a4.back().a << " front = " << a4.front().a << std::endl;
	color_red();
	std::cout << "or : size = " << b4.size() << " max_size = " << b4.max_size() << " back = " << b4.back().a << " front = " << b4.front().a << std::endl;
	color_blue();
	std::cout << "my\n";
	for (ft::list<for_test>::iterator it = a4.begin(); it != a4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_red();
	std::cout <<"or\n";
	for (std::list<for_test>::iterator it = b4.begin(); it != b4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_black();
	std::cout << "\npush front/pop front test\n";
	a4.pop_front();
	a4.pop_front();
	a4.pop_front();
	b4.pop_front();
	b4.pop_front();
	b4.pop_front();
	a4.push_front(temp1);
	a4.push_front(temp1);
	a4.push_front(temp1);
	b4.push_front(temp1);
	b4.push_front(temp1);
	b4.push_front(temp1);
	color_blue();
	std::cout << "my : size = " << a4.size() << " max_size = " << a4.max_size() << " back = " <<a4.back().a << " front = " << a4.front().a << std::endl;
	color_red();
	std::cout << "or : size = " << b4.size() << " max_size = " << b4.max_size() << " back = " << b4.back().a << " front = " << b4.front().a << std::endl;
	color_blue();
	std::cout << "my\n";
	for (ft::list<for_test>::iterator it = a4.begin(); it != a4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_red();
	std::cout <<"or\n";
	for (std::list<for_test>::iterator it = b4.begin(); it != b4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;

	color_black();
	wait_input();
	std::cout << "\npush back/pop back test\n";

	for_test temp2 = gen_test();
	a4.pop_back();
	a4.pop_back();
	b4.pop_back();
	b4.pop_back();
	a4.push_back(temp2);
	a4.push_back(temp2);
	a4.push_back(temp2);
	b4.push_back(temp2);
	b4.push_back(temp2);
	b4.push_back(temp2);
	color_blue();
	std::cout << "my : size = " << a4.size() << " max_size = " << a4.max_size() << " back = " <<a4.back().a << " front = " << a4.front().a << std::endl;
	color_red();
	std::cout << "or : size = " << b4.size() << " max_size = " << b4.max_size() << " back = " << b4.back().a << " front = " << b4.front().a << std::endl;
	color_blue();
	std::cout << "my\n";
	for (ft::list<for_test>::iterator it = a4.begin(); it != a4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_red();
	std::cout <<"or\n";
	for (std::list<for_test>::iterator it = b4.begin(); it != b4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;

	wait_input();
	color_black();
	std::cout << "\nsingle element insert test\n";
	ft::list<for_test>::iterator myit = a4.begin();
	std::list<for_test>::iterator orit = b4.begin();
	myit++;
	myit++;
	orit++;
	orit++;
	a4.insert(myit, zero);
	b4.insert(orit, zero);
	color_blue();
	std::cout << "my : size = " << a4.size() << " max_size = " << a4.max_size() << " back = " <<a4.back().a << " front = " << a4.front().a << std::endl;
	color_red();
	std::cout << "or : size = " << b4.size() << " max_size = " << b4.max_size() << " back = " << b4.back().a << " front = " << b4.front().a << std::endl;
	color_blue();
	std::cout << "my\n";
	for (ft::list<for_test>::iterator it = a4.begin(); it != a4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_red();
	std::cout <<"or\n";
	for (std::list<for_test>::iterator it = b4.begin(); it != b4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;

	color_black();
	std::cout << "\nfill insert test\n";
	a4.insert(myit, 5, zero);
	b4.insert(orit, 5, zero);
	color_blue();
	std::cout << "my : size = " << a4.size() << " max_size = " << a4.max_size() << " back = " <<a4.back().a << " front = " << a4.front().a << std::endl;
	color_red();
	std::cout << "or : size = " << b4.size() << " max_size = " << b4.max_size() << " back = " << b4.back().a << " front = " << b4.front().a << std::endl;
	color_blue();
	std::cout << "my\n";
	for (ft::list<for_test>::iterator it = a4.begin(); it != a4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_red();
	std::cout <<"or\n";
	for (std::list<for_test>::iterator it = b4.begin(); it != b4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;

	wait_input();
	color_black();
	std::cout << "\nrange insert test\n";
	a4.insert(myit, a3.begin(), a3.end());
	b4.insert(orit, b3.begin(), b3.end());
	color_blue();
	std::cout << "my : size = " << a4.size() << " max_size = " << a4.max_size() << " back = " <<a4.back().a << " front = " << a4.front().a << std::endl;
	color_red();
	std::cout << "or : size = " << b4.size() << " max_size = " << b4.max_size() << " back = " << b4.back().a << " front = " << b4.front().a << std::endl;
	color_blue();
	std::cout << "my\n";
	for (ft::list<for_test>::iterator it = a4.begin(); it != a4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_red();
	std::cout <<"or\n";
	for (std::list<for_test>::iterator it = b4.begin(); it != b4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;

	wait_input();
	color_black();
	std::cout << "\nsingle erase test\n";
	a4.erase(a4.begin());
	b4.erase(b4.begin());
	color_blue();
	std::cout << "my : size = " << a4.size() << " max_size = " << a4.max_size() << " back = " <<a4.back().a << " front = " << a4.front().a << std::endl;
	color_red();
	std::cout << "or : size = " << b4.size() << " max_size = " << b4.max_size() << " back = " << b4.back().a << " front = " << b4.front().a << std::endl;
	color_blue();
	std::cout << "my\n";
	for (ft::list<for_test>::iterator it = a4.begin(); it != a4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_red();
	std::cout <<"or\n";
	for (std::list<for_test>::iterator it = b4.begin(); it != b4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;



	wait_input();
	color_black();
	std::cout << "\nrange erase test\n";
	a4.erase(myit, a4.end());
	b4.erase(orit, b4.end());
	color_blue();
	std::cout << "my : size = " << a4.size() << " max_size = " << a4.max_size() << " back = " <<a4.back().a << " front = " << a4.front().a << std::endl;
	color_red();
	std::cout << "or : size = " << b4.size() << " max_size = " << b4.max_size() << " back = " << b4.back().a << " front = " << b4.front().a << std::endl;
	color_blue();
	std::cout << "my\n";
	for (ft::list<for_test>::iterator it = a4.begin(); it != a4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;
	color_red();
	std::cout <<"or\n";
	for (std::list<for_test>::iterator it = b4.begin(); it != b4.end(); it++)
		std::cout << (*it).a <<" " << (*it).b << " "<<(*it).c <<" "<<(*it).d <<std::endl;


	wait_input();
	color_black();
	std::cout << "\nmember function swap test\n";
	ft::list<int> a_int(14, 16);
	std::list<int> b_int(14, 16);
	ft::list<int> a1_int;
	std::list<int> b1_int;
	for (int i = 0;i < 10; i++)
	{
		int random = rand();
		a1_int.push_back(random);
		b1_int.push_back(random);
	}
	std::cout << "before swap\n";
	color_blue();
	std::cout << "my list 1 : ";
	for (ft::list<int>::iterator it = a_int.begin();it != a_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a_int.size();
	std::cout << "\nmy list 2 : ";
	for (ft::list<int>::iterator it = a1_int.begin(); it!=a1_int.end();it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a1_int.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list 1 : ";
	for (std::list<int>::iterator it = b_int.begin();it != b_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b_int.size();
	std::cout << "\nor list 2 : ";
	for (std::list<int>::iterator it = b1_int.begin(); it!=b1_int.end();it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b1_int.size();
	std::cout << "\n";
	a_int.swap(a1_int);
	b_int.swap(b1_int);
	color_black();

	std::cout << "after swap\n";
	color_blue();
	std::cout << "my list 1 : ";
	for (ft::list<int>::iterator it = a_int.begin();it != a_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a_int.size();
	std::cout << "\nmy list 2 : ";
	for (ft::list<int>::iterator it = a1_int.begin(); it!=a1_int.end();it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a1_int.size();
	color_red();
	std::cout << "\n";
	std::cout << "or list 1 : ";
	for (std::list<int>::iterator it = b_int.begin();it != b_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b_int.size();
	std::cout << "\nor list 2 : ";
	for (std::list<int>::iterator it = b1_int.begin(); it!=b1_int.end();it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b1_int.size();
	std::cout <<"\n";

	wait_input();
	color_black();
	std::cout << "\nnon member funcition swap test\n";
	ft::swap(a_int, a1_int);
	std::swap(b_int, b1_int);
	color_blue();
	std::cout << "my list 1 : ";
	for (ft::list<int>::iterator it = a_int.begin();it != a_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a_int.size();
	std::cout << "\nmy list 2 : ";
	for (ft::list<int>::iterator it = a1_int.begin(); it!=a1_int.end();it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a1_int.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list 1 : ";
	for (std::list<int>::iterator it = b_int.begin();it != b_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b_int.size();
	std::cout << "\nor list 2 : ";
	for (std::list<int>::iterator it = b1_int.begin(); it!=b1_int.end();it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b1_int.size();
	std::cout << "\n";

	color_black();
	std::cout << "\nentire list splice test\n";
	ft::list<int>::iterator a_it = a_int.begin();
	std::list<int>::iterator b_it = b_int.begin();
	a_it++;
	a_it++;
	a_it++;
	b_it++;
	b_it++;
	b_it++;
	a_int.splice(a_it, a1_int);
	b_int.splice(b_it, b1_int);
	color_blue();
	std::cout << "my list 1 : ";
	for (ft::list<int>::iterator it = a_int.begin();it != a_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a_int.size();
	std::cout << "\nmy list 2 : ";
	for (ft::list<int>::iterator it = a1_int.begin(); it!=a1_int.end();it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a1_int.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list 1 : ";
	for (std::list<int>::iterator it = b_int.begin();it != b_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b_int.size();
	std::cout << "\nor list 2 : ";
	for (std::list<int>::iterator it = b1_int.begin(); it!=b1_int.end();it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b1_int.size();
	std::cout << "\n";

	color_black();
	std::cout << "\nsingle element splice test\n";
	a_it = a_int.begin();
	b_it = b_int.begin();
	a_it++;
	a_it++;
	a_it++;
	a_it++;
	a_it++;
	b_it++;
	b_it++;
	b_it++;
	b_it++;
	b_it++;
	a1_int.splice(a1_int.begin(), a_int, a_it);
	b1_int.splice(b1_int.begin(), b_int, b_it);
	color_blue();
	std::cout << "my list 1 : ";
	for (ft::list<int>::iterator it = a_int.begin();it != a_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a_int.size();
	std::cout << "\nmy list 2 : ";
	for (ft::list<int>::iterator it = a1_int.begin(); it!=a1_int.end();it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a1_int.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list 1 : ";
	for (std::list<int>::iterator it = b_int.begin();it != b_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b_int.size();
	std::cout << "\nor list 2 : ";
	for (std::list<int>::iterator it = b1_int.begin(); it!=b1_int.end();it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b1_int.size();
	std::cout << "\n";


	wait_input();
	color_black();
	std::cout << "\nelement range splice test\n";
	a_it = a_int.begin();
	b_it = b_int.begin();
	ft::list<int>::iterator a_ite = a_int.begin();
	std::list<int>::iterator b_ite = b_int.begin();
	for (int i = 0 ; i < 3;i++)
	{
		a_it++;
		b_it++;
	}
	for (int i = 0 ; i < 10; i++)
	{
		a_ite++;
		b_ite++;
	}
	a1_int.splice(a1_int.begin(), a_int, a_it, a_ite);
	b1_int.splice(b1_int.begin(), b_int, b_it, b_ite);
	color_blue();
	std::cout << "my list 1 : ";
	for (ft::list<int>::iterator it = a_int.begin();it != a_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a_int.size();
	std::cout << "\nmy list 2 : ";
	for (ft::list<int>::iterator it = a1_int.begin(); it!=a1_int.end();it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a1_int.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list 1 : ";
	for (std::list<int>::iterator it = b_int.begin();it != b_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b_int.size();
	std::cout << "\nor list 2 : ";
	for (std::list<int>::iterator it = b1_int.begin(); it!=b1_int.end();it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b1_int.size();
	std::cout << "\n";


	color_black();
	std::cout << "\nremove test\n";
	ft::list<int> atemp(a_int);
	std::list<int> btemp(b_int);
	a_int.remove(16);
	b_int.remove(16);
	color_blue();
	std::cout << "my list : ";
	for (ft::list<int>::iterator it = a_int.begin();it != a_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a_int.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list : ";
	for (std::list<int>::iterator it = b_int.begin();it != b_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b_int.size();
	std::cout << "\n";

	wait_input();
	color_black();
	std::cout << "\nunique test\n";
	atemp.unique();
	btemp.unique();
	color_blue();
	std::cout << "my list : ";
	for (ft::list<int>::iterator it = atemp.begin();it != atemp.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<atemp.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list : ";
	for (std::list<int>::iterator it = btemp.begin();it != btemp.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<btemp.size();
	std::cout << "\n";


	color_black();
	std::cout << "\nsort test\n";
	a1_int.sort();
	b1_int.sort();
	color_blue();
	std::cout << "my list : ";
	for (ft::list<int>::iterator it = a1_int.begin();it != a1_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a1_int.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list : ";
	for (std::list<int>::iterator it = b1_int.begin();it != b1_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b1_int.size();
	std::cout << "\n";


	color_black();
	std::cout << "\nrerverse test\n";

	a1_int.reverse();
	b1_int.reverse();
	color_blue();
	std::cout << "my list : ";
	for (ft::list<int>::iterator it = a1_int.begin();it != a1_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a1_int.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list : ";
	for (std::list<int>::iterator it = b1_int.begin();it != b1_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b1_int.size();
	std::cout << "\n";

	color_black();
	std::cout << "\nmerge test\n";
	a1_int.sort();
	b1_int.sort();
	ft::list<int> last_my;
	std::list<int> last_or;
	for (int i = 0 ; i < 6; i++)
	{
		int temp3 = rand();
		last_my.push_back(temp3);
		last_or.push_back(temp3);
	}
	last_my.sort();
	last_or.sort();
	std::cout << "before merge\n";
	color_blue();
	std::cout << "my list 1: ";
	for (ft::list<int>::iterator it = a1_int.begin();it != a1_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a1_int.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list 1: ";
	for (std::list<int>::iterator it = b1_int.begin();it != b1_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b1_int.size();
	std::cout << "\n";
	color_blue();
	std::cout << "my list 2: ";
	for (ft::list<int>::iterator it = last_my.begin();it != last_my.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<last_my.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list 2: ";
	for (std::list<int>::iterator it = last_or.begin();it != last_or.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<last_or.size();
	std::cout << "\n";
	a1_int.merge(last_my);
	b1_int.merge(last_or);
	color_black();
	std::cout << "after merge\n";
	color_blue();
	std::cout << "my list 1: ";
	for (ft::list<int>::iterator it = a1_int.begin();it != a1_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a1_int.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list 1: ";
	for (std::list<int>::iterator it = b1_int.begin();it != b1_int.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b1_int.size();
	std::cout << "\n";
	color_blue();
	std::cout << "my list 2: ";
	for (ft::list<int>::iterator it = last_my.begin();it != last_my.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<last_my.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list 2: ";
	for (std::list<int>::iterator it = last_or.begin();it != last_or.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<last_or.size();
	std::cout << "\n";
	color_black();
	std::cout << "\nreverse iterator test\n";
	color_blue();
	std::cout << "my list 1: ";
	for (ft::list<int>::reverse_iterator it = a1_int.rbegin();it != a1_int.rend(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<a1_int.size();
	std::cout << "\n";
	color_red();
	std::cout << "or list 1: ";
	for (std::list<int>::reverse_iterator it = b1_int.rbegin();it != b1_int.rend(); it++)
		std::cout << *it << " ";
	std::cout << "\nsize = "<<b1_int.size();
	std::cout << "\n";


	color_black();
	wait_input();
	std::cout << "list test is finish\n";
	wait_input();
}
#endif
