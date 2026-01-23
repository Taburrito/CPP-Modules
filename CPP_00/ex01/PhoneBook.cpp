/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:56:13 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/16 14:39:10 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook(void) : index(0)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

int		PhoneBook::get_index(void){
	return (this->index);
}

int	valid_contact_input(std::string temp)
{
	int	i = -1;

	if (temp.length() < 1)
	{
		std::cout << "-- Invalid empty entry: please write again --" << std::endl << std::endl;
		return (EXIT_FAILURE);
	}
	else
	{
		while (++i < static_cast<int>(temp.length()))
		{
			if (temp[i] < 32 || temp[i] > 126)
			{
				std::cout << "-- Invalid entry: Unrecognised character --" << std::endl << std::endl;
				return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}

void PhoneBook::add_contact(void)
{
	std::string	temp;

	while (true){
		std::cout << "-- Please enter new contact's firt name --" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, temp);
		if (valid_contact_input(temp) == EXIT_SUCCESS)
			break;
	}
	this->contacts[this->index % 8].set_contact_first_name(temp);

	while (true){
		std::cout << "-- Please enter new contact's last name --" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, temp);
		if (valid_contact_input(temp) == EXIT_SUCCESS)
			break;
	}
	this->contacts[this->index % 8].set_contact_last_name(temp);

	while (true){
		std::cout << "-- Please enter new contact's nickname --" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, temp);
		if (valid_contact_input(temp) == EXIT_SUCCESS)
			break;
	}
	this->contacts[this->index % 8].set_contact_nickname(temp);

	while (true){
		std::cout << "-- Please enter new contact's phone number --" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, temp);
		if (valid_contact_input(temp) == EXIT_SUCCESS)
			break;
	}
	this->contacts[this->index % 8].set_contact_phone_number(temp);

	while (true){
		std::cout << "-- Please enter new contact's darkest secret --" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, temp);
		if (valid_contact_input(temp) == EXIT_SUCCESS)
			break;
	}
	this->contacts[this->index % 8].set_contact_darkest_secret(temp);
	this->index++;
}

void	PhoneBook::search_for_contact(void)
{
	int			i = -1;
	int			y = -1;
	std::string	temp_first_name;
	std::string	temp_last_name;
	std::string	temp_nickname;
	std::string	temp_prompt;

	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	while (++i < this->index && i < 8)
	{
		if (this->contacts[i].get_contact_first_name().length() > 9)
			temp_first_name = this->contacts[i].get_contact_first_name().substr(0, 9) + ".";
		else if (this->contacts[i].get_contact_first_name().length() < 10){
			while (++y < static_cast<int>(10 - this->contacts[i].get_contact_first_name().length()))
				temp_first_name += " ";
			temp_first_name += this->contacts[i].get_contact_first_name();
			y = -1;
		}
		else
			temp_nickname += this->contacts[i].get_contact_first_name();

		if (this->contacts[i].get_contact_last_name().length() > 9)
			temp_last_name = this->contacts[i].get_contact_last_name().substr(0, 9) + ".";
		else if (this->contacts[i].get_contact_last_name().length() < 10){
			while (++y < static_cast<int>(10 - this->contacts[i].get_contact_last_name().length()))
				temp_last_name += " ";
			temp_last_name += this->contacts[i].get_contact_last_name();
			y = -1;
		}
		else
			temp_nickname += this->contacts[i].get_contact_last_name();

		if (this->contacts[i].get_contact_nickname().length() > 9)
			temp_nickname = this->contacts[i].get_contact_nickname().substr(0, 9) + ".";
		else if (this->contacts[i].get_contact_nickname().length() < 10){
			while (++y < static_cast<int>(10 - this->contacts[i].get_contact_nickname().length()))
				temp_nickname += " ";
			temp_nickname += this->contacts[i].get_contact_nickname();
			y = -1;
		}
		else
			temp_nickname += this->contacts[i].get_contact_nickname();

		std::cout << "|         " << (i + 1) << "|" << temp_first_name << "|" << temp_last_name << "|" << temp_nickname << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		temp_first_name.clear();
		temp_last_name.clear();
		temp_nickname.clear();
	}

	std::cout << std::endl << "-- Please enter the index of the contact to get their informations --" << std::endl;
	while (true){
		std::cout << "> ";
		std::getline(std::cin, temp_prompt);
		if (temp_prompt.length() != 1 || temp_prompt[0] < '1' || temp_prompt[0] > '8' || (temp_prompt[0] > '0' + this->index && this->index <= 8))
			std::cout << "Invalid entry: please write within the possible scope" << std::endl;
		else
			break;
	}
	std::cout << "First name: " << this->contacts[temp_prompt[0] - '0' - 1].get_contact_first_name() << std::endl;
	std::cout << "Last name: " << this->contacts[temp_prompt[0] - '0' - 1].get_contact_last_name() << std::endl;
	std::cout << "Nickname: " << this->contacts[temp_prompt[0] - '0' - 1].get_contact_nickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[temp_prompt[0] - '0' - 1].get_contact_phone_number() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[temp_prompt[0] - '0' - 1].get_contact_darkest_secret() << std::endl;
}
