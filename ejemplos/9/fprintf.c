#include <stdio.h>
#include <stdlib.h>

void genera_mensaje(FILE *file)
{
	int linea = 0;

	while (linea < 6) {
		fprintf(file, "Linea %d: Mensaje de prueba\n", linea); // comprobar que el valor de devolucion no sea menor que cero
		linea++;
	}
	rewind(file);
}

int main (void)
{
	FILE *file = fopen("datos.dat", "a+");
	char *code;
	size_t n = 0;
	int c;

	if (file == NULL)
		return -1;

	genera_mensaje(file);

//comprobar que el malloc no retorna error
//tamaño del malloc debe ser 100
	code = malloc(101);
	while(fgets(code, 100, file)) {
		printf("%s", code);
	}

	free(code);
	return 0;

//hacer el fclose y cerrar
}
