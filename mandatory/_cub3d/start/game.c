/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:02:20 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 15:20:43 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_tex_line(t_prog *prog, int win_x, t_ray *ray)
{
	t_point	line;
	int			x;
	double	y;
	double	step;
	SDL_Surface	*tex;

	tex = prog->texs[ray->side];
	line.x = -0.5 * ray->line_height + HEIGHT / 2;
	line.y = 0.5 * ray->line_height + HEIGHT / 2;
	step = 1.0 * tex->h / ray->line_height;
	y = 0;
	if (line.x < 0)
	{
		y = -line.x * step;
		line.x = 0;
	}
	line.y = min(line.y, HEIGHT);
	x = tex->w * ray->wall_x;
	while (line.x < line.y)
	{
		ft_put_pixel_to_window_img(win_x, line.x,
			shade_color(ft_get_pixel(tex, x, y), ray->dist * 0.4));
		line.x++;
		y += step;
	}
}

static void	draw_floor(t_prog *prog)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (j < HEIGHT / 2)
				ft_put_pixel_to_window_img(i, j, shade_color(
						prog->floor[0], (j + 200) * 0.005));
			else
				ft_put_pixel_to_window_img(i, j, shade_color(
						prog->floor[1], (HEIGHT - j + 200) * 0.005));
			i++;
		}
		j++;
	}
}

void	game(t_prog *prog)
{
	t_ray		ray;
	int			x;
	double		camera_x;

	new_frame_image(prog);
	draw_floor(prog);
	x = -1;
	while (++x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1.0;
		raycasting(camera_x, &ray, &prog->player);
		draw_tex_line(prog, x, &ray);
	}
	perform_events(prog);
	put_image(prog);
}
