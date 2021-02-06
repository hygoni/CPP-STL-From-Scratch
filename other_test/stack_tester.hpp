/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tester.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsokim <minsokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:38:30 by minsokim          #+#    #+#             */
/*   Updated: 2020/11/15 18:54:30 by minsokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <stack>
#include <iostream>
#include "stack.hpp"
#ifndef STACK_TESTER_HPP
# define STACK_TESTER_HPP
void stack_test()
{
	system("clear");

	std::cout<<"  ██████ ▄▄▄█████▓ ▄▄▄       ▄████▄   ██ ▄█▀   ▄▄▄█████▓▓█████   ██████ ▄▄▄█████▓\n";
	std::cout<<"▒██    ▒ ▓  ██▒ ▓▒▒████▄    ▒██▀ ▀█   ██▄█▒    ▓  ██▒ ▓▒▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒\n";
	std::cout<<"░ ▓██▄   ▒ ▓██░ ▒░▒██  ▀█▄  ▒▓█    ▄ ▓███▄░    ▒ ▓██░ ▒░▒███   ░ ▓██▄   ▒ ▓██░ ▒░\n";
	std::cout<<"  ▒   ██▒░ ▓██▓ ░ ░██▄▄▄▄██ ▒▓▓▄ ▄██▒▓██ █▄    ░ ▓██▓ ░ ▒▓█  ▄   ▒   ██▒░ ▓██▓ ░ \n";
	std::cout<<"▒██████▒▒  ▒██▒ ░  ▓█   ▓██▒▒ ▓███▀ ░▒██▒ █▄     ▒██▒ ░ ░▒████▒▒██████▒▒  ▒██▒ ░ \n";
	std::cout<<"▒ ▒▓▒ ▒ ░  ▒ ░░    ▒▒   ▓▒█░░ ░▒ ▒  ░▒ ▒▒ ▓▒     ▒ ░░   ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░   \n";
	std::cout<<"░ ░▒  ░ ░    ░      ▒   ▒▒ ░  ░  ▒   ░ ░▒ ▒░       ░     ░ ░  ░░ ░▒  ░ ░    ░   \n";
	std::cout<<"░  ░  ░    ░        ░   ▒   ░        ░ ░░ ░      ░         ░   ░  ░  ░    ░      \n";
	std::cout<<"      ░                 ░  ░░ ░      ░  ░                  ░  ░      ░          \n";
	std::cout<<"                            ░                                                   \n";

	std::stack<for_test> random_b;
	ft::stack<for_test> random_a;
	for (int i = 0; i < 10; i++)
	{
		for_test temp = gen_test();
		random_a.push(temp);
		random_b.push(temp);
	}
	color_black();
	std::cout << "\ndefalut constructor test\n";
	ft::stack<for_test> a1;
	std::stack<for_test> b1;
	color_blue();
	std::cout << "my : size = " << a1.size() << std::endl;
	color_red();
	std::cout << "or : size = " << b1.size() << std::endl;
	color_black();
	std::cout << "\npush test\n";
	color_blue();
	std::cout << "my : size = " << random_a.size() << std::endl;
	color_red();
	std::cout << "or : size = " << random_b.size() << std::endl;
	color_black();
	wait_input();
	std::cout <<"\nchange top test\n";
	for_test r = gen_test();
	std::cout << "before top\n";
	color_blue();
	std::cout << "my : " << random_a.top().a <<" "<<random_a.top().b<<" " <<random_a.top().c<<" " <<random_a.top().d <<std::endl;
	color_red();
	std::cout << "or : " << random_b.top().a <<" "<<random_b.top().b<<" " <<random_b.top().c<<" " <<random_b.top().d <<std::endl;
	color_black();
	random_a.top() = r;
	random_b.top() = r;
	std::cout << "after top\n";
	color_blue();
	std::cout << "my : " << random_a.top().a <<" "<<random_a.top().b<<" " <<random_a.top().c<<" " <<random_a.top().d <<std::endl;
	color_red();
	std::cout << "or : " << random_b.top().a <<" "<<random_b.top().b<<" " <<random_b.top().c<<" " <<random_b.top().d <<std::endl;

	color_black();
	std::cout <<"\npop and top test\n";
	color_blue();
	std::cout << "my\n";
	while (!random_a.empty())
	{
		std::cout << "TOP : " << random_a.top().a << " " << random_a.top().b << " " << random_a.top().c << " " << random_a.top().d << std::endl;
		random_a.pop();
	}
	color_red();
	std::cout << "or\n";
	while (!random_b.empty())
	{
		std::cout << "TOP : " << random_b.top().a << " " << random_b.top().b << " " << random_b.top().c << " " << random_b.top().d << std::endl;
		random_b.pop();
	}
	color_black();
	wait_input();
	std::cout << "stack test is finish\n";
	wait_input();
}
#endif
