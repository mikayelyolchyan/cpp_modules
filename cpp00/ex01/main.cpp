#include "PhoneBook.hpp"
#include <iostream>
#include <string>

static std::string	ft_get_input(const std::string &prompt)
{
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);
	return (input);
}

static int	ft_stoi(const std::string &str)
{
	int result = 0;
	int i = 0;

	if (str[0] == '-' || str[0] == '+')
		i = 1;
	while (i < (int)str.length())
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		result = -result;
	return (result);
}

static void	ft_add_contact(PhoneBook &phoneBook)
{
	Contact contact;
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	firstName = ft_get_input("Enter first name: ");
	if (firstName.empty())
	{
		std::cout << "Error: first name cannot be empty." << std::endl;
		return ;
	}

	lastName = ft_get_input("Enter last name: ");
	if (lastName.empty())
	{
		std::cout << "Error: last name cannot be empty." << std::endl;
		return ;
	}

	nickname = ft_get_input("Enter nickname: ");
	if (nickname.empty())
	{
		std::cout << "Error: nickname cannot be empty." << std::endl;
		return ;
	}

	phoneNumber = ft_get_input("Enter phone number: ");
	if (phoneNumber.empty())
	{
		std::cout << "Error: phone number cannot be empty." << std::endl;
		return ;
	}

	darkestSecret = ft_get_input("Enter darkest secret: ");
	if (darkestSecret.empty())
	{
		std::cout << "Error: darkest secret cannot be empty." << std::endl;
		return ;
	}

	contact.setFirstName(firstName);
	contact.setLastName(lastName);
	contact.setNickname(nickname);
	contact.setPhoneNumber(phoneNumber);
	contact.setDarkestSecret(darkestSecret);

	phoneBook.addContact(contact);
	std::cout << "Contact added successfully!" << std::endl;
}

static void	ft_search_contact(PhoneBook &phoneBook)
{
	if (phoneBook.getContactCount() == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}

	phoneBook.displayContacts();

	std::string input = ft_get_input("Enter index: ");
	int index = ft_stoi(input);
	
	if (index == -1 || !phoneBook.isValidIndex(index))
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}

	Contact contact = phoneBook.getContact(index);
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		command = ft_get_input("Enter command (ADD, SEARCH, EXIT): ");
		
		if (command == "ADD")
		{
			ft_add_contact(phoneBook);
		}
		else if (command == "SEARCH")
		{
			ft_search_contact(phoneBook);
		}
		else if (command == "EXIT")
		{
			break ;
		}
	}

	return (0);
}
