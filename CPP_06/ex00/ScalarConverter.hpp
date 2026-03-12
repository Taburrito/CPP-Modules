/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/06 10:42:17 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_H__
#define __SCALARCONVERTER_H__

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <iomanip>

// ************************************************************************** //
//                          ScalarConverter Class                                  //
// ************************************************************************** //

class ScalarConverter
{

public:
	static void			convert(std::string literal);


private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter(void);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	static bool			isChar(std::string literal);
	static bool			isInt(std::string literal);
	static bool			isFloat(std::string literal);
	static bool			isDouble(std::string literal);
	static bool			isPseudoLiteral(std::string literal);
};


#endif
