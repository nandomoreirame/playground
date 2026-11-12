#include <iostream>

void print_menu() {
	std::cout << "\n"
			  << "1) Adicionar\n"
			  << "2) Buscar\n"
			  << "3) Remover\n"
			  << "4) Listar\n" 
			  << "0) Sair\n"
			  << "> ";
}

int main() {
	int option{-1};
	
	while (option != 0)  {
		print_menu();

		if (!(std::cin >> option)) {
			std::cout << "\n" << "Entrada errada. \n";
			break;
		}

		std::cin.ignore(1000, '\n');

		if (option == 1) {
			std::string name;
			std::cout <<  "Nome: ";
			std::getline(std::cin, name);
			std::cout << "Você digitou [" << name << "]\n";
		} else if (option == 0) {
			std::cout << "Até a próxima!\n";
		} else {
			std::cout << "Opção inválida. \n";
		}
	}

	return 0;
}
