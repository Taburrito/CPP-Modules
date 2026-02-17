/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:32:22 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/09 15:30:26 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	print_res(std::string type, Point p, bool result, bool expected)
{
	std::cout << type << " Point (" << p.getPointX().toFloat() << ", " << p.getPointY().toFloat() << ") : ";
	if (result == expected)
		std::cout << "\033[1;32m[OK]\033[0m";
	else
		std::cout << "\033[1;31m[KO]\033[0m";
	std::cout	<< "	-> Resultat: " << (result ? "TRUE" : "FALSE")
				<< " (Attendu: " << (expected ? "TRUE" : "FALSE") << ")"
				<< std::endl;
}

int main(void) {
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Triangle defini par : A(0,0), B(10,0), C(0,10)" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;

	Point p_in(2.0f, 2.0f);
	print_res("DEDANS		", p_in, bsp(a, b, c, p_in), true);

	Point p_out(20.0f, 20.0f);
	print_res("DEHORS		", p_out, bsp(a, b, c, p_out), false);

	Point p_edge(5.0f, 0.0f);
	print_res("SUR BORD	", p_edge, bsp(a, b, c, p_edge), false);

	Point p_diag(5.0f, 5.0f);
	print_res("DIAGONALE	", p_diag, bsp(a, b, c, p_diag), false);

	Point p_vertex(0.0f, 0.0f);
	print_res("SOMMET		", p_vertex, bsp(a, b, c, p_vertex), false);

	Point p_near_out(5.1f, 5.0f);
	print_res("JUST OUT	", p_near_out, bsp(a, b, c, p_near_out), false);

	Point p_near_in(4.9f, 5.0f);
	print_res("JUSTE IN	", p_near_in, bsp(a, b, c, p_near_in), true);

	std::cout << "----------------------------------------------" << std::endl;
	return 0;
}
