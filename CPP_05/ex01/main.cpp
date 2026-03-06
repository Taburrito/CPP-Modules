/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/06 17:59:30 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Colors.hpp"

int main( void )
{
	std::cout << BOLDBLUE << "--- 1. Tests de creation de formulaires valides ---" << RESET << std::endl;
	try
	{
		Form nda("NDA", 50, 20);
		std::cout << "creation success : " << nda << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "error : " << e.what() << std::endl;
	}

	std::cout << std::endl << BOLDYELLOW << "--- 2. Tests de creation de formulaires invalides ---" << RESET << std::endl;
	try
	{
		std::cout << "creating a form with grade to sign = 0 : ";
		Form looserCertificate("Looser Certificate", 0, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << "creating a form with grade to sign = 151 : ";
		Form bigLooserCertificate("Big Looser Certificate", 42, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << BOLDMAGENTA << "--- 3. Tests de signatures de forms par des bureaucrat ---" << RESET << std::endl;
	Bureaucrat	gabe("Gabe CEO of steam", 1);
	Bureaucrat	epicGamesRandom("Jhon", 150);
	Form		accountHackRetrieval("Account Hack Retrieval", 42, 20);

	std::cout << "High grade : " << gabe << std::endl;
	std::cout << "Low grade : " << epicGamesRandom << std::endl;
	std::cout << "Form : " << accountHackRetrieval << std::endl;

	std::cout << std::endl << YELLOW << "3.1 Jhon tries to sign (150 < 42)" << RESET << std::endl;
	epicGamesRandom.signForm(accountHackRetrieval);

	std::cout << std::endl << BLUE << "3.2 Gabe tries to sign (1 > 42)" << RESET << std::endl;
	gabe.signForm(accountHackRetrieval);

	return 0;
}
