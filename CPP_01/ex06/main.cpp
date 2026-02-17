/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/29 15:14:34 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Usage: ./harlfilter \"level or statement\"" << std::endl, 1);

	Harl		Karen;
	std::string	level_tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			switch_case = -1;

	for (int i = 0; i < 4; i++)
		if (level_tab[i].compare(argv[1]) == 0)
			switch_case = i;

	switch (switch_case)
	{
		case 0:
			Karen.complain("DEBUG");
			switch_case++;
		case 1:
			Karen.complain("INFO");
			switch_case++;
		case 2:
			Karen.complain("WARNING");
			switch_case++;
		case 3:
			Karen.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}

	return 0;
}
