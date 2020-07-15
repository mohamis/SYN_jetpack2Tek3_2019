/*
** EPITECH PROJECT, 2020
** my_gnl
** File description:
** my_gnl
*/
#define SIZE 4
#include "../../../include/jetpack_client.h"

char *my_strcat(char *str, char buffer)
{
    size_t	size = 0;
    char *dest;
    
    if (!(dest = my_malloc(strlen(str) + 2)))
        return (0);
    while (size < strlen(str)) {
        dest[size] = str[size];
        size = size + 1;
    }
    dest[size] = buffer;
    dest[size + 1] = '\0';
    if (str && str[0] != 0)
        free(str);
    return (dest);
}

int	clean_str(char **tab, char *buffer, int j, int c)
{
    j = j + 1;
    while (j < c) {
        *tab = my_strcat(*tab, buffer[j]);
        j = j + 1;
    }
    return (0);
}

char *check_last(char **tab, int *cout)
{
    char	*str = "";
    
    while (*tab[0] && *tab[0] != '\n') {
        str = my_strcat(str, *tab[0]);
        *tab = *tab + 1;
    }
    if (*tab[0])
    {
        *tab = *tab + 1;
        *cout = 1;
    }
    return (str);
}

char *my_gnl(int fd)
{
    int a;
    int b;
    int c;
    char *str;
    char *buffer;
    static char	*is_send = "";
    
    a = 0;
    str = check_last(&is_send, &a);
    if (a || (a = 0))
        return (str);
    if (!(buffer = my_malloc(SIZE * sizeof(char))))
        return (0);
    while ((c = (read(fd, buffer, SIZE) + (b = 0))))
        while (b < c + 0 * (a = a + 1)) {
	        if (buffer[b] == '\n')
	            return (str + clean_str(&is_send, buffer, b, c));
	        if (!(str = my_strcat(str, buffer[b])))
	            return (0);
            b = b + 1;
        }
    if (!str[0])
        return (0);
    return (str);
}