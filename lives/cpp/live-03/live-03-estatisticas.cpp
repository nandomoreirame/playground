/*
 * Live 03: estatísticas de uma lista de números (gabarito comentado).
 *
 * Referência de quem apresenta: o desafio é escrito ao vivo, sem olhar aqui.
 * Usa o que a live 3 ensinou: passagem por valor, por referência (&) e por
 * referência constante (const&), ponteiro e nullptr, iteradores, <algorithm>
 * e <numeric>. O <cmath> só entra para a raiz quadrada do desvio padrão.
 *
 * Compilar: g++ -std=c++20 -Wall -Wextra -o estatisticas live-03-estatisticas.cpp
 */
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

int read_number(const std::string& msg = "Quantos números você quer? ") {
	int number{};

	std::cout << msg;
	std::cin >> number;

	while (number <= 0 || (std::cin.fail() && !std::cin.eof())) {
		std::cin.clear(); // limpa o estado de falha para o cin
		std::cin.ignore(1000, '\n'); // descarta o resto da linha

		std::cout << "Erro: O número precisa ser maior que 0 e não deve ser uma string.\n";
		std::cout << "Quantos números você quer? ";
		std::cin >> number;
	}

	return number;
}

// altera o vetor da main, por isso recebe por referencia &
void read_numbers(std::vector<double>& values, int count) {
	// o loop vai pedir o numero total de números que o usuário informou;
	for (int i = 1; i <= count; ++i) {
		std::cout << "Digite o Número " << i << ": "; // perguntar o numero da vez
		double value{}; // value começa em zero
		std::cin >> value; // cin vai trocar o valor digitado pelo usuario
		values.push_back(value); // adicionamos o valor digita no vetor (referencia, não cópia)
	}
}

// função que soma todos os items
double sum(const std::vector<double>& values) { // também recebe values por ref
	return std::accumulate(values.begin(), values.end(), 0.0);
}

// função para pegar o menor número, recebe values como ref
double smallest(const std::vector<double>& values) {
	// min_element também vem de algorithm
	return *std::min_element(values.begin(), values.end());
}

// função que vai fazer a média aritmética
double mean(const std::vector<double>& values) { // também recebe values por referencia &
	// aqui é a soma dividida pela quantidade, em decimal
	return sum(values) / static_cast<double>(values.size());
}

// receber a cópia por valor
double median(std::vector<double> values) {
	// ordenar a posição do menor para o maior ::sort
	std::sort(values.begin(), values.end());
	
	// pegar a posição do meio
	const std::size_t middle{values.size()/2};

	// vamos pegar o mod par 
	if (values.size() % 2 == 0) {
		return (values[middle - 1] + values[middle] / 2.0); // media dos dois valores do meio
	}
	
	return values[middle];
}

// desvio padrão populacional
// vamo receber o vector por referencia e a média por cópia
double deviation(const std::vector<double>& values, double average) {
	double squares{0.0}; // aqui o acumulador
	
	for (double value : values) { // para cada numero enviado
		const double diff{value - average}; //distância até a média
		squares += diff * diff; // soma o quadrado da distancia
	}
	
	return std::sqrt(squares / static_cast<double>(values.size()));
}

// função vai pegar o maior número digitado
const double* find_largest(const std::vector<double>& values) {
	if (values.empty()) {
		return nullptr; // se o vector for vazio retorna nada
	}

	// max_ement previsa de algorithm
	return &*std::max_element(values.begin(), values.end());
}

int main() {
	int count = read_number(); // quantos numeros serão digitados

	std::vector<double> values; // aqui a lista vazia dos números que serão digitados;
	read_numbers(values, count); // a função vai preencher o vetor por referência;

	const double average{mean(values)};
	const double* largest{find_largest(values)};

	std::cout << "Quantidade: " << values.size() << "\n";
	std::cout << "A Soma é: " << sum(values) << "\n";
	std::cout << "O menor número é: " << smallest(values) << "\n";

	if (largest != nullptr) {
		// afunção find_largest devolve o ponteiro do número
		// precisa adicionar * na frente da variável para ler o valor;
		std::cout << "O maior número é: " << *largest << "\n";
	}
	
	std::cout << "Média: " << average << "\n";
	std::cout << "Mediana: " << median(values) << "\n";
	// Desvio
	std::cout << "Desvio: " << deviation(values, average) << "\n";
	
	return 0;
}
