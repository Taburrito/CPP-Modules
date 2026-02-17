/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:49:35 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 14:20:38 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_H__
#define __HUMANA_H__

# include "Weapon.hpp"

// ************************************************************************** //
//                               HumanA Class                                 //
// ************************************************************************** //

class HumanA
{

public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);

	void	attack(void);

private:
	std::string	name;
	Weapon&		weapon;
};

#endif
