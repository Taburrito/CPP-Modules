/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 11:50:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream	&operator<<(std::ostream &o, const Fixed &i)
{
	o << i.toFloat();
	return (o);
}

float	Fixed::toFloat(void) const
{
	return((float)RawBits / (1 << fractional_bits));
}

int		Fixed::toInt(void) const
{
	return(RawBits >> fractional_bits);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

Fixed::Fixed(void) : RawBits(0)
{
	// std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const int init) : RawBits(init << fractional_bits)
{
	// std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(const float init) : RawBits(roundf(init * (1 << fractional_bits)))
{
	// std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->RawBits = rhs.getRawBits();
	return (*this);
}

int Fixed::operator<(const Fixed &rhs) const
{
	return (RawBits < rhs.getRawBits());
}

int Fixed::operator>(const Fixed &rhs) const
{
	return (RawBits > rhs.getRawBits());
}

int Fixed::operator<=(const Fixed &rhs) const
{
	return (RawBits <= rhs.getRawBits());
}

int Fixed::operator>=(const Fixed &rhs) const
{
	return (RawBits >= rhs.getRawBits());
}

int Fixed::operator==(const Fixed &rhs) const
{
	return (RawBits == rhs.getRawBits());
}

int Fixed::operator!=(const Fixed &rhs) const
{
	return (RawBits != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed	result;
	result.setRawBits((this->getRawBits() * rhs.getRawBits()) >> fractional_bits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed	result;
	result.setRawBits((this->getRawBits() << fractional_bits) / rhs.getRawBits());
	return (result);
}

Fixed& Fixed::operator++(void)
{
	RawBits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	RawBits++;
	return (temp);
}

Fixed& Fixed::operator--(void)
{
	RawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	RawBits--;
	return (temp);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //

int		Fixed::getRawBits(void) const
{
	return (this->RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->RawBits = raw;
}
