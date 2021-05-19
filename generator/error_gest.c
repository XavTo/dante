/*
** EPITECH PROJECT, 2021
** dante
** File description:
** first version
*/

static const char *ERROR_MALLOC = "Malloc error\n";
static const char *ERROR_WRITE = "Write error\n";
static const char *ERROR_SIZE = "Size too small\n";
#include "dante.h"

int check_error(int err)
{
    if (err == -1) {
        write(2, ERROR_MALLOC, my_strlen(ERROR_MALLOC));
        return (-1);
    }
    if (err == -1) {
        write(2, ERROR_WRITE, my_strlen(ERROR_WRITE));
        return (-2);
    }
    return (0);
}

int check_error_size(pos_t pos)
{
    int i = 0;

    if (pos.x <= 0 || pos.y  - 2 <= 0) {
        write(2, ERROR_SIZE, my_strlen(ERROR_SIZE));
        return (-1);
    } if (pos.y - 2 == 1) {
        while (i != pos.x) {
            my_putchar('*');
            i++;
        } return (1);
    } if (pos.x == 1) {
        while (i != pos.y - 3) {
            my_putchar('*');
            my_putchar('\n');
            i++;
        }
        my_putchar('*');
        return (1);
    } return (0);
}

void destructor(mapstatus_t *map_status, int y)
{
    int i = 0;

    while (i != y) {
        free(map_status->map[i]);
        free(map_status->value_map[i]);
        i++;
    }
    free(map_status->map);
    free(map_status->value_map);
}

int change_map(mapstatus_t *map, pos_t pos)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int value = map->value_map[1][0];

    while (i != pos.y) {
        x = rand() % (pos.x - 2) + 1;
        if (x % 2 == 0)
            y = ((rand() % ((pos.y - 1) / 2))) * 2 + 1;
        else
            y = ((rand() % ((pos.y - 2) / 2))) * 2 + 2;
        map->value_map[y][x] = value;
        i++;
    }
    clean_map(map->map, map->value_map);
    return (0);
}

int adapt_map(char **map, int y, int x, int nb)
{
    int i = 0;

    if (nb == 3) {
        map[y - 2][x - 2] = '*';
        return (0);
    }
    map[y - 2][x - 2] = '*';
    if (map[y - 3][x - 2] == 'X' && map[y - 2][x - 3] == 'X')
        map[y - 2][x - 3] = '*';
    if (map[y - 3][x - 3] == '*' && map[y - 2][x - 3] != 'X')
        map[y - 3][x - 2] = 'X';
    if (x == 3)
        map[y - 3][x - 1] = 'X';
    if (x == 2) {
        while (i != y) {
            map[i][0] = '*';
            i++;
        }
    }
    return (0);
}