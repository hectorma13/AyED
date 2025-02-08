# AyED
Public repository with all the problems I have done for the Algorithms and Data Structures (AyED) course.

# Problemas de examen resueltos I

## Problema 1

### Enunciado

Construir una función que devuelva el [producto escalar](https://es.wikipedia.org/wiki/Producto_escalar) de dos vectores. La cabecera de la función debe ser:

```cpp
int scal_prod(int v1[], int v2[], int sz)
```

Elabora además, un programa principal en el que se inicialicen dos vectores `v1` y `v2` con números aleatorios con valores comprendidos entre -50 y 50, y efectúe el producto escalar entre ambos.

> Mi solución: [problema1.cc](https://github.com/hectorma13/AyED/blob/main/problemas_examen_1/problema1.cc)

## Problema 2

### Enunciado

Diseñar e implementar una función que devuelva el número de ocurrencias de un elemento `val` dentro de un vector de tipo `double`, con una precisión `tol`.
La cabecera del procedimiento debe ser

```cpp
int count_eq(double v[], int sz, double val, double tol)
```

> Mi solución: [problema2.cc](https://github.com/hectorma13/AyED/blob/main/problemas_examen_1/problema2.cc)

## Problema 3

### Enunciado

1. Diséñese e impleméntese una función que cuente el número de elementos menores que el valor `val` dentro de un vector `double` con una tolerancial `tol`.
2. Diséñese e impleméntese una función que cuente el número de elementos mayores que el valor `val` dentro de un vector `double` con una tolerancial `tol`.

La cabecera de los procedimientos debería ser:

```cpp
int count_less(double v[], int sz, double val, double tol)
int count_great(double v[], int sz, double val, double tol)
```

> Mi solución: [problema3.cc](https://github.com/hectorma13/AyED/blob/main/problemas_examen_1/problema3.cc)

## Problema 4

### Enunciado

1. Diseñar e implementar una función que sume todos los elementos de un vector `int`.
2. Diseñar e implementar una función de cuente el número de elementos pares que hay dentro de un vector `int`.
3. Diseñar e implementar una función de cuente el número de elementos impares que hay dentro de un vector `int`.

Las cabeceras debería ser de la siguiente manera:

```cpp
int suma(int v[], int sz)
int cont_pair(int v[], int sz)
int cont_odd(int v[], int sz)
```
> Mi solución: [problema4.cc](https://github.com/hectorma13/AyED/blob/main/problemas_examen_1/problema4.cc)

# Problemas de examen resueltos II

## Problema 1

### Enunciado

Construir una clase `point_t` que represente un punto en el plano euclídeo en dos dimensiones. Esta clase debe estar caracterizada por las coordenadas del punto. Constrúyase asimismo una clase `line_eq_t` que represente una [recta](https://es.wikipedia.org/wiki/Recta) en el plano euclídeo, caracterizada por la pendiente y la ordenada al origen. Ambas clases deben tener sendos métodos que calculen la distancia euclídea desde un punto a la respectiva estructura. Es decir, la clase `point_t` debe tener un método que devuelva la [distancia](https://es.wikipedia.org/wiki/Distancia_euclidiana) del punto invocante al punto que se pasa como mensaje, y la clase `line_eq_t` debe tener un método que devuelva la [distancia](https://es.wikipedia.org/wiki/Distancia_de_un_punto_a_una_recta) de la recta invocante al punto que se pasa como mensaje.

> Mi solución: [Multiple files](https://github.com/hectorma13/AyED/blob/main/problemas_examen_2/prob1)
