# c-gestor-notas-memoria

![stack: C (C11)](https://img.shields.io/badge/stack--C%20(C11)-0d9488?style=flat-square) ![stack: make](https://img.shields.io/badge/stack--make-0d9488?style=flat-square)
![IA: asistido](https://img.shields.io/badge/IA--asistido-6366f1?style=flat-square)

Gestor de notas en C con arreglo dinamico, punteros y lectura de archivos.

> **Transparencia sobre IA:** este proyecto se desarrollo con asistencia de inteligencia artificial (generacion de codigo, revision y documentacion). El codigo fue leido, ejecutado y probado manualmente antes de publicarse. No declara clientes, metricas ni resultados que no puedan verificarse.

## Problema que resuelve

Practicar y demostrar el manejo manual de memoria en C: sin recolector de basura, un error de reserva o liberacion produce fugas y cierres inesperados.

## Solucion implementada

Lista de notas con memoria dinamica (malloc/realloc), lectura y escritura de un archivo de texto, orden por prioridad y menu de consola.

### Funcionalidades principales

- Arreglo dinamico que crece con realloc
- Lectura/escritura de notas.txt
- Orden por prioridad con qsort
- Makefile con objetivo clean

## Stack

- C (C11)
- make

## Estructura

```
src/main.c   # logica y E/S de archivos
notas.txt    # datos de ejemplo
Makefile
```

## Puesta en marcha

```bash
make run
```

## Complejidad del proyecto

**Nivel: Intermedio** — Un unico modulo, pero con gestion manual de memoria, E/S de archivos y ordenamiento; se verifica con valgrind.

El nivel describe la complejidad tecnica del proyecto, no el grado de dominio de quien lo escribio.

## Despliegue

Aplicacion de consola; no tiene interfaz web que desplegar.  
El codigo fuente si esta disponible en este repositorio.

## Autor

**Luis Felipe Zuniga Leon** — Desarrollador de software asistido por IA

- GitHub: <https://github.com/Luisf2020>

---

_Proyecto de portafolio. El desarrollo se apoyo en herramientas de IA bajo revision tecnica humana._
