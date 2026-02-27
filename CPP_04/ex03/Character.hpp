/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/18 15:05:44 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

# include "ICharacter.hpp"

// ************************************************************************** //
//                           Character Class                                 //
// ************************************************************************** //

class Character : public ICharacter
{

public:
	Character(void);
	Character(std::string name);
	Character(const Character &src);
	Character &operator=(const Character &rhs);
	~Character(void) {};
	std::string const & getName(void) const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, Character& target);
private:
	AMateria*	_inventory[4];
	int			_index;
	std::string	_name;
	struct		_floor {
		AMateria*	materia;
		_floor*		next;
	};
	_floor*		_floornode;
};

#endif
