/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:17:45 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 14:00:47 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(SDL_Surface* surface, unsigned int x, unsigned int y, unsigned int color)
{
	if (y >= (unsigned int)surface->h || x >= (unsigned int)surface->w)
		return ;
	*((Uint32*)((Uint8*)surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel)) = color;
}

void	ft_put_pixel_to_window_img(unsigned int x, unsigned int y, unsigned int color)
{
	static t_prog	*prog;

	if (!prog)
		prog = get_prog();
	ft_put_pixel(prog->win_tex, x, y, color);
}

void	ft_put_pixel_in(SDL_Surface* surface, unsigned int x, unsigned int y, unsigned int color)
{
	Uint32				*pixels;
	float					p;

	if (y >= (unsigned int)surface->h || x >= (unsigned int)surface->w)
		return ;
	pixels = ((Uint32*)((Uint8*)surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel));

	p = ((float)((color >> 24) & 255) / 255);
	*pixels = ((int)((((*pixels) >> 16) & 255)
				* (1 - p) + (((color) >> 16) & 255) * (p)) << 16)
		| ((int)((((*pixels) >> 8) & 255)
				* (1 - p) + (((color) >> 8) & 255) * (p)) << 8)
		| ((int)(((*pixels) & 255) * (1 - p)
				+ ((color) & 255) * (p)));
}

void	ft_put_pixel_in_to_window_img(unsigned int x, unsigned int y, unsigned int color)
{
	static t_prog	*prog;

	if (!prog)
		prog = get_prog();
	ft_put_pixel_in(prog->win_tex, x, y, color);
}

unsigned int ft_get_pixel(SDL_Surface* surface, unsigned int x, unsigned int y)
{
	if (x < (unsigned int)surface->w && y < (unsigned int)surface->h){
		Uint32 pixel = *((Uint32*)((Uint8*)surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel));
    return pixel;
	}
	return 0;
}
