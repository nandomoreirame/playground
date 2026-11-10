#include <iostream>
#include <string>

int main() {
	int idade{37};
	std::string name{"Fernando"};
	double height{1.55};
	bool aprendendo{true};
	char inicial{'F'};

	auto cidade = std::string{"São Paulo"};

	if (aprendendo) {
		// comentário em linha
		std::cout << "Aprendendo C++ em Live!\n"; // no fim da linha
	} else {
		std::cout << "Olar!\n"; // nunca vai cair aqui.
	}

	std::cout << "Idade: " << idade << " \nNome: " << name << " \nAltura: " << height << " \n";
	std::cout << "Inicial: " << inicial << "\n";
	std::cout << "Cidade: " << cidade << "\n";
	return 0;
}
