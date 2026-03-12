/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/11 16:04:03 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Colors.hpp"


int	main(void)
{
	Data* data_ptr = new Data("Gauthier", 69);
	std::cout << "Before serialization: " << data_ptr << ", " << *data_ptr << std::endl;
	data_ptr = Serializer::deserialize(Serializer::serialize(data_ptr));
	std::cout << "After serialization: " << data_ptr << ", " << *data_ptr << std::endl;
	delete data_ptr;
	return 0;
}
