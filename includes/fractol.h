/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 12:27:45 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/02 14:45:48 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ZOOM 10
# define ORIGINE_X 500
# define ORIGINE_Y 700
# define W_WIDTH 700
# define W_HEIGHT 500
# define MAX_IT 60
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <libft.h>
# include "/usr/X11/include/X11/X.h"

typedef struct		s_image
{
	void			*ptr;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_fractal
{
	int				id;
	float			zoom;
	float			pos_x;
	float			pos_y;
	double			max_x;
	double			max_y;
	int				gen;
}					t_fractal;

typedef struct		s_clic
{
	int				active;
	int				x;
	int				y;
}					t_clic;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_fractal		fractal;
	t_clic			clic;
	t_image			img;
}					t_env;

typedef struct		s_img
{
	long double		img;
	long double		real;
}					t_img;

/*
** TOOLS
*/
int					rgb_to_i(int r, int g, int b);
void				verif_print(t_env *e, int x, int y, int color);

/*
** KEY
*/
int					press_hook(int keycode, int x, int y, t_env *e);
int					release_hook(int keycode, int x, int y, t_env *e);
int					hook(int x, int y, t_env *e);

/*
** JULIA
*/
void				draw_julia(t_env *e);

/*
** MENDELBROT
*/
void				draw_mandelbrot(t_env *e);

/*
** BURNING_SHIP
*/
void				draw_burning_ship(t_env *e);

/*
** BRAIN
*/
void				draw_brain(t_env *e);

#endif
