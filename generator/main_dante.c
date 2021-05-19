/*
** EPITECH PROJECT, 2021
** dante
** File description:
** first version
*/

#include "dante.h"

int split_main(pos_t pos, mapstatus_t *map_status, int ac, char **av)
{
    int err = 0;

    err = check_error_size(pos);
    if (err == -1)
        return (84);
    if (err == 1)
        return (1);
    err = createmap_empty(pos.x, pos.y, map_status);
    err = full_map(map_status->map, pos, map_status);
    if (check_error(err) == -1)
        return (84);
    if (ac == 3)
        change_map(map_status, pos);
    if (ac >= 4) {
        if (my_strcmp(av[3], "perfect") != 0
            && my_strcmp(av[3], "[perfect]") != 0)
            change_map(map_status, pos);
    } if (pos.y % 2 == 0 || pos.x % 2 == 0)
        adapt_map(map_status->map, pos.y, pos.x, ac);
    return (0);
}

int main(int ac, char **av)
{
    pos_t pos;
    mapstatus_t map_status;
    int err = 0;

    if (ac <= 2)
        return (84);
    pos.y = my_getnbr(av[2]) + 2;
    pos.x = my_getnbr(av[1]);
    srand(time(NULL));
    err = split_main(pos, &map_status, ac, av);
    if (err == 84)
        return (84);
    if (err == 1)
        return (0);
    if (check_error(err) == -2)
        return (84);
    display_map(map_status.map);
    destructor(&map_status, pos.y);
    return (0);
}