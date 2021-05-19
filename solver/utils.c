/*
** EPITECH PROJECT, 2021
** utils funcs
** File description:
** utils
*/

#include "my.h"
#include "dante.h"

int is_solution(char **map)
{
    int valid = 0;
    int valid2 = 0;
    int size = my_strlen(map[0]);
    for (int i = 0; map[i] != NULL; i++) {
        if (map[i][0] == '*')
            valid = 1;
        if (map[i][size - 1] == '*')
            valid2 = 1;
        if (valid == 1 && valid2 == 1)
            return 1;
    }
    return 0;
}

int count_lines(char *buffer)
{
    int count = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            count++;
    return count + 1;
}

char *load_file(char *path)
{
    struct stat buf;
    int fd = 0;
    char *buffer = NULL;
    if ((fd = open(path, O_RDONLY)) == -1) {
        write(2, "Failed to open the file.\n", 26);
        return NULL;
    }
    stat(path, &buf);
    buffer = malloc(sizeof(char) * (buf.st_size + 1));
    read(fd, buffer, buf.st_size);
    buffer[buf.st_size] = '\0';
    close(fd);
    return buffer;
}

void dealoc_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
    }
    free(map);
}

char **parse_map(char *buffer)
{
    int count = 0;
    int i = 0;
    int d = 0;
    int lines = count_lines(buffer);
    char **map = malloc(sizeof(char *) * (lines + 1));
    int size = 0;

    for (; buffer[size] != '\n' && buffer[size] != '\0'; size++);
    for (i = 0; i != lines; i++)
        map[i] = malloc(sizeof(char) * (size + 1));
    for (; d != lines; d++) {
        for (i = 0; i != size; i++) {
            map[d][i] = buffer[count];
            count++;
        }
        map[d][i] = '\0';
        count++;
    }
    map[d] = NULL;
    return map;
}