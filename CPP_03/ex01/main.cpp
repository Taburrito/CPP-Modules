/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/12 17:04:41 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "Colors.hpp"

int	main( void )
{
	std::cout << BOLDYELLOW << "--- STEP1: CONSTRUCTION ---" << RESET << std::endl;
	std::cout << "Creating ScavTrap named " << CYAN << "Scavy" << RESET << "..." << std::endl;

	ScavTrap scavy("Scavy");

	std::cout << std::endl << BOLDYELLOW << "--- STEP 2: STATS & ATTACK CHECK ---" << RESET << std::endl;
	std::cout << CYAN << "Scavy" << RESET << " attacks (Should deal " << RED << "20 dmg" << RESET << "):" << std::endl;
	scavy.attack("Glados");

	std::cout << std::endl << BOLDYELLOW << "--- STEP 3: INHERITED METHODS CHECK ---" << RESET << std::endl;
	std::cout << "Testing inherited takeDamage (-10 HP):" << std::endl;
	scavy.takeDamage(10);

	std::cout << "Testing inherited beRepaired (+10 HP):" << std::endl;
	scavy.beRepaired(10);

	std::cout << std::endl << BOLDYELLOW << "--- STEP 4: SPECIAL ABILITY ---" << RESET << std::endl;
	std::cout << "Activating Guard Gate mode:" << std::endl;
	scavy.guardGate();

	std::cout << std::endl << BOLDYELLOW << "--- STEP %: COPY TEST ---" << RESET << std::endl;
	{
		std::cout << "Creating a copy inside a scope..." << std::endl;
		ScavTrap copy = scavy;
		copy.guardGate();
		std::cout << "Exiting scope (Copy should be destroyed)..." << std::endl;
	}

	std::cout << std::endl << BOLDRED << "--- STEP 6: DESTRUCTION ---" << RESET << std::endl;
	std::cout << "End of main. Originial Scavy is destroyed now:" << std::endl;

	return 0;
}
