/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/06 10:42:17 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_H__
#define __SPAN_H__

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

class Span
{

public:
	Span(void);
	Span(unsigned int N);
	~Span(void);
	Span(const Span &other);
	Span &operator=(const Span &rhs);

	void	addNumber(int nb);
	template <typename Iterator>
	void	addNumbers(Iterator begin, Iterator end)
	{
		if (std::distance(begin, end) > static_cast<long>(_N - _vec.size()))
			throw NotEnoughRoom();
		_vec.insert(_vec.end(), begin, end);
	}
	int		shortestSpan(void) const;
	int		longestSpan(void) const;

	class ListAlreadyFull : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class NotEnoughRoom : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class NoSpanFound : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
private:
	std::vector<int>	_vec;
	unsigned int		_N;
};

#endif
