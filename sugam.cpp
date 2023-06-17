#include <iostream>
#include <string>
#include <vector>

class Contact {
public:
  std::string name;
  std::string phoneNumber;
  std::string emailAddress;
  std::string notes;
};

class ContactManager {
private:
  std::vector<Contact> contacts;

public:
  void addContact(const Contact& contact) {
    contacts.push_back(contact);
    std::cout << "Contact added successfully!" << std::endl;
  }

  void displayContacts() {
    if (contacts.empty()) {
      std::cout << "No contacts found." << std::endl;
    } else {
      for (const auto& contact : contacts) {
        std::cout << "Name: " << contact.name << std::endl;
        std::cout << "Phone: " << contact.phoneNumber << std::endl;
        std::cout << "Email: " << contact.emailAddress << std::endl;
        std::cout << "Notes: " << contact.notes << std::endl;
        std::cout << "---------------------------" << std::endl;
      }
    }
  }

  void searchContact(const std::string& name) {
    bool found = false;
    for (const auto& contact : contacts) {
      if (contact.name == name) {
        std::cout << "Name: " << contact.name << std::endl;
        std::cout << "Phone: " << contact.phoneNumber << std::endl;
        std::cout << "Email: " << contact.emailAddress << std::endl;
        std::cout << "Notes: " << contact.notes << std::endl;
        std::cout << "---------------------------" << std::endl;
        found = true;
      }
    }
    if (!found) {
      std::cout << "Contact not found." << std::endl;
    }
  }

  void updateContact(const std::string& name) {
    bool found = false;
    for (auto& contact : contacts) {
      if (contact.name == name) {
        std::cout << "Enter new phone number: ";
        std::getline(std::cin, contact.phoneNumber);

        std::cout << "Enter new email address: ";
        std::getline(std::cin, contact.emailAddress);

        std::cout << "Enter new notes: ";
        std::getline(std::cin, contact.notes);

        std::cout << "Contact updated successfully!" << std::endl;
        found = true;
        break;
      }
    }
    if (!found) {
      std::cout << "Contact not found." << std::endl;
    }
  }

  void deleteContact(const std::string& name) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
      if (it->name == name) {
        contacts.erase(it);
        std::cout << "Contact deleted successfully!" << std::endl;
        return;
      }
    }
    std::cout << "Contact not found." << std::endl;
  }
};

int main() {
  ContactManager manager;

  while (true) {
    std::cout << "----------- Contact Manager -----------" << std::endl;
    std::cout << "1. Add Contact" << std::endl;
    std::cout << "2. Display Contacts" << std::endl;
    std::cout << "3. Search Contact" << std::endl;
    std::cout << "4. Update Contact" << std::endl;
    std::cout << "5. Delete Contact" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;
    std::cin.ignore(); 

    switch (choice) {
      case 1: {
        Contact newContact;

        std::cout << "Enter name: ";
        std::getline(std::cin, newContact.name);

        std::cout << "Enter phone number: ";
        std::getline(std::cin, newContact.phoneNumber);

        std::cout << "Enter email address: ";
        std::getline(std::cin, newContact.emailAddress);

        std::cout << "Enter notes: ";
        std::getline(std::cin, newContact.notes);

        manager.addContact(newContact);
        break;
      }
      case 2:
        manager.displayContacts();
        break;
      case 3: {
        std::string searchName;
        std::cout << "Enter name to search: ";
        std::getline(std::cin, searchName);
        manager.searchContact(searchName);
        break;
      }
      case 4: {
        std::string updateName;
        std::cout << "Enter name to update: ";
        std::getline(std::cin, updateName);
        manager.updateContact(updateName);
        break;
      }
      case 5: {
        std::string deleteName;
        std::cout << "Enter name to delete: ";
        std::getline(std::cin, deleteName);
        manager.deleteContact(deleteName);
        break;
      }
      case 0:
        return 0;
      default:
        std::cout << "Invalid choice. Please try again." << std::endl;
    }

    std::cout << std::endl;
  }
}
