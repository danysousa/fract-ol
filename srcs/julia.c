/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:35:25 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/24 17:00:06 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void		julia_col(t_env *e, int y, t_img *c)
{
	int			x;
	int			i;
	int			color;
	t_img		z;
	t_img		tmp;

	x = 0;
	while (x < W_WIDTH)
	{
		z.real = (-2.4) + (2.4 - (-2.4)) / W_WIDTH * x;
		z.img = (-1.5) + (1.5 - (-1.5)) / W_HEIGHT * y;
		c->real = 50.0 / (long double)W_WIDTH;
		c->img = 100.0 / (long double)W_HEIGHT;
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
		color = rgb_to_i(i % 256, 120, 255 * (i < MAX_IT));
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
