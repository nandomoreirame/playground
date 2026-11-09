#include <iomanip>
#include <iostream>
#include <string>

int main() {
	std::string name;
	double celsius{};

	std::cout << "Seu nome: ";
	std::getline(std::cin, name);

	std::cout << "Teperatura atual em Celsius: ";
	std::cin >> celsius;

	const double fh = celsius * 9.0 / 5.0 + 32.0;
	const double kv = celsius + 273.15;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\n" << name << ", aqui está a conversão:\n";
	std::cout << " - Celsius: " << celsius << "C\n";
	std::cout << " - Fahrenheit: " << fh << "F\n";
	std::cout << " - Kelvin: " << kv << "K\n";

	return 0;
}
