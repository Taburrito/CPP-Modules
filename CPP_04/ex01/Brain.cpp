/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/17 12:30:34 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

void	Brain::printIdeas(void)
{
	for (int i = 0; i < 100; i++)
		std::cout << i << ": " << _ideas[i] << std::endl;
	return;
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	return;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	return;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain assignment overload called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

std::string	Brain::getIdea(int i)
{
	return (_ideas[i]);
}

void		Brain::setIdea(int i, std::string idea)
{
	_ideas[i] = idea;
	return;
}
