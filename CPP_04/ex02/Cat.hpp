/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/18 15:25:11 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
#define __CAT_H__

# include "A_Animal.hpp"
# include "Brain.hpp"

// ************************************************************************** //
//                               Cat Class                                  //
// ************************************************************************** //

class Cat : public A_Animal
{

public:
	Cat(void);
	~Cat(void);
	Cat(const Cat &other);
	Cat &operator=(const Cat &rhs);

	void	makeSound(void) const;

private:
	Brain*	_brain;
};

#endif
