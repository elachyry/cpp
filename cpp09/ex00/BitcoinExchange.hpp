/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:20:53 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/18 21:29:26 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cctype>
# include <map>

class	BitcoinExchange
{
	private:
		std::string						inputFile;
		std::multimap<std::string, float>	database;
		void	loadDatabase( void );

	public:
		BitcoinExchange( void );
		BitcoinExchange( std::string& );
		BitcoinExchange( const BitcoinExchange& );
		~BitcoinExchange( void );
		BitcoinExchange&	operator = ( const BitcoinExchange& );
		void				display( void );
};

#endif