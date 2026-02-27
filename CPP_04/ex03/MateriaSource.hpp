/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/18 15:05:44 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_H__
#define __MATERIASOURCE_H__

# include "IMateriaSource.hpp"

// ************************************************************************** //
//                               MateriaSource Class                                  //
// ************************************************************************** //

class MateriaSource : public IMateriaSource
{

public:
	MateriaSource(void);
	virtual ~MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &rhs);

	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);

private:
	AMateria*	_materia;
	AMateria*	_inventory[4];
	int			_index;
};


#endif
