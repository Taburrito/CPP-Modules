/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 12:45:34 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	slim_shady = "HI THIS IS BRAIN";
	std::string	*stringPTR = &slim_shady;
	std::string	&stringREF = slim_shady;

	std::cout << "adress of Slim Shady: " << &slim_shady << std::endl;
	std::cout << "adress of his stalker living in his shed: " << &stringPTR << std::endl;
	std::cout << "adress of Eminem: " << &stringREF << std::endl;

	std::cout << "Slim Shady says: \"" << slim_shady << "\"" << std::endl;
	std::cout << "His stalker looks at him saying: \"" << *stringPTR << "\"" << std::endl;
	std::cout << "Eminem says: \"" << stringREF << "\"" << std::endl;
	return (0);
}
