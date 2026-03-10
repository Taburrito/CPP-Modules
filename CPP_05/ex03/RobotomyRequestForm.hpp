/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/09 14:14:16 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

// ************************************************************************** //
//                             RobotomyRequestForm Class                                     //
// ************************************************************************** //

class RobotomyRequestForm : public AForm
{

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	void				execute(Bureaucrat const & executor) const;

	std::string			getTarget(void) const;

private:
	std::string			_target;
};

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &i);

#endif
