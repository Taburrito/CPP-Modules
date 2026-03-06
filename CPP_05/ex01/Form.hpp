/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/06 16:41:26 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_H__
#define __FORM_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                             Form Class                                     //
// ************************************************************************** //

class Bureaucrat;

class Form
{

public:
	Form(void);
	Form(std::string name, int sign_grade, int execute_grade);
	~Form(void);
	Form(const Form &other);
	Form &operator=(const Form &rhs);

	void				beSigned(Bureaucrat const& i);

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
private:
	std::string const		_name;
	bool					_signed;
	int const				_sign_grade;
	int const				_execute_grade;
};

std::ostream &operator<<(std::ostream &o, const Form &i);

#endif
