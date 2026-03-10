/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 11:50:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("The form you are trying to execute has not been signed");
}

void	AForm::beSigned(Bureaucrat const& i)
{
	if (i.getGrade() <= _sign_grade)
		_signed = true;
	else
		throw GradeTooLowException();
	return;
}

void	AForm::validate_execution(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > _execute_grade)
		throw GradeTooLowException();
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

AForm::AForm(void) : _name("Aform"), _signed(false), _sign_grade(150), _execute_grade(150)
{
	return;
}

AForm::AForm(std::string name, int sign_grade, int execute_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	return;
}

AForm::~AForm(void)
{
	return;
}

AForm::AForm(const AForm &src) : _name(src._name), _sign_grade(src._sign_grade), _execute_grade(src._execute_grade)
{
	*this = src;
}

AForm	&AForm::operator=(const AForm &rhs)
{
	std::cout << "Assignment overload called" << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

std::string const	AForm::getName(void) const
{
	return (_name);
}

bool				AForm::getSigned(void) const
{
	return (_signed);
}

int					AForm::getSignGrade(void) const
{
	return (_sign_grade);
}

int					AForm::getExecuteGrade(void) const
{
	return (_execute_grade);
}

// ************************************************************************** //

std::ostream	&operator<<(std::ostream &o, const AForm &i)
{
	o << i.getName() << ", signed status: " << i.getSigned() << "; grade to sign: " << i.getSignGrade() << "; grade to execute: " << i.getExecuteGrade();
	return (o);
}
