#include <iostream>
#include <vector>
#include <random>

/*
 * O que o programa faz
 * - Sorteia um número inteiro entre 1 e 100 e dá
 *   7 tentativas para o jogador acertar.
 * - A cada palpite, diz se o número secreto é maior
 *   ou menor que o palpite.
 * - Se o jogador digitar algo que não é um número
 *   (por exemplo `abc`), pede de novo sem gastar a
 *   tentativa e sem travar.
 * - No fim, diz se ganhou (e em quantas tentativas)
 *   ou perdeu (revelando o número) e lista todos os
 *   palpites, na ordem.
 */
 
// função para randomizar um número de 1 a 100
int random_secret (int l, int h) {
	// motor do random, sempre diferente em cada execução
	std::mt19937 engine{std::random_device{}()};

	// aqui fazemos o sorteio de 1 a 100
	std::uniform_int_distribution<int> distribution{l,h};
	return distribution(engine);
}

// função para ler e tratar o numero digitado
int get_guess () {
	int guess{};
	std::cin >> guess; // pega o que o usuario digitou

	// se for string vai entrar aqui com erro (true)
	while (std::cin.fail()) {
		std::cin.clear(); // limpa o erro fazendo cin.failt() para false;
		std::cin.ignore(1000, '\n');
		std::cout << "Por favor, digite um número: ";
		std::cin >> guess; // tenta pegar o numero de novo?
	}

	return guess;
}


int main () {
	const int low{1}; // menor numero possível
	const int high{100}; // maior numero
	const int max_tries{7}; // numero maximo de tentativas
	const int secret_number{random_secret(low, high)}; // numero secreto
  
	// lista vazia dos palpites, inicia vazia
	std::vector<int> guesses; // vector<T> guarda o tipo em uma lista de itens do tipo <T>

	bool winner{false};

	std::cout << "Adivinhe o número entre " << low 
			  << " e " << high << " \n\n";

	for (int attempt = 1; attempt <= max_tries; ++attempt) {
		std::cout << "Tentativa " << attempt << " de "
		  		  << max_tries <<  " tentativas. \n\n";

		std::cout << "Por favor, digite um número: ";
		int guess{get_guess()}; // pega o numero digitado como inteiro
		guesses.push_back(guess); // adicionar o numero na fila de numeros digitados `guesses`

		std::cout << "\nNumero digitado: [" << guess << "]\n\n";

		if (guess == secret_number) {
			winner = true;
			std::cout << "ACERTO MIZERAVI! "
					  << "o número é " << secret_number << "\n\n";
			break; // encerra e sai o laço
		} else if (guess < secret_number) {
			std::cout << "Número errado, sobe mais. \n\n";
		} else {
			std::cout << "Número errado, pode descer. \n\n";
		}
	}

	if (!winner) {
		std::cout << "Acabaram as tentativas :( \n"
				  << "O número era: [" << secret_number << "]\n\n";
	}

	// vamos mostrar os palpites do jogador
	std::cout << "Seus palpites foram: \n";
	for (int guess : guesses) {
		std::cout << " - [" << guess << "]\n";
	}
	std::cout << "\n";

	return 0;
}
