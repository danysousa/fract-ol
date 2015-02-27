/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 12:27:45 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/27 16:25:01 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ZOOM 10
# define ORIGINE_X 500
# define ORIGINE_Y 700
# define W_WIDTH 700
# define W_HEIGHT 500
# define MAX_IT 42
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <libft.h>
# include "/usr/X11/include/X11/X.h"

typedef struct		s_fractal
{
	int				id;
	float			zoom;
	float			pos_x;
	float			pos_y;
	double			max_x;
	double			max_y;
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
#endif
