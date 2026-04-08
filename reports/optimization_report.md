# Reporte de Optimización y Sanitizers

## 1. Comparación de Builds (Benchmark N = 1,000,000)
| Build | Bandera | Tiempo de Ejecución | Tamaño del Ejecutable |
|---|---|---|---|
| Depuración | `-O0` | 0.110195 seg | 174 kb |
| Depurable | `-Og` | 0.0161558 seg | 143 kb |
| Release | `-O2` | 0.0060269 seg | 149 kb |
| Compacto | `-Os` | 0.0126084 seg | 141 kb |
