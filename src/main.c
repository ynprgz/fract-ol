/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:34:14 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/19 09:18:03 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief Initalize variables values and MiniLibX instance
 */
void	init_data(t_data *f, char *code, char *type)
{
	f->mlx = mlx_init();
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol");
	f->image = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->image, &f->bpp, &f->line_length, &f->endian);
	f->max_iters = 50;
	set(f, code, type);
	f->color = 0xFCBE11;
	pixel_to_complexplane(f);
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

	if (argc != 3 || (argv[1][0] != '1' && argv[1][0] != '2' &&
		argv[1][0] != '3') || (argv[2][0] != '0' && argv[2][0] != '1' &&
		argv[2][0] != '2' && argv[2][0] != '3'))
	{
		put_message();
		return (1);
	}
	else if ((argv[1][0] == '1' || argv[1][0] == '3') && (argv[2][0] != '0'))
	{
		put_message();
		return (1);
	}
	f = malloc(sizeof(t_data));
	if (!f)
		return (1);
	init_data(f, argv[1], argv[2]);
	return (0);
}
