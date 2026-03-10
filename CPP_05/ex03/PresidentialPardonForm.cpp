/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 11:50:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	validate_execution(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblerox" << std::endl;
	return;
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
	this->_target = src._target;
	return;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

std::string			PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

// ************************************************************************** //

std::ostream	&operator<<(std::ostream &o, const PresidentialPardonForm &i)
{
	o << i.getName() << ", signed status: " << i.getSigned() << ", grade to sign: " << i.getSignGrade() << ", grade to execute: " << i.getExecuteGrade() << ", target: " << i.getTarget();
	return (o);
}
