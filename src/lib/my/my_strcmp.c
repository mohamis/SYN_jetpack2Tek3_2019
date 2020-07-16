/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp2
*/

#include "../../../include/jetpack_client.h"

int my_strcmp2(char *str1, char *str2)
{
    int j = 0;
    
    while (str1 && str2 && str1[j] && str2[j] &&
	 tolower(str1[j]) == tolower(str2[j]))
        j++;
    return (tolower(str1[j]) - tolower(str2[j]));
}
