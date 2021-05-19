/*
** EPITECH PROJECT, 2021
** dante's funcs
** File description:
** dante
*/

#ifndef DANTE_H_
#define DANTE_H_

// Includes
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/resource.h>

// Structs
typedef struct pos {
    int x;
    int y;
} pos_t;

typedef struct maze {
    char **map;
    char **res;
    int width;
    int height;
} maze_t;

// SOLVER FUNCS
// Utils
char *load_file(char *path);
char **parse_map(char *buffer);
void dealoc_map(char **map);
int is_solution(char **map);
int get_heigth(char **map);
int set_true(maze_t *m, pos_t curr);
void dealoc_maze(maze_t *maze);
void print_arr(char **map);
void set_limit(void);

#endif /* !DANTE_H_ */