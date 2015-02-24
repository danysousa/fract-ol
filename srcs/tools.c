/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:30:05 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/24 15:34:19 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

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
	if (x >= 0 && x <= W_WIDTH && y >= 0 && y <= W_HEIGHT)
		mlx_pixel_put(e->mlx, e->win, x, y, color);
}
