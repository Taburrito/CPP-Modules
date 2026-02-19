/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/17 12:30:34 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

AMateria::AMateria(void) : _type("Amalgame")
{
	std::cout << "AMateria default constructor called" << std::endl;
	return;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria type constructor called, it's a " << type << "!" << std::endl;
	return;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
	return;
}

AMateria::AMateria(const AMateria &src)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria	&AMateria::operator=(const AMateria &rhs)
{
	std::cout << "AMateria assignment overload called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //


