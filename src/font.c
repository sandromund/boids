#include "font.h"

SDL_Texture* createTextTexture(SDL_Color color, char* text, TTF_Font* font, SDL_Renderer* r) {
  SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
  if (textSurface == NULL) {
    fprintf(stderr, "Error creating text surface: %s\n", TTF_GetError());
    return NULL;
  }
  SDL_Texture* textTexture = SDL_CreateTextureFromSurface(r, textSurface);
  if (textTexture == NULL) {
    fprintf(stderr, "Error creating text texture\n");
    SDL_FreeSurface(textSurface);
    return NULL;
  }

  SDL_FreeSurface(textSurface);

  return textTexture;
}
