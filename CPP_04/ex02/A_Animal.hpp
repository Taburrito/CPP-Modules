/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/18 15:05:44 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __A_ANIMAL_H__
#define __A_ANIMAL_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                               A_Animal Class                                  //
// ************************************************************************** //

class A_Animal
{

public:
	A_Animal(void);
	A_Animal(std::string type);
	virtual ~A_Animal(void);
	A_Animal(const A_Animal &other);
	A_Animal &operator=(const A_Animal &rhs);

	std::string		getType(void) const;

	virtual void	makeSound(void) const = 0;
protected:
	std::string				_type;
};

#endif
