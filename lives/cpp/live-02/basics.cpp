#include <iostream>

int main() {
	int temperature{5};

	if (temperature >= 30) {
		std::cout << "Calor\n";
	} else if (temperature >= 20) {
		std::cout << "Agradável\n";
	} else if (temperature <= 10) {
		std::cout << "Frio BACARAI!\n";
	} else {
		std::cout << "Frio\n";
	}

	return 0;
}
