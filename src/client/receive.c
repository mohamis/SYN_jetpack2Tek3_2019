

#include "client.h"
#include <ctype.h>

int recv_from(int socket)
{
    char buffer[1024];
    int n = recv(socket, buffer, sizeof(buffer) - 1, 0);

    if (n < 0) {
        perror("recv()");
        return (84);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);
    return (0);
}

fd_set init_select(int sock)
{
    fd_set rdfs;
    fd_set err;

    #ifdef __APPLE__
        err.fds_bits[0] = 84;
    #else
        err.__fds_bits[0] = 84;
    #endif
    FD_ZERO(&rdfs);
    FD_SET(STDIN_FILENO, &rdfs);
    FD_SET(sock, &rdfs);
    if (select(sock + 1, &rdfs, NULL, NULL, NULL) == -1) {
        perror("select()");
        close(sock);
        return (err);
    }
    return (rdfs);
}

struct sockaddr_in init_sockadrr(struct sockaddr_in to_fill, int port,
                                    struct hostent *hostinfo)
{
    to_fill.sin_addr = *(struct in_addr *) hostinfo->h_addr_list[0];
    to_fill.sin_port = htons(port);
    to_fill.sin_family = PF_INET;
    return (to_fill);
}