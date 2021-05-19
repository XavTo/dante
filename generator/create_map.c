/*
** EPITECH PROJECT, 2021
** dante
** File description:
** first version
*/

#include "dante.h"

static void create_map_value_split(int i, int y, mapstatus_t *map, int x)
{
    int a = 0;
    int nb = 2;

    while (i != y) {
        if (i % 2 == 0 || a == 0) {
            map->value_map[i][a] = 1;
            a++;
        } else {
            map->value_map[i][a] = nb;
            nb++;
            a++;
        } if (a % 2 == 1)
            map->value_map[i][a - 1] = 1;
        if (a == x) {
            map->value_map[i][a - 1] = 1;
            map->value_map[i][a] = -1;
            i++;
            a = 0;
        }
    }
}

static void create_map_value(mapstatus_t *map, int x, int y)
{
    int i = 1;

    create_map_value_split(i, y, map, x);
    i = 0;
    while (i != x) {
        map->map[y - 1][i] = '1';
        map->value_map[y - 1][i] = 1;
        i++;
    }
    map->map[y - 1][i] = '\0';
    map->value_map[y - 1][i] = -1;
    map->map[1][0] = '0';
    map->value_map[1][0] = 0;
    map->map[y - 2][x - 1] = '0';
    map->value_map[y - 2][x - 1] = 0;
}

static void create_map_empty_split(mapstatus_t *map, int x, int y, int i)
{
    int a = 0;

    while (i != y) {
        if (i % 2 == 0 || a == 0)
            map->map[i][a] = '1', a++;
        else
            map->map[i][a] = '*', a++;
        if (a % 2 == 1)
            map->map[i][a - 1] = '1';
        if (a == x) {
            map->map[i][a - 1] = '1';
            map->map[i][a] = '\0';
            i++;
            a = 0;
        }
    }
}

static void create_map_split(int x, int y, mapstatus_t *map)
{
    int i = 0;

    while (i != x) {
        map->map[0][i] = '1';
        map->value_map[0][i] = 1;
        i++;
    }
    map->map[0][i] = '\0';
    map->value_map[0][i] = -1;
    create_map_empty_split(map, x, y, 1);
    create_map_value(map, x, y);
}

int createmap_empty(int x, int y, mapstatus_t *map)
{
    int i = 0;

    map->map = malloc(sizeof(char *) *(y + 1));
    map->value_map = malloc(sizeof(int *) * (y + 1));
    if (map->map == NULL || map->value_map == NULL)
        return (-1);
    while (i != y) {
        map->map[i] = malloc(sizeof(char) * (x + 1));
        map->value_map[i] = malloc(sizeof(int) * (x + 1));
        if (map->map[i] == NULL || map->value_map[i] == NULL)
            return (-1);
        i++;
    }
    map->map[i] = NULL;
    map->value_map[i] = NULL;
    create_map_split(x, y, map);
    return (0);
}