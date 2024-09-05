/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:24:56 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/06 00:10:44 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LinkedList.hpp"

LinkedList floor;

LinkedList::LinkedList( void )
{
	this->head = NULL;
	this->size = 0;
}

LinkedList::~LinkedList( void )
{
	Node *ntmp;
	while (head)
	{
		std::cout << "data = " << head->data << std::endl;
		::operator delete(head->data);
		ntmp = head;
		head = head->next;
		delete ntmp;
	}
}

unsigned int	LinkedList::getSize( void )
{
	return (this->size);
}

Node	*LinkedList::getHead( void )
{
	return (this->head);
}

void	LinkedList::addBack(void *data)
{
	Node *node = newNode(data);
	if (this->head)
	{
		Node *tmp = this->head;
		while (this->head->next)
			this->head = this->head->next;
		this->head->next = node;
		this->head = tmp;
		return ;
	}
	this->head = node;
}

void	LinkedList::removeNode(void *data)
{
	if (!head)
		return;

	Node *current = head;
	Node *previous = NULL;

	if (current->data == data)
	{
		head = current->next;
		delete current;
		size--;
		return;
	}
	while (current && current->data != data)
	{
		previous = current;
		current = current->next;
	}
	if (!current)
		return;
	previous->next = current->next;
	delete current;
	size--;
}

bool	LinkedList::checkIfExist( void *data )
{
	Node	*tmp = this->head;
	while (tmp)
	{
		if (tmp->data == data)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

Node	*LinkedList::newNode(void *data)
{
	Node	*node = new Node;
	node->data = data;
	node->next = NULL;
	return (node);
}
