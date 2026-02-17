/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/17 12:34:56 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                               WrongAnimal Class                            //
// ************************************************************************** //

class WrongAnimal
{

public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	virtual ~WrongAnimal(void);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &rhs);

	std::string		getType(void) const;

	void	makeSound(void) const;
protected:
	std::string				_type;
};

#endif
