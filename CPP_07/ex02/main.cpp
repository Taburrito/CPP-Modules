/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/13 12:12:20 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
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
	std::cout << BOLDBLUE << "--- TEST CREATION TABLEAU INT - EXEPTION ---" << RESET << std::endl;
	Array<int> tab(10);
	try
	{
		tab[42] = 10;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << BOLDYELLOW << "-- TEST DE DEEP COPY ---" << RESET << std::endl;
	for (unsigned int i = 0; i < tab.size(); i++)
		tab[i] = i*10;
	std::cout << "Tab: ";
	for (unsigned int i = 0; i < tab.size(); i++)
		std::cout << tab[i] << ", ";
	std::cout << std::endl;

	Array<int> copy_constructor(tab);
	Array<int> copy_assign;
	copy_assign = tab;

	copy_constructor[0] = 42;
	copy_assign[0] = 67;

	std::cout << "Tab apres modif copies: ";
	for (unsigned int i = 0; i < tab.size(); i++)
		std::cout << tab[i] << ", ";
	std::cout << std::endl;
	std::cout << "Tab copie constructeur: ";
	for (unsigned int i = 0; i < copy_constructor.size(); i++)
		std::cout << copy_constructor[i] << ", ";
	std::cout << std::endl;
	std::cout << "Tab copie assignation: ";
	for (unsigned int i = 0; i < copy_assign.size(); i++)
		std::cout << copy_assign[i] << ", ";
	std::cout << std::endl;

	std::cout << BOLDMAGENTA << "--- TEST TAB CLASS ---" << RESET << std::endl;
	Array<Awesome> ct(2);
	std::cout << "tab awesome (default): " << ct[0] << ", " << ct[1] << std::endl;
	return 0;
}
