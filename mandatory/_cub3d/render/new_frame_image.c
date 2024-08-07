/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:20:10 by aben-ham          #+#    #+#             */
/*   Updated: 2022/04/02 09:09:00 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*new_frame_image(t_prog *prog)
{
	SDL_FillRect(prog->win_tex, NULL, SDL_MapRGB(prog->win_tex->format, 0, 0, 0));
	return prog;
}
