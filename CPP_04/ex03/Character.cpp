/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/17 12:30:34 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void Character::equip(AMateria* m)
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
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Trying to unequip the wind is not an option" << std::endl;
		return;
	}
	else if (_inventory[idx])
	{
		_floor* newnode = new _floor;
		newnode->materia = _inventory[idx];
		newnode->next = _floornode;
		_floornode = newnode;
		_inventory[idx] = NULL;
		std::cout << _floornode->next->materia->getType() << " has been unequiped" << std::endl;
		return;
	}
	std::cout << "You don't have anything equiped on this slot" << std::endl;
	return;
}

void Character::use(int idx, Character& target)
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

Character::Character(void) : _index(0), _floornode(NULL)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
	return;
}

Character::Character(std::string name) : _name(name), _index(0), _floornode(NULL)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character type constructor called, character's name is " << name << "!" << std::endl;
	return;
}

Character::~Character(void)
{
	_floor* temp = _floornode;

	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete (_inventory[i]);
	while (_floornode && _floornode->next)
	{
		_floornode = _floornode->next;
		delete temp;
		temp = _floornode;
	}
	if (_floornode)
	delete _floornode;
	return;
}

Character::Character(const Character &src)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
	for (int i = 0; i < _index; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character	&Character::operator=(const Character &rhs)
{
	std::cout << "Character assignment overload called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_index = rhs._index;
		for (int i = 0; i < _index; i++)
		{
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

std::string const & Character::getName(void) const
{
	return(_name);
}
