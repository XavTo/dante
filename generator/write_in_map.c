/*
** EPITECH PROJECT, 2021
** dante
** File description:
** first version
*/

#include "dante.h"

int write_in_map(char **map, int y)
{
    int i = 0;
    int fd = 0;
    int err = 0;

    fd = open("labyrinthe.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
        return (-2);
    while (i != y) {
        err = write(fd, map[i], my_strlen(map[i]));
        if (err == -1)
            return (-1);
        i++;
        if (i != y) {
            err = write(fd, "\n", 1);
        }
        if (err == -1)
            return (-2);
    }
    close (fd);
    return (0);
}