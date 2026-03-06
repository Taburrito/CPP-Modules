/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 11:50:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void	Form::beSigned(Bureaucrat const& i)
{
	if (i.getGrade() <= _sign_grade)
		_signed = true;
	else
		throw GradeTooLowException();
	return;
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

Form::Form(void) : _name("form"), _signed(false), _sign_grade(150), _execute_grade(150)
{
	return;
}

Form::Form(std::string name, int sign_grade, int execute_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	return;
}

Form::~Form(void)
{
	return;
}

Form::Form(const Form &src) : _name(src._name), _sign_grade(src._sign_grade), _execute_grade(src._execute_grade)
{
	*this = src;
}

Form	&Form::operator=(const Form &rhs)
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

std::string const	Form::getName(void) const
{
	return (_name);
}

bool				Form::getSigned(void) const
{
	return (_signed);
}

int					Form::getSignGrade(void) const
{
	return (_sign_grade);
}

int					Form::getExecuteGrade(void) const
{
	return (_execute_grade);
}

// ************************************************************************** //

std::ostream	&operator<<(std::ostream &o, const Form &i)
{
	o << i.getName() << ", signed status: " << i.getSigned() << "; grade to sign: " << i.getSignGrade() << "; grade to execute: " << i.getExecuteGrade();
	return (o);
}
