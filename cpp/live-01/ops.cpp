#include <iostream>
#include <limits>
#include <string>

int main() {
	std::string name{};
	int age{};
	std::string city{};

	std::cout << "Qual teu nome mané? ";
	std::getline(std::cin, name);

	std::cout << "Qual a idade? ";
	std::cin >> age;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Qual cidade? ";
	std::getline(std::cin, city);
	// std::getline(std::cin >> std::ws, city);

	std::cout << name << " tem " << age << " anos!\n";
	std::cout << "Moda em: " << city << "\n";
}
