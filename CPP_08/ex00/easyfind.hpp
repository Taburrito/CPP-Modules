/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/06 10:42:17 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_H__
#define __EASYFIND_H__

# include <iostream>
# include <string>
# include <list>
# include <algorithm>

class ValueNotInList : public std::exception
{
public:
	const char* what() const throw()
	{
		return ("Could not find value in list");
	}
};



template <class T>
typename T::iterator	easyfind(T& list, int to_find)
{
	typename T::iterator it = std::find(list.begin(), list.end(), to_find);
	if(it == list.end())
		throw ValueNotInList();
	return it;
}

#endif
