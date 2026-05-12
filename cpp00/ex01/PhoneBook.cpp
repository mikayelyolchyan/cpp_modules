#include "PhoneBook.hpp"
#include <iostream>

static std::string	ft_format_column(const std::string &str)
{
	std::string result = "";
	int len = str.length();

	if (len > 10)
	{
		result = str.substr(0, 9) + ".";
	}
	else
	{
		for (int i = 0; i < 10 - len; i++)
			result += " ";
		result += str;
	}
	return (result);
}

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact &contact)
{
	if (contactCount < 8)
	{
		contacts[contactCount] = contact;
		contactCount++;
	}
	else
	{
		contacts[oldestIndex] = contact;
		oldestIndex = (oldestIndex + 1) % 8;
	}
}

void PhoneBook::displayContacts() const
{
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < contactCount; i++)
	{
		std::string index_str = "";
		for (int j = 0; j < 10 - 1; j++)
			index_str += " ";
		index_str += (char)('0' + i);

		std::cout << "|" << index_str;
		std::cout << "|" << ft_format_column(contacts[i].getFirstName());
		std::cout << "|" << ft_format_column(contacts[i].getLastName());
		std::cout << "|" << ft_format_column(contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}
}

Contact PhoneBook::getContact(int index) const
{
	return (contacts[index]);
}

int PhoneBook::getContactCount() const
{
	return (contactCount);
}

bool PhoneBook::isValidIndex(int index) const
{
	return (index >= 0 && index < contactCount);
}
