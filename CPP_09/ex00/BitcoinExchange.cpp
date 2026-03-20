/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 11:50:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool		BitcoinExchange::isFloat(std::string literal) const
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

void		BitcoinExchange::isDataLineValid(std::string content_line) const
{
	if (content_line.length() < 12) throw InvalidDataFormat();
	for (int i = 0; i < 4; i++)
		if (!isdigit(content_line[i]))
			throw InvalidDataFormat();
	if (content_line[4] != '-' || content_line[7] != '-' || content_line[10] != ',')
		throw InvalidDataFormat();
	if (!isdigit(content_line[5]) || !isdigit(content_line[6]) || !isdigit(content_line[8]) || !isdigit (content_line[9]))
		throw InvalidDataFormat();
	if (!isFloat(content_line.substr(11, content_line.length() - 11)))
		throw InvalidDataFormat();
	// ---------------------- VERIF DATE --------------------
	int year = static_cast<int>(std::strtod(content_line.substr(0, 4).c_str(), NULL));
	int month = static_cast<int>(std::strtod(content_line.substr(5, 2).c_str(), NULL));
	int day = static_cast<int>(std::strtod(content_line.substr(8, 2).c_str(), NULL));
	if (month > 12 || month < 1) throw InvalidDataFormat();
	if (day > 31 || day < 1) throw InvalidDataFormat();
	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) throw InvalidDataFormat();
	if (month == 2)
	{
		if (day > 29) throw InvalidDataFormat();
		if (day == 29 && (((year % 100) % 4) % 400 != 0)) throw InvalidDataFormat();
	}
}

void		BitcoinExchange::isInputLineValid(std::string content_line) const
{
	if (content_line.length() < 14) throw InvalidInputFormat();
	for (int i = 0; i < 4; i++)
		if (!isdigit(content_line[i]))
			throw InvalidInputFormat();
	if (content_line[4] != '-' || content_line[7] != '-' || content_line.substr(10, 3) != " | ")
		throw InvalidInputFormat();
	if (!isdigit(content_line[5]) || !isdigit(content_line[6]) || !isdigit(content_line[8]) || !isdigit (content_line[9]))
		throw InvalidInputFormat();
	if (!isFloat(content_line.substr(13, content_line.length() - 13)))
		throw InvalidInputFormat();
	// ---------------------- VERIF DATE --------------------
	int year = static_cast<int>(std::strtod(content_line.substr(0, 4).c_str(), NULL));
	int month = static_cast<int>(std::strtod(content_line.substr(5, 2).c_str(), NULL));
	int day = static_cast<int>(std::strtod(content_line.substr(8, 2).c_str(), NULL));
	if (month > 12 || month < 1) throw InvalidInputFormat();
	if (day > 31 || day < 1) throw InvalidInputFormat();
	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) throw InvalidInputFormat();
	if (month == 2)
	{
		if (day > 29) throw InvalidInputFormat();
		if (day == 29 && (((year % 100) % 4) % 400 != 0)) throw InvalidInputFormat();
	}
}

float		BitcoinExchange::isNbValid(std::string svalue) const
{
	double value = std::strtod(svalue.c_str(), NULL);
	if (value < 0)
		throw NumberIsNegative();
	else if (value > 1000)
		throw NumberIsTooBig();
	return static_cast<float>(value);
}

void		BitcoinExchange::parseInputLine(std::string content_line)
{
	double nb = std::strtod(content_line.substr(content_line.find(',', 0) + 1, content_line.length() - 11).c_str(), NULL);
	_BtcRates[content_line.substr(0, 10)] = static_cast<float>(nb);
}

void		BitcoinExchange::ShowExchangeResult(void) const
{
	std::ifstream	filename_stream(_FileName.c_str());
	if (!filename_stream.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}
	std::string	content_line;
	float fvalue;
	std::getline(filename_stream, content_line);
	while (std::getline(filename_stream, content_line))
	{
		try
		{
			isInputLineValid(content_line);
			try
			{
				fvalue = isNbValid(content_line.substr(13, content_line.length() - 13));
				std::string content_date = content_line.substr(0, 10);
				std::map<std::string, float>::const_iterator it = _BtcRates.find(content_date);
				if (it != _BtcRates.end())
				{
					if (fvalue == static_cast<int>(fvalue))
						std::cout << content_date << " => " << static_cast<int>(fvalue) << " = " << fvalue * it->second << std::endl;
					else
						std::cout << content_date << " => " << fvalue << " = " << fvalue * it->second << std::endl;
				}
				else
				{
					it = _BtcRates.upper_bound(content_date);
					if (it != _BtcRates.begin())
						it--;
					else
					{
						std::cerr << "Error: No data available at this date or any date prior" << std::endl;
						continue;
					}
					if (fvalue == static_cast<int>(fvalue))
						std::cout << content_date << " => " << static_cast<int>(fvalue) << " = " << fvalue * it->second << std::endl;
					else
						std::cout << content_date << " => " << fvalue << " = " << fvalue * it->second << std::endl;
				}
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " => " << content_line << std::endl;
		}
	}
	filename_stream.close();
}

const char* BitcoinExchange::InvalidInputFormat::what() const throw()
{
	return ("Error: bad input");
}

const char* BitcoinExchange::InvalidDataFormat::what() const throw()
{
	return ("Error: bad data");
}

const char* BitcoinExchange::NumberIsNegative::what() const throw()
{
	return ("Error: not a positive number.");
}

const char* BitcoinExchange::NumberIsTooBig::what() const throw()
{
	return ("Error: too large a number");
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

BitcoinExchange::BitcoinExchange(void)
{
	return;
}

BitcoinExchange::BitcoinExchange(std::string Filename) : _FileName(Filename)
{
	std::ifstream	filename_stream("data.csv");
	if (!filename_stream.is_open())
	{
		std::cerr << "Error: could not open data file" << std::endl;
		return;
	}
	std::string	content_line;
	std::getline(filename_stream, content_line);
	while (std::getline(filename_stream, content_line))
	{
		try
		{
			this->isDataLineValid(content_line);
			this->parseInputLine(content_line);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " => " << content_line << std::endl;
		}
	}
	filename_stream.close();
	return;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_BtcRates = rhs._BtcRates;
		this->_FileName = rhs._FileName;
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

// ************************************************************************** //


