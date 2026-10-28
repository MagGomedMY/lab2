#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Функция repeat: повторяет вектор v n раз
std::vector<int> repeat(const std::vector<int>& v, int n) {
    std::vector<int> result;
    result.reserve(v.size() * n);
    for (int i = 0; i < n; ++i) {
        result.insert(result.end(), v.begin(), v.end());
    }
    return result;
}

// Последняя цифра числа
int lastDigit(int x) {
    return std::abs(x) % 10;
}

// Предпоследняя цифра числа
int preLastDigit(int x) {
    return (std::abs(x) / 10) % 10;
}

int main() {
    int n;
    std::cout << "Введите количество элементов исходного вектора: ";
    std::cin >> n;

    std::vector<int> v(n);
    std::cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    int k;
    std::cout << "Введите число повторений k: ";
    std::cin >> k;

    // Получаем последовательность (вектор, повторённый k раз)
    std::vector<int> seq = repeat(v, k);

    // 1. Среднее арифметическое всех элементов
    double sum = 0;
    for (int x : seq) sum += x;
    double avg = sum / seq.size();
    double avgSq = avg * avg;

    // 2. Отбираем элементы, у которых две последние цифры одинаковы
    std::vector<int> filtered;
    for (int x : seq) {
        int last = lastDigit(x);
        int preLast = preLastDigit(x);
        if (last == preLast) {
            filtered.push_back(x);
        }
    }

    // 3. Ищем пары
    long long pairCount = 0;
    long long maxSumSq = -1;

    for (size_t i = 0; i < seq.size(); ++i) {
        for (size_t j = i + 1; j < seq.size(); ++j) {
            int a = seq[i];
            int b = seq[j];

            // Условие 1: последняя цифра одного = предпоследней цифре другого
            bool cond1 = (lastDigit(a) == preLastDigit(b)) ||
                         (lastDigit(b) == preLastDigit(a));

            // Условие 2: ровно один делится на 11
            bool divA = (a % 11 == 0);
            bool divB = (b % 11 == 0);
            bool cond2 = (divA != divB);

            // Условие 3: сумма квадратов >= квадрата среднего арифметического
            long long sumSq = 1LL * a * a + 1LL * b * b;
            bool cond3 = (sumSq >= avgSq);

            if (cond1 && cond2 && cond3) {
                pairCount++;
                if (sumSq > maxSumSq) maxSumSq = sumSq;
            }
        }
    }

    std::cout << pairCount << " " << maxSumSq << std::endl;

    return 0;
}
