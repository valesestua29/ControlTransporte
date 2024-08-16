# Proyecto Control de uso de transporte 

Este documento describe el funcionamiento del código C provisto, el cual realiza la lectura de datos desde archivos binarios, calcula promedios de viajes en subte y tren, y ofrece un menú interactivo para mostrar diferentes análisis relacionados con los datos.

## Librerías Utilizadas

- `#include <stdio.h>`: Proporciona funciones para realizar operaciones de entrada y salida, como imprimir en pantalla y leer datos del usuario.
- `#include <stdlib.h>`: Incluye funciones para la manipulación de memoria dinámica, control de procesos, conversiones y manejo de archivos.

## Función Principal

### Lectura de Datos desde Archivos

El programa comienza leyendo datos de dos archivos binarios:
- **Archivo 1: `subte_ene-jun.dat`**
- **Archivo 2: `tren_ene-jun.dat`**

Cada archivo contiene datos sobre la cantidad de viajes en subte y tren, respectivamente, durante un periodo de 182 días.

### Cálculo de Promedios

El programa calcula los promedios de viajes en subte y tren tanto para el periodo pre-pandemia como post-pandemia. Estos promedios se almacenan en dos nuevos archivos:
- **Archivo 3: `cambioscovidsubte.dat`**
- **Archivo 4: `cambioscovidtren.dat`**

### Análisis de Datos

El programa realiza varios análisis sobre los datos leídos:
- **Promedio de Viajes:** Se calcula tanto para el subte como para el tren, diferenciando entre el periodo pre-pandemia y post-pandemia.
- **Porcentaje Diario Subte-Tren:** Se calcula el porcentaje de viajes diarios para ambos medios de transporte en cada mes.
- **Días de Alta Ocupación en Trenes:** Se identifica la cantidad de días en que la ocupación de los trenes superó el promedio pre-pandemia.
- **Mínima Cantidad de Pasajeros:** Se determina el día en que se registró la menor cantidad de pasajeros tanto en subte como en tren.

### Menú Interactivo

El programa presenta un menú interactivo que permite al usuario elegir entre las diferentes opciones de análisis:

1. **Promedio de Viajes en Subte o Tren**
2. **Porcentaje Diario Subte-Tren**
3. **Días de Alta Ocupación en Trenes**
4. **Mínima Cantidad de Pasajeros en Subte o Tren**
5. **Salir**

Cada opción dentro del menú permite visualizar los resultados calculados previamente, y el usuario puede navegar entre las opciones hasta que decida salir del programa.

## Consideraciones

- **Manejo de Errores:** El código implementa manejo de errores para la apertura, lectura y cierre de archivos, asegurando que cualquier problema en estas operaciones sea notificado al usuario.
- **Optimización:** Algunas partes del código, como la lectura de archivos y el cálculo de promedios, podrían optimizarse para mejorar la eficiencia y reducir la redundancia.

## Conclusión

Este código es útil para analizar y comparar datos de ocupación en subte y tren durante un periodo específico, ofreciendo una herramienta simple pero eficaz para estudiar el impacto de la pandemia en el transporte público.
