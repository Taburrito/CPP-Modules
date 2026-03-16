/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/06 10:42:17 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__

# include <iostream>
# include <string>
# include <vector>
# include <stack>
# include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{

public:
	MutantStack(void) : std::stack<T>() {return;}
	~MutantStack(void) {return;}
	MutantStack(const MutantStack &other) : std::stack<T>(other) {return;}
	MutantStack &operator=(const MutantStack &rhs)
	{
		if (this != &rhs)
		{
			std::stack<T>::operator=(rhs);
		}
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator	begin(void) {return (this->c.begin());}
	iterator	end(void) {return (this->c.end());}

	const_iterator begin(void) const {return (this->c.begin());}
	const_iterator end(void) const {return (this->c.end());}

	reverse_iterator	rbegin(void) {return (this->c.rbegin());}
	reverse_iterator	rend(void) {return (this->c.rend());}

	const_reverse_iterator	rbegin(void) const {return (this->c.rbegin());}
	const_reverse_iterator	rend(void) const {return (this->c.rend());}

private:

};

#endif
