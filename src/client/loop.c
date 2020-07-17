

#include "client.h"
#include <ctype.h>

fd_set read_main(fd_set rdfs, int socket)
{
                rdfs = init_select(socket);
            #ifdef __APPLE__
                if (rdfs.fds_bits[0] == 84)
                    exit (84);
            #else
                if (rdfs.__fds_bits[0] == 84)
                    exit (84);
            #endif
            return (rdfs);
}

int loop_main(int socket, t_client *client, size_t bufsize, size_t characters)
{
        while (1) {
            client->rdfs = read_main(client->rdfs, socket);
            if (FD_ISSET(STDIN_FILENO, &client->rdfs)) {
                    characters = getline(&client->buffer, &bufsize, stdin);
                    if (characters == (size_t) -1) {
                        perror("getline()");
                        close(socket);
                        return (84);
                    }
                    if (send_to(socket, client->buffer) == 84) {
                        close(socket);
                        return (84);
                    }
            } else if (FD_ISSET(socket, &client->rdfs)) {
                if (recv_from(socket) == 84)
                    return (84);
            }
        }
}