/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 12:27:45 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/24 17:03:30 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ZOOM 10
# define ORIGINE_X 500
# define ORIGINE_Y 700
# define W_WIDTH 700
# define W_HEIGHT 500
# define MAX_IT 20
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <libft.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				fractal;
	double			zoom;
	double			x;
	double			y;
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
** JULIA
*/
void				draw_julia(t_env *e);


/*
** MENDELBROT
*/
void				draw_mandelbrot(t_env *e);
#endif
