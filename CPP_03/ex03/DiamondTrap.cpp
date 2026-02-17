/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 11:50:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << _Name << " but my ClapTrap name is " << ClapTrap::_Name << std::endl;
	return;
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	this->_Name = "Default";
	this->_Hit_Points = FragTrap::_Hit_Points;
	this->_Energy_Points = ScavTrap::_Energy_Points;
	this->_Attack_Damage = FragTrap::_Attack_Damage;

	std::cout << "Default DiamondTrap constructor called" << std::endl;
	return;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_Name = name;
	this->_Hit_Points = FragTrap::_Hit_Points;
	this->_Energy_Points = ScavTrap::_Energy_Points;
	this->_Attack_Damage = FragTrap::_Attack_Damage;

	std::cout << "DiamondTrap naming constructor called for:" << name << std::endl;
	return;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called, rip " << _Name << std::endl;
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	return;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "DiamondTrap assignment overload called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		_Name = rhs._Name;
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

// std::string	DiamondTrap::getName(void)
// {
// 	return (_Name);
// }
