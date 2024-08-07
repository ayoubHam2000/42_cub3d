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

static void	control_mouse(t_prog *prog)
{
	int margin;
	int mouse_x;
	int mouse_y;

	margin = 5;
	mouse_x = prog->m_x;
	mouse_y = prog->m_y;
	if (mouse_x > 0 && mouse_y < HEIGHT)
		SDL_ShowCursor(SDL_DISABLE);
	else
		SDL_ShowCursor(SDL_ENABLE);
	if (mouse_x <= margin)
			mouse_x = WIDTH - margin - 1;
	else if (mouse_x >= WIDTH - margin)
			mouse_x = margin - 1;
	if (mouse_x != prog->m_x || mouse_y != prog->m_y)
		SDL_WarpMouseInWindow(prog->win, mouse_x, mouse_y);
}

static int	the_game(t_prog *prog)
{	
	if (prog->player.health > 0)
	{
		control_mouse(prog);
		game(prog);
	}
	else
	{
		game_over(prog);
	}
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
			else if (e.type == SDL_MOUSEMOTION)
				on_mouse_move(e.motion.x, e.motion.y, prog);
			else if (e.type == SDL_MOUSEBUTTONUP)
				on_mouse_up(e.button.button, prog);
		}
		frame_time = SDL_GetTicks() - frame_time;
		if (frame_time < FRAME_DELAY) {
				SDL_Delay(FRAME_DELAY - frame_time);
		}
	}
}
