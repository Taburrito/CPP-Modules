/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/10 15:01:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

Data::Data(void) : _name("Default"), _id(42)
{
	return;
}

Data::Data(std::string name, int id) : _name(name), _id(id)
{
	return;
}

Data::~Data(void)
{
	return;
}

Data::Data(const Data &src)
{
	*this = src;
}

Data	&Data::operator=(const Data &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_id = rhs._id;
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

std::string		Data::getName(void) const
{
	return (_name);
}

int				Data::getId(void) const
{
	return (_id);
}

// ************************************************************************** //

std::ostream	&operator<<(std::ostream &o, const Data &i)
{
	o << i.getName() << ", id: " << i.getId();
	return (o);
}
