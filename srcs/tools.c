/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:30:05 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/27 17:40:08 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <math.h>

int			rgb_to_i(int r, int g, int b)
{
	int		rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;

	return (rgb);
}

void		verif_print(t_env *e, int x, int y, int color)
{
	int		index;

	index = 0;
	if (x >= 0 && x <= W_WIDTH && y >= 0 && y <= W_HEIGHT)
	{
		index = y * e->img.size_line + x * (e->img.bpp / 8);
		e->img.data[index] = color;
		e->img.data[index + 1] = color >> 8;
		e->img.data[index + 2] = color >> 16;
	}
}
