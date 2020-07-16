/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "../../include/jetpack_client.h"

void my_loop(int sockfd)
{
    char *buffer;
    int i;

    buffer = malloc(sizeof(char *));
    for(;;){
        bzero(buffer, sizeof(buffer));
        i = 0;
        while ((buffer[i++] = getchar()) != '\n');
            write(sockfd, buffer, sizeof(buffer));
            bzero(buffer, sizeof(buffer));
            read(sockfd, buffer, sizeof(buffer));
            printf("%s", buffer);
            //do_func() fonction qui récupere les protocoles
    }
}

int my_connect(char **av)
{
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("fail to create socket\n");
        exit (0);
    } else 
        printf("socket created.\n");
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(av[2]);
    servaddr.sin_port = htons(atoi(av[4]));
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        printf("fail to connect with the server\n");
        exit(0);
    } else
        printf("connected to the server");
    my_loop(sockfd);
}

int main(int ac, char **av)
{
    if (manage_args(ac, av) == 84)
        return (84);
    my_connect(av);
}