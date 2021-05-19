/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** fichier h prototypes
*/

#ifndef dante_h
#define dante_h

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"

typedef struct {
    int y;
    int x;
} pos_t;

typedef struct {
    char **map;
    int **value_map;
} mapstatus_t;

char *my_itoa(int nb);
void display_map(char **map);
void display_map_total(char **map);
void display_value_map(int **map_value);
int full_map(char **map, pos_t pos, mapstatus_t *map_status);
int map_is_finish(int **map);
int clean_map(char **map, int **map_value);
int write_in_map(char **map, int y);
int check_error(int err);
int check_error_size(pos_t pos);
int change_map(mapstatus_t *map, pos_t pos);
int adapt_map(char **map, int y, int x, int nb);
void *my_realloc(void *data, size_t size);
void destructor(mapstatus_t *map_status, int y);
int createmap_empty(int x, int y, mapstatus_t *map);
int full_map_split(int **map, int cell1, int cell2, pos_t pos);
#endif