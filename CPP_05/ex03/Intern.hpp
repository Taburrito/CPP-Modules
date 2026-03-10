/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/10 13:08:09 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_H__
#define __INTERN_H__

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

// ************************************************************************** //
//                          Intern Class                                  //
// ************************************************************************** //

class Intern
{

public:
	Intern(void);
	~Intern(void);
	Intern(const Intern &other);
	Intern &operator=(const Intern &rhs);

	AForm*				makeForm(std::string form, std::string target) const;


private:
	typedef AForm*		(Intern::*Intern_function_pointer)(std::string target) const;

	AForm*				makeShrub(std::string target) const;
	AForm*				makeRobot(std::string target) const;
	AForm*				makePardon(std::string target) const;
};

#endif
