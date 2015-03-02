/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 12:10:11 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/02 14:25:34 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <math.h>


static t_img		brain_init(int x, int y, t_env *e, t_img *c)
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
	z.real = min_x + ( max_x - min_x ) / W_WIDTH * (x);
	z.img = min_y + ( max_y - min_y ) / W_HEIGHT * (y);
	c->real = 0.6;
	c->img = 0.2;
	return (z);
}

static int		choose_color(int i)
{
	int			color;

	if (i == MAX_IT)
		color = rgb_to_i(240, 230, 10);
	else
		color = rgb_to_i(sin((float)i / ((float)MAX_IT / 4)) * 255, \
			sin((float)i / ((float)MAX_IT)) * 255, 0);

	return (color);
}

static void		brain_col(t_env *e, int y, t_img *c)
{
	int			x;
	int			i;
	int			color;
	t_img		z;
	t_img		tmp;

	x = 0;
	while (x < W_WIDTH)
	{
		z = brain_init(x, y, e, c);
		i = 0;
		while (i < MAX_IT)
		{
			tmp.img = z.img;
			tmp.real = z.real;
			z.real = tmp.real * tmp.real - tmp.img * tmp.img + c->real;
			z.img = 2 * fabs(tmp.real * tmp.img) + c->img;
			if (z.real * z.real + z.img * z.img >= 4)
				break;
			i++;
		}
		color = choose_color(i);
		verif_print(e, x, y, color);
		x++;
	}
}

void			draw_brain(t_env *e)
{
	int		y;
	t_img	img;


	y = 0;
	while (y < W_HEIGHT)
	{
		brain_col(e, y++, &img);
	}
}
