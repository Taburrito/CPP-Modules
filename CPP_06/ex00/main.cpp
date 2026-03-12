/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/11 15:18:25 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Colors.hpp"

void	test_conversion(std::string input)
{
	std::cout << "--- Test avec: \"" << input << "\" ---" << std::endl;
	ScalarConverter::convert(input);
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return 0;
	}

	std::cout << BOLDWHITE << "===== TESTS CHAR =====" << RESET << std::endl;
	test_conversion("c");
	test_conversion("a");
	test_conversion("*");
	test_conversion("+");

	std::cout << BOLDWHITE << "===== TESTS INT =====" << RESET << std::endl;
	test_conversion("0");
	test_conversion("42");
	test_conversion("-42");
	test_conversion("+100");
	test_conversion("2147483647");
	test_conversion("2147483648");

	std::cout << BOLDWHITE << "===== TESTS FLOAT/DOUBLE =====" << RESET << std::endl;
	test_conversion("42.0f");
	test_conversion("-4.2f");
	test_conversion("4.2");
	test_conversion(".5");
	test_conversion("-.5");

	std::cout << BOLDWHITE << "===== TESTS PSEUDO-LITTERAUX =====" << RESET << std::endl;
	test_conversion("nan");
	test_conversion("+inf");
	test_conversion("-inff");

	std::cout << BOLDWHITE << "===== TESTS IMPOSSIBLE =====" << RESET << std::endl;
	test_conversion("salut");
	test_conversion("42a42b42c");

	return 0;
}
