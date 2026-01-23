/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:11:05 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/15 18:20:53 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	while (42){
		std::cout << "-- To add a contact enter \"ADD\", to search for a contact enter \"SEARCH\" and to exit enter \"EXIT\" --" << std::endl;
		std::cout << "> ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH" && phonebook.get_index() == 0)
			std::cout << "No contact to search for in phonebook" << std::endl;
		else if (command == "SEARCH" && phonebook.get_index() > 0)
			phonebook.search_for_contact();
	}
	return (0);
}
