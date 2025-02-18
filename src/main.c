/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:34:14 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/18 12:26:35 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief Initalize variables values and MiniLibX instance
 */
void	init_data(t_data *f, char *code)
{
	f->mlx = mlx_init();
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol");
	f->image = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->image, &f->bpp, &f->line_length, &f->endian);
	f->max_iters = 50;
	f->f_code = (code[0] - '0');
	if (f->f_code == 2)
	{
		f->c_re = -0.8;
		f->c_im = 0.156;
	}
	f->color = 0xFFD700;
	draw_fractal(f);
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
	mlx_loop(f->mlx);
}

/**
 * @brief Validates command-line arguments and calls the pertinent functions
 */
int	main(int argc, char **argv)
{
	t_data	*f;

	if (argc != 2 || (argv[1][0] != '1' && argv[1][0] != '2' &&
		argv[1][0] != '3'))
	{
		put_message();
		return (1);
	}
	f = malloc(sizeof(t_data));
	if (!f)
		return (1);
	init_data(f, argv[1]);
	return (0);
}
