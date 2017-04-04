#include "fileutil.h"
#include <string.h>
#include <stdlib.h> //malloc
#include <stdio.h>

int main(int argc, char ** argv) {

	int pid;
	int fd[2];

	int cantidadArchivos = countFiles(argv[1]);
	char ** listaArchivos = getFileList(argv[1]);
	
	pipe(fd);
	if ((pid = fork())) {
		long long totalPadre = 0;
		long long totalHijo = 0;
		close(fd[1]);
		for (int i = 0; i < (cantidadArchivos/2); i++){
			char * ruta = (char *) malloc(  sizeof(char)*strlen(argv[1]) + sizeof(char)*strlen(listaArchivos[i]) + sizeof("/") );
		strcpy(ruta, argv[1]);
		strcat(ruta, "/");
		strcat(ruta, listaArchivos[i]);
			totalPadre += filesize(ruta);
		}

		read(fd[0],&totalHijo,sizeof(totalHijo));

		printf("Estudiante_1: 201530267\n");
		printf("Estudiante_2: 201527471\n");
		printf("Total archivos: %d\n", cantidadArchivos);
		printf("Total bytes: %lld bytes", totalPadre + totalHijo);

	} else {
		close(fd[0]);
		long long totalHijo = 0;
		for (int i = (cantidadArchivos/2); i <cantidadArchivos; i++){
			char * ruta = (char *) malloc(  sizeof(char)*strlen(argv[1]) + sizeof(char)*strlen(listaArchivos[i]) + sizeof("/") );
		strcpy(ruta, argv[1]);
		strcat(ruta, "/");
		strcat(ruta, listaArchivos[i]);
			totalHijo += filesize(ruta);
		}

		write(fd[1],&totalHijo,sizeof(totalHijo));
	}

}
