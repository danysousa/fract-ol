/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 12:27:45 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/24 15:15:20 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ZOOM 10
# define ORIGINE_X 500
# define ORIGINE_Y 700
# define W_WIDTH 700
# define W_HEIGHT 500
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <libft.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			fractal;
}				t_env;

#endif
