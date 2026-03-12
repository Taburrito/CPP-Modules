/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/06 10:42:17 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_T__
#define __ARRAY_T__

template <class T>
unsigned int	Array<T>::size(void) const
{
	return _size;
}

template <class T>
const char* Array<T>::IndexOutOfBounds::what() const throw()
{
	return ("Index is out of bounds");
}

template <class T>
Array<T>::Array(void) : _array(NULL), _size(0)
{
	return;
}

template <class T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
	return;
}

template <class T>
Array<T>::Array(const Array &src) : _array(NULL), _size(0)
{
	*this = src;
	return;
}

template <class T>
Array<T>	&Array<T>::operator=(const Array &rhs)
{
	if (this != &rhs)
	{
		delete[] this->_array;
		this->_size = rhs.size();
		this->_array = new T[this->_size]();
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = rhs._array[i];
	}
	return (*this);
}

template <class T>
Array<T>::~Array(void)
{
	delete[] _array;
	return;
}

template <class T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw IndexOutOfBounds();
	return _array[index];
}

template <class T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw IndexOutOfBounds();
	return _array[index];
}

#endif
