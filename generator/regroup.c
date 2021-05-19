/*
** EPITECH PROJECT, 2021
** dante
** File description:
** first version
*/

#include "dante.h"

static int regrou_split_again(int **map, int y, int x, int move)
{
    if (map[y + 1] != NULL) {
        if ((map[y][x] != 0 && map[y][x] != 1)
            && (map[y + 1][x] != 1 && map[y + 1][x] != 0)
            && map[y + 1][x] != map[y][x]) {
            map[y + 1][x] = map[y][x];
            move++;
        }
    }
    if (y - 1 >= 1) {
        if ((map[y][x] != 0 && map[y][x] != 1)
            && (map[y - 1][x] != 1 && map[y - 1][x] != 0)
            && map[y - 1][x] != map[y][x]) {
            map[y - 1][x] = map[y][x];
            move++;
        }
    }
    return (move);
}

static int regrou_split(int **map, int y, int x, int move)
{
    if (map[y][x + 1] != -1) {
        if ((map[y][x] != 0 && map[y][x] != 1)
            && (map[y][x + 1] != 1 && map[y][x + 1] != 0)
            && map[y][x] != map[y][x + 1]) {
            map[y][x + 1] = map[y][x];
            move++;
        }
    }
    if (x - 1 >= 1) {
        if ((map[y][x] != 0 && map[y][x] != 1)
            && (map[y][x - 1] != 1 && map[y][x - 1] != 0)
            && map[y][x] != map[y][x - 1]) {
            map[y][x - 1] = map[y][x];
            move++;
        }
    }
    move = regrou_split_again(map, y, x, move);
    return (move);
}

static int regroup(int **map)
{
    int y = 0;
    int x = 0;
    int move = 0;

    while (map[y] != NULL) {
        while (map[y][x] != -1) {
            move = regrou_split(map, y, x, move);
            x++;
        }
        y++;
        x = 0;
    }
    return (0);
}

static int full_map_split_again(pos_t *index, pos_t pos, pos_t cell, int **map)
{
    while (index->x < pos.x - 1) {
        if (map[index->y][index->x] == cell.x)
            map[index->y][index->x] = cell.y;
        index->x += 2;
    }
    return (0);
}

int full_map_split(int **map, int cell1, int cell2, pos_t pos)
{
    int i = 1;
    int j = 1;
    pos_t index = {i, j};
    pos_t cell = {cell1, cell2};

    if (cell1 != cell2) {
        while (index.y < pos.y - 1) {
            full_map_split_again(&index, pos, cell, map);
            index.x = 1;
            index.y += 2;
        }
        regroup(map);
    }
    return (0);
}