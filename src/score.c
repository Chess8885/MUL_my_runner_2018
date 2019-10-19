/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** my_hunter
*/

#include <stdlib.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int length = my_strlen(str);
    int m = length - 1;
    int n = 0;
    int temp;

    while (n < length / 2) {
        temp = str[n];
        str[n] = str[m];
        str[m] = temp;
        n = n + 1;
        m = m - 1;
    }
    return (str);
}

int count_int(int nb)
{
    int count = 0;

    if (nb < 10) {
        return (1);
    }

    while (nb != 0) {
        nb = nb / 10;
        count = count + 1;
    }
    return (count);
}

char *int_to_text(int nb)
{
    int i = 0;
    int length = count_int(nb);
    char *str = malloc(sizeof(char *) * (length + 1));

    str[length] = '\0';
    while (length > 0) {
        if (nb < 10) {
            str[i] = nb + 48;
        } else {
            str[i] = nb % 10 + 48;
            nb = nb / 10;
        }
        i++;
        length--;
    }
    return (my_revstr(str));
}
