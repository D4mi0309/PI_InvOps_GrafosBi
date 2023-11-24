#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "libinvops.h"

#define NUMCURSOS 5
#define NUMSALAS 5

int main(int argc, char** argv) {

    //Creacion de cursos:
    Curso curso1 = {"Arquitectura de computadores",10,"Alvaro Salazar",2,10,11};
    Curso curso2 = {"Ambiente Web II",15,"Alvaro Salazar",2,3,5};
    Curso curso3 = {"Sistemas Operativos",25,"Wilmar Salgado",1,8,10};
    Curso curso4 = {"Investigacion de operaciones",27,"Giovanny Cruz",2,8,10};
    Curso curso5 = {"Analisis Numerico",35,"Efrain Vasquez",4,1,2};

    //Guardar cursos en un array tipo 'Curso':
    char CantCursos = NUMCURSOS;
    Curso * cursos;
    cursos = malloc(sizeof (Curso) *CantCursos); //Memory ALLOCation: Localizacion de memoria
    cursos[0] = curso1;
    cursos[1] = curso2;
    cursos[2] = curso3;
    cursos[3] = curso4;
    cursos[4] = curso5;

    //----------------------------------------------
    //Creacion de salas:
    Sala sala1 = {"Laboratorio A",10};
    Sala sala2 = {"Laboratorio B",20};
    Sala sala3 = {"Laboratorio C",30};
    Sala sala4 = {"Laboratorio D",30};
    Sala sala5 = {"Laboratorio E",40};

    //Guardar salas en un array tipo 'Sala':
    char CantSalas = NUMSALAS;
    Sala * salas;
    salas = malloc(sizeof (Sala) *CantSalas); //Memory ALLOCation: Localizacion de memoria
    salas[0] = sala1;
    salas[1] = sala2;
    salas[2] = sala3;
    salas[3] = sala4;
    salas[4] = sala5;

    //-----------------------------------------
    Grafo grafo;
    Grafo grafo2;
    Grafo grafo3;
    //----------METODO 1: assing_rooms----------
    grafo = crearGrafo(CantCursos, CantSalas);
    /* Prueba impresion de matriz
    printf("Creacion del grafo cursosXsalas:");
    for(int i = 0; i < CantCursos; i++){
        printf("\n");
        for(int j = 0; j < CantSalas; j++){
            printf(" %d",grafo.asignaciones[i][j]);
        }
    }
    printf("\n\n");
    */

    //-----------METODO 2: find_lab----------
    grafo2 = encontrarSala(grafo,cursos,salas,CantCursos,CantSalas);
    /* Prueba imprsion de matriz
    printf("Asignacion de salas CantEstdsXCapacidad:");
    for(int i = 0; i < CantCursos; i++){
        printf("\n");
        for(int j = 0; j < CantSalas; j++){
            printf(" %d",grafo.asignaciones[i][j]);
        }
    }
    printf("\n\n");
    */

    //---------METODO 3: remove_overlapping_blocks---------
    grafo3 = eliminarSuperposicion(grafo2,cursos,CantCursos,CantSalas);
    printf("\nCursos X Salas: ");
    for(int i = 0; i < CantCursos; i++){
        printf("\nCurso %d: ",i+1);
        for(int j = 0; j < CantSalas; j++){
            printf(" %d",grafo3.asignaciones[i][j]);
        }
    }
    printf("\n");

    //-------------METODO 4: select_blocks-------------
    Bloques blockT;
    blockT = bloquesTiempo(cursos,salas,CantCursos);
    printf("\nBloques horarios X Dia de la semana:");
    printf("\n           L M M J V S");
    for(int i = 0; i < 15; i++){
        printf("\nBlockH %2d:",i+1);
        for(int j = 0; j < 6; j++){
            printf(" %d",blockT.BloquesTiempo[i][j]);
        }
    }
    printf("\n");

    //Impresion de las asignaciones
    for(int i = 0; i < CantCursos; i++){
	for(int j = 0; j < CantSalas; j++){
            if(grafo3.asignaciones[i][j] == true){
                printf("\nEl curso %s esta asignado desde el bloque %d hasta el bloque %d el dia %d en el %s",cursos[i].NombreCurso,cursos[i].BloqueIn,cursos[i].BloqueFi,cursos[i].DiaSemana,salas[j].NombreSala);
	    }
        }
    }
    printf("\n\n");

    free(blockT.BloquesTiempo);
    free(grafo.asignaciones);
    free(cursos);
    free(salas);

    return (EXIT_SUCCESS);

}
