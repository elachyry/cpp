/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:20:52 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/05 17:24:05 by melachyr         ###   ########.fr       */
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
	//std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (slots[i]) 
		{
			delete slots[i];
			slots[i] = NULL;
		}
	}
}
Character& Character::operator=(const Character& character)
{
    // std::cout << "Character Copy assignment operator called" << std::endl;
    if (this != &character)
    {
		for (int i = 0; i < 4; i++)
		{
			if (slots[i]) 
			{
				delete slots[i];
				slots[i] = NULL;
			}
		}
		this->name = character.name;
		for (int i = 0; i < 4; i++)
		{
			if (character.slots[i])
			{
				this->slots[i] = character.slots[i]->clone();
				floor.removeNode(slots[i]);
			}
			else
			{
				slots[i] = NULL;
			}
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
	if (!floor.checkIfExist(m))
		return ;
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
		floor.addBack(this->slots[idx]);
		this->slots[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->slots[idx])
		this->slots[idx]->use(target);
}
