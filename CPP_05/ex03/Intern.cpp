/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/10 13:32:13 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm*		Intern::makeForm(std::string form, std::string target) const
{
	Intern_function_pointer	function_tab[3];
	function_tab[0] = &Intern::makeShrub;
	function_tab[1] = &Intern::makeRobot;
	function_tab[2] = &Intern::makePardon;
	std::string	formName[3];
	formName[0] = "shrubbery creation";
	formName[1] = "robotomy request";
	formName[2] = "presidential pardon";

	for (int i = 0; i < 3; i++)
	{
		if (formName[i] == form)
		{
			AForm*	ret = (this->*function_tab[i])(target);
			std::cout << "Intern creates " << *ret << std::endl;
			return (ret);
		}
	}
	std::cerr << "Error: the form you asked for doesn't exist" << std::endl;
	return NULL;
}

AForm*		Intern::makeShrub(std::string target) const
{
	AForm*	s = new ShrubberyCreationForm(target);
	return s;
}

AForm*		Intern::makeRobot(std::string target) const
{
	AForm*	r = new RobotomyRequestForm(target);
	return r;
}

AForm*		Intern::makePardon(std::string target) const
{
	AForm*	p = new PresidentialPardonForm(target);
	return p;
}


// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

Intern::Intern(void)
{
	return;
}

Intern::~Intern(void)
{
	return;
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	(void) rhs;
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

// ************************************************************************** //

