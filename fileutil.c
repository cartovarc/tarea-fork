#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

//Funcion que permite dado un directorio ubicacion, calcular el tamaño de un archivo en bytes
int filesize(char * fileLocation) {

        // Definicion e inicializacion de variables
        FILE *fp;
        int count = 0;

        // Se abre el archivo y se contara caracter por caracter el numero
        // de bytes del archivo
        fp = fopen(fileLocation,"r");
        if (fp == NULL) {
                printf("filesize - No se pudo abrir archivo %s \n", fileLocation);
                return -1;
        }
        while (fgetc(fp) != EOF) {
                count++;

        }
        fclose(fp);
        return count;
}


//Funcion que permite contar la cantidad de archivos que hay en un directorio
int countFiles(char * location){
	DIR * directorio; // creamos el directorio
	struct dirent * ent; 
	int contador=0; // contador de archivos que hay en el directorio

	directorio = opendir (location); //Obtenemos la ruta desde argv

	//Si el directorio se pudo abrir
	if (directorio != NULL){
		while(ent = readdir(directorio)){
			//Sacamos un elemento del directorio
			if(ent->d_type == DT_REG){ //Comprobamos que archivo regular
				contador++;
			}
		}

		return contador; //devolvemos la cantidad de archivos
	}else{
		return 1; // Notificamos que el programa arrojo un error
	}
}


//funcion que permite obtener una lista de nombres de archivos dado una ubicacion
char ** getFileList(char * location){
	DIR * directorio;
	struct dirent * ent;

	directorio = opendir (location); //Obtenemos la ruta desde argv

	//Si el directorio se pudo abrir
	if (directorio != NULL){
		int contador = countFiles(location); // contamos cuantos archivos hay en la carpeta
		directorio = opendir (location); //Obtenemos la ruta desde argv

		char ** m = (char**)malloc(sizeof(char*)*contador); //lista de nombres de archivos
		int iteradorFilas = 0;
		while(ent = readdir(directorio)){
			//Sacamos un elemento del directorio
			if(ent->d_type == DT_REG){ //Comprobamos que archivo regular
				char * nombreArchivo = (char*)malloc(sizeof(char)*sizeof(ent->d_name));
				strcpy(nombreArchivo, ent->d_name);
				m[iteradorFilas] = nombreArchivo;
				iteradorFilas++; //Cambiamos de fila

			}

		}

		(void) closedir (directorio);
		return m;

	}else{
		return 1; // Notificamos que el programa arrojo un error
	}
}
