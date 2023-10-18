#include <string>
#include <vector>
#include <regex>

// Define regex patterns for input validation
std::regex passwordPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#\\$%^&*])[A-Za-z\\d!@#\\$%^&*]{8,}$");
std::regex emailPattern("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4}");
std::regex phonePattern("\\d{10}");


// Define an abstract input-output interface
class io {
public:
	virtual void read(std::istream& in) = 0;
	virtual void print(std::ostream& out) const = 0;
};

// Define a base class for all Drink objects
class Drink {
protected:
	std::string name;
	float price;
	unsigned short volume;
	std::vector<std::string> ingredients;
	unsigned short sugar_level;
public:
	Drink() : name(""), price(0), volume(0), ingredients({}), sugar_level(0) {};
	Drink(std::string name, float price, unsigned short volume, std::vector<std::string> ingredients, unsigned short sugar_level) {
		this->name = name;
		this->price = price;
		this->volume = volume;
		this->ingredients = ingredients;
		this->sugar_level = sugar_level;
	}
	// Allows the user to set a new price for the drink
	void setPrice() {
		std::cout << "Current price: " << price << "\n";
		try {
			float new_price;
			std::cout << "Enter the new price (in $): "; std::cin >> new_price;
			if (new_price <= 0) throw std::runtime_error("Price must be over 0.\n");
			else {
				price = new_price;
				std::cout << "Price changed successfully!\n";
			}
		}
		catch (std::exception& e) {
			std::cout<<e.what()<<"To retry press y... ";
			char option; std::cin >> option;
			if (option == 'y' or option == 'Y') setPrice();
		}
	}
	// Allows the user to set a new volume for the drink
	void setVolume() {
		std::cout << "Current volume: " << volume << "\n";
		try {
			unsigned short new_volume;
			std::cout << "Enter the new volume (in ml): "; std::cin >> new_volume;
			if (new_volume <= 0) throw std::runtime_error("Volume must be over 0\n");
			else {
				volume = new_volume;
				std::cout << "Volume changed successfully!\n";
			}
		}
		catch (std::exception& e) {
			std::cout << e.what() << "To retry press y... ";
				char option; std::cin >> option;
			if (option == 'y' or option == 'Y') setVolume();
		}
	}
	virtual void addIngredient() = 0; // Abstract method to add an ingredient
};

// Derived class Coffee, inherits from Drink and implements the io interface
class Coffee : public Drink, public io {
	unsigned short caffeine_level;
	std::string origin;
public:
	Coffee() : Drink(), caffeine_level(0), origin("") {};
	Coffee(std::string name, float price, unsigned short volume, std::vector<std::string> ingredients, unsigned short sugar_level, 
		unsigned short caffeine_level, std::string origin) : Drink(name, price, volume, ingredients, sugar_level) {
		this->caffeine_level = caffeine_level;
		this->origin = origin;
	}
	// Allows the user to set a new caffeine level for the Coffee
	void setCaffeine() {
		std::cout << "Current caffeine level: " << caffeine_level;
		std::cout << "Enter the new caffeine level: "; std::cin >> caffeine_level;
		std::cout << "Caffeine level changed successfully!\n";
	}
	void read(std::istream& in) override {
		name = "";
		while (name == "") {
			system("cls");
			std::cout << "Enter the name: "; getline(in, name);
		}
		name[0] = std::toupper(name[0]);
		std::cout << "Enter the price (in $): "; in >> price;
		std::cout << "Enter the volume (in ml): "; in >> volume;
		std::cout << "Enter the number of ingredients: ";
		unsigned short nr_ingredients; in >> nr_ingredients;
		ingredients.resize(nr_ingredients); in.ignore();
		for (int i = 0; i < ingredients.size(); i++) {
			std::cout << "Enter the name of ingredient: ";
			getline(in, ingredients[i]);
			ingredients[i][0] = std::toupper(ingredients[i][0]);
		}
		std::cout << "Enter the sugar level (in g): "; in >> sugar_level;
		std::cout << "Enter the caffeine level (in g): "; in >> caffeine_level;
		std::cout << "Origin: "; in.ignore(); getline(in, origin);
		origin[0] = std::toupper(origin[0]);
	}
	// Allows the user to add an ingredient to the Coffee
	void addIngredient() override {
		std::string ingredient = "";
		while (ingredient == "") {
			system("cls");
			std::cout << "--- ADD A COFFEE IN MENU ---\n";
			std::cout << "Enter the name of the ingredient: "; getline(std::cin, ingredient);
		}
		ingredients.push_back(ingredient);
		std::cout << "Do you want to change the volume? y/n";
		char option; std::cin >> option;
		if (option == 'y' or option == 'Y') setVolume();
		std::cout << "Do you want to change the price? y/n"; std::cin >> option;
		if (option == 'y' or option == 'Y') setPrice();
		std::cout << "Ingredient added successfully!\n";
	}
	void print(std::ostream& out) const override {
		out << "Name: " << name << "\n";
		out << "Price: " << price << "$\n";
		out << "Volume: " << volume << "ml\n";
		out << "Ingredients: ";
		for (auto ingredient : ingredients)
			if (ingredient != ingredients.back()) out << ingredient << ", ";
			else out << ingredient << "\n";
		out << "Sugar level: " << sugar_level << "g\n";
		out << "Caffeine level: " << caffeine_level << "g\n";
		out << "Origin: " << origin << "\n\n";
	}
};

