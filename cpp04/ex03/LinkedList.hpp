/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:22:17 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/04 15:46:16 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP

# include <iostream>

struct Node
{
	void		*data;
	struct Node	*next;
};

class LinkedList
{
	private:
		Node			*head;
		unsigned int	size;
		Node			*newNode( void *data );

	public:
		LinkedList( void );
		~LinkedList( void );
		void			addBack( void *data );
		unsigned int	getSize( void );
		Node			*getHead( void );
		void			removeNode( void *data );
		bool			checkIfExist( void *data );
};

extern LinkedList floor;

#endif