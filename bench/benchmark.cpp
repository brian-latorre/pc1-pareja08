#include <iostream>
#include <chrono>
#include <vector>
#include "../src/solution.hpp"

/**
 * Experimento simple para observar el rendimiento de MinStaack
 * tal como lo solicita la sección 7.5 de la guía de la PC1.
 */
int main() {
    MinStack s;
    const int N = 1000000; // 1 millón de operaciones

    std::cout << "Iniciando benchmark para " << N << " operaciones..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        s.push(i);
    }
    for (int i = 0; i < N; ++i) {
        s.getMin();
        s.pop();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    std::cout << "Tiempo total para " << N << " operaciones: " << diff.count() << " segundos." << std::endl;
    std::cout << "Operaciones por segundo: " << (N * 2) / diff.count() << std::endl;

    return 0;
}