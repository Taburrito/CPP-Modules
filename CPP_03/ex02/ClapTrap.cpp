/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 11:50:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	ClapTrap::attack(const std::string &target)
{
	if (_Energy_Points > 0 && _Hit_Points > 0)
	{
		_Energy_Points--;
		std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing " << _Attack_Damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _Name << " is no longer able to moove..." << std::endl;
	return;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _Hit_Points)
		_Hit_Points = 0;
	else
		_Hit_Points -= amount;
	std::cout << "ClapTrap " << _Name << " takes " << amount << " damage !" << std::endl << "HP left is: " << _Hit_Points << std::endl;
	if (_Hit_Points == 0)
		std::cout << "ClapTrap " << _Name << " is no longer able to moove..." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_Energy_Points > 0 && _Hit_Points > 0)
	{
		_Hit_Points += amount;
		_Energy_Points--;
		std::cout << "ClapTrap " << _Name << " repairs itself for " << amount << " HP" << std::endl << "New HP total is: " << _Hit_Points << std::endl;
	}
	else
		std::cout << "ClapTrap " << _Name << " is no longer able to moove..." << std::endl;
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

ClapTrap::ClapTrap(void) : _Name("Default Name"), _Hit_Points(10), _Energy_Points(10), _Attack_Damage(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _Hit_Points(10), _Energy_Points(10), _Attack_Damage(0)
{
	std::cout << "Naming constructor called for:" << name << std::endl;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called, rip " << _Name << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "Assignment overload called" << std::endl;
	if (this != &rhs)
	{
		this->_Name = rhs._Name;
		this->_Hit_Points = rhs._Hit_Points;
		this->_Energy_Points = rhs._Energy_Points;
		this->_Attack_Damage = rhs._Attack_Damage;
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

// std::string	ClapTrap::getName(void)
// {
// 	return (_Name);
// }
