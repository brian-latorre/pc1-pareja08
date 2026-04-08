# Reporte de Cobertura - PC1
**Elaborado por:** Oscar Alberto Pomalia Suyo y Brian Jair La Torre Urbina
## 1. Generación del Reporte
[cite_start]Para medir la cobertura de nuestras pruebas, compilamos el proyecto utilizando el comando sugerido por la cátedra, desactivando las optimizaciones (`-O0`) para que GCOV pueda mapear correctamente las líneas:
```bash
g++ -std=c++17 --coverage -O0 tests/tests.cpp src/solution.cpp -o run_tests
./run_tests
gcov src/solution.cpp