/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/10 13:44:18 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Colors.hpp"


int main( void )
{
	Intern	postit;
	Bureaucrat	scotch("Didier", 1);
	std::cout << BOLDGREEN << "--- Test: intern creates pardon form to be executed ---" << RESET << std::endl;
	AForm*	pp = postit.makeForm("presidential pardon", "potdecol");
	if (pp)
	{
		scotch.signForm(*pp);
		scotch.executeForm(*pp);
		delete pp;
	}

	std::cout << std::endl << BOLDRED << "--- Test: intern creates tries to make inexistant form ---" << RESET << std::endl;
	AForm*	ds = postit.makeForm("demande salaire", "Didier");
	(void) ds;

	return 0;
}
