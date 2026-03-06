/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/06 12:23:03 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Colors.hpp"

int	main( void )
{
	std::cout << BOLDBLUE << "Tests de bureaucrat fonctionnel" << RESET << std::endl;
	Bureaucrat jhon;
	std::cout << jhon << " He is a " << YELLOW << "default " << RESET << "employee" << std::endl;
	Bureaucrat weak("Weak", 130);
	std::cout << weak << " He is a " << YELLOW << "named " << RESET << "employee" << std::endl;
	for (int i = 1; i < 130; i++)
		weak.promote();
	std::cout << weak << "   Started from the bottom now he here" << std::endl;
	for (int i = 1; i < 140; i++)
		weak.demote();
	std::cout << weak << " Couldn't handle behing a top dog" << std::endl;

	std::cout << std::endl << BOLDYELLOW << "Tests de bureaucraft defaillant" << RESET << std::endl;
	std::cout << "Number 1 employee gets promoted: ";
	try
	{
		Bureaucrat joe("Joe", 1);
		joe.promote();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << "Really bad employee gets demoted: ";
	try
	{
		Bureaucrat boe("Boe", 150);
		boe.demote();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << "His grade is above 9000: ";
	try
	{
		Bureaucrat moe("Moe", 9999);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << "Sub Zero goes corporate: ";
	try
	{
		Bureaucrat loe("Loe", -42);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	return 0;
}
