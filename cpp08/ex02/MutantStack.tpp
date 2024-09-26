/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:03:23 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/19 18:19:07 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
MutantStack<T>::MutantStack( void ) : std::stack<T>() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& mutantStack) : std::stack<T>(mutantStack) {}


template<typename T>
MutantStack<T>::~MutantStack( void ) {}

template<typename T>
MutantStack<T>&	MutantStack<T>::operator = (const MutantStack<T>& mutantStack)
{
	if (this != &mutantStack)
	{
		std::stack<T>::operator=(mutantStack);
	}
	return (*this);
}

template<typename T>
void	MutantStack<T>::pop( void )
{
	if (!std::stack<T>::size())
		throw std::out_of_range("Exception: You cannot call pop on an empty stack!");
	std::stack<T>::pop();
}

template<typename T>
T const&	MutantStack<T>::top( void )
{
	if (!std::stack<T>::size())
		throw std::out_of_range("Exception: You cannot call top on an empty stack!");
	return (std::stack<T>::top());
}


