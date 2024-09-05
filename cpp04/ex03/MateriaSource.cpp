/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:20:42 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/04 16:28:08 by melachyr         ###   ########.fr       */
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
		delete this->materias[i];
}

MateriaSource&	MateriaSource::operator = (const MateriaSource& materiaSource)
{
	//std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if (this != &materiaSource)
	{
		this->~MateriaSource();
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
			// std::cout << "type1 " << m->getType() << std::endl;
			AMateria* tmp;
			tmp = m->clone();
			floor.removeNode(tmp);
			this->materias[i] = tmp;
			break ;
		}
	}
	// int i = 0;
	// while (this->materias[i])
	// {
	// 	std::cout << "type2 " << this->materias[i]->getType() << std::endl;
	// 	i++;	
	// }
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	if (type == "cure" || type == "ice")
	{
		for (int i = 0; i < 4; i++)
		{
			// std::cout << "type " << materias[i]->getType() << std::endl;
			if (materias[i] && materias[i]->getType() == type)
			{
				// std::cout << "hello " << std::endl;
				return (materias[i]->clone());
			}
			// if (materias[i] && materias[i]->getType() == "ice" && type == "ice")
			// {
			// 	// std::cout << "hello Ice " << std::endl;
			// 	return (new Ice());
			// }
		}
	}
	return (0);
}
