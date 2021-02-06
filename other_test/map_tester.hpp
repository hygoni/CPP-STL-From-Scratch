/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tester.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsokim <minsokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:29:37 by minsokim          #+#    #+#             */
/*   Updated: 2020/11/16 19:57:52 by minsokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils.hpp"
# include <iostream>
# include <map>
# include "map.hpp"
#ifndef MAP_TESTER_HPP
# define MAP_TESTER_HPP
void	map_test()
{
	system("clear");
	std::cout<<"███▄ ▄███▓ ▄▄▄       ██▓███     ▄▄▄█████▓▓█████   ██████ ▄▄▄█████▓\n";
	std::cout<<"▓██▒▀█▀ ██▒▒████▄    ▓██░  ██▒   ▓  ██▒ ▓▒▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒\n";
	std::cout<<"▓██    ▓██░▒██  ▀█▄  ▓██░ ██▓▒   ▒ ▓██░ ▒░▒███   ░ ▓██▄   ▒ ▓██░ ▒░\n";
	std::cout<<"▒██    ▒██ ░██▄▄▄▄██ ▒██▄█▓▒ ▒   ░ ▓██▓ ░ ▒▓█  ▄   ▒   ██▒░ ▓██▓ ░\n";
	std::cout<<"▒██▒   ░██▒ ▓█   ▓██▒▒██▒ ░  ░     ▒██▒ ░ ░▒████▒▒██████▒▒  ▒██▒ ░\n";
	std::cout<<"░ ▒░   ░  ░ ▒▒   ▓▒█░▒▓▒░ ░  ░     ▒ ░░   ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░  \n";
	std::cout<<"░  ░      ░  ▒   ▒▒ ░░▒ ░            ░     ░ ░  ░░ ░▒  ░ ░    ░   \n";
	std::cout<<"░      ░     ░   ▒   ░░            ░         ░   ░  ░  ░    ░     \n";
	std::cout<<"░         ░  ░                        ░  ░      ░           \n";


	std::cout<<"default constructor test\n";
	ft::map<int, int> a;
	std::map<int, int> b;
	color_blue();
	std::cout << "my map  size : " << a.size() << " max_size : " << a.max_size() << std::endl;
	color_red();
	std::cout << "or map  size : " << b.size() << " max_size : " << b.max_size() << std::endl;
	color_black();

	std::cout<<"\nrange constructor test\n";
	ft::map<int, int> a1;
	std::map<int, int> b1;
	for (int i = 0 ; i < 10;i++)
	{
		int temp_key = rand();
		int temp_value = rand();
		a1.insert(ft::make_pair(temp_key, temp_value));
		b1.insert(std::make_pair(temp_key, temp_value));
	}
	std::cout << "sample map\n";
	color_blue();
	std::cout << "my map\n";
	for (ft::map<int,int>::iterator it = a1.begin(); it != a1.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map\n";
	for (std::map<int,int>::iterator it = b1.begin(); it != b1.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_black();
	wait_input();
	std::cout << "after create\n";
	ft::map<int,int> a2(a1.begin(), a1.end());
	std::map<int,int> b2(b1.begin(), b1.end());
	color_blue();
	std::cout << "my map\n";
	for (ft::map<int,int>::iterator it = a2.begin(); it != a2.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map\n";
	for (std::map<int,int>::iterator it = b2.begin(); it != b2.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_black();

	std::cout << "\ncopy constructor test\n";
	ft::map<int,int> a3(a1.begin(), a1.end());
	std::map<int, int> b3(b1.begin(), b1.end());
	color_blue();
	std::cout << "my map\n";
	for (ft::map<int,int>::iterator it = a2.begin(); it != a2.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map\n";
	for (std::map<int,int>::iterator it = b2.begin(); it != b2.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	wait_input();

	color_black();
	std::cout << "\nassign operator test\n";
	ft::map<int, int> a4;
	std::map<int, int> b4;
	a4 = a3;
	b4 = b3;
	color_blue();
	std::cout << "my map\n";
	for (ft::map<int,int>::iterator it = a2.begin(); it != a2.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map\n";
	for (std::map<int,int>::iterator it = b2.begin(); it != b2.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;

	color_black();
	wait_input();
	std::cout << "\noperator [] test\n";
	ft::map<char, std::string> a5;
	std::map<char, std::string> b5;
	a5['a'] = "this is A";
	a5['c'] = "this is C";
	a5['f'] = "this is f";
	a5['x'] = "this is x";
	a5['c'] = "no this is d";
	color_blue();
	std::cout <<	"a5[\'a\'] = \"this is A\"\n";
	std::cout <<    "a5[\'c\'] = \"this is C\"\n";
	std::cout <<    "a5[\'f\'] = \"this is f\"\n";
	std::cout <<    "a5[\'x\'] = \"this is x\"\n";
	std::cout <<    "a5[\'c\'] = \"no this is d\"\n";


	b5['a'] = "this is A";
	b5['c'] = "this is C";
	b5['f'] = "this is f";
	b5['x'] = "this is x";
	b5['c'] = "no this is d";
	color_red();
	std::cout <<	"b5[\'a\'] = \"this is A\"\n";
	std::cout <<    "b5[\'c\'] = \"this is C\"\n";
	std::cout <<    "b5[\'f\'] = \"this is f\"\n";
	std::cout <<    "b5[\'x\'] = \"this is x\"\n";
	std::cout <<    "b5[\'c\'] = \"no this is d\"\n";
	color_blue();
	std::cout << "my map    max size : " << a5.max_size() << "\n";
	for (ft::map<char,std::string>::iterator it = a5.begin(); it != a5.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map    max size : " << b5.max_size()<< "\n";
	for (std::map<char,std::string>::iterator it = b5.begin(); it != b5.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;

	color_black();
	wait_input();
	std::cout <<"\nsingle element insert test\n";
	ft::pair<ft::map<char, std::string>::iterator, bool> ret1;
	std::pair<std::map<char, std::string>::iterator, bool> ret2;
	std::cout << "insert (z, this is z)\n";
	a5.insert(ft::make_pair('z', "this is z"));
	b5.insert(std::make_pair('z', "this is z"));
	color_blue();
	std::cout << "my map\n";
	for (ft::map<char,std::string>::iterator it = a5.begin(); it != a5.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map\n";
	for (std::map<char,std::string>::iterator it = b5.begin(); it != b5.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_black();
	std::cout <<"insert (A, this is A)\n";
	b5.insert(std::make_pair('A', "this is A"));
	a5.insert(ft::make_pair('A', "this is A"));
	color_blue();
	std::cout << "my map\n";
	for (ft::map<char,std::string>::iterator it = a5.begin(); it != a5.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map\n";
	for (std::map<char,std::string>::iterator it = b5.begin(); it != b5.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_black();
	std::cout << "insert (c, hello c)\n";
	a5.insert(ft::make_pair('c', "hello c"));
	b5.insert(std::make_pair('c',"hello c"));
	color_blue();
	std::cout << "my map\n";
	for (ft::map<char,std::string>::iterator it = a5.begin(); it != a5.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map\n";
	for (std::map<char,std::string>::iterator it = b5.begin(); it != b5.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_black();
	wait_input();

	std::cout << "\nrange insert\n";
	ft::map<char,std::string>	a6;
	std::map<char, std::string> b6;
	a6['a'] = "new AAAA";
	a6['b'] = "new CCCC";
	a6['z'] = "new ZZZZ";
	b6['a'] = "new AAAA";
	b6['b'] = "new CCCC";
	b6['z'] = "new ZZZZ";
	std::cout << "before insert\n";
	color_blue();
	std::cout << "my map\n";
	for (ft::map<char,std::string>::iterator it = a6.begin(); it != a6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map\n";
	for (std::map<char,std::string>::iterator it = b6.begin(); it != b6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_black();
	std::cout << "after insert\n";
	a6.insert(a5.begin(), a5.end());
	b6.insert(b5.begin(), b5.end());
	color_blue();
	std::cout << "my map\n";
	for (ft::map<char,std::string>::iterator it = a6.begin(); it != a6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map\n";
	for (std::map<char,std::string>::iterator it = b6.begin(); it != b6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_black();
	wait_input();
	std::cout <<"\nsingle erase test : delete begin() + 3\n";
	ft::map<char, std::string>::iterator myit = a6.begin();
	std::map<char, std::string>::iterator orit = b6.begin();
	for (int i = 0 ; i <3 ; i++)
	{
		myit++;
		orit++;
	}
	a6.erase(myit);
	b6.erase(orit);
	color_blue();
	std::cout << "my map\n";
	for (ft::map<char,std::string>::iterator it = a6.begin(); it != a6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map\n";
	for (std::map<char,std::string>::iterator it = b6.begin(); it != b6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_black();
	std::cout << "\nkey erase : key : a, z, k\n";
	a6.erase('a');
	a6.erase('z');
	b6.erase('a');
	b6.erase('z');
	a6.erase('k');
	b6.erase('k');
	color_blue();
	std::cout << "my map\n";
	for (ft::map<char,std::string>::iterator it = a6.begin(); it != a6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map\n";
	for (std::map<char,std::string>::iterator it = b6.begin(); it != b6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_black();
	std::cout <<"\range erase begin()+2 , end()\n";
	myit = a6.begin();
	orit = b6.begin();
	myit++;
	myit++;
	orit++;
	orit++;
	a6.erase(myit, a6.end());
	b6.erase(orit, b6.end());
	color_blue();
	std::cout << "my map\n";
	for (ft::map<char,std::string>::iterator it = a6.begin(); it != a6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map\n";
	for (std::map<char,std::string>::iterator it = b6.begin(); it != b6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_black();
	wait_input();
	std::cout <<"\nswap test\n";
	std::cout << "before swap\n";
	color_blue();
	std::cout << "my map 1\n";
	for (ft::map<char,std::string>::iterator it = a6.begin(); it != a6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map 1\n";
	for (std::map<char,std::string>::iterator it = b6.begin(); it != b6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_blue();
	std::cout << "my map 2\n";
	for (ft::map<char,std::string>::iterator it = a5.begin(); it != a5.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map 2\n";
	for (std::map<char,std::string>::iterator it = b5.begin(); it != b5.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;

	color_black();
	std::cout << "after swap\n";
	a6.swap(a5);
	b6.swap(b5);
	color_blue();
	std::cout << "my map 1\n";
	for (ft::map<char,std::string>::iterator it = a6.begin(); it != a6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map 1\n";
	for (std::map<char,std::string>::iterator it = b6.begin(); it != b6.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_blue();
	std::cout << "my map 2\n";
	for (ft::map<char,std::string>::iterator it = a5.begin(); it != a5.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map 2\n";
	for (std::map<char,std::string>::iterator it = b5.begin(); it != b5.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;

	color_black();
	std::cout << "reverse iterator test\n";
	color_blue();
	std::cout << "my map 1\n";
	for (ft::map<char,std::string>::reverse_iterator it = a6.rbegin(); it != a6.rend(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map 1\n";
	for (std::map<char,std::string>::reverse_iterator it = b6.rbegin(); it != b6.rend(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;


	wait_input();
	color_black();
	std::cout << "\nfind , count test\n";
	std::cout << "find a, b, c, d, e\n";
	color_blue();
	std::cout << "my\n";
	for (int i = 0 ; i < 5; i++)
	{
		myit = a6.find('a'+i);
		if (myit == a6.end())
			std::cout << "can't find\n";
		else
			std::cout << "key : " << (*myit).first << " value : " << (*myit).second << std::endl;
	}
	color_red();
	std::cout << "or\n";
	for (int i = 0 ; i < 5; i++)
	{
		orit = b6.find('a'+i);
		if (orit == b6.end())
			std::cout << "can't find\n";
		else
			std::cout << "key : " << (*orit).first << " value : " << (*orit).second << std::endl;
	}
	color_black();
	std::cout << "count a, b, c, d, e\n";
	color_blue();
	std::cout << "my\n";
	for (int i = 0 ; i < 5; i++)
		std::cout << 'a' + i << " count : " << a6.count('a'+i)<<std::endl;
	color_red();
	std::cout << "or\n";
	for (int i = 0 ; i < 5; i++)
		std::cout << 'a' + i << " count : " << b6.count('a'+i)<<std::endl;
	wait_input();
	color_black();
	std::cout << "\nlower_bound, upper_bound test lower bound 'c', upper bound 'e'\n";

	ft::map<char,int> mymap;
	std::map<char,int> ormap;
	mymap['a'] = 184;
	mymap['b'] = 134;
	mymap['c'] = 42;
	mymap['d'] = 12;
	mymap['e'] = 14;
	mymap['z'] = -4;
	mymap['f'] = 34;
	mymap['A'] = -134;
	ormap['a'] = 184;
	ormap['b'] = 134;
	ormap['c'] = 42;
	ormap['d'] = 12;
	ormap['e'] = 14;
	ormap['z'] = -4;
	ormap['f'] = 34;
	ormap['A'] = -134;
	color_blue();
	std::cout << "my map  -> lower_boud :  "<< (*mymap.lower_bound('c')).second << " upper_bound " << (*mymap.upper_bound('e')).second << "\n";
	for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map  -> lower_boud :  "<< (*ormap.lower_bound('c')).second << " upper_bound " << (*ormap.upper_bound('e')).second << "\n";
	for (std::map<char,int>::iterator it = ormap.begin(); it != ormap.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_black();
	std::cout << "erase lower_bound ~ upper_bound \n";
	mymap.erase(mymap.lower_bound('c'), mymap.upper_bound('e'));
	ormap.erase(ormap.lower_bound('c'), ormap.upper_bound('e'));
	color_blue();
	std::cout << "my map  -> lower_boud :  "<< (*mymap.lower_bound('c')).second << " upper_bound" << (*mymap.upper_bound('e')).second << "\n";
	for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	color_red();
	std::cout << "or map  -> lower_boud :  "<< (*ormap.lower_bound('c')).second << " upper_bound" << (*ormap.upper_bound('e')).second << "\n";
	for (std::map<char,int>::iterator it = ormap.begin(); it != ormap.end(); it++)
		std::cout << "key : "<<(*it).first<<" value : "<<(*it).second<<std::endl;
	wait_input();
	color_black();
	std::cout << "map test finish\n";
	wait_input();
}
#endif
