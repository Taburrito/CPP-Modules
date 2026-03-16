/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/16 14:49:30 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Colors.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::cout << BOLDYELLOW << "--- TEST DU SUJET ---" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << BOLDYELLOW << "--- TEST EXCEPTIONS ---" << RESET << std::endl;
	Span empty(5);
	Span big_span(10000);
	std::srand(time(NULL));
	std::vector<int> rd_nbs;
	for (int i = 0; i < 10000; i++)
		rd_nbs.push_back(std::rand());
	try
	{
		empty.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " <<e.what() << std::endl;
	}
	try
	{
		empty.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		sp.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		sp.addNumbers(rd_nbs.begin(), rd_nbs.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << BOLDYELLOW << "--- TEST GRANDE LISTE (10k) ---" << RESET << std::endl;
	big_span.addNumbers(rd_nbs.begin(), rd_nbs.end());
	std::cout << "Shortest span: " << big_span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << big_span.longestSpan() << std::endl;

	return 0;
}
