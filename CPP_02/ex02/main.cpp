/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/19 15:20:03 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed aa(10);
	Fixed bb(20);
	Fixed c(42.42f);
	Fixed d(b);

	std::cout << std::endl;
	std::cout << "Comparaisons:" << std::endl;
	std::cout << "10 < 20 : " << (aa < bb) << std::endl;
	std::cout << "10 > 20 : " << (aa > bb) << std::endl;
	std::cout << "10 <= 10 : " << (aa <= aa) << std::endl;
	std::cout << "10 >= 10 : " << (aa >= aa) << std::endl;
	std::cout << "10 == 20 : " << (aa == bb) << std::endl;
	std::cout << "10 != 20 : " << (aa != bb) << std::endl;

	std::cout << std::endl << "Operations" << std::endl;
	Fixed res;

	res = bb + aa;
	std::cout << "20 + 10 = " << res << std::endl;

	res = bb - aa;
	std::cout << "20 - 10 = " << res << std::endl;

	res = Fixed(2) * Fixed(2);
	std::cout << "2 * 2 = " << res << std::endl;

	res = Fixed(10) / Fixed(2);
	std::cout << "10 / 2 = " << res << std::endl;

	res = c * Fixed(2);
	std::cout << "42.42 * 2 = " << res << std::endl;

	std::cout << std::endl << "Min/Max:" << std::endl;
	std::cout << "Min(10, 20) : " << Fixed::min(aa, bb) << std::endl;
	std::cout << "Max(10, 20) : " << Fixed::max(aa, bb) << std::endl;

	const Fixed ca(5.5f);
	const Fixed cb(2.2f);
	std::cout << "Const Min(5.5, 2.2) : " << Fixed::min(ca, cb) << std::endl;
	std::cout << "Const Max(5.5, 2.2) : " << Fixed::max(ca, cb) << std::endl;

	return 0;
}
