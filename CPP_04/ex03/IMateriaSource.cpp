/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/17 12:30:34 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"


void IMateriaSource::learnMateria(AMateria* m)
{
	std::cout << "Materia Source stores " << m->getType() << " blueprint" << std::endl;
	_materia = m;
	return;
}

AMateria* IMateriaSource::createMateria(std::string const & type)
{
	return (new AMateria(type));
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

IMateriaSource::IMateriaSource(void)
{
	std::cout << "IMateriaSource default constructor called" << std::endl;
	return;
}

IMateriaSource::~IMateriaSource(void)
{
	std::cout << "IMateriaSource destructor called" << std::endl;
	return;
}

IMateriaSource::IMateriaSource(const IMateriaSource &src)
{
	std::cout << "IMateriaSource copy constructor called" << std::endl;
	*this = src;
}

IMateriaSource	&IMateriaSource::operator=(const IMateriaSource &rhs)
{
	std::cout << "IMateriaSource assignment overload called" << std::endl;
	if (this != &rhs)
	{
		this->_materia = rhs._materia;
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //


