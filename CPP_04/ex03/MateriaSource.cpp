/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/17 12:30:34 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;

	if (_index < 4)
	{
		_inventory[_index++] = m;
		std::cout << "Materia Source stores " << m->getType() << " blueprint" << std::endl;
	}
	else
	{
		std::cout << "Materia Source is full" << std::endl;
		delete m;
	}
	return;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _index; i++)
	{
		if (_inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return NULL;
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

MateriaSource::MateriaSource(void)
{
	_index = 0;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
	return;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	std::cout << "MateriaSource destructor called" << std::endl;
	return;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = src;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &rhs)
{
	std::cout << "MateriaSource assignment overload called" << std::endl;
	if (this != &rhs)
	{
		this->_index = rhs._index;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
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


