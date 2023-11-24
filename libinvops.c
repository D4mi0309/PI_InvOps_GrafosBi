#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "libinvops.h"

Grafo crearGrafo(char CantCursos, char CantSalas){
    Grafo grafo;
    grafo.asignaciones = (bool **)malloc(CantCursos * sizeof(bool *));
    // Inicializar la matriz de adyacencia con todas las aristas como no asignadas
    for (int i = 0; i < CantCursos; i++) {
        grafo.asignaciones[i] = (bool *)malloc(CantSalas * sizeof(bool));
        for (int j = 0; j < CantSalas; j++) {
            grafo.asignaciones[i][j] = false;
        }
    }
    return grafo;
}

Grafo encontrarSala(Grafo grafo,Curso cursos[],Sala salas[],char CantCursos, char CantSalas){

    for(int i = 0; i < CantCursos; i++){       //Iterar sobre cursos
        bool asignacion = false;
        for(int j = 0; j < CantSalas; j++){   //Iterar sobre salas
            if(asignacion == false){
                if(cursos[i].CantidadEstudiantes <= salas[j].Capacidad){
                        grafo.asignaciones[i][j] = true;
                        asignacion = true;
                }
            }
        }
    }
    return grafo;
}

Bloques bloquesTiempo(Curso cursos[],Sala salas[],char CantCursos){
    Bloques block;
    //Grafo grafo;
    block.BloquesTiempo = (bool **)malloc(15 * sizeof(bool *));
    // Inicializar la matriz con 0 en todos los bloques
    for (int i = 0; i < 15; i++) {
        block.BloquesTiempo[i] = (bool *)malloc(6 * sizeof(bool));
        for (int j = 0; j < 6; j++) {
            block.BloquesTiempo[i][j] = false;
        }
    }
    for(int i = 0; i < CantCursos; i++){   //Iterar sobre cursos
        for(int j = cursos[i].BloqueIn; j <= cursos[i].BloqueFi; j++){
            int Dia = cursos[i].DiaSemana;
            block.BloquesTiempo[j-1][Dia-1] = true; //Asignar los bloques de tiempo
        }
    }
    return block;
}

// Función para comparar los bloques de tiempo de los cursos
Grafo eliminarSuperposicion(Grafo grafo2,Curso cursos[],char CantCursos, char CantSalas){
    for (int i = 0; i < CantCursos; i++) {
        for (int j = 0; j < CantSalas; j++) {
            if((cursos[j].DiaSemana == cursos[j+1].DiaSemana && cursos[j].BloqueIn == cursos[j+1].BloqueIn) || (cursos[j].DiaSemana == cursos[j+1].DiaSemana && cursos[j].BloqueFi == cursos[j+1].BloqueFi)){
                grafo2.asignaciones[i][j] = false;
            }
        }
    }
    return grafo2;
}
