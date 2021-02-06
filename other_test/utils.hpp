/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsokim <minsokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:49:26 by minsokim          #+#    #+#             */
/*   Updated: 2020/11/15 18:54:54 by minsokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include <string>
# include <iostream>

struct for_test
{
	int a;
	std::string b;
	double c;
	char d;
};

void color_blue()
{
	std::cout <<"\x1b[34m";
}
void color_red()
{
	std::cout <<"\x1b[31m";
}
void color_black()
{
	std::cout << "\x1b[0m";
}
void wait_input()
{
	std::string trash;
	std::cin >> trash;
	system("clear");
}
for_test gen_test()
{
	for_test ret;
	ret.a = rand();
	for (int i = 0; i < ret.a % 10; i++)
		ret.b += "a";
	ret.c = rand() / rand() + 1;
	ret.d = rand() % 127;
	return (ret);
}
#endif
