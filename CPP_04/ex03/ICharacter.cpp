/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/17 12:30:34 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

void ICharacter::equip(AMateria* m)
{
	if (_index < 4)
	{
		_inventory[_index] = m;
		std::cout << _inventory[_index]->getType() << " has been added to your " << _index++ << " slot" << std::endl;
	}
	else
		std::cout << "Inventory full" << std::endl;
	return;
}
void ICharacter::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Trying to unequip the wind is not an option" << std::endl;
		return;
	}
	else if (_inventory[idx])
	{
		_floor[_floor_index] = _inventory[idx];
		_inventory[idx] = NULL;
		std::cout << _floor[_floor_index++]->getType() << " has been unequiped" << std::endl;
		return;
	}
	std::cout << "You don't have anything equiped on this slot" << std::endl;
	return;
}

void ICharacter::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "You cannot use what you do not posses, let that sink in" << std::endl;
		return;
	}
	else if (_inventory[idx])
	{
		_inventory[idx]->use(target);
		return;
	}
	std::cout << "You don't have anything equiped on this slot" << std::endl;
	return;
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

ICharacter::ICharacter(void) : _index(0), _floor_index(0)
{
	std::cout << "ICharacter default constructor called" << std::endl;
	return;
}

ICharacter::ICharacter(std::string name) : _name(name)
{
	std::cout << "ICharacter type constructor called, character's name is " << name << "!" << std::endl;
	return;
}

ICharacter::~ICharacter(void)
{
	std::cout << "ICharacter destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete (_inventory[i]);
	return;
}

ICharacter::ICharacter(const ICharacter &src)
{
	std::cout << "ICharacter copy constructor called" << std::endl;
	*this = src;
	for (int i = 0; i < _index; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = src._inventory[i];
	}
}

ICharacter	&ICharacter::operator=(const ICharacter &rhs)
{
	std::cout << "ICharacter assignment overload called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_index = rhs._index;
		for (int i = 0; i < _index; i++)
			*rhs._inventory[i] = *this->_inventory[i];
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

std::string const & ICharacter::getName(void) const
{
	return(_name);
}
