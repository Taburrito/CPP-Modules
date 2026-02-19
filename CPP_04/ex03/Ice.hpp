/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/18 17:05:08 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_H__
#define __ICE_H__

# include "AMateria.hpp"

// ************************************************************************** //
//                               Ice Class                                    //
// ************************************************************************** //

class Ice : public AMateria
{

public:
	Ice(void);
	~Ice(void);
	Ice(const Ice &other);
	Ice &operator=(const Ice &rhs);

	AMateria* clone(void) const;

private:

};

#endif
