/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/09 14:14:16 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_H__
#define __PRESIDENTIALPARDONFORM_H__

# include <iostream>
# include <string>
# include "AForm.hpp"

// ************************************************************************** //
//                      PresidentialPardonForm Class                          //
// ************************************************************************** //

class PresidentialPardonForm : public AForm
{

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	void				execute(Bureaucrat const & executor) const;

	std::string			getTarget(void) const;

private:
	std::string			_target;
};

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &i);

#endif
