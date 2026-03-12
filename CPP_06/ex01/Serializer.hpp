/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/11 15:58:48 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

# include <iostream>
# include <string>
# include <cstdlib>
# include <stdint.h>
# include "Data.hpp"

// ************************************************************************** //
//                          Serializer Class                                  //
// ************************************************************************** //

class Serializer
{

public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);


private:
	Serializer(void);
	Serializer(const Serializer &other);
	~Serializer(void);
	Serializer &operator=(const Serializer &rhs);
};


#endif
