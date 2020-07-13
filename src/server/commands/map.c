/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** list
*/

#include "jetpack.h"

void map_files(__attribute__((unused)) char *lines)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");

    if (d) {
        dprintf(tft_client, "150 \r\n");
        dprintf(tft_client, "226 \r\n");
        while ((dir = readdir(d)) != NULL) {
            dprintf(tft_client, "%s\r\n", dir->d_name);
        }
        dprintf(tft_client, "226 \r\n");
        closedir(d);
    }
}