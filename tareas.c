#include "GestorTareas.h"
#include <stdbool.h>
#include <stdio.h>


void agregarTarea(Tarea tareas[], int *total){    
    if (*total >= MAX_TAREAS){
        printf("**** La capacidad de las Tareas esta llenan ****\n");
    }else{
        printf("Ingresa la descripcion de la tarea\n");
        scanf(" %[^\n]", tareas[*total].descripcion);
        tareas[*total].completada = 0;
        printf("Ingresa la prioridad de la tarea (1: Alta, 2: Media, 3: Baja)\n");
        scanf(" %d", &tareas[*total].prioridad);
        tareas[*total].id = *total + 1;
        (*total)++;        
    }
}

void listarTareas(Tarea tareas[], int total){
    int i;
    if(total == 0){
        printf("**** La lista esta vacia ****\n");
    }else{
        printf("**** El listado de las tareas: ****\n");
        for(i = 0; i < total; i++){
            printf("%d  %s - Completada - No(0), Si(1): %d - Prioridad: %d\n", tareas[i].id,tareas[i].descripcion, tareas[i].completada, tareas[i].prioridad);
        }
    }
}
void marcarCompletada(Tarea tareas[], int total){
    int comp;
    int i;
    int contador = 0;
    bool valido = false;

    if(total == 0){
        printf("**** La lista esta vacia ****\n");
    }else{
        for(i = 0; i < total; i++){
            if(tareas[i].completada == 1){
                contador++;
            }
        }
        if (contador == total){
            printf("**** No hay tareas por completar ****\n");
        }else{
            printf("**** Que tarea desea marcar como completada? ****\n");
            for(i = 0; i < total; i++){
                if(tareas[i].completada == 0){
                printf("%d  %s\n", tareas[i].id, tareas[i].descripcion);
                }

            }
            scanf("%d", &comp);
            for(i = 0; i < total; i++){
                if(tareas[i].completada == 0){
                    if(comp == i + 1){
                        valido = true;                    
                    }   
                }
            }
            if(valido){
                tareas[comp -1].completada = 1;
            }else{
                printf("El numero introducido no existe\n");
            }
        }
    }    
}
void guardarEnArchivo(Tarea tareas[], int total){
    FILE *f = fopen("Lista_Tareas.csv", "w");
    if(f == NULL){
        printf("Error al abrir o crear el archivo");
        return;
    }
    fprintf(f,"id;descripcion;completada;prioridad\n");
    for(int i = 0; i < total; i++){
        fprintf(f,"%d;\"%s\";%d;%d\n", tareas[i].id,tareas[i].descripcion, tareas[i].completada, tareas[i].prioridad);
    }
    fclose(f);    
}
