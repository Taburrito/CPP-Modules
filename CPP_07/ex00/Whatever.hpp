/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/06 10:42:17 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_H__
#define __WHATEVER_H__

# include <iostream>
# include <string>

template <class T>
void	swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
const T&		min(const T& a, const T& b)
{
	if (a < b)
		return a;
	return b;
}

template <class T>
const T&		max(const T& a, const T& b)
{
	if (a > b)
		return a;
	return b;
}

#endif
