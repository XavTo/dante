/*
** EPITECH PROJECT, 2021
** core funcs
** File description:
** core
*/

#include "my.h"
#include "dante.h"

int init_maze(char **av, maze_t *maze)
{
    char *buffer = NULL;
    if ((buffer = load_file(av[1])) == NULL)
        return 1;
    maze->map = parse_map(buffer);
    maze->res = parse_map(buffer);
    maze->width = my_strlen(maze->map[0]);
    maze->height = get_heigth(maze->map);
    free(buffer);
    return 0;
}

pos_t get_start(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        if (map[i][0] == '*')
            return (pos_t){0, i};
    return (pos_t){0, 0};
}

pos_t get_end(char **map)
{
    int i = 0;
    int end = 0;
    end = my_strlen(map[0]);
    for (i = 0; map[i] != NULL; i++);
    return (pos_t){end - 1, i - 1};
}

int solve(maze_t *m, pos_t curr, pos_t end)
{
    if (curr.x == end.x && curr.y == end.y)
        return set_true(m, curr);
    if (m->map[curr.y][curr.x] == 'X' || m->map[curr.y][curr.x] == 'o')
        return 0;
    m->map[curr.y][curr.x] = 'o';
    if (curr.x != m->width - 1)
        if (solve(m, (pos_t){curr.x + 1, curr.y}, end) == 1)
            return set_true(m, curr);
    if (curr.y != m->height - 1)
        if (solve(m, (pos_t){curr.x, curr.y + 1}, end) == 1)
            return set_true(m, curr);
    if (curr.x != 0)
        if (solve(m, (pos_t){curr.x - 1, curr.y}, end) == 1)
            return set_true(m, curr);
    if (curr.y != 0)
        if (solve(m, (pos_t){curr.x, curr.y - 1}, end) == 1)
            return set_true(m, curr);
    return 0;
}

int main(int ac, char **av)
{
    maze_t *maze = NULL;
    set_limit();
    if ((maze = malloc(sizeof(maze_t))) == NULL)
        return 84;
    if (ac != 2) {
        write(2, "Arguments error.\n", 17);
        return 84;
    } else if (init_maze(av, maze) == 1)
        return 84;
    if (is_solution(maze->map) == 0) {
        my_printf("no solution found");
        return 0;
    }
    if (solve(maze, get_start(maze->map), get_end(maze->map)) == 1) {
        print_arr(maze->res);
        dealoc_maze(maze);
        return 0;
    }
    my_printf("no solution found");
    dealoc_maze(maze);
    return 84;
}