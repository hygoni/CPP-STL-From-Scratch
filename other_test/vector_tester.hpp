/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsokim <minsokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 06:09:59 by minsokim          #+#    #+#             */
/*   Updated: 2020/11/16 19:43:53 by minsokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "utils.hpp"
#include <cstddef>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
#include <list>

#ifndef VECTOR_TESTER_HPP
# define VECTOR_TESTER_HPP
void	vector_test()
{

	system("clear");
	std::cout<<" ██▒   █▓▓█████  ▄████▄  ▄▄▄█████▓ ▒█████   ██▀███     ▄▄▄█████▓▓█████   ██████ ▄▄▄█████▓\n";
	std::cout<<"▓██░   █▒▓█   ▀ ▒██▀ ▀█  ▓  ██▒ ▓▒▒██▒  ██▒▓██ ▒ ██▒   ▓  ██▒ ▓▒▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒\n";
	std::cout<<"▓██  █▒░▒███   ▒▓█    ▄ ▒ ▓██░ ▒░▒██░  ██▒▓██ ░▄█ ▒   ▒ ▓██░ ▒░▒███   ░ ▓██▄   ▒ ▓██░ ▒░\n";
	std::cout<<" ▒██ █░░▒▓█  ▄ ▒▓▓▄ ▄██▒░ ▓██▓ ░ ▒██   ██░▒██▀▀█▄     ░ ▓██▓ ░ ▒▓█  ▄   ▒   ██▒░ ▓██▓ ░ \n";
	std::cout<<"  ▒▀█░  ░▒████▒▒ ▓███▀ ░  ▒██▒ ░ ░ ████▓▒░░██▓ ▒██▒     ▒██▒ ░ ░▒████▒▒██████▒▒  ▒██▒ ░ \n";
	std::cout<<"  ░ ▐░  ░░ ▒░ ░░ ░▒ ▒  ░  ▒ ░░   ░ ▒░▒░▒░ ░ ▒▓ ░▒▓░     ▒ ░░   ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░   \n";
	std::cout<<"  ░ ░░   ░ ░  ░  ░  ▒       ░      ░ ▒ ▒░   ░▒ ░ ▒░       ░     ░ ░  ░░ ░▒  ░ ░    ░    \n";
	std::cout<<"   ░░     ░   ░          ░      ░ ░ ░ ▒    ░░   ░      ░         ░   ░  ░  ░    ░      \n";
	std::cout<<"   ░     ░  ░░ ░                   ░ ░     ░                    ░  ░      ░           \n";
	std::cout<<"   ░          ░                                                                        \n";

	std::cout << "defalut constructor test\n";
	ft::vector<for_test> a;
	std::vector<for_test> b;
	std::cout << "\x1b[34mmy size : " << a.size() << "  my capacity :  " << a.capacity() << "  my max_size : " << a.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << b.size() << "  or capacity :  " << b.capacity() << "  or max_size : " << b.max_size() <<"\x1b[0m\n";

	std::cout << "\npush_back test\n";
	for (int i = 0; i < 10; i++)
	{
		for_test temp =gen_test();
		a.push_back(temp);
		b.push_back(temp);
	}
	std::cout << "\x1b[34mmy size : " << a.size() << "  my capacity :  " << a.capacity() << "  my max_size : " << a.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << b.size() << "  or capacity :  " << b.capacity() << "  or max_size : " << b.max_size() <<"\x1b[0m\n";

	std::cout << "\x1b[34mmy : \n";
	for (ft::vector<for_test>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";
	std::cout << "\x1b[31mor : \n";
	for (std::vector<for_test>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";

	wait_input();
	std::cout <<"\x1b[0m\npop_back test\n";
	a.pop_back();
	a.pop_back();
	b.pop_back();
	b.pop_back();
	std::cout << "\x1b[34mmy size : " << a.size() << "  my capacity :  " << a.capacity() << "  my max_size : " << a.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << b.size() << "  or capacity :  " << b.capacity() << "  or max_size : " << b.max_size() <<"\x1b[0m\n";

	std::cout << "\x1b[34mmy : \n";
	for (ft::vector<for_test>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";
	std::cout << "\x1b[31mor : \n";
	for (std::vector<for_test>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";
	wait_input();
	std::cout << "\x1b[0m\niterator constructor test\n";
	ft::vector<for_test> xx(a.begin(), a.end());
	std::vector<for_test> yy(b.begin(), b.end());
	std::cout << "\x1b[34mmy size : " << xx.size() << "  my capacity :  " << xx.capacity() << "  my max_size : " << xx.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << yy.size() << "  or capacity :  " << yy.capacity() << "  or max_size : " << yy.max_size() <<"\x1b[0m\n";

	std::cout << "\x1b[34mmy : \n";
	for (ft::vector<for_test>::iterator it = xx.begin(); it != xx.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";
	std::cout << "\x1b[31mor : \n";
	for (std::vector<for_test>::iterator it = yy.begin(); it != yy.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";

	wait_input();
	std::cout << "\x1b[0m\nresize test\n";
	a.resize(65);
	b.resize(65);
	std::cout << "\x1b[34mmy size : " << a.size() << "  my capacity :  " << a.capacity() << "  my max_size : " << a.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << b.size() << "  or capacity :  " << b.capacity() << "  or max_size : " << b.max_size() <<"\x1b[0m\n";
	a.resize(0);
	b.resize(0);
	std::cout << "\x1b[34mmy size : " << a.size() << "  my capacity :  " << a.capacity() << "  my max_size : " << a.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << b.size() << "  or capacity :  " << b.capacity() << "  or max_size : " << b.max_size() <<"\x1b[0m\n";

	std::cout << "\nreserver test\n";
	a.reserve(8);
	b.reserve(8);
	std::cout << "\x1b[34mmy size : " << a.size() << "  my capacity :  " << a.capacity() << "  my max_size : " << a.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << b.size() << "  or capacity :  " << b.capacity() << "  or max_size : " << b.max_size() <<"\x1b[0m\n";
	a.reserve(50);
	b.reserve(50);
	std::cout << "\x1b[34mmy size : " << a.size() << "  my capacity :  " << a.capacity() << "  my max_size : " << a.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << b.size() << "  or capacity :  " << b.capacity() << "  or max_size : " << b.max_size() <<"\x1b[0m\n";


	std::cout << "\nother constructor test\n";
	ft::vector<int> c(3, 5);
	std::vector<int> d(3, 5);
	std::cout << "\x1b[34mmy size : " << c.size() << "  my capacity :  " << c.capacity() << "  my *end -1 : " << *(c.end() -1) <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << d.size() << "  or capacity :  " << d.capacity() << "  or *end -1 : " << *(d.end() -1) <<"\x1b[0m\n";

	c.resize(1);
	d.resize(1);
	std::cout << "\x1b[34mmy size : " << c.size() << "  my capacity :  " << c.capacity() << "  my *end -1 : " << *(c.end() - 1) <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << d.size() << "  or capacity :  " << d.capacity() << "  or *end -1 : " << *(d.end()-1) <<"\x1b[0m\n";

	c.reserve(10);
	d.reserve(10);
	std::cout << "\x1b[34mmy size : " << c.size() << "  my capacity :  " << c.capacity() << "  my *end -1 : " << *(c.end()-1) <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << d.size() << "  or capacity :  " << d.capacity() << "  or *end -1 : " << *(d.end()-1) <<"\x1b[0m\n";


	std::cout <<"\nstl sort test\n";
	c.clear();
	c.push_back(5);
	c.push_back(2);
	c.push_back(4);
	c.push_back(7);
	c.push_back(0);
	d.clear();
	d.push_back(5);
	d.push_back(2);
	d.push_back(4);
	d.push_back(7);
	d.push_back(0);
	std::cout <<"\x1b[34mmy\n";
	std::cout <<"before sort : ";
	for (ft::vector<int>::iterator i = c.begin(); i != c.end(); i++)
		std::cout << *i << " ";
	std::sort(c.begin(), c.end());
	std::cout <<"\nafter sort : ";
	for (ft::vector<int>::iterator i = c.begin(); i != c.end(); i++)
		std::cout << *i << " ";
	std::cout <<"\x1b[31m\nor\n";
	std::cout <<"before sort : ";
	for (std::vector<int>::iterator i = d.begin(); i != d.end(); i++)
		std::cout << *i <<" ";
	std::sort(d.begin(),d.end());
	std::cout <<"\nafter sort : ";
	for (std::vector<int>::iterator i = d.begin(); i != d.end(); i++)
		std::cout << *i <<" ";
	std::cout <<"\x1b[0m\n";
	wait_input();

	std::cout << "\ncopy constructor test\n";
	a.clear();
	b.clear();
	for (int i = 0; i < 10; i++)
	{
		for_test temp =gen_test();
		a.push_back(temp);
		b.push_back(temp);
	}
	ft::vector<for_test> e(a);
	std::vector<for_test> f(b);
	std::cout << "\x1b[34mmy size : " << e.size() << "  my capacity :  " << e.capacity() << "  my max_size : " << e.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << f.size() << "  or capacity :  " << f.capacity() << "  or max_size : " << f.max_size() <<"\x1b[0m\n";

	std::cout << "\x1b[34mmy : \n";
	for (ft::vector<for_test>::iterator it = e.begin(); it != e.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";
	std::cout << "\x1b[31mor : \n";
	for (std::vector<for_test>::iterator it = f.begin(); it != f.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";

	std::cout <<"\x1b[0m\ninsert test\n";
	for_test zero_struct;
	zero_struct.a = 0;
	zero_struct.b = "0";
	zero_struct.c = 0;
	zero_struct.d = 0;

	e.insert(e.begin()+3, zero_struct);
	f.insert(f.begin()+3, zero_struct);
	std::cout << "\x1b[34mmy size : " << e.size() << "  my capacity :  " << e.capacity() << "  my max_size : " << e.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << f.size() << "  or capacity :  " << f.capacity() << "  or max_size : " << f.max_size() <<"\x1b[0m\n";

	std::cout << "\x1b[34mmy : \n";
	for (ft::vector<for_test>::iterator it = e.begin(); it != e.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";
	std::cout << "\x1b[31mor : \n";
	for (std::vector<for_test>::iterator it = f.begin(); it != f.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";


	wait_input();
	std::cout <<"\x1b[0m\ninsert test2\n";
	e.insert(e.begin()+3,4, zero_struct);
	f.insert(f.begin()+3,4, zero_struct);
	std::cout << "\x1b[34mmy size : " << e.size() << "  my capacity :  " << e.capacity() << "  my max_size : " << e.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << f.size() << "  or capacity :  " << f.capacity() << "  or max_size : " << f.max_size() <<"\x1b[0m\n";

	std::cout << "\x1b[34mmy : \n";
	for (ft::vector<for_test>::iterator it = e.begin(); it != e.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";
	std::cout << "\x1b[31mor : \n";
	for (std::vector<for_test>::iterator it = f.begin(); it != f.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";


	std::cout <<"\x1b[0m\nerase test\n";
	e.erase(e.begin()+3);
	f.erase(f.begin()+3);
	e.erase(e.begin()+1);
	f.erase(f.begin()+1);
	std::cout << "\x1b[34mmy size : " << e.size() << "  my capacity :  " << e.capacity() << "  my max_size : " << e.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << f.size() << "  or capacity :  " << f.capacity() << "  or max_size : " << f.max_size() <<"\x1b[0m\n";

	std::cout << "\x1b[34mmy : \n";
	for (ft::vector<for_test>::iterator it = e.begin(); it != e.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";
	std::cout << "\x1b[31mor : \n";
	for (std::vector<for_test>::iterator it = f.begin(); it != f.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";

	wait_input();
	std::cout <<"\x1b[0m\nerase test2\n";
	e.erase(e.begin() + 3, e.end());
	f.erase(f.begin() + 3, f.end());
	std::cout << "\x1b[34mmy size : " << e.size() << "  my capacity :  " << e.capacity() << "  my max_size : " << e.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << f.size() << "  or capacity :  " << f.capacity() << "  or max_size : " << f.max_size() <<"\x1b[0m\n";

	std::cout << "\x1b[34mmy : \n";
	for (ft::vector<for_test>::iterator it = e.begin(); it != e.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";
	std::cout << "\x1b[31mor : \n";
	for (std::vector<for_test>::iterator it = f.begin(); it != f.end(); it++)
		std::cout << (*it).a << " " << (*it).b << " " << (*it).c << " " << (*it).d << "\n";


	std::cout <<"\x1b[0m\nindex, at test\n";
	std::cout << "\x1b[34mmy : \n";
	for (size_t i = 0; i  < e.size(); i++)
		std::cout << e[i].a << " " << e[i].b << " " << e.at(i).c << " " << e.at(i).d << "\n";
	std::cout << "\x1b[31mor : \n";
	for (size_t i = 0; i < f.size(); i++)
		std::cout << f[i].a << " " << f[i].b << " " << f.at(i).c << " " << f.at(i).d << "\n";



	std::cout <<"\x1b[0m\nassign test\n";
	ft::vector<int> a1(15, 111);
	std::vector<int> b1(15, 111);

	std::cout << "before assign\n";
	std::cout << "\x1b[34mmy size : " << a1.size() << "  my capacity :  " << a1.capacity() << "  my max_size : " << a1.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << b1.size() << "  or capacity :  " << b1.capacity() << "  or max_size : " << b1.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[34mmy : \n";
	for (ft::vector<int>::iterator it = a1.begin(); it != a1.end(); it++)
		std::cout << (*it) << " ";
	std::cout << "\x1b[31m\nor : \n";
	for (std::vector<int>::iterator it = b1.begin(); it != b1.end(); it++)
		std::cout << (*it) << " ";
	std::cout << "\x1b[0m\n";

	std::cout << "after assign using iterator\n";
	a1.assign(c.begin(),c.end());
	b1.assign(d.begin(), d.end());
	std::cout << "\x1b[34mmy size : " << a1.size() << "  my capacity :  " << a1.capacity() << "  my max_size : " << a1.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << b1.size() << "  or capacity :  " << b1.capacity() << "  or max_size : " << b1.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[34mmy : \n";
	for (ft::vector<int>::iterator it = a1.begin(); it != a1.end(); it++)
		std::cout << (*it) << " ";
	std::cout << "\x1b[31m\nor : \n";
	for (std::vector<int>::iterator it = b1.begin(); it != b1.end(); it++)
		std::cout << (*it) << " ";
	std::cout << "\x1b[0m\n";

	std::cout << "after assign using number (to big)\n";
	a1.assign(17, 0);
	b1.assign(17, 0);
	std::cout << "\x1b[34mmy size : " << a1.size() << "  my capacity :  " << a1.capacity() << "  my max_size : " << a1.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << b1.size() << "  or capacity :  " << b1.capacity() << "  or max_size : " << b1.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[34mmy : \n";
	for (ft::vector<int>::iterator it = a1.begin(); it != a1.end(); it++)
		std::cout << (*it) << " ";
	std::cout << "\x1b[31m\nor : \n";
	for (std::vector<int>::iterator it = b1.begin(); it != b1.end(); it++)
		std::cout << (*it) << " ";
	std::cout << "\x1b[0m\n";

	std::cout << "after assign using number (to small)\n";
	a1.assign(8, 7);
	b1.assign(8, 7);
	std::cout << "\x1b[34mmy size : " << a1.size() << "  my capacity :  " << a1.capacity() << "  my max_size : " << a1.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor size : " << b1.size() << "  or capacity :  " << b1.capacity() << "  or max_size : " << b1.max_size() <<"\x1b[0m\n";
	std::cout << "\x1b[34mmy : \n";
	for (ft::vector<int>::iterator it = a1.begin(); it != a1.end(); it++)
		std::cout << (*it) << " ";
	std::cout << "\x1b[31m\nor : \n";
	for (std::vector<int>::iterator it = b1.begin(); it != b1.end(); it++)
		std::cout << (*it) << " ";
	std::cout << "\x1b[0m\n";

	wait_input();

	std::cout << "\nfront back test\n";
	ft::vector<char> c1;
	std::vector<char> c2;
	for (int i = 0 ; i < 10;i++)
	{
		c1.push_back('a' + i);
		c2.push_back('a' + i);
	}
	std::cout << "\x1b[34mmy front : " << c1.front() << "  my back : " << c1.back() <<"\x1b[0m\n";
	std::cout << "\x1b[31mor front : " << c2.front() << "  or back : " << c2.back() << "\x1b[0m\n";

	std::cout << "\nswap test\n";
	ft::vector<std::string> mys1;
	ft::vector<std::string> mys2;
	std::vector<std::string> ors1;
	std::vector<std::string> ors2;

	mys1.push_back("minsokim");
	mys1.push_back("yepark");
	mys1.push_back("yomoon");
	mys1.push_back("jjoo");
	mys1.push_back("soohchoi");

	mys2.push_back("llim");
	mys2.push_back("hyeyoo");
	mys2.push_back("kkang");
	mys2.push_back("seongjpa");
	mys2.push_back("jungwlee");
	mys2.push_back("hyochoi");
	mys2.push_back("jinykim");

	ors1.push_back("minsokim");
	ors1.push_back("yepark");
	ors1.push_back("yomoon");
	ors1.push_back("jjoo");
	ors1.push_back("soohchoi");

	ors2.push_back("llim");
	ors2.push_back("hyeyoo");
	ors2.push_back("kkang");
	ors2.push_back("seongjpa");
	ors2.push_back("jungwlee");
	ors2.push_back("hyochoi");
	ors2.push_back("jinykim");
	std::cout << "before swap\n";
	color_blue();
	std::cout << "my s1\n";
	for (size_t i = 0 ; i < mys1.size(); i++)
		std::cout << mys1[i] << " ";
	color_red();
	std::cout << "\nor s1\n";
	for (size_t i = 0 ; i < ors1.size(); i++)
		std::cout << ors1[i] << " ";
	color_blue();
	std::cout << "\nmy s2\n";
	for (size_t i = 0 ; i < mys2.size(); i++)
		std::cout << mys2[i] << " ";
	color_red();
	std::cout << "\nor s2\n";
	for (size_t i = 0 ; i < ors2.size(); i++)
		std::cout << ors2[i] << " ";
	color_black();
	std::cout << "\nafter swap\n";
	mys1.swap(mys2);
	ors1.swap(ors2);
	color_blue();
	std::cout << "my s1\n";
	for (size_t i = 0 ; i < mys1.size(); i++)
		std::cout << mys1[i] << " ";
	color_red();
	std::cout << "\nor s1\n";
	for (size_t i = 0 ; i < ors1.size(); i++)
		std::cout << ors1[i] << " ";
	color_blue();
	std::cout << "\nmy s2\n";
	for (size_t i = 0 ; i < mys2.size(); i++)
		std::cout << mys2[i] << " ";
	color_red();
	std::cout << "\nor s2\n";
	for (size_t i = 0 ; i < ors2.size(); i++)
		std::cout << ors2[i] << " ";
	color_black();
	std::cout << "\n\nnon member swap test\n";
	ft::swap(mys1, mys2);
	std::swap(ors1, ors2);
	color_blue();
	std::cout << "my s1\n";
	for (size_t i = 0 ; i < mys1.size(); i++)
		std::cout << mys1[i] << " ";
	color_red();
	std::cout << "\nor s1\n";
	for (size_t i = 0 ; i < ors1.size(); i++)
		std::cout << ors1[i] << " ";
	color_blue();
	std::cout << "\nmy s2\n";
	for (size_t i = 0 ; i < mys2.size(); i++)
		std::cout << mys2[i] << " ";
	color_red();
	std::cout << "\nor s2\n";
	for (size_t i = 0 ; i < ors2.size(); i++)
		std::cout << ors2[i] << " ";
	color_black();
	std::cout << "\n\nreverse iterator test\n";
	color_blue();
	std::cout << "my\n";
	for (ft::vector<std::string>::reverse_iterator it = mys1.rbegin(); it != mys1.rend(); it++)
		std::cout << *it << " ";
	color_red();
	std::cout <<"\nor\n";
	for (std::vector<std::string>::reverse_iterator it = ors1.rbegin(); it != ors1.rend(); it++)
		std::cout << *it << " ";
	color_black();
	std::cout <<'\n';
	wait_input();
	std::cout << "vector test finish\n";
	wait_input();
}
#endif
