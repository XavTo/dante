/*
** EPITECH PROJECT, 2021
** dante
** File description:
** first version
*/

#include "dante.h"

static int split_clean_map(char **map, int **map_value, int y, int x)
{
    if (map_value[y][x] != 1)
        map[y][x] = '*';
    else
        map[y][x] = 'X';
    return (0);
}

int clean_map(char **map, int **map_value)
{
    int y = 0;
    int x = 0;

    while (map_value[y] != NULL) {
        while (map_value[y][x] != -1) {
            split_clean_map(map, map_value, y, x);
            x++;
        }
        y++, x = 0;
    }
    return (0);
}

static int split_map_is_finish(int **map, int *i, int y, int *st)
{
    int x = 0;

    while (map[y][x] != -1) {
        if (map[y][x] != st[0] && map[y][x] != st[1] && map[y][x] != st[2]) {
            st[*i] = map[y][x];
            (*i)++;
        }
        if (*i > 3) {
            free(st);
            return (1);
        }
        x++;
    }
    return (0);
}

int map_is_finish(int **map)
{
    int y = 0;
    int i = 1;
    int *stock = malloc(sizeof(int) * 4);

    if (stock == NULL)
        return (-1);
    stock[0] = 0;
    stock[1] = 0;
    stock[2] = 0;
    stock[3] = 0;
    while (map[y] != NULL) {
        if (split_map_is_finish(map, &i, y, stock) == 1)
            return (0);
        y++;
    }
    free(stock);
    return (1);
}