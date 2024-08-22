/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:54:56 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/21 22:06:01 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "contact.class.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		int		getCurrentIndex(void);
		void	add(Contact contact);
		Contact	search(int index);
		
	private:
		int		currenIndex;
		Contact	contacts[8];
};

#endif