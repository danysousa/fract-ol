/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:00:49 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/27 16:14:33 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

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
		// MINX = -2.4 MAXX = 2.4
		// MINY = -1.5 MAXY = 1.5
		c->real = (-2.4) + (2.4 - (-2.4)) / W_WIDTH * x;
		c->img = (-1.5) + (1.5 - (-1.5)) / W_HEIGHT * y;
		z.real = 0;
		z.img = 0;
		i = 0;
		while (i < MAX_IT)
		{
			tmp.img = z.img;
			tmp.real = z.real;
			z.real = tmp.real * tmp.real - tmp.img * tmp.img + c->real;
			z.img = 2 * tmp.real * tmp.img + c->img;
			if (z.real * z.real + z.img * z.img >= 4)
				break;
			i++;
		}
		color = rgb_to_i((i + 42) % 256, (i + 120) % 256, 255 * (i < MAX_IT));
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
