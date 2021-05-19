/*
** EPITECH PROJECT, 2021
** utils funcs sequel
** File description:
** utils2
*/

#include "my.h"
#include "dante.h"

void print_arr(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        write(1, map[i], my_strlen(map[i]));
        if (map[i + 1] != NULL)
            write(1, "\n", 1);
    }
}

void dealoc_maze(maze_t *maze)
{
    dealoc_map(maze->map);
    dealoc_map(maze->res);
    free(maze);
}

int set_true(maze_t *m, pos_t curr)
{
    m->res[curr.y][curr.x] = 'o';
    return 1;
}

int get_heigth(char **map)
{
    int i = 0;
    for (i = 0; map[i] != NULL; i++);
    return i;
}

void set_limit(void)
{
    struct rlimit lim;
    getrlimit(RLIMIT_STACK, &lim);
    lim.rlim_cur = 16000000000;
    setrlimit(RLIMIT_STACK, &lim);
}