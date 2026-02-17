/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/12 17:44:31 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "Colors.hpp"

int	main( void )
{
	std::cout << "--- CREATION ---" << std::endl;
	FragTrap gang("Blud");

	std::cout << std::endl << "--- TEST ACTION ---" << std::endl;
	gang.attack("Diddy");
	gang.highFivesGuys();
	std::cout << std::endl << "--- DESTRUCTION ---" << std::endl;
	return 0;
}
