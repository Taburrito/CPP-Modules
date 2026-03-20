/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/20 18:32:31 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "Colors.hpp"

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		RPN empty;
		try
		{
			empty.Calculate();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
	{
		RPN test(argv[1]);
		try
		{
			test.Calculate();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

	}
	return 0;
}
