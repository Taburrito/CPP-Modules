/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:11:38 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/15 16:24:23 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <cctype>
# include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact(void);
		~Contact(void);

		void set_contact_first_name(std::string new_first_name);
		void set_contact_last_name(std::string new_last_name);
		void set_contact_nickname(std::string new_nickname);
		void set_contact_phone_number(std::string new_phone_number);
		void set_contact_darkest_secret(std::string new_darkest_secret);

		std::string get_contact_first_name();
		std::string get_contact_last_name();
		std::string get_contact_nickname();
		std::string get_contact_phone_number();
		std::string get_contact_darkest_secret();
};

#endif
