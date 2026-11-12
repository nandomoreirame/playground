#include <iostream>
#include <string> // std::string
#include <utility> // std::move

class Contract {
	public:
		Contract(std::string name, std::string phone)
			: name_{std::move(name)}, phone_{std::move(phone)} {}
		const std::string& name() const { return name_; }
		const std::string& phone() const { return phone_; }

	private:
		std::string name_;
		std::string phone_;
};

int main() {
	Contract ana{"Ana Souza", "1192922-0022"};
	std::cout << ana.name() << "\n" << ana.phone() << "\n";
	return  0;
}
