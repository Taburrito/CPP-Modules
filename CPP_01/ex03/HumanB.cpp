/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 14:26:37 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	return;
}

// ************************************************************************** //
//                           Constructor&Destructor                           //
// ************************************************************************** //

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

// ************************************************************************** //
//                                   Get&Set                                  //
// ************************************************************************** //

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
	return;
}
