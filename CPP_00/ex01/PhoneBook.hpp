/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:31:08 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/15 17:37:44 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		index;
public:
	PhoneBook(void);
	~PhoneBook(void);

	void	add_contact(void);
	void	search_for_contact(void);
	int		get_index(void);
};

#endif
