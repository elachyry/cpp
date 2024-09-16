/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:28:34 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/15 22:22:12 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <exception>
# include <stack>

#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef T ValueType;

		class iterator
		{
			public:
				typedef typename MutantStack::ValueType ValueType;
				typedef ValueType* PointerType;
				typedef ValueType& ReferenceType;
				
			public:
				iterator( void ) : ptr(NULL) {}
				iterator( PointerType ptr ) : ptr(ptr) {}
				iterator( const iterator& other ) : ptr(other.ptr) {}
				~iterator( void ) {}
				iterator&	operator = ( const iterator& other )
				{
					if (this != &other)
					{
						delete this->ptr;
						this->ptr = other.ptr;
					}
					return (*this);
				}
				
				ReferenceType	operator * ( void ) const { return *ptr; }

				iterator&	operator++( void )
				{
					ptr--;
					return (*this);
				}

				iterator	operator ++ ( int )
				{
					iterator tmp = *this;
					--ptr;
					return (tmp);
				}

				iterator&	operator --( void )
				{
					ptr++;
					return (*this);
				}

				iterator	operator -- ( int )
				{
					iterator tmp = *this;
					++ptr;
					return (tmp);
				}

				bool	operator == ( const iterator& other ) const { return (ptr == other.ptr); }

				bool	operator != ( const iterator& other ) const { return ptr != other.ptr; }

			private:
				PointerType	ptr;
		};
	
	public:
		MutantStack( void );
		MutantStack( const MutantStack<T>& );
		~MutantStack( void );
		MutantStack<T>&	operator = ( const MutantStack<T>& );
		void pop( void );
		T const& top( void );
		
		iterator begin( void )
		{
			return iterator(&std::stack<T>::top());
		}
		
		iterator end( void )
		{
			return iterator(&std::stack<T>::top() - std::stack<T>::size());
		}
};

# include "MutantStack.tpp"

#endif