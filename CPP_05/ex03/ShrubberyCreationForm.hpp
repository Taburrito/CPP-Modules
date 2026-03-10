/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AShrubberyCreationForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/09 14:14:16 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_H__
#define __SHRUBBERYCREATIONFORM_H__

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

// ************************************************************************** //
//                             ShrubberyCreationForm Class                                     //
// ************************************************************************** //

class ShrubberyCreationForm : public AForm
{

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	void				execute(Bureaucrat const & executor) const;

	std::string			getTarget(void) const;

private:
	std::string			_target;
};

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &i);

#endif
