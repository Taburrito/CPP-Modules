/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:10:56 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/15 17:44:38 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	// std::cout << "Contact class constructor called" << std::endl;
	return;
}

Contact::~Contact(void)
{
	// std::cout << "Contact class destructor called" << std::endl;
	return;
}

void Contact::set_contact_first_name(std::string new_first_name)
{
	this->first_name = new_first_name;
}

void Contact::set_contact_last_name(std::string new_last_name)
{
	this->last_name = new_last_name;
}

void Contact::set_contact_nickname(std::string new_nickname)
{
	this->nickname = new_nickname;
}

void Contact::set_contact_phone_number(std::string new_phone_number)
{
	this->phone_number = new_phone_number;
}

void Contact::set_contact_darkest_secret(std::string new_darkest_secret)
{
	this->darkest_secret = new_darkest_secret;
}

std::string Contact::get_contact_first_name()
{
	return (this->first_name);
}

std::string Contact::get_contact_last_name()
{
	return (this->last_name);
}

std::string Contact::get_contact_nickname()
{
	return (this->nickname);
}

std::string Contact::get_contact_phone_number()
{
	return (this->phone_number);
}

std::string Contact::get_contact_darkest_secret()
{
	return (this->darkest_secret);
}
