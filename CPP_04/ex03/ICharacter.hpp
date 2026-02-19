/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/18 15:05:44 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICHARACTER_H__
#define __ICHARACTER_H__

# include "AMateria.hpp"

// ************************************************************************** //
//                           ICharacter Class                                 //
// ************************************************************************** //

class ICharacter
{

public:
	ICharacter(void);
	ICharacter(std::string name);
	ICharacter(const ICharacter &src);
	ICharacter &operator=(const ICharacter &rhs);
	virtual ~ICharacter(void) {};
	virtual std::string const & getName(void) const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
protected:
	AMateria*	_inventory[4];
	int			_index;
	std::string	_name;
	AMateria*	_floor[50];
	int			_floor_index;
};

#endif
