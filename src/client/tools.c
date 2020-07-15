/*
** EPITECH PROJECT, 2020
** tools 
** File description:
** tools
*/

#include "../../include/jetpack_client.h"

int	str_to_int(char *str)
{
    int	a = 0;
    int	b = 0;
    int	count = 1;
  
    if (!str)
        is_err("Bad syntax.", 1);
    while (str[a]) {
        if (a == 0 && str[a] == '-')
            count = -1;
        else if (str[a] < '0' || str[a] > '9')
	        is_err("Bad syntax.", 1);
        if (a != 0 || str[a] != '-')
            b = b * 10 + str[a] - '0';
        a++;
    }
    return (b * count);
}

double str_to_double(char *str)
{
    int carac = 0;
    int xp = 0;
    double i = 0;
    
    while ((carac = *str++) && isdigit(carac))
        i = i * 10.0 + (carac - '0');
    if (carac == '.')
        while ((carac = *str++) && isdigit(carac)) {
	    i = i * 10.0 + (carac - '0');
	    xp = xp - 1;
        }
    while (xp != 0) {
        i *= xp > 0 ? 10.0 : 0.1;
        xp = xp > 0 ? xp - 1 : xp + 1;
    }
    return (i);
}

void free_array(char **array)
{
    if (!array)
        return;
    if (array[0])
        free(array[0]);
    free(array);
}