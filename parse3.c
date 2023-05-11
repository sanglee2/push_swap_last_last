
#include "push_swap.h"

int is_num(char *av)
{
    int i;

    i = 0;
    if (is_sign(av[i]) && av[i + 1] != '\0')
        i++;
    while (av[i] && is_digit(av[i]))
        i++;
    if (av[i] != '\0' && !is_digit(av[i]))
        return (0);
    return (1);
}

int is_zero(char *av)
{
    int i;

    i = 0;
    if (is_sign(av[i]))
        i++;
    while (av[i] && av[i] == '0')
        i++;
    if (av[i] != '\0')
        return (0);
    return (1);
}

int is_duplicated(char **av)
{
    int i;
    int j;

    i = 1;
    while (av[i])
    {
        j = 1;
        while (av[j])
        {
            if (j != i && strcmp(av[i], av[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int valid_input(char *av[])
{
    int i;
    int nb;

    nb = 0;
    i = 1;
    while (av[i])
    {
        if (!is_num(av[i]))
            return (0);
        nb += is_zero(av[i]);
        i++;
    }
    if (nb > 1)
        return (0);
    if (is_duplicated(av))
        return (0);
    return (1);
}
