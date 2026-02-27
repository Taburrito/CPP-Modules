/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/18 15:05:44 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_H__
#define __AMATERIA_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                               AMateria Class                                  //
// ************************************************************************** //

class ICharacter;

class AMateria
{

public:
	AMateria(void);
	AMateria(std::string const & type);
	virtual ~AMateria(void);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &rhs);

	std::string const &		getType(void) const;

	virtual AMateria* clone(void) const = 0;
	virtual void use(ICharacter& target);
protected:
	std::string				_type;
};

#endif
