#include <iostream>
#include <vector>
#include <numeric>

// entrega uma cópia de x para number
// a função mexe na cópia (number) e desaparece no fim.
// void add_one_by_value(int number) {
// 	number += 1; // aqui muda a cópia
// } // a cópia some aqui

void add_one_by_reference(int& number) {
	number += 1;
}

void swap_values(int& a, int& b) {
	const int temp = a;
	a = b;
	b = temp;
}

// vou usar std::vector<>& significa não copiar e não deixar alterar;
double mean(const std::vector<double>& values) {
	return std::accumulate(values.begin(), values.end(), 0.0) / static_cast<double>(values.size());
}

int main() {
	int x{10};

	add_one_by_reference(x); // passa number como cópia de x (10)

	std::cout << "O x muda para: " << x << "\n";

	int a{1};
	int b{2};

	swap_values(a, b);

	std::cout << "a=" << a << " b=" << b << "\n";

	// cria um vetor de 5 posições chamado values
	const std::vector<double> values{3, 1, 4, 1, 5};

	// chama a funçõa mean() passando values
	std::cout << "média=" << mean(values) << "\n";

	return 0;
}
