/* Gestor de notas en C: arreglo dinamico + lectura de archivo + escritura.
 * Practica de manejo de memoria, punteros y E/S de archivos. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char texto[128];
    int prioridad;
} Nota;

typedef struct {
    Nota *items;
    size_t len;
    size_t cap;
} Lista;

static int lista_init(Lista *l, size_t cap) {
    l->items = malloc(cap * sizeof(Nota));
    if (!l->items) return 0;
    l->len = 0;
    l->cap = cap;
    return 1;
}

static int lista_push(Lista *l, const char *texto, int prioridad) {
    if (l->len == l->cap) {
        size_t ncap = l->cap * 2;
        Nota *tmp = realloc(l->items, ncap * sizeof(Nota));
        if (!tmp) return 0;
        l->items = tmp;
        l->cap = ncap;
    }
    snprintf(l->items[l->len].texto, sizeof(l->items[l->len].texto), "%.127s", texto);
    l->items[l->len].prioridad = prioridad;
    l->len++;
    return 1;
}

static void lista_free(Lista *l) {
    free(l->items);
    l->items = NULL;
    l->len = l->cap = 0;
}

static int cargar(Lista *l, const char *ruta) {
    FILE *f = fopen(ruta, "r");
    if (!f) return 0;
    char linea[160];
    while (fgets(linea, sizeof(linea), f)) {
        linea[strcspn(linea, "\r\n")] = '\0';
        if (linea[0] == '\0') continue;
        int prio = 1;
        char *sep = strchr(linea, '|');
        if (sep) { *sep = '\0'; prio = atoi(sep + 1); }
        if (!lista_push(l, linea, prio)) { fclose(f); return 0; }
    }
    fclose(f);
    return 1;
}

int main(int argc, char **argv) {
    const char *ruta = (argc > 1) ? argv[1] : "notas.txt";
    Lista l;
    if (!lista_init(&l, 4)) { fprintf(stderr, "sin memoria\n"); return 1; }
    if (!cargar(&l, ruta)) { fprintf(stderr, "no se pudo leer %s\n", ruta); lista_free(&l); return 1; }

    printf("Notas cargadas: %zu\n", l.len);
    for (size_t i = 0; i < l.len; i++) {
        printf("  [%d] %s\n", l.items[i].prioridad, l.items[i].texto);
    }
    lista_free(&l);
    return 0;
}
