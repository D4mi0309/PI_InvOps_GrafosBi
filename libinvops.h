#include <stdbool.h>
#ifndef LIBINVOPS_H
#define LIBINVOPS_H

/*Bloques de Tiempo:
 B1=7:00-7:50,     B2=7:50-8:40,
 B3=9:00-9:50,     B4=9:50-10:40,
 B5=11:00-11:50,   B6=11:50-12:40,
 B7=13:00-13:50,   B8=13:50-14:40,
 B9=15:00-15:50,   B10=15:50-16:40,
 B11=17:00-17:50,  B12=17:50-18:40,
 B13=19:00-19:50,  B14=19:50-20:40,
 B15=21:00-21:50
*/

//Estructura que representa un grafo
typedef struct {
    bool **asignaciones;  // Matriz de adyacencia para representar las asignaciones
} Grafo;

//Estructura que representa un curso
typedef struct Curso{
    char NombreCurso[30];
    char CantidadEstudiantes;
    char NombreDocente[30];
    char DiaSemana; // 1 = Lunes,..., 6 = Sabado
    char BloqueIn; //1 = B1,..., 16 = B16
    char BloqueFi;
} Curso;
//Estructura que represente una sala
typedef struct Sala{
    char NombreSala[15];
    char Capacidad;
} Sala;

//Estructura que representa los bloques de tiempo
typedef struct Bloques{
    bool **BloquesTiempo;
} Bloques;

//Definicion de los metodos
Grafo crearGrafo(char CantCursos, char CantSalas);
Grafo encontrarSala(Grafo grafo,Curso cursos[], Sala salas[], char CantCursos, char CantSalas);
Grafo eliminarSuperposicion(Grafo grafo2,Curso cursos[],char CantCursos, char CantSalas);
Bloques bloquesTiempo(Curso cursos[],Sala salas[],char CantCursos);

#endif
