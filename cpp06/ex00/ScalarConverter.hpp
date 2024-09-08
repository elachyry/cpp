/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:29:52 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/08 01:35:44 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib> 
# include <sstream>
# include <iomanip>
# include <limits>

enum	DataType
{
	TCHAR,
	TINT,
	TFLOAT,
	TDOUBLE,
	NONNUMERIC,
	NONPRINTABLE,
	OVERFLOW,
	NAN,
	INF
};

class ScalarConverter
{
	public:
		static char		charVal;
		static int		intVal;
		static float	floatVal;
		static double	doubleVal;
		static bool		isPrintable;
		static bool		check;
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& );
		~ScalarConverter( void );
		ScalarConverter&	operator = ( const ScalarConverter& );
		static void			convert( const char* );
		static DataType		detectInputType( const char* );
		static void			castFromChar( char );
		static void			castFromInt( int );
		static void			castFromFloat( float );
		static void			castFromDouble( double );
		static void			handlNonPrintable( int );
		static void			handlNonNumeric( double );
		static void			printValues( DataType );
};



#endif