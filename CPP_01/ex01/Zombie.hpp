/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 12:04:33 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                               Zombie Class                                 //
// ************************************************************************** //

class Zombie
{

public:
	Zombie(void);
	Zombie(std::string	z_name);
	~Zombie(void);

	void	set_zombie_name(std::string name);
	void	announce(void);

private:
	std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
