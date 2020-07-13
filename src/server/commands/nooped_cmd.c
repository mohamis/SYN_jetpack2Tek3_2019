/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** pwd
*/

#include "jetpack.h"

void ready(__attribute__((unused)) char *lines)
{
    dprintf(tft_client, "READY\r\n");
}

void player(__attribute__((unused)) char *lines)
{
    dprintf(tft_client, "PLAYER <ID>\r\n");
}

void coin(__attribute__((unused)) char *lines)
{
    dprintf(tft_client, "COIN\r\n");
}

void fire_dir(__attribute__((unused)) char *lines)
{
    dprintf(tft_client, "FIRE\r\n");
}

void start(__attribute__((unused)) char *lines)
{
    dprintf(tft_client, "START\r\n");
}