/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/18 17:06:58 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_H__
#define __CURE_H__

# include "AMateria.hpp"

// ************************************************************************** //
//                               Cure Class                                    //
// ************************************************************************** //

class Cure : public AMateria
{

public:
	Cure(void);
	~Cure(void);
	Cure(const Cure &other);
	Cure &operator=(const Cure &rhs);

	AMateria* clone(void) const;

private:

};

#endif
