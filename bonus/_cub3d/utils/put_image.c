#include "cub3d.h"

void  *put_image(t_prog *prog)
{
  SDL_UpdateWindowSurface(prog->win);
  return (prog);
}