/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/09 14:14:16 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_H__
#define __AFORM_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                             AForm Class                                     //
// ************************************************************************** //

class Bureaucrat;

class AForm
{

public:
	AForm(void);
	AForm(std::string name, int sign_grade, int execute_grade);
	virtual ~AForm(void);
	AForm(const AForm &other);
	AForm &operator=(const AForm &rhs);

	void				beSigned(Bureaucrat const& i);
	virtual void		execute(Bureaucrat const & executor) const = 0;
	void				validate_execution(Bureaucrat const & executor) const;

	std::string const	getName(void) const;
	bool				getSigned(void) const;
	int					getSignGrade(void) const;
	int					getExecuteGrade(void) const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	std::string const		_name;
	bool					_signed;
	int const				_sign_grade;
	int const				_execute_grade;
};

std::ostream &operator<<(std::ostream &o, const AForm &i);

#endif
