/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/06 10:42:17 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_H__
#define __RPN_H__

# include <iostream>
# include <string>
# include <queue>
# include <stack>
# include <algorithm>
# include <fstream>
# include <sstream>
# include <ctime>
# include <cstdlib>

class RPN
{

public:
	RPN(void);
	RPN(std::string tokens_string);
	~RPN(void);
	RPN(const RPN &other);
	RPN &operator=(const RPN &rhs);

	void	Calculate(void);

	class InvalidInput: public std::exception
	{
		virtual const char* what() const throw();
	};
	class NotEnoughNumbers: public std::exception
	{
		virtual const char* what() const throw();
	};
	class TooManyNumbers: public std::exception
	{
		virtual const char* what() const throw();
	};
	class TryingToDevideByO: public std::exception
	{
		virtual const char* what() const throw();
	};
private:
	std::stack<int>	_Tokens;
	std::string		_input;

};

#endif
