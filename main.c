/*
** EPITECH PROJECT, 2021
** fortn.c
** File description:
** wow fortn
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcul_velocity(char **av)
{
    double dx = atof(av[4]) - atof(av[1]);
    double dy = atof(av[5]) - atof(av[2]);
    double dz = atof(av[6]) - atof(av[3]);
    double nx = dx * atoi(av[7]) + atof(av[4]);
    double ny = dy * atoi(av[7]) + atof(av[5]);
    double nz = dz * atoi(av[7]) + atof(av[6]);
    double norm = sqrtf(powf(dx, 2) + powf(dy, 2) + powf(dz, 2));
    double keb = atof(av[3]) - atof(av[6]);
    double angle = asin(keb / norm) * 180 / M_PI;

    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", dx, dy, dz);
    printf("At time t + %s, ball coordinates will be:\n", av[7]);
    printf("(%.2f, %.2f, %.2f)\n", nx, ny, nz);
    if (atof(av[6]) >= 0 && nz < 0)
        printf("The incidence angle is:\n%.2f degrees\n", angle);
    else if (!(atof(av[6]) >= 0 && nz < 0))
        printf("The ball won't reach the paddle.\n");
}

int check_arg(char *av)
{
    for (int i = 0; av[i]; i++) {
        if (av[i] == '-' || av[i] == '.')
            i++;
        if (av[i] < '0' || av[i] > '9')
            return 1;
    }
    return 0;
}

void print_h(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        printf("Usage\n");
        printf("    ./101pong x0 y0 z0 x1 y1 z1 n\n\nDESCRIPTION\n");
        printf("    x0 ball abscissa at time t - 1\n");
        printf("    y0 ball ordinate at time t - 1\n");
        printf("    z0 ball altitude at time t - 1\n");
        printf("    x1 ball abscissa at time t\n");
        printf("    y1 ball ordinate at time t\n");
        printf("    z1 ball altitude at time t\n");
        printf("    n  time shift (greater than or equal to zero, integer)\n");
    }
}

int check_time(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '-')
            return (1);
        if (str[i] == '.')
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2)
        print_h(av);
    if (check_time(av[7]) == 1)
        return (84);
    if (ac == 8 && atoi(av[7]) > 0) {
        for (int i = 1; av[i]; i++)
            if (check_arg(av[i]) == 1)
                return 84;
        calcul_velocity(av);
    }
    else
        return (84);
    return (0);
}
