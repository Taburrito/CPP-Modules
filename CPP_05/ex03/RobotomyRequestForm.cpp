/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 11:50:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	validate_execution(executor);
	std::cout << "DrrRRrRRrRRrRrRRRRRRRRRrrrrRRRRr klong kling" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy has failed" << std::endl;
	return;
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	srand(time(NULL));
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	srand(time(NULL));
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
	this->_target = src._target;
	return;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
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

std::string			RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

// ************************************************************************** //

std::ostream	&operator<<(std::ostream &o, const RobotomyRequestForm &i)
{
	o << i.getName() << ", signed status: " << i.getSigned() << ", grade to sign: " << i.getSignGrade() << ", grade to execute: " << i.getExecuteGrade() << ", target: " << i.getTarget();
	return (o);
}
