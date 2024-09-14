/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:25:31 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/14 15:42:16 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
typename T::const_iterator	easyfind(T const & container, int const & val)
{
	typename T::const_iterator begin = container.begin();
	typename T::const_iterator end = container.end();
	typename T::const_iterator result = std::find(begin, end, val);

	if (result == end)
		throw std::runtime_error("Exception: The value not found in the container!");

	std::cout << "The value is found." << std::endl;
	return (result);
}
