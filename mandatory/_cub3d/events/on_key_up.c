/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:35:59 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 08:20:12 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_key_up(int keycode, t_prog *prog)
{
	if (keycode == KEY_ESC)
	{
		exit_cube3d(prog);
		return (0);
	}
	else
	{
		if (keycode == KEY_L || keycode == KEY_R)
			prog->pressed_key[0] = -1;
		else if (keycode == KEY_S || keycode == KEY_W)
			prog->pressed_key[1] = -1;
		else if (keycode == KEY_A || keycode == KEY_D)
			prog->pressed_key[2] = -1;
	}
	return (0);
}
