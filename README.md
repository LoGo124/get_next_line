*Este proyecto ha sido creado como parte del currículo de 42 por ilopez-g*

## Descripción

get_next_line es una función en C diseñada para leer un descriptor de archivo (file descriptor) línea por línea. Su objetivo principal es proporcionar una manera eficiente y cómoda de leer archivos de texto o entrada estándar (stdin), devolviendo cada línea terminada en \n (excepto la última si el archivo no termina con salto de línea). El proyecto introduce el uso de variables estáticas en C, permitiendo que la función "recuerde" el estado de la lectura entre llamadas consecutivas, sin necesidad de usar variables globales. La versión bonus permite gestionar múltiples descriptores de archivo a la vez mediante un array de variables estáticas.

## Instrucciones

El proyecto debe compilarse con las flags -Wall, -Werror, -Wextra y definiendo el tamaño del buffer (BUFFER_SIZE):
```
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```
Para la parte bonus (soporte multi-fd):
```
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```
Si no se define BUFFER_SIZE, por defecto se usa el valor 9999. Para usar la función, incluye el header correspondiente:
```c
#include "get_next_line.h"          // Parte obligatoria
#include "get_next_line_bonus.h"    // Parte bonus (multi-fd)
```
Ejemplo de uso:
```c
int fd1 = open("archivo1.txt", O_RDONLY);
int fd2 = open("archivo2.txt", O_RDONLY);
char *line1, *line2;

line1 = get_next_line(fd1);
line2 = get_next_line(fd2);
while (line1 || line2)
{
    if (line1) { printf("%s", line1); free(line1); line1 = get_next_line(fd1); }
    if (line2) { printf("%s", line2); free(line2); line2 = get_next_line(fd2); }
}
close(fd1);
close(fd2);
```
## Recursos

- Manual de read()
- Variables estáticas en C
- File descriptors en Unix
- Subject oficial del proyecto Get Next Line

Durante el desarrollo de este proyecto, se ha utilizado IA para generar este README.md unicamente.

## Algoritmo y decisiones técnicas

El algoritmo se basa en una variable estática que preserva el resto de la línea no devuelta entre llamadas. En la versión bonus, se utiliza un array static char *saved[4096] donde cada índice corresponde a un file descriptor.

Flujo de ejecución:
1. Validación de fd, BUFFER_SIZE y legibilidad mediante read(fd, 0, 0)
2. Inicialización del estático con ft_strdup("") si es la primera llamada
3. Lectura con read() en bloques de tamaño BUFFER_SIZE hasta encontrar \n o EOF
4. Extracción de la línea desde el inicio hasta \n (o hasta el final)
5. Guardado del resto (después del \n) en la variable estática para la siguiente llamada
6. Liberación de memoria y devolución de la línea

Decisiones clave:
- Se utiliza read(fd, 0, 0) para validar el FD sin consumir datos
- La función extract_nline extrae el resto después de \n y libera la cadena original
- Se usa join_and_free para concatenar y liberar automáticamente el buffer anterior
- El array de 4096 posiciones en bonus soporta el máximo típico de FDs del sistema
