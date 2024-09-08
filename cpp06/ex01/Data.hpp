/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:23:50 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/08 21:54:07 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class	Data
{
	private:
		std::string	name;
		int			age;
		char		gender;
		double		bankAccount;

	public:
		Data( void );
		Data( std::string, int, char, double );
		Data( const Data& );
		~Data( void );
		Data&		operator = ( const Data& );
		std::string	getName( void );
		int			getAge( void );
		char		getGender( void );
		double		getAccountBalance( void );
};

#endif