/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:20:52 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/04 16:23:50 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"
#include "LinkedList.hpp"

Character::Character( void )
{
	//std::cout << "Character Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}

Character::Character(std::string name)
{
	//std::cout << "Character Parameterized constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}

Character::Character(const Character& character)
{
	//std::cout << "Character Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
	*this = character;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (slots[i])
			delete this->slots[i];
	//std::cout << "Character Destructor called" << std::endl;
}

Character&	Character::operator = (const Character& character)
{
	//std::cout << "Character Copy assignment operator called" << std::endl;
	if (this != &character)
	{
		
		this->~Character();
		this->name = character.name; // deep copy
		for (int i = 0; i < 4; i++)
		{
			if (character.slots[i])
			{
				this->slots[i] = character.slots[i]->clone();
				floor.removeNode(slots[i]);
			}
			else
				slots[i] = NULL;
		}
	}
	return (*this);
}

std::string const &	Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	//check if exits it the floor !!!!!!!!
	if (!floor.checkIfExist(m))
		return ;
	// std::cout << "type3 " << m->getType() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i] == NULL)
		{
			this->slots[i] = m;
			floor.removeNode(m);
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx > 0 && idx < 4)
	{
		std::cout << "test : " << std::endl;
		floor.addBack(this->slots[idx]);//return it to the floor
		this->slots[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	// int i = 0;
	// while (this->slots[i])
	// {
	// 	std::cout << "type2 " << this->slots[i]->getType() << std::endl;
	// 	i++;	
	// }
	
	if (idx >= 0 && idx < 4 && this->slots[idx])
		this->slots[idx]->use(target);
}
