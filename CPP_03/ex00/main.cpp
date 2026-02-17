/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/10 14:09:01 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	std::cout << "\033[34m--- CONSTRUCTORS TEST ---\033[0m" << std::endl;
	ClapTrap	Maati("Maati");
	ClapTrap	Arthur("Arthur");
	ClapTrap	defaultTrap;

	std::cout << std::endl << "\033[34m--- ATTACK & DAMAGE TEST ---\033[0m" << std::endl;
	Maati.attack("Arthur");
	Arthur.takeDamage(0);
	std::cout << "Arthur falls" << std::endl;
	Arthur.takeDamage(5);

	std::cout << std::endl << "\033[34m--- REPAIR TEST ---\033[0m" << std::endl;
	Arthur.beRepaired(3);

	std::cout << std::endl << "\033[34m--- ENERGY EXHAUSTION TEST ---\033[0m" << std::endl;
	for (int i = 1; i < 10; i++)
		Maati.attack("Target Dummy");
	std::cout << "Maati tries one last attack:" << std::endl;
	Maati.attack("Target Dummy");

	std::cout << "Maati tries to repair:" << std::endl;
	Maati.beRepaired(42);

	std::cout << std::endl << "\033[34m--- DEATH TEST ---\033[0m" << std::endl;
	Arthur.takeDamage(20);
	Arthur.attack("Maati");
	Arthur.beRepaired(10);

	std::cout << std::endl << "\033[34m--- COPY & ASSIGNEMENT TEST ---\033[0m" << std::endl;
	ClapTrap clone(Maati);
	defaultTrap = Arthur;

	std::cout << "Clone tries to attack (should fail if Maati had no energy):" << std::endl;
	clone.attack("Someone");

	std::cout << std::endl << "\033[34m--- DESTRUCTORS ---\033[0m" << std::endl;
	return 0;
}
