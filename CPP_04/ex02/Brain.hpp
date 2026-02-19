/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/17 16:31:51 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_H__
#define __BRAIN_H__

# include <iostream>
# include <string>

// ************************************************************************** //
//                               Brain Class                                  //
// ************************************************************************** //

class Brain
{
public:
	Brain(void);
	virtual ~Brain(void);
	Brain(const Brain &other);
	Brain &operator=(const Brain &rhs);

	std::string	getIdea(int i);
	void		setIdea(int i, std::string idea);

	void	printIdeas(void);
private:
	std::string	_ideas[100];
};

#endif
