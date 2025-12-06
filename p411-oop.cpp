#include <iostream>
#include <array>

template <typename T>
T solveLinear(T a, T b) {
	if (a == T(0)) return -b;
	return -b / a;
}

template <typename T>
struct QuadraticRoots {
	std::array<T, 2> roots;
	int count;
};

template <typename T>
QuadraticRoots<T> solveQuadratic(T a, T b, T c) {
	QuadraticRoots<T> result;
	result.roots = { T(0), T(0) };
	result.count = 0;

	if (a == T(0)) {
		result.roots[0] = solveLinear(b, c);
		result.count = 1;
		return result;
	}

	T discriminant = b * b - 4 * a * c;

	if (discriminant > T(0)) {
		result.roots[0] = (-b + std::sqrt(discriminant)) / (2 * a);
		result.roots[1] = (-b - std::sqrt(discriminant)) / (2 * a);
		result.count = 2;
	}
	else if (discriminant == T(0)) {
		result.roots[0] = -b / (2 * a);
		result.count = 1;
	}
	else {
		result.count = 0;
	}

	return result;
}

template <typename T>
void printRoots(QuadraticRoots<T>& result) {
	if (result.count == 0) {
		std::cout << "Not found roots" << std::endl;
	}
	else if (result.count == 2) {
		std::cout << "Two roots: "
			<< "x1 = " << result.roots[0] << " " << "x2 = " << result.roots[1] << std::endl;
	}
	else {
		std::cout << "One root: "
			<< "x = " << result.roots[0] << std::endl;
	}
}

int main()
{
	// 2x + 4 = 0
	std::cout << "Linear: " << solveLinear(2, 4) << std::endl; // -2

	// x^2 - 5x + 6 = 0
	QuadraticRoots<int> roots = solveQuadratic(1, -5, 6);
	printRoots(roots);

	// x^2 - 2x + 1 = 0
	QuadraticRoots<int> roots1 = solveQuadratic(1, -2, 1);
	printRoots(roots1);

	// x^2 + 1 = 0
	QuadraticRoots<int> roots2 = solveQuadratic(1, 0, 1);
	printRoots(roots2);
}
