#include <iostream>
#include <stdexcept>

int main() {
    setlocale(LC_ALL, "Russian");

    const int size = 10;
    int arr[size];

    std::cout << "Введите " << size << " элементов массива:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Элемент " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    try {
        // Взятие указателя на первый элемент массива
        int* ptr = &arr[0];

        if (ptr < &arr[0] || ptr > &arr[9]) {
            throw std::out_of_range("Указатель находится за пределами массива");
        }

        int fourthElement = *(ptr + 3); // Также можно использовать ptr[3]

        std::cout << "Четвертый элемент массива: " << fourthElement << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}