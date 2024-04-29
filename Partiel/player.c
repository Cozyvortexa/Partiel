#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>

#include "PLAYER.h"

#define LONGUEURPLAYER 100
#define LARGEURPLAYER 100

struct Joueurs {
    int x;
    int y;
};

void action(SDL_Event evenement, int* player1_up, int* player1_down,
    int* player1_right, int* player1_left, int valeur) {
    switch (evenement.key.keysym.sym) {
    case SDLK_z:
        *player1_up = valeur;
        break;
    case SDLK_s:
        *player1_down = valeur;
        break;
    case SDLK_d:
        *player1_right = valeur;
        break;
    case SDLK_q:
        *player1_left = valeur;
        break;
    }
}

void controller(int* continuer, int* player1_up, int* player1_down,
    int* player1_left, int* player1_right) {
    SDL_Event event;

    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            *continuer = 0;
        }
        else if (event.type == SDL_KEYDOWN) {
            action(event, player1_up, player1_down, player1_right,
                player1_left, 1);
        }
        else if (event.type == SDL_KEYUP) {
            action(event, player1_up, player1_down, player1_right,
                player1_left, 0);
        }
    }
}

void deplacement(int* y, int* x, int player1_up
    , int player1_left, int player1_down, int player1_right) {

    if (player1_up && *y >= 0) {
        *y -= 10;
    }
    else if (player1_down && *y + LARGEURPLAYER <= 1080) {
        *y += 10;
    }
    else if (player1_left && *x >= 0) {
        *x -= 10;
    }
    else if (player1_right && *x + LONGUEURPLAYER <= 1920) {
        *x += 10;
    }
}

struct Joueurs initJoueur(int x, int y) {
    struct Joueurs joueurs;
    joueurs.x = x;
    joueurs.y = y;
    return joueurs;
}