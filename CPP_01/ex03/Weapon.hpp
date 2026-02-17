/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:52:51 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 14:25:32 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H__
#define __WEAPON_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                               Weapon Class                                 //
// ************************************************************************** //

class Weapon
{

public:
	Weapon(std::string weapon_type);
	~Weapon(void);

	const std::string&	getType(void) const;
	void	setType(std::string);

private:
	std::string	type;
};

#endif
