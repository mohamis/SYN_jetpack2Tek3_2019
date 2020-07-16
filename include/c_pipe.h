/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** pipe
*/

#ifndef PIPE_H_
#define PIPE_H_

static cmd_t c_func[] = {
    {"ID", &getID, 1},
    {"FINISH", &quit_finish, 0},
    {"COIN", &coin, 1},
    {"PLAYER", &player, 1},
    {"START", &start, 1},
    {"FIRE", &fire_dir, 1},
    {"READY", &ready, 1},
    {"MAP", &map_files, 1},
    {NULL, NULL, 0}
};

#endif /* !PIPE_H_ */