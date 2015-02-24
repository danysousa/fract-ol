/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 15:11:23 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/24 17:03:06 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int		expose_hook(t_env *e)
{
	if (e->fractal == 1)
		draw_julia(e);
	else
		draw_mandelbrot(e);
	return (0);
}

static int		key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int				main(int argc, char *argv[])
{
	t_env	e;

	if (argc > 1)
	{
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, W_WIDTH, W_HEIGHT, "fractol");
		e.fractal = ft_atoi(argv[1]);
		e.zoom = 0.0;
		e.x = 0.0;
		e.y = 0.0;
		mlx_key_hook(e.win, key_hook, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_putendl("usage : ./fractol [fractal_id]\n");
	return (0);
}
