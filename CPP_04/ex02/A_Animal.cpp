/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/17 12:30:34 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"

void	A_Animal::makeSound(void) const
{
	std::cout << "ün ün ün ün ün AAAAAAAAAAAAAOOOOOOOOOOORRRRRXT" << std::endl;
	return;
}
// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

A_Animal::A_Animal(void) : _type("Amalgame")
{
	std::cout << "A_Animal default constructor called" << std::endl;
	return;
}

A_Animal::A_Animal(std::string type) : _type(type)
{
	std::cout << "A_Animal type constructor called, it's a " << type << "!" << std::endl;
	return;
}

A_Animal::~A_Animal(void)
{
	std::cout << "A_Animal destructor called" << std::endl;
	return;
}

A_Animal::A_Animal(const A_Animal &src)
{
	std::cout << "A_Animal copy constructor called" << std::endl;
	*this = src;
}

A_Animal	&A_Animal::operator=(const A_Animal &rhs)
{
	std::cout << "A_Animal assignment overload called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

std::string	A_Animal::getType(void) const
{
	return (this->_type);
}
