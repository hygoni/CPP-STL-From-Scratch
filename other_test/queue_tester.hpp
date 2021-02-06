/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_tester.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsokim <minsokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:14:24 by minsokim          #+#    #+#             */
/*   Updated: 2020/11/15 18:53:29 by minsokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <queue>
#include <iostream>
#include "queue.hpp"
#ifndef QUEUE_TESTER_HPP
# define QUEUE_TESTER_HPP
void queue_test()
{
	system("clear");


	std::cout<<"  █████   █    ██ ▓█████  █    ██ ▓█████    ▄▄▄█████▓▓█████   ██████ ▄▄▄█████▓\n";
	std::cout<<"▒██▓  ██▒ ██  ▓██▒▓█   ▀  ██  ▓██▒▓█   ▀    ▓  ██▒ ▓▒▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒\n";
	std::cout<<"▒██▒  ██░▓██  ▒██░▒███   ▓██  ▒██░▒███      ▒ ▓██░ ▒░▒███   ░ ▓██▄   ▒ ▓██░ ▒░\n";
	std::cout<<"░██  █▀ ░▓▓█  ░██░▒▓█  ▄ ▓▓█  ░██░▒▓█  ▄    ░ ▓██▓ ░ ▒▓█  ▄   ▒   ██▒░ ▓██▓ ░ \n";
	std::cout<<"░▒███▒█▄ ▒▒█████▓ ░▒████▒▒▒█████▓ ░▒████▒     ▒██▒ ░ ░▒████▒▒██████▒▒  ▒██▒ ░ \n";
	std::cout<<"░░ ▒▒░ ▒ ░▒▓▒ ▒ ▒ ░░ ▒░ ░░▒▓▒ ▒ ▒ ░░ ▒░ ░     ▒ ░░   ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░   \n";
	std::cout<<" ░ ▒░  ░ ░░▒░ ░ ░  ░ ░  ░░░▒░ ░ ░  ░ ░  ░       ░     ░ ░  ░░ ░▒  ░ ░    ░    \n";
	std::cout<<"   ░   ░  ░░░ ░ ░    ░    ░░░ ░ ░    ░        ░         ░   ░  ░  ░    ░      \n";
	std::cout<<"    ░       ░        ░  ░   ░        ░  ░               ░  ░      ░           \n";

	std::queue<for_test> random_b;
	ft::queue<for_test> random_a;
	for (int i = 0; i < 10; i++)
	{
		for_test temp = gen_test();
		random_a.push(temp);
		random_b.push(temp);
	}
	color_black();
	std::cout << "\ndefalut constructor test\n";
	ft::queue<for_test> a1;
	std::queue<for_test> b1;
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
	std::cout <<"\nchange front test\n";
	for_test r = gen_test();
	std::cout << "before front\n";
	color_blue();
	std::cout << "my : " << random_a.front().a <<" "<<random_a.front().b<<" " <<random_a.front().c<<" " <<random_a.front().d <<std::endl;
	color_red();
	std::cout << "or : " << random_b.front().a <<" "<<random_b.front().b<<" " <<random_b.front().c<<" " <<random_b.front().d <<std::endl;
	color_black();
	random_a.front() = r;
	random_b.front() = r;
	std::cout << "after front\n";
	color_blue();
	std::cout << "my : " << random_a.front().a <<" "<<random_a.front().b<<" " <<random_a.front().c<<" " <<random_a.front().d <<std::endl;
	color_red();
	std::cout << "or : " << random_b.front().a <<" "<<random_b.front().b<<" " <<random_b.front().c<<" " <<random_b.front().d <<std::endl;
	color_black();

	std::cout <<"\nchange back test\n";
	for_test rb= gen_test();
	std::cout << "before back\n";
	color_blue();
	std::cout << "my : " << random_a.back().a <<" "<<random_a.back().b<<" " <<random_a.back().c<<" " <<random_a.back().d <<std::endl;
	color_red();
	std::cout << "or : " << random_b.back().a <<" "<<random_b.back().b<<" " <<random_b.back().c<<" " <<random_b.back().d <<std::endl;
	color_black();
	random_a.back() = rb;
	random_b.back() = rb;
	std::cout << "after back\n";
	color_blue();
	std::cout << "my : " << random_a.back().a <<" "<<random_a.back().b<<" " <<random_a.back().c<<" " <<random_a.back().d <<std::endl;
	color_red();
	std::cout << "or : " << random_b.back().a <<" "<<random_b.back().b<<" " <<random_b.back().c<<" " <<random_b.back().d <<std::endl;


	wait_input();
	color_black();
	std::cout <<"\npop test\n";
	color_blue();
	std::cout << "my\n";
	while (!random_a.empty())
	{
		std::cout << "front : " << random_a.front().a << " " << random_a.front().b << " " << random_a.front().c << " " << random_a.front().d << std::endl;
		std::cout << "back : " << random_a.back().a << " " << random_a.back().b << " " << random_a.back().c << " " << random_a.back().d << std::endl;
		random_a.pop();
	}
	color_red();
	std::cout << "or\n";
	while (!random_b.empty())
	{
		std::cout << "front : " << random_b.front().a << " " << random_b.front().b << " " << random_b.front().c << " " << random_b.front().d << std::endl;
		std::cout << "back : " << random_b.back().a << " " << random_b.back().b << " " << random_b.back().c << " " << random_b.back().d << std::endl;
		random_b.pop();
	}
	color_black();
	wait_input();
	std::cout << "queue test is finish\n";
	wait_input();
}
#endif
