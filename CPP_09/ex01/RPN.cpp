/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 11:50:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	RPN::Calculate(void)
{
	int	tmp;
	std::stringstream ss(_input);
	std::string token;
	while (ss >> token)
	{
		if (token.size() > 1)
			throw InvalidInput();
		if (isdigit(token[0]))
			_Tokens.push(static_cast<int>(std::strtod(token.c_str(), NULL)));
		else
		{
			if (_Tokens.size() < 2)
				throw NotEnoughNumbers();
			tmp = _Tokens.top();
			_Tokens.pop();
			if (token[0] == '+')
				_Tokens.top() += tmp;
			else if (token[0] == '-')
				_Tokens.top() -= tmp;
			else if (token[0] == '*')
				_Tokens.top() *= tmp;
			else if (token[0] == '/')
			{
				if (tmp == 0)
					throw TryingToDevideByO();
				_Tokens.top() /= tmp;
			}
			else
				throw InvalidInput();
		}
	}
	if (_Tokens.size() != 1)
		throw TooManyNumbers();
	std::cout << _Tokens.top() << std::endl;
}

const char* RPN::InvalidInput::what() const throw()
{
	return ("Error");
}

const char* RPN::NotEnoughNumbers::what() const throw()
{
	return ("Error");
}

const char* RPN::TooManyNumbers::what() const throw()
{
	return ("Error");
}

const char* RPN::TryingToDevideByO::what() const throw()
{
	return ("Error");
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

RPN::RPN(void) : _input("Default")
{
	return;
}

RPN::RPN(std::string tokens_string) : _input(tokens_string)
{
	return;
}

RPN::~RPN(void)
{
	return;
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN	&RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		this->_Tokens = rhs._Tokens;
		this->_input = rhs._input;
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

// ************************************************************************** //


