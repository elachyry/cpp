/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:39:12 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/09 02:11:49 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_HPP
# define OPERATIONS_HPP

# include <iostream>

template<typename T>
void	swap( T&, T& );

template<typename T>
T const &	min( T const &, T const & );

template<typename T>
T const &	max( T const &, T const & );

#endif