#define MAX_TAREAS 100
#define MAX_CHARS 100

typedef struct {
    int id;
    char descripcion[MAX_CHARS];
    int completada; // 0 para pendiente, 1 para completada
    int prioridad;  // 1: Alta, 2: Media, 3: Baja
} Tarea;

void agregarTarea(Tarea tareas[], int *total); 
void listarTareas(Tarea tareas[], int total);
void marcarCompletada(Tarea tareas[], int total);
void guardarEnArchivo(Tarea tareas[], int total);
void cargarDesdeArchivo(Tarea tareas[], int *total);
