#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		contactCount;
	int		oldestIndex;

public:
	PhoneBook();
	~PhoneBook();

	void	addContact(const Contact &contact);
	void	displayContacts() const;
	Contact	getContact(int index) const;
	int		getContactCount() const;
	bool	isValidIndex(int index) const;
};

#endif
