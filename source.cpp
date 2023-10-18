#include <iostream>
#include "classes.h"

std::vector<Drink*> drinks;
std::vector<Employee> employees;
std::vector<Table> tables;

void ManagerSection(std::shared_ptr<Manager> manager) {
	bool retry = true;
	while (retry) {
		system("cls");
		std::cout << "|----------------------------------|\n";
		std::cout << "|      --- MANAGER SECTION ---     |\n";
		std::cout << "|----------------------------------|\n";
		std::cout << "| 1. Your profile                  |\n";
		std::cout << "| 2. Change your e-mail            |\n";
		std::cout << "| 3. Change your phone number      |\n";
		std::cout << "| 4. Change your username          |\n";
		std::cout << "| 5. Change your password          |\n";
		std::cout << "| 6. View all employees            |\n";
		std::cout << "| 7. View all drinks               |\n";
		std::cout << "| 8. View all tables               |\n";
		std::cout << "| 9. Hire a employee               |\n";
		std::cout << "| 10. Add a coffee in menu         |\n";
		std::cout << "| 11. Add a tea in menu            |\n";
		std::cout << "| 12. Add a table                  |\n";
		std::cout << "| 13. Fire a employee              |\n";
		std::cout << "| 14. Remove a drink from menu     |\n";
		std::cout << "| 15. Remove a table               |\n";
		std::cout << "| 16. Change salary for a employee |\n";
		std::cout << "------------------------------------\n";
		std::cout << "\tYour option... ";
		unsigned short option_menu; std::cin >> option_menu;
		switch (option_menu) {
		case 1:{
			system("cls");
			std::cout << "--- YOUR PROFILE ---\n" << *manager;
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 2: {
			system("cls");
			std::cout << "--- CHANGE E-MAIL ---\n";
			manager->changeEmail();
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 3: {
			system("cls");
			std::cout << "--- CHANGE PHONE NUMBER ---\n";
			manager->changePhone();
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 4: {
			system("cls");
			std::cout << "--- CHANGE YOUR USERNAME ---\n";
			manager->getAccount().changeUsername();
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 5: {
			system("cls");
			std::cout << "--- CHANGE YOUR PASSWORD ---\n";
			manager->getAccount().changePassword();
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 6: {
			system("cls");
			std::cout << "--- VIEW ALL EMPLOYEES ---\n\n";
			if (employees.empty()) std::cout << "No employees.\n";
			else {
				for (auto employee : employees)
					employee.print(std::cout);
			}
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 7: {
			system("cls");
			std::cout << "--- VIEW ALL DRINKS ---\n\n";
			if (drinks.empty()) std::cout << "No drinks.\n";
			else {
				for (auto drink : drinks) {
					if (const Coffee* coffee = dynamic_cast<const Coffee*>(drink)) coffee->print(std::cout);
					else if (const Tea* tea = dynamic_cast<const Tea*>(drink)) tea->print(std::cout);
				}
			}
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 8: {
			system("cls");
			std::cout << "--- VIEW ALL TABLES ---\n\n";
			if (tables.empty()) std::cout << "No tables.\n";
			else {
				for (auto table : tables)
					table.print(std::cout);
			}
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 9: {
			system("cls");
			std::cout << "--- HIRE A EMPLOYEE ---\n";
			Employee e; e.read(std::cin);
			employees.push_back(e);
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 10: {
			system("cls");
			Coffee c; c.read(std::cin);
			Coffee* coffee = new Coffee(c);
			drinks.push_back(coffee);
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 11: {
			system("cls");
			Tea t; t.read(std::cin);
			Tea* tea = new Tea(t);
			drinks.push_back(tea);
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 12: {
			system("cls");
			std::cout << "--- ADD A TABLE ---\n";
			Table table; table.read(std::cin);
			tables.push_back(table);
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 13: {
			system("cls");
			std::cout << "--- FIRE A EMPLOYEE ---\n";
			if (employees.empty()) std::cout << "No employees.\n";
			else {
				std::cout << "Select employee by idex: \n";
				for (int i = 0; i < employees.size(); i++) {
					std::cout << i + 1 << ":\n";
					employees[i].print(std::cout);
				}
				unsigned short index;
				std::cout << "Enter the selected index: "; std::cin >> index;
				if (index > employees.size() or index < 1) std::cout << "Invalid index!\n";
				else {
					employees.erase(employees.begin() + index - 1);
					std::cout << "Employee fired successfully!\n";
				}
			}
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 14: {
			system("cls");
			std::cout << "--- REMOVE A DRINK FROM MENU ---\n";
			if (drinks.empty()) std::cout << "No drinks.\n";
			else {
				std::cout << "Select drink by index: \n";
				for (int i = 0; i < drinks.size(); i++) {
					std::cout << i + 1 << ":\n";
					if (const Coffee* coffee = dynamic_cast<const Coffee*>(drinks[i])) coffee->print(std::cout);
					else if (const Tea* tea = dynamic_cast<const Tea*>(drinks[i])) tea->print(std::cout);
				}
				std::cout << "Enter the selected index: ";
				unsigned short index; std::cin >> index;
				if (index > drinks.size() or index < 1) std::cout << "Invalid index!\n";
				else {
					drinks.erase(drinks.begin() + index - 1);
					std::cout << "Drink removed successfully!\n";
				}
			}
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 15: {
			system("cls");
			std::cout << "--- REMOVE A TABLE ---\n";
			if (tables.empty()) std::cout << "No tables.\n";
			else {
				std::cout << "Select table by index: \n";
				for (int i = 0; i < tables.size(); i++) {
					std::cout << i + 1 << ":\n";
					tables[i].print(std::cout);
				}
				std::cout << "Enter the selected index: ";
				unsigned int index; std::cin >> index;
				if (index > tables.size() or index < 1) std::cout << "Invalid index.\n";
				else {
					tables.erase(tables.begin() + index - 1);
					std::cout << "Table removed successfully!\n";
				}
			}
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case 16: {
			system("cls");
			if (employees.empty()) std::cout << "No employees.\n";
			else {
				std::cout << "Select employee by idex: \n";
				for (int i = 0; i < employees.size(); i++) {
					std::cout << i + 1 << ":\n";
					employees[i].print(std::cout);
				}
				unsigned short index;
				std::cout << "Enter the selected index: "; std::cin >> index;
				if (index > employees.size() or index < 1) std::cout << "Invalid index!\n";
				else {
					employees[index - 1].changeSalary();
				}
			}
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		default: {
			std::cout << "Wrong option!\n";
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		}
	}
}

void ManagerLogIn(std::shared_ptr<Manager> manager) {
	system("cls"); std::string user, pass;
	std::cout << "|-------------------------------|\n";
	std::cout << "|         --- LOG IN ---        |\n";
	std::cout << "|-------------------------------|\n";
	std::cout << "Enter the username: "; std::cin >> user;
	std::cout << "Enter the password: "; std::cin >> pass;
	if (user == manager->getAccount().getUsername() and pass == manager->getAccount().getPassword()) ManagerSection(manager);
	else {
		std::cout << "Wrong username or password.\nPress y to retry... ";
		char option_retry; std::cin >> option_retry;
		if (option_retry == 'y' or option_retry == 'Y') ManagerSection(manager);
	}
}

void EmployeeSection(Employee employee) {
	bool retry = true;
	while (retry) {
		system("cls");
		std::cout << "|-------------------------------|\n";
		std::cout << "|    --- EMPLOYEE SECTION ---   |\n";
		std::cout << "|-------------------------------|\n";
		std::cout << "| 1. Your profile               |\n";
		std::cout << "| 2. Change email               |\n";
		std::cout << "| 3. Change phone number        |\n";
		std::cout << "| 4. Change username            |\n";
		std::cout << "| 5. Change password            |\n";
		std::cout << "| 6. View all drinks            |\n";
		std::cout << "| 7. View all tables            |\n";
		std::cout << "| 8. Set aviability for a table |\n";
		std::cout << "|-------------------------------|\n";
		std::cout << "\tYour option... ";
		char employee_option; std::cin >> employee_option;
		switch (employee_option) {
		case '1': {
			system("cls");
			std::cout << "--- YOUR PROFILE ---\n";
			employee.print(std::cout);
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case '2': {
			system("cls");
			std::cout << "--- CHANGE E-MAIL ---\n";
			employee.changeEmail();
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case '3': {
			system("cls");
			std::cout << "--- CHANGE PHONE NUMBER ---\n";
			employee.changePhone();
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case '4': {
			system("cls");
			std::cout << "--- CHANGE USERNAME ---\n";
			employee.changeAccount("username");
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case '5': {
			system("cls");
			std::cout << "--- CHANGE PASSWORD ---\n";
			employee.changeAccount("password");
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case '6': {
			system("cls");
			if (employee.getType() == "Waiter") {
				std::cout << "Section only for baristas.\n";
			}
			else {
				std::cout << "--- VIEW ALL DRINKS ---\n\n";
				if (drinks.empty()) std::cout << "No drinks.\n";
				else {
					for (auto drink : drinks) {
						if (const Coffee* coffee = dynamic_cast<const Coffee*>(drink)) coffee->print(std::cout);
						else if (const Tea* tea = dynamic_cast<const Tea*>(drink)) tea->print(std::cout);
					}
				}
			}
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case '7': {
			system("cls");
			if (employee.getType() == "Barista") {
				std::cout << "Section only for waiters.\n";
			}
			else {
				std::cout << "--- VIEW ALL TABLES ---\n\n";
				if (tables.empty()) std::cout << "No tables.\n";
				else {
					for (auto table : tables)
						table.print(std::cout);
				}
			}
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		case '8': {
			system("cls");
			if (employee.getType() == "Barista") {
				std::cout << "Section only for waiters.\n";
			}
			else {
				if (tables.empty()) std::cout << "No tables.\n";
				else {
					std::cout << "Select table by index:\n";
					for (int i = 0; i < tables.size(); i++) {
						std::cout << i + 1 << ":\n";
						tables[i].print(std::cout);
					}
					unsigned int index;
					std::cout << "Selected index: "; std::cin >> index;
					if (index > tables.size() or index < 1) std::cout << "Invalid index.\n";
					else {
						unsigned short amount;
						std::cout << "Table no. " << index << " capacity: " << tables[index - 1].getCapacity() << "\n";
						std::cout << "Enter the number of guests: "; std::cin >> amount;
						if (amount > tables[index - 1].getCapacity() or amount < 1) std::cout << "Invalid amount!\n";
						else tables[index - 1] -= amount;
					}
				}
			}
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		default: {
			std::cout << "Wrong option!\n";
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		}
	}
}

void EmployeeLogIn() {
	system("cls"); std::string user, pass;
	std::cout << "---------------------------------\n";
	std::cout << "|         --- LOG IN ---        |\n";
	std::cout << "|-------------------------------|\n";
	std::cout << "Enter the username: "; std::cin >> user;
	std::cout << "Enter the password: "; std::cin >> pass;
	bool found = false;
	for (auto employee : employees) {
		if (employee.getAccount().getUsername() == user and employee.getAccount().getPassword() == pass) {
			found = true;
			EmployeeSection(employee);
			break;
		}
	}
	if (!found) {
		std::cout << "Wrong username or password!\n\tTo retry press y....";
		char option_retry; std::cin >> option_retry;
		if (option_retry == 'y' or option_retry == 'Y') EmployeeLogIn();
	}
}

void main(void) {
	std::shared_ptr<Manager> manager = Manager::Get();
	manager->setManager("Full Name", "0987654321", "example@example.com", "username", "password");
	Employee barista("Alexander", "Sterling", 20, 1000, "alexandersterling@ex.com", "0987654321", "Barista", Account("barista", "pass"));
	Employee waiter("Joe", "Doe", 28, 2000, "joedoe@example.com", "1234567890", "Waiter", Account("waiter", "pass"));
	employees.push_back(barista); employees.push_back(waiter);
	Table table1(1, 5); Table table2(2, 3); 
	tables.push_back(table1); tables.push_back(table2);
	Coffee* coffee1 = new Coffee("Espresso", 5, 35, {"Espresso"}, 0, 5, "Arabica");
	Coffee* coffee2 = new Coffee("Americano", 6, 70, { "Espresso", "Water" }, 0, 5, "Robusta");
	drinks.push_back(coffee1); drinks.push_back(coffee2);
	std::cout << "|---------------------|\n";
	std::cout << "|     --- MENU ---    |\n";
	std::cout << "|---------------------|\n";
	std::cout << "| 1. Manager Section  |\n";
	std::cout << "| 2. Employee Section |\n";
	std::cout << "|---------------------|\n";
	std::cout << "\tYour option... ";
	unsigned short menu_option; std::cin >> menu_option;
	bool retry = true;
	while (retry) {
		switch (menu_option)
		{
		case 1: {
			ManagerLogIn(manager);
			retry = false;
			break;
		}
		case 2: {
			EmployeeLogIn();
			retry = false;
			break;
		}
		default: {
			std::cout << "Wrong option!\n";
			std::cout << "\nDo you want to make another action? y/n\n";
			char option_retry; std::cin >> option_retry;
			if (option_retry != 'y' and option_retry != 'Y') retry = false;
			break;
		}
		}
	}
	for (auto drink : drinks) {
		delete drink;
	}
	drinks.clear();
}