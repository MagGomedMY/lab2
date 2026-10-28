#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cout << "Введите n: ";
    std::cin >> n;

    std::vector<int> v(n);
    std::cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    // Поиск min и max через итераторы
    std::vector<int>::iterator minIt = v.begin();
    std::vector<int>::iterator maxIt = v.begin();

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        if (*it < *minIt) minIt = it;
        if (*it > *maxIt) maxIt = it;
    }

    // Меняем местами значения по итераторам
    std::swap(*minIt, *maxIt);

    std::cout << "Изменённый вектор: ";
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
