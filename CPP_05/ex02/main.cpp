/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/10 10:51:00 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	std::cout << BOLDGREEN << "--- Creation des bureaucrates ---" << RESET << std::endl;
	Bureaucrat mafiaboss("Pablo Escobar", 1);
	Bureaucrat righthand("Gustavo de Jesus Gaviria Rivero", 50);
	Bureaucrat lackey("Jose", 150);

	std::cout << mafiaboss << std::endl;
	std::cout << righthand << std::endl;
	std::cout << lackey << std::endl;

	std::cout << std::endl << BOLDCYAN << "--- Test Shrubbery ---" << RESET << std::endl;
	ShrubberyCreationForm jardinier("jardin");
	std::cout << jardinier << std::endl;
	lackey.signForm(jardinier);
	lackey.executeForm(jardinier);
	righthand.signForm(jardinier);
	lackey.executeForm(jardinier);
	righthand.executeForm(jardinier);

	std::cout << std::endl << BOLDBLUE << "--- Test Robotomy ---" << RESET << std::endl;
	RobotomyRequestForm robot("Tommy");
	std::cout << robot << std::endl;
	righthand.signForm(robot);
	righthand.executeForm(robot);
	mafiaboss.executeForm(robot);
	mafiaboss.executeForm(robot);
	mafiaboss.executeForm(robot);
	mafiaboss.executeForm(robot);

	std::cout << std::endl << BOLDMAGENTA << "--- Test Presidential ---" << RESET << std::endl;
	PresidentialPardonForm pardon("Big Tony");
	std::cout << pardon << std::endl;
	righthand.signForm(pardon);
	mafiaboss.signForm(pardon);
	mafiaboss.executeForm(pardon);

	std::cout << std::endl << BOLDRED << "--- Fin des tests ---" << RESET << std::endl;
	return 0;
}
