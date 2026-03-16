/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/16 16:59:20 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "Colors.hpp"
#include <list>

int main(void)
{
	std::cout << BOLDYELLOW << "--- list main ---" << RESET << std::endl;
	std::list<int> lstack;

	lstack.push_back(5);
	lstack.push_back(17);

	std::cout << lstack.back() << std::endl;

	lstack.pop_back();

	std::cout << lstack.size() << std::endl;

	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	//[...]
	lstack.push_back(0);

	std::list<int>::iterator it = lstack.begin();
	std::list<int>::iterator ite = lstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << BOLDBLUE << "--- mutant stack main ---" << RESET << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator mit = mstack.begin();
	MutantStack<int>::iterator mite = mstack.end();

	++mit;
	--mit;

	while (mit != mite)
	{
		std::cout << *mit << std::endl;
		++mit;
	}

	std::stack<int> s(mstack);
	return 0;
}
