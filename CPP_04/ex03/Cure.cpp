/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/21 15:32:09 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

AMateria* Cure::clone(void) const
{
	return (new Cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return;
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

Cure::Cure(void) : AMateria("Cure")
{
	std::cout << "Cure default constructor called" << std::endl;
	return;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
	return;
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	std::cout << "Cure copy constructor called" << std::endl;
	return;
}

Cure	&Cure::operator=(const Cure &rhs)
{
	std::cout << "Cure assignment overload called" << std::endl;
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //


