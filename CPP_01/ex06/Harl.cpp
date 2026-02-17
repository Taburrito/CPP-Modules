/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:52:21 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/29 15:13:35 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
		if (level.compare(_level_tab[i]) == 0)
			(this->*_function_tab[i])();

	return;
}

// ************************************************************************** //
//                           Constructor&Destructor                           //
// ************************************************************************** //

Harl::Harl(void)
{
	_function_tab[0] = &Harl::debug;
	_function_tab[1] = &Harl::info;
	_function_tab[2] = &Harl::warning;
	_function_tab[3] = &Harl::error;

	_level_tab[0] = "DEBUG";
	_level_tab[1] = "INFO";
	_level_tab[2] = "WARNING";
	_level_tab[3] = "ERROR";

	return;
}

Harl::~Harl(void)
{
	return;
}
