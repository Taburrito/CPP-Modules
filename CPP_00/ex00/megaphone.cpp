/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:53:16 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/13 16:17:42 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int i = 1;
	int y = 0;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < argc)
		{
			while (argv[i][y])
			{
				std::cout << static_cast<char>(toupper(argv[i][y]));
				y++;
			}
			y = 0;
			i++;
		}
		std::cout << std::endl;
	}
}
