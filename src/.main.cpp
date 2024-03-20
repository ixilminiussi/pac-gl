#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include <SDL2/SDL_video.h>
#include <iostream>

/* Sets constants */
#define WIDTH 800
#define HEIGHT 600
#define DELAY 3000

int main(int argc, char **argv) {
    /* Initialises data */
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);

    /* Creates a SDL window */
    window =
        SDL_CreateWindow("Pacman",                /* Title of the SDL window */
                         SDL_WINDOWPOS_UNDEFINED, /* Position x of the window */
                         SDL_WINDOWPOS_UNDEFINED, /* Position y of the window */
                         WIDTH,  /* Width of the window in pixels */
                         HEIGHT, /* Height of the window in pixels */
                         SDL_WINDOW_OPENGL); /* Additional flag(s) */

    /* Checks if window has been created; if not, exits program */
    if (window == NULL) {
        std::cout << "SDL window failed to initialise: %s" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    // A basic main loop to prevent blocking
    bool is_running = true;
    SDL_Event event;
    while (is_running) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                is_running = false;
            }
        }
        SDL_Delay(16);
    }

    /* Frees memory */
    SDL_DestroyWindow(window);

    /* Shuts down all SDL subsystems */
    SDL_Quit();

    return 0;
}
