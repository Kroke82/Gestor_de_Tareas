#include <stdio.h>
#include <stdbool.h>
#include "GestorTareas.h"

int main(void){
    Tarea tareas[MAX_TAREAS];
    int total = 0;
    int expression;
    do{
        printf("\n1. Agregar tarea\n2. Listar tareas\n3. Marcar Completada\n4. Guardar en archivo\n0. Salir\nOpcion: ");
        scanf("%i", &expression);

        switch (expression)
        {
        case (1):
            agregarTarea(tareas, &total);
            break;
        case (2):
            listarTareas(tareas, total);
            break;
        case (3):
            marcarCompletada(tareas, total);
            break;
        case (4):
            guardarEnArchivo(tareas, total);
            break;
        default:
            break;
        }
    }while (expression != 0);
    return(0);
} 


