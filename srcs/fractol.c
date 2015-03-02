/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 15:11:23 by dsousa            #+#    #+#             */
/*   Updated: 2015/03/02 12:19:21 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 32)
		e->clic.active = e->clic.active ? 0 : 1;
	return (0);
}

static int		init(t_env *e, char *argv[], int argc)
{
	if (ft_strlen(argv[1]) != 1 || !ft_isdigit(argv[1][0]))
		return (-1);
	if (argc == 3 && (ft_strlen(argv[2]) != 1 || !ft_isdigit(argv[2][0])))
		return (-1);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, "fractol");
	e->fractal.id = ft_atoi(argv[1]);
	e->fractal.gen = argc == 3 ? ft_atoi(argv[2]) : 0;
	if (e->fractal.id > 4 || e->fractal.gen > 1)
		return (-1);
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
	return (0);
}

int				loop(t_env *e)
{
	if (e->fractal.id == 0)
		draw_julia(e);
	else if (e->fractal.id == 1)
		draw_mandelbrot(e);
	else if (e->fractal.id == 2)
		draw_burning_ship(e);
	else if (e->fractal.id == 3)
		draw_buddhabrot(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.ptr, 0, 0);
	return (0);
}

void			ft_usage(void)
{
	ft_putendl("usage : ./fractol [ID] [procedural option]");
	ft_putendl("(0) Julia");
	ft_putendl("(1) Mandelbrot");
	ft_putendl("(2) Burning Ship");
	ft_putendl("(3) Buddhabrot");
	exit(-1);
}

int				main(int argc, char *argv[])
{
	t_env		e;

	if (argc > 1 && argc < 4)
	{
		if (init(&e, argv, argc) == -1)
			ft_usage();
		mlx_hook(e.win, MotionNotify, PointerMotionMask, hook, &e);
		mlx_hook(e.win, ButtonPress, ButtonPressMask, press_hook, &e);
		mlx_hook(e.win, ButtonRelease, ButtonReleaseMask, release_hook, &e);
		mlx_key_hook(e.win, key_hook, &e);
		mlx_loop_hook(e.mlx, loop, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_usage();
	return (0);
}
