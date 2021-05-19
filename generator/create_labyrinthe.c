/*
** EPITECH PROJECT, 2021
** dante
** File description:
** first version
*/

#include "dante.h"

static int complex_map(mapstatus_t *map_status, pos_t pos)
{
    int y = 0;
    int m = pos.x - 1;
    int val = map_status->value_map[1][1];

    while (y != pos.y - 2) {
        if (map_status->value_map[y][1] == val
            && map_status->value_map[y - 1][0] != val)
            map_status->value_map[y][0] = val;
        if (map_status->value_map[y][m - 1] == val
            && map_status->value_map[y - 1][m] != val)
            map_status->value_map[y][m] = val;
        y++;
    }
    map_status->value_map[pos.y - 3][pos.x - 1] = 1;
    clean_map(map_status->map, map_status->value_map);
    return (0);
}

static int check_is_good(int *x, int *y, mapstatus_t *map_status)
{
    int cell1;
    int cell2;

    if (map_status->value_map[*y][*x] != 1)
        return (0);
    if (map_status->value_map[*y - 1][*x] == 1) {
        cell1 = map_status->value_map[*y][*x - 1];
        cell2 = map_status->value_map[*y][*x + 1];
    }
    else {
        cell1 = map_status->value_map[*y - 1][*x];
        cell2 = map_status->value_map[*y + 1][*x];
    }
    if (cell1 != cell2)
        return (1);
    return (0);
}

static int create_random(int *x, int *y, pos_t pos, mapstatus_t *map_status)
{
    *x = 0;
    *y = 1;
    int nb_op = 0;

    while (nb_op == 0) {
        *x = rand() % (pos.x - 1 + 1) + 1;
        if (*x % 2 <= 0)
            *y = ((rand() % ((pos.y - 1) / 2))) * 2 + 1;
        else
            *y = ((rand() % ((pos.y - 2) / 2))) * 2 + 2;
        nb_op = check_is_good(x, y, map_status);
    }
    return (0);
}

static int destroy_wall(pos_t pos, mapstatus_t *map_status, int y, int x)
{
    int cell1 = 0;
    int cell2 = 0;

    if (map_status->value_map[y - 1][x] == 1) {
        cell1 = map_status->value_map[y][x - 1];
        cell2 = map_status->value_map[y][x + 1];
    }
    else {
        cell1 = map_status->value_map[y - 1][x];
        cell2 = map_status->value_map[y + 1][x];
    }
    if (cell1 != cell2) {
        map_status->value_map[y][x] = cell1;
        full_map_split(map_status->value_map, cell1, cell2, pos);
    }
    return (0);
}

int full_map(char **map, pos_t pos, mapstatus_t *map_status)
{
    int y = 0;
    int x = 0;

    while (map_is_finish(map_status->value_map) != 1) {
        if (map_is_finish(map_status->value_map) == -1)
            return (-1);
        if (create_random(&x, &y, pos, map_status) == 1)
            break;
        destroy_wall(pos, map_status, y, x);
    }
    clean_map(map, map_status->value_map);
    complex_map(map_status, pos);
    return (0);
}