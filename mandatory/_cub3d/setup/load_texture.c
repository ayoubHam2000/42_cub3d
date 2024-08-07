/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:42:23 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 17:43:05 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	format_tex_queue(t_queue *tex)
{
	t_node	*node;
	char	**split;

	if ((int)tex->len >= TEX_BUFFER_SIZE)
		return (0);
	node = tex->first;
	while (node)
	{
		split = ft_split(node->p, ' ');
		if (!split || ft_arrlen(split) != 2)
			return (0);
		node->p = split;
		node = node->next;
	}
	return (1);
}

SDL_Surface *load_texture(char *path)
{
	printf("load texture: %s\n", path);
	SDL_Surface *s = IMG_Load(path);
	SDL_Surface *new = SDL_ConvertSurfaceFormat(s, SDL_PIXELFORMAT_RGB888, 0);
	SDL_FreeSurface(s);
	return new;
}

int	load_textures(t_prog *prog, t_queue *tex)
{
	int			i;
	t_node	*node;

	if (!format_tex_queue(tex))
		return (0);
	i = 0;
	node = tex->first;
	while (node)
	{
		prog->texs[i] = load_texture(((char **)(node->p))[1]);
		if (!prog->texs[i])
			return 0;
		node->p = ((char **)(node->p))[0];
		i++;
		node = node->next;
	}
	return (1);
}
