#include <iostream>
#include <vector>

struct Contract {
	std::string name;
	std::string phone;
};

int main()  {
	Contract nando{"Fernando Moreira", "3333-3333"};
	std::vector<Contract> contracts{nando, {"Bruno", "3333-3332"}};

	for (const Contract& contract : contracts) {
		std::cout << "Nome: " << contract.name << "\nTelefone: " << contract.phone << "\n";
	}

	return 0;
}
