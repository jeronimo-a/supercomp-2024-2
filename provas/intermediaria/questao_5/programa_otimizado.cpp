#include <chrono>
#include <iostream>
#include <unordered_map>

long fib(int n, std::unordered_map<int, long>& memory) {
    if (memory.find(n) != memory.end()) {
        return memory[n];
    }
    if (n <= 1) {
        return n;
    } else {
        long fib1 = fib(n - 1, memory);
        long fib2 = fib(n - 2, memory);
        memory[n - 1] = fib1;
        memory[n - 2] = fib2;
        return fib1 + fib2;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::unordered_map<int, long> memory;
    auto start = std::chrono::high_resolution_clock::now();
    long result = fib(n, memory);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Fibonacci de " << n << " é " << result << std::endl;
    std::cout << "Tempo de execução: " << duration.count() << " s" << std::endl;
    return 0;
}