/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 11:50:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	validate_execution(executor);
	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}
	outfile << "               ,@@@@@@@," << std::endl;
	outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	outfile << "       |o|        | |         | |" << std::endl;
	outfile << "       |.|        | |         | |" << std::endl;
	outfile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	outfile.close();
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	this->_target = src._target;
	return;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
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

std::string			ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

// ************************************************************************** //

std::ostream	&operator<<(std::ostream &o, const ShrubberyCreationForm &i)
{
	o << i.getName() << ", signed status: " << i.getSigned() << ", grade to sign: " << i.getSignGrade() << ", grade to execute: " << i.getExecuteGrade() << ", target: " << i.getTarget();
	return (o);
}
