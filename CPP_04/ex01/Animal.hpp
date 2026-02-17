/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/17 12:30:47 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_H__
#define __ANIMAL_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                               Animal Class                                  //
// ************************************************************************** //

class Animal
{

public:
	Animal(void);
	Animal(std::string type);
	virtual ~Animal(void);
	Animal(const Animal &other);
	Animal &operator=(const Animal &rhs);

	std::string		getType(void) const;
	
	virtual void	makeSound(void) const;
protected:
	std::string				_type;
};

#endif