// Define a class for Tea, which is similar to Coffee
class Tea : public Drink, public io {
	std::string tea_type;
public:
	Tea() : Drink(), tea_type("") {};
	Tea(std::string name, float price, unsigned short volume, std::vector<std::string> ingredients, 
		unsigned short sugar_level, std::string tea_type) : Drink(name, price, volume, ingredients, sugar_level) {
		this->tea_type = tea_type;
	}
	void read(std::istream& in) override {
		name = "";
		while (name == "") {
			system("cls");
			std::cout << "--- ADD A TEA IN MENU ---\n";
			std::cout << "Enter the name: "; getline(in, name);
		}
		name[0] = std::toupper(name[0]);
		std::cout << "Enter the price (in $): "; in >> price;
		std::cout << "Enter the volume (in ml): "; in >> volume;
		std::cout << "Enter the number of ingredients: ";
		unsigned short nr_ingredients; in >> nr_ingredients;
		ingredients.resize(nr_ingredients); in.ignore();
		for (int i = 0; i < ingredients.size(); i++) {
			std::cout << "Enter the name of ingredient: ";
			getline(in, ingredients[i]);
			ingredients[i][0] = std::toupper(ingredients[i][0]);
		}
		std::cout << "Enter the sugar level (in g): "; in >> sugar_level;
		std::cout << "Tea type: "; in.ignore(); getline(in, tea_type);
		tea_type[0] = std::toupper(tea_type[0]);
	}
	void print(std::ostream& out) const override {
		out << "Name: " << name << "\n";
		out << "Price: " << price << "$\n";
		out << "Volume: " << volume << "ml\n";
		out << "Ingredients: ";
		for (auto ingredient : ingredients)
			if (ingredient != ingredients.back()) out << ingredient << ", ";
			else out << ingredient << "\n";
		out << "Sugar level: " << sugar_level << "g\n";
		out << "Tea type: " << tea_type << "\n\n";
	}
	void addIngredient() override {}
};

class Table: public io {
	unsigned short number;
	unsigned short capacity;
public:
	Table() : number(0), capacity(0) {};
	Table(unsigned short number, unsigned short capacity) {
		this->number = number;
		this->capacity = capacity;
	}
	Table& operator-=(int num) {
		capacity -= num;
		return *this;
	}
	const unsigned short getCapacity() {
		return capacity;
	}
	void read(std::istream& in) override {
		std::cout << "Enter the number: "; in >> number;
		std::cout << "Enter the capacity: "; in >> capacity;
	}
	void print(std::ostream& out) const override {
		out << "Number: " << number << "\n";
		out << "Capacity: " << capacity << "\n\n";
	}
};

