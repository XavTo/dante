/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** Concatenates 2 strings.
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int d = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[d] != '\0') {
        dest[i] = src[d];
        i++;
        d++;
    }
    return (dest);
}
