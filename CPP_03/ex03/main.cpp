/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/17 15:05:52 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "Colors.hpp"

int	main( void )
{
	std::cout << BOLDYELLOW << "--- STEP 1: CONSTRUCTION ---" << RESET << std::endl;
	std::cout << "Creating DiamondTrap named " << CYAN << "Star Platinum" << RESET << "..." << std::endl;
	DiamondTrap Jotaro("Star Platinum");

	std::cout << std::endl << BOLDYELLOW << "--- STEP 2: IDENTITY CHECK (WhoAmI) ---" << RESET << std::endl;
	Jotaro.whoAmI();

	std::cout << std::endl << BOLDYELLOW << "--- STEP 3: ATTACK CHECK (Inherited from ScavTrap) ---" << RESET << std::endl;
	std::cout << "Jotaro attacks a target with Star Platinum. Expected damage: " << RED << "30" << RESET << std::endl;
	Jotaro.attack("Dio");

	std::cout << std::endl << BOLDYELLOW << "--- STEP 4: MIXED CAPABILITIES ---" << RESET << std::endl;
	std::cout << "1. Testing " << MAGENTA << "FragTrap" << RESET << " capacity:" << std::endl;
	Jotaro.highFivesGuys();
	std::cout << "2. Testing " << BLUE << "ScavTrap" << RESET << " capacity:" << std::endl;
	Jotaro.guardGate();

	std::cout << std::endl << BOLDRED << "--- Step 5: DESTRUCTION ---" << RESET << std::endl;
	return 0;
}