// Define a class for managing user accounts
class Account {
	std::string username;
	std::string password;
public:
	Account() : username(""), password("") {};
	Account(std::string username, std::string password) : username(username), password(password) {};
	Account& operator=(const Account & other){
		if (this == &other) return *this;
		this->username = other.username;
		this->password = other.password;
		return *this;
	}
	// Allows the user to change the username
	void changeUsername() {
		try {
			std::cout << "Enter the new username: ";
			std::string new_username; std::cin >> new_username;
			if (new_username == "") throw std::runtime_error("Invalid username!\n");
			else {
				username = new_username;
				std::cout << "Username changed successfully!\n";
			}
		}
		catch (std::exception& e) {
			std::cout << e.what() << "\tTo retry press y... ";
			char option; std::cin >> option;
			if (option == 'y' or option == 'Y') changeUsername();
		}
	}
	// Allows the user to change the password
	void changePassword() {
		std::cout << "\nA valid password is:\n";
		std::cout << "\t• At least 8 characters long.\n";
		std::cout << "\t• Contains both uppercase and lowercase letters.\n";
		std::cout << "\t• Contains at least one digit.\n";
		std::cout << "\t• Contains at least one special character (e.g., !, @, #, $, etc.).\n";
		try {
			std::cout << "\n\tEnter the new password: "; 
			std::string new_password; std::cin >> new_password;
			if (std::regex_match(new_password, passwordPattern)) {
				password = new_password;
				std::cout << "Password changed successfully!\n";
			}
			else throw std::runtime_error("Invalid password!\n");
		}
		catch (std::exception& e) {
			std::cout << e.what() << "\tTo retry press y... ";
			char option; std::cin >> option;
			if (option == 'y' or option == 'Y') changePassword();
		}
	}
	const std::string getUsername() {
		return username;
	}
	const std::string getPassword() {
		return password;
	}
};

class Employee : public io {
protected:
	std::string first_name;
	std::string last_name;
	unsigned short age;
	unsigned int salary;
	std::string email;
	std::string phone;
	std::string type;
	Account account;
public:
	Employee() : first_name(""), last_name(""), age(0), salary(0), email(""), phone(""), type(""), account(Account("", "")) {};
	Employee(std::string first_name, std::string last_name, unsigned short age, unsigned int salary, std::string email, 
		std::string phone, std::string type, Account account) {
		this->first_name = first_name;
		this->last_name = last_name;
		this->age = age;
		this->salary = salary;
		this->email = email;
		this->phone = phone;
		this->type = type;
		this->account = account;
	}
	void changeSalary() {
		std::cout << "Current salary: " << salary << "\n";
		try {
			unsigned int new_salary;
			std::cout << "Enter the new salary: "; std::cin >> new_salary;
			if (new_salary <= 0) throw std::runtime_error("Salary must be over 0!\n");
			else salary = new_salary, std::cout<<"Salary change successfully!\n";
		}
		catch (std::exception& e) {
			std::cout<<e.what()<<"To retry press y... ";
			char option; std::cin >> option;
			if (option == 'y' or option == 'Y') changeSalary();
		}
	}
	void changeAccount(std::string credential) {
		if (credential == "username") account.changeUsername();
		else account.changePassword();
	}
	Account getAccount() {
		return account;
	}
	const std::string getType() {
		return type;
	}
	void changePhone() {
		bool ok = true;
		while (ok) {
			try {
				std::string new_phone;
				std::cout << "Phone number must have 10 digits\n";
				std::cout << "Enter the phone number: "; std::cin >> new_phone;
				if (!std::regex_match(new_phone, phonePattern)) throw std::runtime_error("Wrong phone number format!\n");
				else phone = new_phone, ok = false;
			}
			catch (std::exception& e) {
				std::cout << e.what() << "\n";
			}
		}
	}
	void changeEmail() {
		bool ok = true;
		while (ok) {
			try {
				std::string new_email;
				std::cout << "E-mail format: example@example.com\n";
				std::cout << "Enter the e-mail: "; std::cin >> new_email;
				if (!std::regex_match(new_email, emailPattern)) throw std::runtime_error("Wrong e-mail format!\n");
				else email = new_email, ok = false;
			}
			catch (std::exception& e) {
				std::cout << e.what() << "\n";
			}
		}
	}
	void read(std::istream& in) override {
		first_name = "";
		while (first_name == "") {
			system("cls");
			std::cout << "Enter the first name: "; getline(in, first_name);
		}
		std::cout << "Enter the last name: "; getline(in, last_name);
		bool ok = true;
		while (ok) {
			try {
				unsigned short new_age;
				std::cout << "Enter the age: "; in >> new_age;
				if (new_age < 16) throw std::runtime_error("Employee must be over 16yo\n");
				else age = new_age, ok = false;
			}
			catch (std::exception& e) {
				std::cout << e.what() << "\n";
			}
		}
		ok = true;
		while (ok) {
			try {
				unsigned int new_salary;
				std::cout << "Enter the salary: "; in >> new_salary;
				if (new_salary <= 0) throw std::runtime_error("Salary must be over 0!\n");
				else salary = new_salary, ok = false;
			}
			catch (std::exception& e) {
				std::cout << e.what() << "\n";
			}
		}
		ok = true;
		while (ok) {
			try {
				std::string new_email;
				std::cout << "E-mail format: example@example.com\n";
				std::cout << "Enter the e-mail: "; in >> new_email;
				if (!std::regex_match(new_email, emailPattern)) throw std::runtime_error("Wrong e-mail format!\n");
				else email = new_email, ok = false;
			}
			catch (std::exception& e) {
				std::cout << e.what() << "\n";
			}
		}
		ok = true;
		while (ok) {
			try {
				std::string new_phone;
				std::cout << "Phone number must have 10 digits\n";
				std::cout << "Enter the phone number: "; in >> new_phone;
				if (!std::regex_match(new_phone, phonePattern)) throw std::runtime_error("Wrong phone number format!\n");
				else phone = new_phone, ok = false;
			}
			catch (std::exception& e) {
				std::cout << e.what() << "\n";
			}
		}
		ok = true;
		while (ok) {
			std::cout << "Select type of employee:\n\t1. Barista\n\t2.Waiter";
			std::cout << "\n\tYour option: ";
			char type_option; std::cin >> type_option;
			if (type_option == '1') type = "Barista", ok = false;
			else if (type_option == '2') type = "Waiter", ok = false;
			else std::cout << "Wrong option!\n";
		}
		std::cout << "\n________________________________\n";
		std::cout << "--- Assing account ---\n";
		std::cout << "________________________________\n";
		account.changeUsername(); account.changePassword();
	}
	void print(std::ostream& out) const override {
		out << "--- " << type << " ---\n";
		out << "Full name: " << first_name << " " << last_name << "\n";
		out << "Type: " << type << "\n";
		out << "Age: " << age << "\n";
		out << "Salary: " << salary << "\n";
		out << "E-mail: " << email << "\n";
		out << "Phone number: " << phone << "\n\n";
	}
};

