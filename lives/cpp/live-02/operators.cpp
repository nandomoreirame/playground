#include <iostream>

int main () {
	int day{3};

	// switch case
	switch (day) {
		case 1:
			std::cout << "domingo\n";
			break;
		case 2:
			std::cout << "segunda\n";
			break;
		case 3:
			std::cout << "terça\n";
			break;
		case 4:
			std::cout << "quarta\n";
			break;
	}

	// Repetição for
	for (int i = 1; i <= 5; ++i) {
		std::cout << i << " ao quadrado é " << i * i << "\n \n";
	}

	// Repetição ~ while
	int countdown{5};
	
	while (countdown > 0) {
		std::cout << countdown << "... \n\n";
		--countdown;
	}
	std::cout << "Valendo! \n";

	return 0;
}
