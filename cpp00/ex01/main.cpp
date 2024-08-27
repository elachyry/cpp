/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:34:15 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 15:16:57 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iomanip>
#include <cstdlib> 

bool	searchForContact(PhoneBook &phoneBook)
{
	std::string input;
	std::cout << "#####################################################" << std::endl;
	std::cout << "# " << std::setw(10) << "Index" 
				<< " | " << std::setw(10) << "First Name" 
				<< " | " << std::setw(10) << "Last Name" 
				<< " | " << std::setw(10) << "Nick Name" 
				<< " #" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		Contact contact = phoneBook.search(i);
		std::string firstName = contact.getFirstName().size() > 10 
						? contact.getFirstName().substr(0, 9) + "." : contact.getFirstName();
		std::string lastName = contact.getLastName().size() > 10 
						? contact.getLastName().substr(0, 9) + "." : contact.getLastName();
		std::string nickName = contact.getNickName().size() > 10 
						? contact.getNickName().substr(0, 9) + "." : contact.getNickName();
		if (firstName.empty())
			continue ;
		std::cout << "# " << std::setw(10) << i + 1
				<< " | " << std::setw(10) << firstName
				<< " | " << std::setw(10) << lastName
				<< " | " << std::setw(10) << nickName
				<< " #" << std::endl;
	}
	std::cout << "#####################################################" << std::endl;
	std::cout << "Please enter contact index: ";
	std::getline(std::cin, input);
	int index = std::atoi(input.c_str());
	if (index <= 0)
	{
		std::cout << "Invalid index!" << std::endl;
		return (true);
	}
	else
	{
		Contact contact = phoneBook.search(index - 1);
		if (contact.getFirstName().empty())
		{
			std::cout << "No contact found with this index!" << std::endl;
			return (true);
		}
		std::cout << "#####################################################" << std::endl;
		std::cout << "# First Name: " << contact.getFirstName() << std::endl;
		std::cout << "# Last Name: " << contact.getLastName() << std::endl;
		std::cout << "# Nick Name: " << contact.getNickName() << std::endl;
		std::cout << "# Phone Number: " << contact.getPhoneNumber() << std::endl;
		std::cout << "# Darkest Secret: " << contact.getDarkestSecret() << std::endl;
		std::cout << "#####################################################" << std::endl;
	}
	return (false);
}
void	addNewContact(PhoneBook &phoneBook)
{
	std::string input;
	Contact     contact;

	std::cout << "##################################################" << std::endl;
	std::cout << "# Please enter contact informations:             #" << std::endl;
	std::cout << "# First Name: ";
	std::getline(std::cin, input);
	contact.setFirstName(input);
	std::cout << "# Last Name: ";
	std::getline(std::cin, input);
	contact.setLastName(input);
	std::cout << "# Nick Name: ";
	std::getline(std::cin, input);
	contact.setNickName(input);
	std::cout << "# Phone Number: ";
	std::getline(std::cin, input);
	contact.setPhoneNumber(input);
	std::cout << "# Darkest Secret: ";
	std::getline(std::cin, input);
	contact.setDarkestSecret(input);
	if (contact.getFirstName().empty() || contact.getLastName().empty()
		|| contact.getNickName().empty() || contact.getPhoneNumber().empty()
		|| contact.getDarkestSecret().empty())
	{
		std::cout << "######## Contatct can't have empty fields ########" << std::endl
			<< std::endl;
	}
	else
	{    
		phoneBook.add(contact);
		std::cout << "######## Your contatct added successfully ########" << std::endl
				<< std::endl;
	}
}

bool	showMenu(std::string &input)
{
	std::cout << "##################################################" << std::endl;
	std::cout << "# 1 - ADD a contact.                             #" << std::endl;
	std::cout << "# 2 - SEARCH for a contact.                      #" << std::endl;
	std::cout << "# 3 - Exit from the program.                     #" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "Please select an option: ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << "Exiting..." << std::endl;
		return (true);
	}
	std::cout << std::endl;
	return (false);
}

int	main()
{
	PhoneBook phoneBook;
	while (1)
	{
		std::string input;
		Contact contact;
		if (showMenu(input))
			break ;
		if (input == "1")
			addNewContact(phoneBook);
		else if (input == "2")
		{
			if (searchForContact(phoneBook))
				continue ;
		}
		else if (input == "3")
			break ;
		else
		{
			std::cout << "Wrong option" << std::endl;
			continue ;
		}
	}
	return (0);
}
