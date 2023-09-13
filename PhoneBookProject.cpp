#include <bits/stdc++.h>

using namespace std;


class Contact {  // Abstract class representing  Contact
public:
    Contact(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber)
        : firstName_(firstName), lastName_(lastName), phoneNumber_(phoneNumber) {}

    virtual void display() const = 0; // Pure virtual function From abstraction


protected:
    std::string firstName_;       // Encapsulation:  variable
    std::string lastName_;        // Encapsulation:  variable
    std::string phoneNumber_;     // Encapsulation:  variable

};


class PersonalContact : public Contact {
public:
    PersonalContact(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber)
        : Contact(firstName, lastName, phoneNumber) {}

    void display() const override {   //overrides function
        std::cout << "Personal Contact: " << firstName_ << " " << lastName_ << ", Phone: " << phoneNumber_ << std::endl;
    } //Inheritance and Polymorphism from Contact


};


class BusinessContact : public Contact {
public:
    BusinessContact(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber)
        : Contact(firstName, lastName, phoneNumber) {}

    void display() const override {  //overrides function
        std::cout << "Business Contact: " << firstName_ << " " << lastName_ << ", Phone: " << phoneNumber_ << std::endl;
    }  //Inheritance and Polymorphism from Contact

};


int main() {
    std::vector<Contact*> contacts;

    char choice;

    system("cls");
    system("color 06");
    do {
        std::cout << ">>Select Options<<\n";
        std::cout << "1. Add Personal Contact\n";
        std::cout << "2. Add Business Contact\n";
        std::cout << "3. Display Contacts\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                std::string firstName, lastName, phoneNumber;
                std::cout << "Enter First Name: ";
                std::cin >> firstName;
                std::cout << "Enter Last Name: ";
                std::cin >> lastName;
                std::cout << "Enter Phone Number: ";
                std::cin >> phoneNumber;
                contacts.push_back(new PersonalContact(firstName, lastName, phoneNumber));
                break;
            }
            case '2': {
                std::string firstName, lastName, phoneNumber;
                std::cout << "Enter First Name: ";
                std::cin >> firstName;
                std::cout << "Enter Last Name: ";
                std::cin >> lastName;
                std::cout << "Enter Phone Number: ";
                std::cin >> phoneNumber;
                contacts.push_back(new BusinessContact(firstName, lastName, phoneNumber));
                break;
            }
            case '3':
                for (const auto& contact : contacts) {
                    contact->display();
                }
                break;
            case '4':
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != '4');

    // Clean up dynamically allocated objects
    for (const auto& contact : contacts) {
        delete contact;
    }

    return 0;
}
