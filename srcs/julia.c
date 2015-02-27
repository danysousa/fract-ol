/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:35:25 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/27 16:19:15 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <math.h>

static void		julia_col(t_env *e, int y, t_img *c)
{
	int			x;
	int			i;
	int			color;
	t_img		z;
	t_img		tmp;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;

	x = 0;
	while (x < W_WIDTH)
	{
		min_x = (-e->fractal.max_x / e->fractal.zoom) + e->fractal.pos_x;
		max_x = (e->fractal.max_x / e->fractal.zoom) + e->fractal.pos_x;
		min_y = (-e->fractal.max_y / e->fractal.zoom) + e->fractal.pos_y;
		max_y = (e->fractal.max_y / e->fractal.zoom) + e->fractal.pos_y;


		z.real = min_x + ( max_x - min_x ) / W_WIDTH * (x);// / e->fractal.zoom);
		z.img = min_y + ( max_y - min_y ) / W_HEIGHT * (y);// / e->fractal.zoom);


		c->real = (e->clic.x * 0.5) / (long double)W_WIDTH;
		c->img = (e->clic.y * 0.5) / (long double)W_HEIGHT;

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
		// color = rgb_to_i((i + 42) % 256, (i + 120) % 256, 255 * (i < MAX_IT));
		if (i == MAX_IT)
			color = rgb_to_i(240, 230, 10);
		else
			color = rgb_to_i(sin((float)i / ((float)MAX_IT / 2)) * 255, 0, 0);
		verif_print(e, x, y, color);
		x++;
	}
}

void			draw_julia(t_env *e)
{
	int		y;
	t_img	img;


	y = 0;
	while (y < W_HEIGHT)
	{
		julia_col(e, y++, &img);
	}
}
