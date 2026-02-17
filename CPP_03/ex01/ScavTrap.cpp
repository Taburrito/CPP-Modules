/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 11:50:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ScavTrap::attack(const std::string &target)
{
	if (_Energy_Points > 0 && _Hit_Points > 0)
	{
		_Energy_Points--;
		std::cout << "ScavTrap " << _Name << " combos " << target << " for " << _Attack_Damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _Name << " is no longer able to moove..." << std::endl;
	return;
}

void	ScavTrap::guardGate(void)
{
	std::cout << _Name << " enters a guarding state, YOU SHALL NOT PASS !" << std::endl;
	return;
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_Hit_Points = 100;
	this->_Energy_Points = 50;
	this->_Attack_Damage = 20;

	std::cout << "Default ScavTrap constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_Hit_Points = 100;
	this->_Energy_Points = 50;
	this->_Attack_Damage = 20;

	std::cout << "ScavTrap naming constructor called for:" << name << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called, rip " << _Name << std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	return;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap assignment overload called" << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

// std::string	ScavTrap::getName(void)
// {
// 	return (_Name);
// }
