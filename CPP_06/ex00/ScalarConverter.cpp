/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/10 15:01:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


void		ScalarConverter::convert(std::string literal)
{
	std::cout << std::fixed << std::setprecision(1);
	if (isPseudoLiteral(literal))
	{
		double nb_conv = std::strtod(literal.c_str(), NULL);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(nb_conv) << "f" << std::endl;
		std::cout << "double: " << nb_conv << std::endl;
	}
	else if (isChar(literal))
	{
		char c = literal[0];
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
	}
	else if (isInt(literal) || isFloat(literal) || isDouble(literal))
	{
		double nb_conv = std::strtod(literal.c_str(), NULL);
		if (nb_conv >= 32 && nb_conv < 127)
			std::cout << "char: " << static_cast<char>(nb_conv) << std::endl;
		else if (nb_conv < 0 || nb_conv > 127)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: non displayable" << std::endl;
		if (nb_conv <= std::numeric_limits<int>::max() && nb_conv >= std::numeric_limits<int>::min())
			std::cout << "int: " << static_cast<int>(nb_conv) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		if (nb_conv <= std::numeric_limits<float>::max() && nb_conv >= -std::numeric_limits<float>::max())
			std::cout << "float: " << static_cast<float>(nb_conv) << "f" << std::endl;
		else
			std::cout << "float: impossible" << std::endl;
		if (nb_conv <= std::numeric_limits<double>::max() && nb_conv >= -std::numeric_limits<double>::max())
			std::cout << "double: " << static_cast<double>(nb_conv) << std::endl;
		else
			std::cout << "double: impossible" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

bool	ScalarConverter::isChar(std::string literal)
{
	if (literal.length() == 1 && !isdigit(literal[0]) && isprint(literal[0]))
		return true;
	return false;
}

bool			ScalarConverter::isInt(std::string literal)
{
	if (literal[0] != '-' && literal[0] != '+' && !isdigit(literal[0]))
		return false;
	for (int i = 1; i < static_cast<int>(literal.length()); i++)
		if (!isdigit(literal[i]))
			return false;
	return true;
}

bool			ScalarConverter::isFloat(std::string literal)
{
	bool onepoint = false;

	if (literal[0] != '-' && literal[0] != '+' && !isdigit(literal[0]) && literal[0] != '.')
		return false;
	if (literal[0] == '.')
		onepoint = true;
	for (int i = 1; i < static_cast<int>(literal.length() - 1); i++)
	{
		if (literal[i] != '.' && !isdigit(literal[i]))
			return false;
		else if (literal[i] == '.')
		{
			if (onepoint == true)
				return false;
			else
				onepoint = true;
		}
	}
	if (literal[literal.length() - 1] != 'f')
		return false;
	return true;
}

bool			ScalarConverter::isDouble(std::string literal)
{
	bool onepoint = false;

	if (literal[0] != '-' && literal[0] != '+' && !isdigit(literal[0]) && literal[0] != '.')
		return false;
	if (literal[0] == '.')
		onepoint = true;
	for (int i = 1; i < static_cast<int>(literal.length()); i++)
	{
		if (literal[i] != '.' && !isdigit(literal[i]))
			return false;
		else if (literal[i] == '.')
		{
			if (onepoint == true)
				return false;
			else
				onepoint = true;
		}
	}
	return true;
}

bool			ScalarConverter::isPseudoLiteral(std::string literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf"  || literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	return false;
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

ScalarConverter::ScalarConverter(void)
{
	return;
}

ScalarConverter::~ScalarConverter(void)
{
	return;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

// ************************************************************************** //
