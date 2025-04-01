# Polinomios con listas enlazadas

## Objetivo

La práctica consiste en el desarrollo de la clase **SllPolynomial** para poder trabajar con **Polinomios**. Será una clase heredera de la clase `sll_t` que almacena polinomios en listas simplemente enlazadas, a la que habrá que incorporarle un **constructor adecuado** para generar los objetos desde vectores densos. Los polinomios almacenará solo sus monomios con coeficientes distintos de cero, como nodos de la lista con el campo de datos conteniendo pares (`pair_t<double>`), en los que los **pares tienen dos elementos**: el **índice del elemento indicará el grado del monomio**, y su **valor correspondiente indicará el coeficiente** de dicho monomio. Se propondrá también el desarrollo de un **método para la evaluación de un polinomio en un valor x dado**, para **comparar si dos polinomios son iguales** y para **sumar al polinomio invocante otro polinomio**.

Todo el código nuevo a desarrollar ha de ceñirse a la [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
