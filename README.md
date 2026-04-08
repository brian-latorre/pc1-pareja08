# Min Stack - Práctica Calificada 1 (CC232)

## 1. Información General
* **Integrantes:** Brian Jair La Torre Urbina y Oscar Alberto Pomalia Suyo
* **Problema Asignado:** Min Stack
* **Enlace LeetCode:** [Min Stack (Problem 155)](https://leetcode.com/problems/min-stack/description/)

## 2. Especificación del Problema
* **Descripción breve:** Diseñar una pila que soporte las operaciones clásicas (`push`, `pop`, `top`) y que además pueda recuperar el elemento mínimo (`getMin`) en tiempo constante.
* **Entrada:** Secuencia de instrucciones y valores enteros (`val`) dentro del rango de $[-2^{31}, 2^{31} - 1]$.
* **Salida:** Valores enteros solicitados por las funciones `top()` y `getMin()`. Retornos `void` para modificaciones.
* **Tamaño de entrada relevante ($n$):** Hasta $3 \times 10^4$ llamadas a funciones en total según restricciones.

## 3. Fundamentos del Algoritmo
### Descripción de la Solución
Nuestra implementación separa la *interfaz* de su *representación*. Internamente usamos dos pilas: `main_stack` para almacenar todos los valores y preservar el orden LIFO, y `min_stack` para rastrear los mínimos históricos.

### Justificación Lógica
* **Determinismo:** Dada una secuencia idéntica de operaciones `push` y `pop`, la estructura de memoria interna y los valores retornados serán siempre exactamente los mismos.
* **Factibilidad:** Las operaciones se basan en arreglos dinámicos subyacentes (`std::stack`), lo cual es completamente representable y operable dentro del modelo de costo *word-RAM*.
* **Finitud:** Ninguna de las operaciones (`push`, `pop`, `top`, `getMin`) contiene bucles de iteración dependientes de $n$. Todas constan de un número constante y finito de pasos, garantizando su terminación inmediata.

### Correctitud e Invariante de Representación
Para garantizar la correctitud formal, nuestro código mantiene el siguiente invariante después de cada operación:

> **"El tope de la pila `min_stack` siempre contiene el valor mínimo absoluto del conjunto de elementos actualmente presentes en `main_stack`."**

* **Al insertar (`push`):** Se inserta el valor en `main_stack`. Si `min_stack` está vacía o el valor es $\le$ al tope de `min_stack`, se empuja en `min_stack`.
* **Al eliminar (`pop`):** Se extrae el tope de `main_stack`. Si coincide con el tope de `min_stack`, el mínimo histórico acaba de ser eliminado, ejecutando un `pop` también en `min_stack` (revelando el mínimo anterior válido).
* **Monotonicidad:** Cada operación `pop` reduce de manera estricta el tamaño de la pila principal en exactamente 1 unidad. 

## 4. Análisis de Complejidad Asintótica
* **Complejidad Temporal:** $O(1)$ en todos los casos (mejor, peor y promedio) para todas las operaciones. El diseño realiza un número constante de evaluaciones condicionales y asignaciones por llamada.
* **Ubicación en la Jerarquía:** Orden constante ($O(1)$), la base más eficiente de la jerarquía de crecimiento.
* **Complejidad Espacial:** $O(n)$ en el peor de los casos (e.g., elementos insertados en estricto orden descendente requiriendo que `min_stack` escale al tamaño $n$).
* **Alternativa Ingenua:** Utilizar un solo arreglo LIFO y ejecutar un escaneo global cada vez que se llama a `getMin()`. Esto degeneraría la complejidad temporal a $O(n)$ por llamada, haciéndolo inviable para sistemas a gran escala.

## 5. Diseño y Estructura
* **Robustez y Degeneración:** El uso de tipos primitivos `int` maneja nativamente el rango requerido por LeetCode. Se incluyeron aserciones para evitar extracción en pilas vacías.
* **Reutilización:** El ADT expone una interfaz limpia y acoplada que puede ser consumida por otros módulos como cualquier contenedor de la STL.

## 6. Instrucciones de Uso
**Configuración y Compilación (CMake):**
```bash
cmake -S . -B build
cmake --build build