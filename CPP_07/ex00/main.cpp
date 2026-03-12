/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/12 13:51:01 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include "Colors.hpp"

class Awesome
{
	public:
		Awesome(void) : _n(0) {}
		Awesome(int n) : _n(n) {}
		Awesome& operator= (Awesome & a) { _n = a._n; return *this; }
		bool operator==(Awesome const & rhs) const { return (this->_n == rhs._n); }
		bool operator!=(Awesome const & rhs) const { return (this->_n != rhs._n); }
		bool operator>(Awesome const & rhs) const { return (this->_n > rhs._n); }
		bool operator<(Awesome const & rhs) const { return (this->_n < rhs._n); }
		bool operator>=(Awesome const & rhs) const { return (this->_n >= rhs._n); }
		bool operator<=(Awesome const & rhs) const { return (this->_n <= rhs._n); }
		int get_n() const { return _n; }
	private:
		int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o;}

int	main(void)
{
	std::cout << BOLDYELLOW << "--- TESTS DU SUJET ---" << RESET << std::endl;
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl << BOLDBLUE << " TEST AVEC LITTERAUX ET CLASS ---" << RESET << std::endl;
	std::cout << "min(42,21) = " << ::min(42, 21) << std::endl;
	std::cout << "max(42,41) = " << ::max(42,21) << std::endl;
	Awesome aw1(42);
	Awesome aw2(21);
	std::cout << "before swap: aw1 = " << aw1 << ", aw2 = " << aw2 << std::endl;
	::swap(aw1, aw2);
	std::cout << "after swap: aw1 = " << aw1 << ", aw2 = " << aw2 << std::endl;
	std::cout << "min (aw1, aw2) = " << ::min(aw1, aw2) << std::endl;
	std::cout << "max (aw1, aw2) = " << ::max(aw1, aw2) << std::endl;

	return 0;
}
