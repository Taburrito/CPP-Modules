/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/21 15:32:09 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

AMateria* Ice::clone(void) const
{
	return (new Ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return;
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
	return;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
	return;
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	std::cout << "Ice copy constructor called" << std::endl;
	return;
}

Ice	&Ice::operator=(const Ice &rhs)
{
	std::cout << "Ice assignment overload called" << std::endl;
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //


