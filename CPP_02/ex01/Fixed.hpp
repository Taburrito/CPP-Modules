/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/05 14:31:35 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

# include <iostream>
# include <string>
# include <cmath>

// ************************************************************************** //
//                               Fixed Class                                  //
// ************************************************************************** //

class Fixed
{

public:
	Fixed(void);
	Fixed(const int init);
	Fixed(const float init);
	~Fixed(void);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					RawBits;
	static const int	fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &i);

#endif
