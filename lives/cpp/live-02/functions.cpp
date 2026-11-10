#include <iostream>

int square(int n) {
	return n * n;
}

int main () {
	for (int i = 1; i <= 5; ++i) {
		std::cout << i << " ao quadrado é " << square(i) << "\n \n";
	}
}
