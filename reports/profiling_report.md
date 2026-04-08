# Reporte de Profiling (gprof)

## 1. Configuración de Ejecución
Se generó el análisis de rendimiento utilizando la herramienta gprof. Para ello, el código se compiló con la bandera de optimización -O2 y la bandera de profiling -pg:

```
g++ -std=c++17 -O2 -pg src/solution.cpp bench/benchmark.cpp -o build/profiling_test.exe
./build/profiling_test.exe
gprof build/profiling_test.exe gmon.out > reports/gprof_results.txt
```

## 2\. Análisis de Resultados (Hotspots)

Al analizar el reporte plano generado por gprof tras ejecutar 1,000,000 de operaciones de prueba, se observó lo siguiente:

- **Ausencia de cuellos de botella algorítmicos:** No existen funciones de nuestro código que acumulen un tiempo de ejecución desproporcionado debido a ciclos o iteraciones. Esto coincide perfectamente con nuestro análisis teórico de complejidad $O(1)$ para todas las operaciones (push, pop, top, getMin).
- **Concentración del tiempo:** El tiempo de ejecución se concentra en las operaciones internas de la Standard Template Library (STL), específicamente en funciones de reserva de memoria como std::deque::_M_reallocate_map (que es el contenedor subyacente de std::stack). Esto ocurre al asignar y liberar nodos para un millón de elementos.

## 3\. Conclusión

El profiling confirma que la lógica de nuestro algoritmo es óptima. El "overhead" (costo principal) del programa no radica en cómo calculamos el mínimo, sino en el manejo dinámico de memoria a nivel del sistema operativo. Una potencial microoptimización futura (aunque fuera del alcance necesario de este problema) sería usar un contenedor subyacente diferente que permita usar reserve() para evitar realojamientos de memoria, pero la idea algorítmica actual ya cumple con la máxima eficiencia teórica posible $O(1)$.