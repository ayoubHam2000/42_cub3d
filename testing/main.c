
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void putPixel(SDL_Surface* surface, unsigned int x, unsigned int y, Uint32 pixel) {
    Uint32* pixels = (Uint32*)surface->pixels;
    pixels[y * surface->w + x] = pixel;
}

unsigned int get_pixel(SDL_Surface* surface, unsigned int x, unsigned int y)
{
    if (x <= surface->w && y <= surface->h)
        return *(((unsigned int *)surface->pixels) + surface->w * y + x);
    return 0;
}

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Get window surface
    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

    // Create a surface
    SDL_Surface* bufferSurface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0, 0, 0, 0);
    if (bufferSurface == NULL) {
        printf("Surface could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }


    int imgFlags = 255;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        SDL_Log("Unable to initialize SDL_image: %s", IMG_GetError());
        SDL_Quit();
        return 1;
    }


    // Load PNG image
    SDL_Surface *imageSurface = IMG_Load("1.jpg");
    if (imageSurface == NULL) {
        SDL_Log("Unable to load image: %s", IMG_GetError());
        SDL_Quit();
        return 1;
    }



    // Fill the surface with a color (e.g., red)
    putPixel(bufferSurface, 100, 100, SDL_MapRGB(bufferSurface->format, 0, 255, 0));
    //SDL_FillRect(bufferSurface, NULL, SDL_MapRGB(bufferSurface->format, 255, 0, 0));

    // Blit the surface onto the screen surface
    SDL_BlitSurface(imageSurface, NULL, screenSurface, NULL);

    // Update the window surface
    SDL_UpdateWindowSurface(window);

    // Wait two seconds
        // Main loop
    int quit = 0;

    // Event handler
    SDL_Event e;

    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            // Handle keydown event
            else if (e.type == SDL_KEYDOWN) {
                printf("Key pressed with keycode: %d\n", e.key.keysym.sym);
            }
            // Handle keyup event
            else if (e.type == SDL_KEYUP) {
                printf("Key released with keycode: %d\n", e.key.keysym.sym);
            }
            // Handle mouse movement event
            else if (e.type == SDL_MOUSEMOTION) {

                // Get mouse position
                int mouseX = e.motion.x;
                int mouseY = e.motion.y;

                if (mouseX >= SCREEN_WIDTH / 2) {
                    SDL_ShowCursor(SDL_ENABLE);
                } else {
                    SDL_ShowCursor(SDL_DISABLE);
                }

                // Constrain mouse position within window boundaries
                int margin = 5;
                if (mouseX <= margin) {
                    mouseX = SCREEN_WIDTH - margin - 1;
                } else if (mouseX >= SCREEN_WIDTH - margin) {
                    mouseX = margin - 1;
                }
                if (mouseY <= margin) {
                    mouseY = SCREEN_HEIGHT - margin - 1;
                } else if (mouseY >= SCREEN_HEIGHT - margin) {
                    mouseY = margin - 1;
                }

                if (mouseX != e.motion.x || mouseY != e.motion.y) {
                    SDL_WarpMouseInWindow(window, mouseX, mouseY);
                }
                
                
                printf("Mouse moved to (%d, %d)\n", e.motion.x, e.motion.y);
            }

            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    // Left mouse button pressed
                } else if (e.button.button == SDL_BUTTON_RIGHT) {
                    // Right mouse button pressed
                }
            } else if (e.type == SDL_MOUSEBUTTONUP) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    // Left mouse button released
                } else if (e.button.button == SDL_BUTTON_RIGHT) {
                    // Right mouse button released
                }
            } else if (e.type == SDL_QUIT) {
                quit = 1;
            }

            

        }
    }

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}