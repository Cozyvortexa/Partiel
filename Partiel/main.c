#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>

#include "INITG.h"
#include "PLAYER.h"


struct Joueurs {
	int x;
	int y;
};

int player1_up = 0;
int player1_down = 0;
int player1_left = 0;
int player1_right = 0;
int player1_shoot = 0;

int continuer = 1;

int x = 200;
int y = 500;

int main() {
	initSDL();
	SDL_Window* window = initWindow();
	SDL_Renderer* renderer = initRenderer(window);

	while (continuer) {
		clearRenderer(renderer);

		controller(&continuer, &player1_up, &player1_down, &player1_left,
			&player1_right);
		deplacement(&y, &x,player1_up,
			player1_left, player1_down, player1_right);
	}


	freeAll(renderer, window);
	return 0;
}





