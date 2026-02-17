/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/17 12:36:49 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGWrongCAT_H__
#define __WRONGWrongCAT_H__

# include "WrongAnimal.hpp"

// ************************************************************************** //
//                               WrongCat Class                                  //
// ************************************************************************** //

class WrongCat : public WrongAnimal
{

public:
	WrongCat(void);
	~WrongCat(void);
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &rhs);

	void	makeSound(void) const;
private:

};

#endif
