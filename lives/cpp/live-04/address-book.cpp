#include <cstddef> // std::size_t e std::ptrdiff_t
#include <iostream> // std::cout
#include <string> // std::string
#include <utility> // std::move
#include <vector> // std::vector

class Contact {
	public:
		Contact(std::string name, std::string phone)
			: name_{std::move(name)}, phone_{std::move(phone)} {}
		const std::string& name() const { return name_; }
		const std::string& phone() const { return phone_; }

	private:
		std::string name_;
		std::string phone_;
};

class AddressBook {
	public:
		void add(const std::string& name, const std::string& phone) {
			contacts_.emplace_back(name, phone);
		}

		const Contact* find(const std::string& name) const {
			for (const Contact& contact : contacts_) {
				if  (contact.name() == name) {
					return &contact;
				}
			}
			return nullptr; // precorreu tudo e não achou nada;
		}

		// retorna true se removeu e false se não achou.
		bool remove(const std::string& name) {
			for (std::size_t i = 0; i < contacts_.size(); ++i) {
				if (contacts_[i].name() == name) {
					contacts_.erase(contacts_.begin() + static_cast<std::ptrdiff_t>(i));
					return true;
				}
			}
			return false;
		}

		void list() const {
			if (contacts_.empty()) {
				std::cout <<  "\nA agenda está vazia.\n";
				return; // sai da função se a lista for vazia
			}

			for (const Contact& contact : contacts_) {
				std::cout << "================================ \n";
				std::cout << contact.name() << " - "
						  << contact.phone() << "\n";
				std::cout << "================================ \n";
			}
		}

	private:
		std::vector<Contact> contacts_;
};

void print_menu() {
	std::cout << "\n====== MENU =====\n";
	std::cout << "1) Adicionar\n"
			  << "2) Buscar\n"
			  << "3) Remover\n"
			  << "4) Listar\n"
			  << "0) Sair\n"
			  << "> ";
}

// função que mostra um prompt para o usuário e le a linha digitada;
std::string read_line(const std::string& prompt) {
	std::string text;
	std::cout << prompt;
	std::getline(std::cin, text);
	return text;
}

int main() {
	AddressBook book;
	int option{-1};

	while (option != 0)  {
		print_menu();

		if (!(std::cin >> option)) {
			if (std::cin.eof()) { // Ctrl+D não há mais o que ler
				std::cout << "\n=============\n"
						  << "Até logo!\n"
						  << "=============\n";
				break;
			}
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "\n==============================\n"
					  << "ERRO: Digite um número válido!\n"
					  << "==============================\n";
			option = -1;  // força a opção inválida;
			continue;
		}
		
		std::cin.ignore(1000, '\n'); // descarta o Enter que sobrou;

		switch (option)
		{
			case 0:
				std::cout << "\n=============\n"
						  << "Até logo!\n"
						  << "=============\n";
				break;
			case 1: {
				const std::string name{read_line("Nome: ")};
				const std::string phone{read_line("Telefone: ")};
	
				book.add(name, phone);
	
				std::cout << "\n====================\n"
						  << "Adicionado.\n"
						  << "====================\n";
				break;
			}
			case 2: {
				const std::string name{read_line("Buscar pelo nome: ")};
				const Contact* found{book.find(name)};
	
				if (found != nullptr) {
					std::cout << found->name() << " - "
							  << found->phone() << "\n\n";
				} else {
					std::cout << "Busca por" << name
							  << " não encontrou nenhum contato.\n\n";
				}
				break;
			}
			case 3: {
				const std::string name{read_line("Digite o nome: ")};
				if (book.remove(name)) {
					std::cout << "Removido.\n";
				} else {
					std::cout << "Não encontrado.\n";
				}
				break;
			}
			case 4:
				book.list();
				break;
			default:
				std::cout << "Opção inválida. \n";
				break;
		}
	}

	return  0;
}
