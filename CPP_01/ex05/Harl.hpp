/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:52:51 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/29 14:43:41 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_H__
#define __HARL_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                               Weapon Class                                 //
// ************************************************************************** //

class Harl
{

public:
	Harl(void);
	~Harl(void);

	void					complain(std::string level);

private:
	typedef void			(Harl::*Harl_function_pointer)(void);

	Harl_function_pointer	_function_tab[4];
	std::string				_level_tab[4];

	void					debug(void);
	void					info(void);
	void					warning(void);
	void					error(void);
};

#endif
