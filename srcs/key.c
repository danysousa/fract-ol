/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 11:21:44 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/27 16:10:42 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void		zoom(int keycode, double x, double y, t_env *e)
{
	float		direction;

	direction = keycode == 4 ? 0.9 : 1.05;
	e->fractal.zoom *= (direction);
	e->fractal.pos_x += (x / (W_WIDTH / 2) ) / e->fractal.zoom;
	e->fractal.pos_y += (y / (W_HEIGHT / 2) ) / e->fractal.zoom;
}

int				press_hook(int keycode, int x, int y, t_env *e)
{
	if (keycode == 5 || keycode == 4)
	{
		zoom(keycode, x - (W_WIDTH / 2), y - (W_HEIGHT / 2), e);
		return (0);
	}
	else if (keycode != 1)
		return (0);
	if (e->clic.active)
		return (0);
	e->clic.active = 1;
	e->clic.x = x;
	e->clic.y = y;

	return (0);
}

int				release_hook(int keycode, int x, int y, t_env *e)
{
	if (keycode != 1)
		return (0);
	e->clic.active = 0;
	e->clic.x = x;
	e->clic.y = y;
	return (0);
}

int				hook(int x, int y, t_env *e)
{
	if (e->clic.active)
	{
		e->clic.x = x;
		e->clic.y = y;
		return (0);
	}
	return (0);
}
