#include <iostream>

template <typename T>

double average(T array[], int size) {
    if (size == 0) return 0.0;

    T sum = T(0);

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return static_cast<double>(sum) / size;
}

int main()
{
    int arrayInt[] = { 1, 2, 3, 5 };
    int arrayDouble[] = { 1.1, 1.2, 1.3, 5 };

    std::cout << average(arrayInt, 4) << std::endl;
    std::cout << average(arrayDouble, 4) << std::endl;
}
