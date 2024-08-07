/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:48:49 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 18:26:41 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "utilities.h"
# include "structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include "SDL2/SDL.h"
# include "SDL2/SDL_image.h"

# define WIN_TITLE "cub3d"
# define WIDTH (800)
# define HEIGHT (500)
# define MAX_LINE 1000
# define FRAME_DELAY (1000 / 60)

# define KEY_L SDL_SCANCODE_LEFT
# define KEY_R SDL_SCANCODE_RIGHT
# define KEY_A SDL_SCANCODE_A
# define KEY_D SDL_SCANCODE_D
# define KEY_W SDL_SCANCODE_W
# define KEY_S SDL_SCANCODE_S
# define KEY_SPACE SDL_SCANCODE_SPACE
# define KEY_ESC SDL_SCANCODE_ESCAPE

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define R_SPEED 0.06
# define M_SPEED 0.11
# define MOUSE_ROTATE_SPEED 0.17

//init
int			check_arg(int ac, char **av);
t_prog		*get_prog(void);
void		*init_sdl(t_prog *prog);

//rendering
void		*new_frame_image(t_prog *prog);
void	ft_put_pixel(SDL_Surface* surface, unsigned int x, unsigned int y, unsigned int color);
void	ft_put_pixel_in(SDL_Surface* surface, unsigned int x, unsigned int y, unsigned int color);
void	ft_put_pixel_in_to_window_img(unsigned int x, unsigned int y, unsigned int color);
void	ft_put_pixel_to_window_img(unsigned int x, unsigned int y, unsigned int color);
int			get_tex_color(SDL_Surface *tex, int x, int y);
int			shade_color(int color, float divide);
unsigned int ft_get_pixel(SDL_Surface* surface, unsigned int x, unsigned int y);

//start
void		game(t_prog *prog);
void		start_game(t_prog *prog);

//parsing -> setup
int			check_map(char **map);
int			load_map(t_queue *map);
int			load_textures(t_prog *prog, t_queue *texs);
int			load_static(t_prog	*prog);
t_file_data	*read_file(char *file);
void		init_player_pos(t_player *player);
int			setup(t_prog *prog, char *file);
SDL_Surface *load_texture(char *path);

//events
int			on_key_down(int keycode, t_prog *prog);
int			on_key_up(int keycode, t_prog *prog);
void		exit_cube3d(t_prog *prog);
void		perform_events(t_prog *prog);


//ray_casting
void		raycasting(double camera_x, t_ray *ray, t_player *player);

//utils
void  *put_image(t_prog *prog);

int	load_types(t_prog *prog, t_queue *types);

#endif
