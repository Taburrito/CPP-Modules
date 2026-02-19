/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/18 15:28:45 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
#define __DOG_H__

# include "A_Animal.hpp"
# include "Brain.hpp"

// ************************************************************************** //
//                               Dog Class                                  //
// ************************************************************************** //

class Dog : public A_Animal
{

public:
	Dog(void);
	~Dog(void);
	Dog(const Dog &other);
	Dog &operator=(const Dog &rhs);

	void	makeSound(void) const;

private:
	Brain*	_brain;

};

#endif
