/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:25:44 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/16 18:02:38 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array( void ) : data(NULL), n(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : n(n)
{
	if (n == 0)
		throw std::invalid_argument("Exception: Size must be greater that 0!");
	try
	{
		data = new T[n];
	}
	catch(std::bad_alloc& e)
	{
		this->data = NULL;
		std::cerr << e.what() << std::endl;
	}
}

template<typename T>
Array<T>::Array(const Array<T>& array) : n(array.n)
{
	try
	{
		data = new T[this->n];
		for (unsigned int i = 0; i < this->n; ++i)
			data[i] = array.data[i];
	}
	catch(const std::exception& e)
	{
		this->data = NULL;
		std::cerr << e.what() << std::endl;
	}
}

template<typename T>
Array<T>::~Array( void )
{
	if (data)
		delete[] data;
}

template<typename T>
Array<T>& Array<T>::operator = (const Array<T>& array)
{
	if (this != &array)
	{
		if (data)
			delete[] data;
		this->n = array.n;
		try
		{
			data = new T[this->n];
			for (unsigned int i = 0; i < this->n; ++i)
				data[i] = array.data[i];
		}
		catch(const std::exception& e)
		{
			this->data = NULL;
			std::cerr << e.what() << std::endl;
		}
	}
	return (*this);
}

template<typename T>
T&	Array<T>::operator [] (unsigned int index)
{
	if (index >= n)
		throw std::out_of_range("Exception: Index out of range");
	return (data[index]);
}

template<typename T>
T const &	Array<T>::operator [] (unsigned int index) const
{
	if (index >= n)
		throw std::out_of_range("Exception: Index out of range");
	return (data[index]);
}

template<typename T>
unsigned int	Array<T>::size( void ) const
{
	return (this->n);
}
