# Min Stack - Práctica Calificada 1 (CC232)

## 1. Información General
* **Integrantes:** Brian Jair La Torre Urbina y Oscar Alberto Pomalia Suyo
* **Problema Asignado:** Min Stack
* **Enlace LeetCode:** [Min Stack (Problem 155)](https://leetcode.com/problems/min-stack/description/)

## 2. Especificación del Problema
* **Descripción breve:** Diseñar una pila que soporte las operaciones clásicas (push, pop, top) y que además pueda recuperar el elemento mínimo (getMin) en tiempo constante.
* **Entrada:** Secuencia de instrucciones y valores enteros (val) dentro del rango de $[-2^{31}, 2^{31} - 1]$.
* **Salida:** Valores enteros solicitados por las funciones top() y getMin(). Retornos void para modificaciones.
* **Tamaño de entrada relevante ($n$):** Hasta $3 \times 10^4$ llamadas a funciones en total según restricciones.

## 3. Fundamentos del Algoritmo
### Descripción de la Solución
Nuestra implementación separa la *interfaz* de su *representación*. Internamente usamos dos pilas: main_stack para almacenar todos los valores y preservar el orden LIFO, y min_stack para rastrear los mínimos históricos.

### Justificación Lógica
* **Determinismo:** Dada una secuencia idéntica de operaciones push y pop, la estructura de memoria interna y los valores retornados serán siempre exactamente los mismos.
* **Factibilidad:** Las operaciones se basan en arreglos dinámicos subyacentes (std::stack), lo cual es completamente representable y operable dentro del modelo de costo *word-RAM*.
* **Finitud:** Ninguna de las operaciones (push, pop, top, getMin) contiene bucles de iteración dependientes de $n$. Todas constan de un número constante y finito de pasos, garantizando su terminación inmediata.

### Correctitud e Invariante de Representación
Para garantizar la correctitud formal, nuestro código mantiene el siguiente invariante después de cada operación:

> **"El tope de la pila min_stack siempre contiene el valor mínimo absoluto del conjunto de elementos actualmente presentes en main_stack."**

* **Al insertar (push):** Se inserta el valor en main_stack. Si min_stack está vacía o el valor es $\le$ al tope de min_stack, se empuja en min_stack.
* **Al eliminar (pop):** Se extrae el tope de main_stack. Si coincide con el tope de min_stack, el mínimo histórico acaba de ser eliminado, ejecutando un pop también en min_stack (revelando el mínimo anterior válido).
* **Monotonicidad:** Cada operación pop reduce de manera estricta el tamaño de la pila principal en exactamente 1 unidad. 

## 4. Análisis de Complejidad Asintótica
* **Complejidad Temporal:** $O(1)$ en todos los casos (mejor, peor y promedio) para todas las operaciones. El diseño realiza un número constante de evaluaciones condicionales y asignaciones por llamada.
* **Ubicación en la Jerarquía:** Orden constante ($O(1)$), la base más eficiente de la jerarquía de crecimiento.
* **Complejidad Espacial:** $O(n)$ en el peor de los casos (e.g., elementos insertados en estricto orden descendente requiriendo que min_stack escale al tamaño $n$).
* **Alternativa Ingenua:** Utilizar un solo arreglo LIFO y ejecutar un escaneo global cada vez que se llama a getMin(). Esto degeneraría la complejidad temporal a $O(n)$ por llamada, haciéndolo inviable para sistemas a gran escala.

## 5. Diseño y Estructura
* **Robustez y Degeneración:** El uso de tipos primitivos int maneja nativamente el rango requerido por LeetCode. Se incluyeron aserciones para evitar extracción en pilas vacías.
* **Reutilización:** El ADT expone una interfaz limpia y acoplada que puede ser consumida por otros módulos como cualquier contenedor de la STL.

## 6. Instrucciones de Uso
**Configuración y Compilación (CMake):**
bash
cmake -S . -B build
cmake --build build

**Ejecución de los programas:** Una vez compilados, los ejecutables se encontrarán en el directorio build/ (o build\Debug\ / build\Release\ en Windows).

- **Principal:** ./build/main
- **Tests:** ./build/tests (O ejecutar ctest dentro de la carpeta build)
- **Benchmark:** ./build/benchmark

## 7\. Reporte Experimental

### 7.1. Descripción del Benchmark

Se implementó un microexperimento en bench/benchmark.cpp midiendo el tiempo de ejecución mediante la librería <chrono>. La prueba somete a la estructura MinStack a una carga intensiva de $N=1,000,000$ de operaciones push(), seguidas de $N$ operaciones alternadas de getMin() y pop().

### 7.2. Tabla Resumida de Builds y Resultados

| Build | Bandera | Tiempo de Ejecución | Tamaño del Ejecutable |
| --- | --- | --- | --- |
| Depuración | -O0 | 0.110195 seg | 174 kb |
| Depurable | -Og | 0.0161558 seg | 143 kb |
| Release | -O2 | 0.0060269 seg | 149 kb |
| Compacto | -Os | 0.0126084 seg | 141 kb |

### 7.3. Microoptimización vs. Algoritmo

Los resultados del benchmark demuestran que, si bien compilar con -O2 (Release) logra que el programa sea aproximadamente 18 veces más rápido que con -O0 (Depuración) bajando el tiempo a $0.006$ segundos, esta mejora es mínima en comparación al impacto del algoritmo. Si hubiéramos optado por la alternativa ingenua (búsqueda lineal para hallar el mínimo), la complejidad de cada getMin() sería $O(n)$. Para $1,000,000$ de operaciones, esto resultaría en un costo temporal insostenible, independientemente de la bandera de optimización que usemos. El rediseño estructural usando la memoria auxiliar (min_stack) para lograr una complejidad $O(1)$ es lo que verdaderamente escala.

### 7.4. Resumen de Cobertura y Profiling

* **Cobertura (Coverage):** Nuestras pruebas en tests.cpp evalúan los flujos principales (inserción normal, valores repetidos, y extracción hasta vaciar la estructura), cubriendo el comportamiento general de la clase. El análisis con GCOV confirmó una cobertura de líneas del 100% sobre solution.cpp, alcanzando todas las ramas condicionales críticas (por ejemplo, cuando se evalúa si el nuevo valor es menor o igual al mínimo actual en la pila auxiliar).
* **Profiling (gprof):** Durante la evaluación de rendimiento, el análisis indicó que el tiempo de ejecución está fuertemente concentrado en la gestión interna de memoria del contenedor subyacente (std::stack y por ende std::deque de STL) al hacer las expansiones de memoria durante los millones de push(), coincidiendo con la naturaleza O(1) del cálculo lógico del algoritmo en sí.

### 7.5. Uso de Sanitizers

De acuerdo con las exigencias del bloque experimental, se compiló y ejecutó el proyecto activando las banderas de sanitización para memoria y comportamiento indefinido:
`g++ -std=c++17 -O1 -g -fsanitize=address,undefined tests/*.cpp src/*.cpp`

**Observaciones:**
Durante la ejecución de la batería de pruebas, no se reportó ninguna fuga de memoria (Memory Leak) asociada al ciclo de vida dinámico de los contenedores `std::stack`, ni se detectaron comportamientos indefinidos (Undefined Behavior) o accesos inválidos. Esto confirma empíricamente la robustez de las validaciones de límites y vaciado implementadas en la solución.

## 8. Uso de Herramientas de IA y Trabajo Colaborativo

* **Copilot:** Durante el desarrollo, se utilizó GitHub Copilot como asistente de escritura.
  * *Sugerencia aceptada:* Se aceptó el autocompletado para la estructura básica (boilerplate) del `CMakeLists.txt` y la inclusión de cabeceras en los archivos de prueba.
  * *Sugerencia rechazada:* Copilot sugirió una implementación de `getMin()` iterando sobre toda la pila principal. Esta sugerencia se rechazó inmediatamente porque corrompía la complejidad temporal, transformándola en orden lineal en lugar de mantenerla en orden constante mediante la pila auxiliar.
  * *Validación:* Toda sugerencia algorítmica fue revisada manualmente para asegurar que cumpliera con las restricciones asintóticas del problema.
* **Live Share:** Se utilizó para la codificación en pareja, alternando roles de conductor (quien escribe) y revisor (quien verifica la lógica y detecta errores en tiempo real).