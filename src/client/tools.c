/*
** EPITECH PROJECT, 2020
** toools for client
** File description:
** tools for client
*/

int my_isnum(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
	if (str[i] < '0' || str[i] > '9')
	    return (1);
	i++;
    }
    return (0);
}
