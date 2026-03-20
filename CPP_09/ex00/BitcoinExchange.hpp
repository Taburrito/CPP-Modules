/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/06 10:42:17 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_H__
#define __BITCOINEXCHANGE_H__

# include <iostream>
# include <string>
# include <map>
# include <algorithm>
# include <fstream>
# include <sstream>
# include <ctime>
# include <cstdlib>

class BitcoinExchange
{

public:
	BitcoinExchange(void);
	BitcoinExchange(std::string Filename);
	~BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	void	ShowExchangeResult(void) const;

	class InvalidInputFormat : public std::exception
	{
		virtual const char* what() const throw();
	};
	class InvalidDataFormat : public std::exception
	{
		virtual const char* what() const throw();
	};
	class NumberIsNegative : public std::exception
	{
		virtual const char* what() const throw();
	};
	class NumberIsTooBig : public std::exception
	{
		virtual const char* what() const throw();
	};
private:
	std::map<std::string, float>	_BtcRates;
	std::string						_FileName;

	void	isInputLineValid(std::string file_content) const;
	void	isDataLineValid(std::string file_content) const;
	void	parseInputLine(std:: string content_line);
	bool	isFloat(std::string literal) const;
	float	isNbValid(std::string content_line) const;

};

#endif
