/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/18 12:38:08 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"

int main()
{
	std::cout << BOLDYELLOW << "--- TEST 1: ARRAY OF ANIMALS ---" << RESET << std::endl;

	const int	count = 4;
	Animal*		animals[count];

	for (int i = 0; i < count; i++)
	{
		if (i < count / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl << BOLDYELLOW << "--- TEST 2: DEEP COPY PROOF ---" << RESET << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
	}

	std::cout << GREEN << "Une shallow copy aurait fait crash le prog" << RESET << std::endl;

	std::cout << std::endl << BOLDYELLOW << "--- TEST 3: DELETING ARRAY ---" << RESET << std::endl;
	for (int i =0; i < count; i++)
		delete animals[i];

	return 0;
}
