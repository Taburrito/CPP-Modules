/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:49:35 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 14:22:15 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_H__
#define __HUMANB_H__

# include "Weapon.hpp"

// ************************************************************************** //
//                               HumanB Class                                 //
// ************************************************************************** //

class HumanB
{

public:
	HumanB(std::string name);
	~HumanB(void);

	void	attack(void);
	void	setWeapon(Weapon& weapon);

private:
	std::string	name;
	Weapon		*weapon;
};

#endif
