/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 11:50:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char* Span::ListAlreadyFull::what() const throw()
{
	return ("Cannot add to list: already full");
}

const char* Span::NotEnoughRoom::what() const throw()
{
	return ("Not enough room in list");
}

const char* Span::NoSpanFound::what() const throw()
{
	return ("No relevent span found");
}

void	Span::addNumber(int nb)
{
	if (_vec.size() < _N)
		_vec.push_back(nb);
	else
		throw ListAlreadyFull();
	return;
}

int		Span::shortestSpan(void) const
{
	if (_vec.size() <= 1)
		throw NoSpanFound();

	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	int ret = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++)
		if (tmp[i + 1] - tmp[i] < ret)
			ret = tmp[i + 1] - tmp[i];
	return ret;
}

int		Span::longestSpan(void) const
{
	if (_vec.size() <= 1)
		throw NoSpanFound();

	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());
	return (max - min);

}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

Span::Span(void) : _N(0)
{
	return;
}

Span::Span(unsigned int N) : _N(N)
{
	return;
}

Span::~Span(void)
{
	return;
}

Span::Span(const Span &src) : _N(0)
{
	*this = src;
}

Span	&Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->_N = rhs._N;
		this->_vec = rhs._vec;
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

// ************************************************************************** //


