/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:38:46 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 16:07:01 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	prog_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

static int	start_cub3d(char *file)
{
	t_prog	*prog;

	prog = get_prog();
	if (!prog)
		return (prog_error());
	if (!init_sdl(prog))
		return (prog_error());
	if (!setup(prog, file))
		return (prog_error());
	start_game(prog);
	SDL_DestroyWindow(prog->win);
	IMG_Quit();
  SDL_Quit();
	return (1);
}

int	main(int ac, char **av)
{
	if (check_arg(ac, av))
	{
		if (start_cub3d(av[1]))
			return (0);
		return (1);
	}
	return (1);
}
