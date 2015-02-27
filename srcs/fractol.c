/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 15:11:23 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/27 17:41:55 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

// static int		expose_hook(t_env *e)
// {
// 	if (e->fractal.id == 1)
// 		draw_julia(e);
// 	else
// 		draw_mandelbrot(e);
// 	return (0);
// }

static int		key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

static void		init(t_env *e, int id)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, "fractol");
	e->fractal.id = id;
	e->fractal.zoom = 1.0;
	e->fractal.pos_x = 0.0;
	e->fractal.pos_y = 0.0;
	e->fractal.max_x = 2.4;
	e->fractal.max_y = 1.5;
	e->clic.active = 0;
	e->clic.x = 0;
	e->clic.y = 0;
	e->img.ptr = mlx_new_image (e->mlx, W_WIDTH, W_HEIGHT);
	e->img.data = mlx_get_data_addr(e->img.ptr, &e->img.bpp, &e->img.size_line,\
	&e->img.endian);
}

int				loop(t_env *e)
{
	if (e->fractal.id == 1)
		draw_julia(e);
	else
		draw_mandelbrot(e);

	mlx_put_image_to_window(e->mlx, e->win, e->img.ptr, 0, 0);

	return (0);
}

int				main(int argc, char *argv[])
{
	t_env		e;

	if (argc > 1)
	{
		init(&e, ft_atoi(argv[1]));
		mlx_hook(e.win, MotionNotify, PointerMotionMask, hook, &e);
		mlx_hook(e.win, ButtonPress, ButtonPressMask, press_hook, &e);
		mlx_hook(e.win, ButtonRelease, ButtonReleaseMask, release_hook, &e);
		mlx_key_hook(e.win, key_hook, &e);
		// mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop_hook(e.mlx, loop, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_putendl("usage : ./fractol [fractal_id]\n");
	return (0);
}