// Define singleton class for manager
class Manager {
public:
	// Using a smart pointer to avoid the memory leaks
	static std::shared_ptr<Manager> Get() {
		if (!s_Instance) {
			s_Instance = std::shared_ptr<Manager>(new Manager);
		}
		return s_Instance;
	}
	void setManager(std::string name, std::string phone, std::string email, std::string username, std::string password) {
		this->name = name;
		this->phone = phone;
		this->email = email;
		account = Account(username, password);
	}
	Account getAccount() {
		return account;
	}
	void changeCredential(std::string credential){
		if (credential == "username") account.changeUsername();
		else account.changePassword();
	}
	friend std::ostream& operator << (std::ostream& out, Manager m) {
		out << "Name: " << m.name << "\n";
		out << "Phone: " << m.phone << "\n";
		out << "E-mail: " << m.email << "\n";
		return out;
	}
	void changePhone() {
		bool ok = true;
		while (ok) {
			try {
				std::string new_phone;
				std::cout << "Phone number must have 10 digits\n";
				std::cout << "Enter the phone number: "; std::cin >> new_phone;
				if (!std::regex_match(new_phone, phonePattern)) throw std::runtime_error("Wrong phone number format!\n");
				else phone = new_phone, ok = false;
			}
			catch (std::exception& e) {
				std::cout << e.what() << "\n";
			}
		}
	}
	void changeEmail() {
		bool ok = true;
		while (ok) {
			try {
				std::string new_email;
				std::cout << "E-mail format: example@example.com\n";
				std::cout << "Enter the e-mail: "; std::cin >> new_email;
				if (!std::regex_match(new_email, emailPattern)) throw std::runtime_error("Wrong e-mail format!\n");
				else email = new_email, ok = false;
			}
			catch (std::exception& e) {
				std::cout << e.what() << "\n";
			}
		}
	}
private:
	std::string name;
	std::string phone;
	std::string email;
	Account account;
	Manager() : name(""), phone(""), email("") {
		account = Account("", "");
	}
	static std::shared_ptr<Manager> s_Instance;
};

std::shared_ptr<Manager> Manager::s_Instance = nullptr;