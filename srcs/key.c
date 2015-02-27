/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 11:21:44 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/27 12:41:24 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void		zoom(int direction, double x, double y, t_env *e)
{
	e->fractal.zoom += ((float)direction * 0.5);
	e->fractal.pos_x += (x - e->fractal.pos_x) / 8.0;
	e->fractal.pos_y += (y - e->fractal.pos_y) / 8.0;
}

int				press_hook(int keycode, int x, int y, t_env *e)
{
	if (keycode == 5 || keycode == 4)
	{
		keycode = keycode == 5 ? 1 : -1;
		zoom(keycode, (x - (W_WIDTH / 2)), (y - (W_HEIGHT / 2)), e);
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
	e->fractal.zoom = 0;
	return (0);
}
