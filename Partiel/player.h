#pragma once
#ifndef PLAYER_H
#define PLAYER_H

void action(SDL_Event evenement, int* player1_up, int* player1_down,
    int* player1_right, int* player1_left, int valeur);

void controller(int* continuer, int* player1_up, int* player1_down,
    int* player1_left, int* player1_right);

void deplacement(int* y, int* x, int player1_up
    , int player1_left, int player1_down, int player1_right);
#endif