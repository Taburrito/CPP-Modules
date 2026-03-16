/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/13 12:35:20 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "Colors.hpp"

int	main(void)
{
	std::list<int> list;
	for (int i = 0; i < 11; i++)
		list.push_back(i);
	try
	{
		easyfind(list, 4);
		std::cout << "Value 4 was found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		easyfind(list, 42);
		std::cout << "Value 42 was found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
