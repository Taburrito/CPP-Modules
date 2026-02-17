/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 12:05:49 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

void	Zombie::set_zombie_name(std::string name)
{
	this->name = name;
	return;
}

// ************************************************************************** //
//                           Constructor&Destructor                           //
// ************************************************************************** //

Zombie::Zombie(void)
{
	return;
}

Zombie::Zombie(std::string z_name) : name(z_name)
{
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "*" << this->name << " dies of cringe*" << std::endl;
	return;
}
