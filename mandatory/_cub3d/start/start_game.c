/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:03:21 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 15:32:32 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	the_game(t_prog *prog)
{	
	game(prog);
	prog->frame++;
	return (0);
}

void	start_game(t_prog *prog)
{
	SDL_Event e;
	int				frame_time;

	while (!prog->quit)
	{
		frame_time = SDL_GetTicks();
		the_game(prog);
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				prog->quit = 1;
			else if (e.type == SDL_KEYDOWN)
				on_key_down(e.key.keysym.scancode, prog);
			else if (e.type == SDL_KEYUP)
				on_key_up(e.key.keysym.scancode, prog);
		}
		frame_time = SDL_GetTicks() - frame_time;
		if (frame_time < FRAME_DELAY) {
				SDL_Delay(FRAME_DELAY - frame_time);
		}
	}
}
