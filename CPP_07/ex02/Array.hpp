/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/06 10:42:17 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_H__
#define __ARRAY_H__

# include <iostream>
# include <string>


// ************************************************************************** //
//                          Array Class                                  //
// ************************************************************************** //

template <class T>
class Array
{
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array &src);
	~Array(void);
	Array &operator=(const Array &rhs);

	unsigned int	size(void) const;

	T&	operator[](unsigned int index);
	const T&	operator[](unsigned int index) const;

	class IndexOutOfBounds : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
private:
	T*				_array;
	unsigned int	_size;
};

# include "Array.tpp"

#endif
