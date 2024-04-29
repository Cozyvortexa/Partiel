#pragma once
#ifndef INITG_H
#define INITG_H

#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>



void initSDL();

SDL_Window* initWindow();

SDL_Renderer* initRenderer(SDL_Window* window);

void clearRenderer(SDL_Renderer* renderer);

void freeAll(SDL_Renderer* renderer, SDL_Window* window);

#endif
