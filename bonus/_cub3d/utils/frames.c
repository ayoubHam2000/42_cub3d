/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:01:30 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 13:10:22 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_over(t_prog *prog)
{
	int		      x;
	int		      y;
	SDL_Surface	*tex;

	new_frame_image(prog);
	if (prog->frame % 100 > 50)
		tex = prog->static_tex.game_over[0];
	else
		tex = prog->static_tex.game_over[1];
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_put_pixel_to_window_img(x, y, ft_get_pixel(tex, x * tex->w / WIDTH,
					y * tex->h / HEIGHT));
			x++;
		}
		y++;
	}
	put_image(prog);
}
