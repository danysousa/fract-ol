/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:00:49 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/27 18:31:05 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <math.h>

static t_img		mandelbrot_init(int x, int y, t_env *e, t_img *c)
{
	t_img		z;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;

	min_x = (-e->fractal.max_x / e->fractal.zoom) + e->fractal.pos_x;
	max_x = (e->fractal.max_x / e->fractal.zoom) + e->fractal.pos_x;
	min_y = (-e->fractal.max_y / e->fractal.zoom) + e->fractal.pos_y;
	max_y = (e->fractal.max_y / e->fractal.zoom) + e->fractal.pos_y;
	c->real = min_x + ( max_x - min_x ) / W_WIDTH * (x);
	c->img = min_y + ( max_y - min_y ) / W_HEIGHT * (y);
	z.real = 0;
	z.img = 0;
	return (z);
}

static int		choose_color(int i, t_env *e)
{
	int			color;
	int			tmp;

	if (e->fractal.gen)
		tmp = (int)(MAX_IT + e->fractal.zoom / 1000);
	else
		tmp = MAX_IT;
	if (i == tmp)
		color = rgb_to_i(200, 190, 120);
	else
		color = rgb_to_i(sin((float)i / ((float)MAX_IT / 2)) * 255, 0, 0);

	return (color);
}

static void		mandelbrot_col(t_env *e, int y, t_img *c)
{
	int			x;
	int			i;
	int			color;
	t_img		z;
	t_img		tmp;

	x = 0;
	while (x < W_WIDTH)
	{
		z = mandelbrot_init(x, y, e, c);
		i = 0;
		while (i < (int)(MAX_IT + (e->fractal.zoom / 1000) * e->fractal.gen))
		{
			tmp.img = z.img;
			tmp.real = z.real;
			z.real = tmp.real * tmp.real - tmp.img * tmp.img + c->real;
			z.img = 2 * tmp.real * tmp.img + c->img;
			if (z.real * z.real + z.img * z.img >= 4)
				break;
			i++;
		}
		color = choose_color(i, e);
		verif_print(e, x, y, color);
		x++;
	}
}

void			draw_mandelbrot(t_env *e)
{
	int		y;
	t_img	img;


	y = 0;
	while (y < W_HEIGHT)
	{
		mandelbrot_col(e, y++, &img);
	}
}
