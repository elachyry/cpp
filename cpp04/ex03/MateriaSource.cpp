/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:20:42 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/05 17:23:54 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"


MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
	//std::cout << "MateriaSource Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
	//std::cout << "MateriaSource Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
	*this = materiaSource;
}

MateriaSource::~MateriaSource()
{
	//std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (materias[i]) 
		{
			delete materias[i];
			materias[i] = NULL;
		}
	}
}

MateriaSource&	MateriaSource::operator = (const MateriaSource& materiaSource)
{
	//std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if (this != &materiaSource)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materias[i]) 
			{
				delete materias[i];
				materias[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (materiaSource.materias[i])
				this->materias[i] = materiaSource.materias[i]->clone();
			else
				this->materias[i] = NULL;
		}
		
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] == NULL)
		{
			AMateria* tmp;
			tmp = m->clone();
			floor.removeNode(tmp);
			this->materias[i] = tmp;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	if (type == "cure" || type == "ice")
	{
		for (int i = 0; i < 4; i++)
		{
			if (materias[i] && materias[i]->getType() == type)
				return (materias[i]->clone());
		}
	}
	return (0);
}
