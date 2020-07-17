/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** list
*/

#include "jetpack.h"

void loop_map(char **map)
{
    for (int x = 0; map[x] != NULL; x++) {
        for (int y = 0; map[x][y] != '\0'; y++) {
            // printf("%c", map[x][y]);
            dprintf(tft_client, "%c", map[x][y]);
        }
    }
}

void map_files(__attribute__((unused)) char *lines, __attribute__((unused))  server_t *server)
{
    // DIR *d;
    // struct dirent *dir;
    char *buffer = NULL;
    char **map = NULL;
    long numbytes;
    // d = opendir(".");
    FILE *fptr;
    fptr = fopen(server->pathname, "r"); 
    if (fptr == NULL) { 
        exit(84); 
    }
    fseek(fptr, 0L, SEEK_END);
    numbytes = ftell(fptr);
    fseek(fptr, 0L, SEEK_SET);	
    buffer = (char*)calloc(numbytes, sizeof(char));	
    if(buffer == NULL)
        exit(84);
    fread(buffer, sizeof(char), numbytes, fptr);
    // map = my_str_to_word_array(buffer, '\n');
    printf("%s\n", buffer);
    // loop_map(map);
    fclose(fptr);
    free(buffer);
    free_darray(map);
    // if (d) {
    //     dprintf(tft_client, "150 \r\n");
    //     dprintf(tft_client, "226 \r\n");
    //     while ((dir = readdir(d)) != NULL) {
    //         dprintf(tft_client, "%s\r\n", dir->d_name);
    //     }
    //     dprintf(tft_client, "226 \r\n");
    //     closedir(d);
    // }
}