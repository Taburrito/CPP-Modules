/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/18 15:50:07 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Colors.hpp"

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		BitcoinExchange empty;
		empty.ShowExchangeResult();
	}
	else
	{
		BitcoinExchange test(argv[1]);
		test.ShowExchangeResult();
	}
	return 0;
}
