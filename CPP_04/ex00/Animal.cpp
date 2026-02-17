/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/17 12:30:34 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

void	Animal::makeSound(void) const
{
	std::cout << "ün ün ün ün ün AAAAAAAAAAAAAOOOOOOOOOOORRRRRXT" << std::endl;
	return;
}
// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

Animal::Animal(void) : _type("Amalgame")
{
	std::cout << "Animal default constructor called" << std::endl;
	return;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal type constructor called, it's a " << type << "!" << std::endl;
	return;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
	return;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	std::cout << "Animal assignment overload called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

std::string	Animal::getType(void) const
{
	return (this->_type);
}
