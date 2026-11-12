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
				std::cout <<  "A agenda está vazia.\n";
				return; // sai da função se a lista for vazia
			}

			for (const Contact& contact : contacts_) {
				std::cout << "================================ \n";
				std::cout << "Nome: " << contact.name() << "\n";
				std::cout << "Telefone: " << contact.phone() << "\n";
				std::cout << "================================ \n\n";
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
			std::cout << "====== 1 =====\n\n";
			if (std::cin.eof()) { // Ctrl+D não há mais o que ler
			std::cout << "====== 2 =====\n\n";
				break;
			}
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			option = -1;  // força a opção inválida;
			// std::cout << "\n" << "Entrada errada. \n";
			// break;
		} else {
			std::cin.ignore(1000, '\n'); // descarta o Enter que sobrou;
		}

		// std::cout << "====== 4 =====";
		// std::cin.ignore(1000, '\n');

		if (option == 1) { // adicionar
			const std::string name{read_line("Nome: ")};
			const std::string phone{read_line("Telefone: ")};

			book.add(name, phone);

			std::cout << "\n====================\n"
					  << "Adicionado.\n"
					  << "====================\n";

		} else if (option == 2) { // Buscar
			const std::string name{read_line("Buscar pelo nome: ")};
			const Contact* found{book.find(name)};

			if (found != nullptr) {
				std::cout << found->name() << " - "
						  << found->phone() << "\n\n";
			} else {
				std::cout << "Busca por" << name
						  << " não encontrou nenhum contato.\n\n";
			}
		} else if (option == 0) {
			std::cout << "Até a próxima!\n";
		} else {
			std::cout << "Opção inválida. \n";
		}
	}

//
// 	book.add("Ana Souza", "1192922-0022");
// 	book.add("Bruno Lima", "113333-3332");
// 	book.add("Fernando Moreira", "113233-7777");
// 	book.list();
//
// 	const Contact* found = book.find("Fernando Moreira");
// 	if (found != nullptr) {
// 		std::cout << "Contato encontrado: \n"
// 				  << found->name() << " - "  << found->phone()  << "\n";
// 	}
// 	if (book.find("Carlos") == nullptr) {
// 		std::cout << "Carlos não foi encontrado.  \n";
// 	}
//
// 	std::cout << "Remover Bruno: " <<  book.remove("Bruno Lima") << "\n";
// 	std::cout << "Remover Ana: " <<  book.remove("Ana Souza") << "\n";
// 	std::cout << "Remover Bruno de novo: " <<  book.remove("Bruno Lima") << "\n";
// 	book.list();

	return  0;
}
