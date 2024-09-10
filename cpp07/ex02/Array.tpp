/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:25:44 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/10 18:42:50 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array( void ) : data(NULL), n(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : n(n)
{
	if (n == 0)
		throw std::invalid_argument("Exception: Size must be positive");
	try
	{
		data = new T[n];
	}
	catch(std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

template<typename T>
Array<T>::Array(const Array<T>& array) : n(array.n)
{
	data = new T[n];
	for (unsigned int i = 0; i < n; ++i)
		data[i] = array.data[i];
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
		delete[] data;
		n = array.n;
		data = new T[n];
		for (unsigned int i = 0; i < n; ++i)
			data[i] = array.data[i];
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
unsigned int	Array<T>::size( void )
{
	return (this->n);
}
