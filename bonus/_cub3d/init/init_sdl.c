/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:01:18 by aben-ham          #+#    #+#             */
/*   Updated: 2022/05/27 10:30:56 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*init_sdl(t_prog *prog)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return NULL;
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
		return NULL;
  SDL_Window* window = SDL_CreateWindow(
			WIN_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL)
		return NULL;
	prog->win = window;
	prog->win_tex = SDL_GetWindowSurface(prog->win);
	return prog;
}
