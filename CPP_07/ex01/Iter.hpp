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

#ifndef __ITER_H__
#define __ITER_H__

# include <iostream>
# include <string>

template <class T, class F>
void	iter(T* array, const size_t length, F function)
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
	return;
}

template <class T>
void	print_elem(T elem)
{
	std::cout << elem << std::endl;
	return;
}

#endif
