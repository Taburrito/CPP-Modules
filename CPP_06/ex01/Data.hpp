/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/03/11 15:34:39 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DATA_H__
#define __DATA_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                          Data Class                                  //
// ************************************************************************** //

class Data
{
public:
	Data(void);
	Data(std::string name, int id);
	Data(const Data &other);
	~Data(void);
	Data &operator=(const Data &rhs);

	std::string		getName(void) const;
	int				getId(void) const;
private:
	std::string		_name;
	int				_id;
};

std::ostream &operator<<(std::ostream &o, const Data &i);

#endif
