#include <chrono>
#include <iostream>
#include <unordered_map>

long fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n;
    std::cin >> n;
    auto start = std::chrono::high_resolution_clock::now();
    long result = fib(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Fibonacci de " << n << " é " << result << std::endl;
    std::cout << "Tempo de execução: " << duration.count() << " s" << std::endl;
    return 0;
}