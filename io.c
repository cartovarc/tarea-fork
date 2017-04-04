#include "fileutil.h"
#include <string.h>
#include <stdlib.h> //malloc
#include <stdio.h>

int main(int argc, char ** argv) {

	int cantidadArchivos = countFiles(argv[1]); // cantidad de archivos de la carpeta que recibimos
	char ** listaArchivos = getFileList(argv[1]); // lista con todos los nombres de los archivos
	long long total = 0; // acumulador del peso de cada archivo

	//recorremos cada archivo de la carpeta que recibimos
	for(int i=0; i<cantidadArchivos; i++){
		char * ruta = (char *) malloc(  sizeof(char)*strlen(argv[1]) + sizeof(char)*strlen(listaArchivos[i]) + sizeof("/") );
		strcpy(ruta, argv[1]);
		strcat(ruta, "/");
		strcat(ruta, listaArchivos[i]);
		total += (long long) filesize(ruta);
	}

	printf("Estudiante_1: 201530267\n");
	printf("Estudiante_2: 201527471\n");
	printf("Total archivos: %d\n", cantidadArchivos);
	printf("Total bytes: %lld bytes", total);
}
