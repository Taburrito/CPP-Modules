/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/12 14:22:00 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
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
	std::cout << BOLDYELLOW << "--- TEST INT ---" << RESET << std::endl;
	int i[] = {2, 42, 67, 69};
	::iter(i, 4, ::print_elem<int>);

	std::cout << BOLDYELLOW << "--- TEST DOUBLE ---" << RESET << std::endl;
	double d[] = {42.42, 67.67, 0.0};
	::iter(d, 3, ::print_elem<double>);

	std::cout << BOLDYELLOW << "--- TEST STRING ---" << RESET << std::endl;
	std::string s[] = {"Uno", "Dos", "Tres"};
	::iter(s, 3, ::print_elem<std::string>);

	std::cout << BOLDYELLOW << "--- TEST CLASS ---" << RESET << std::endl;
	Awesome a[] = {1, 2, 3};
	::iter(a, 3, ::print_elem<Awesome>);

	return 0;
}
