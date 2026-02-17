/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/03 16:49:13 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                               Fixed Class                                  //
// ************************************************************************** //

class Fixed
{

public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					RawBits;
	static const int	fractional_bits = 8;
};

#endif
