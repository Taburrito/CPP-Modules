/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/12 11:43:54 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Colors.hpp"
#include <cstdlib>
#include <ctime>

Base*	generate(void)
{
	int ranumber = rand();
	Base* ret = NULL;
	if (ranumber % 3 == 0)
		ret = new A;
	else if (ranumber % 3 == 1)
		ret = new B;
	else if (ranumber % 3 == 2)
		ret = new C;
	return ret;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer identifier says its an A!" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "pointer identifier says its a B!" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "pointer identifier says its a C!" << std::endl;
	return;
}

void	identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "reference identifier says its an A!" << std::endl;
	}
	catch(const std::exception& e) {}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "reference identifier says its a B!" << std::endl;

	}
	catch(const std::exception& e) {}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "reference identifier says its a C!" << std::endl;
	}
	catch(const std::exception& e) {}

	return;
}

int	main(void)
{
	srand(time(NULL));
	Base* rand_ptr_ABC = generate();
	Base& rand_ref_ABC = *rand_ptr_ABC;
	identify(rand_ptr_ABC);
	identify(rand_ref_ABC);
	delete rand_ptr_ABC;
	return 0;
}
