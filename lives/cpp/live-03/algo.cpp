#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
	std::vector<double> values{3, 1, 4, 1, 5};

	const double sum = std::accumulate(values.begin(), values.end(), 0.0);
	const double smallest = *std::min_element(values.begin(), values.end());
	const double largest = *std::max_element(values.begin(), values.end());

	std::cout << "soma=" << sum << "\n";
	std::cout << "menor=" << smallest << "\n";
	std::cout << "maior=" << largest << "\n";

	std::sort(values.begin(), values.end());

	std::cout << "Ordenando:\n";
	for (const double value : values) {
		std::cout << " " << value;
	}
	std::cout << "\n";
	
	return 0;
}
