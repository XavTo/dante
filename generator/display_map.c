/*
** EPITECH PROJECT, 2020
** dante
** File description:
** whit theo
*/

#include "dante.h"

void display_value_map(int **map_value)
{
    int y = 0;
    int x = 0;

    while (map_value[y] != NULL) {
        while (map_value[y][x] != -1) {
            my_put_nbr(map_value[y][x]);
            my_putchar('!');
            x++;
        }
        my_putchar('\n');
        y++;
        x = 0;
    }
}

void display_map(char **map)
{
    int y = 1;

    while (map[y + 1] != NULL) {
        if (y != 1)
            my_putchar('\n');
        my_putstr(map[y]);
        y++;
    }
}

void display_map_total(char **map)
{
    int y = 0;

    while (map[y] != NULL) {
        my_putstr(map[y]);
        my_putchar('\n');
        y++;
    }
}