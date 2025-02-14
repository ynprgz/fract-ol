/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:34:14 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/14 11:50:05 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 *
 * @brief Initalize variables values and MiniLibX instance
 *
 */
void	init_data(t_data *f, char *code)
{
	f->mlx = mlx_init();
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol");
	f->image = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->image, &f->bpp, &f->line_length, &f->endian);
	f->f_code = (code[0] - '0');
	f->x = 0;
	f->y = 0;
	while (f->x < HEIGHT)
	{
		while (f->y < WIDTH)
		{
			if (f->f_code == 1)
				put_pixel(f, f->x, f->y, 0xFF5733);
			if (f->f_code == 2)
				put_pixel(f, f->x, f->y, 0x4CAF50);
			if (f->f_code == 3)
				put_pixel(f, f->x, f->y, 0x3A6EA5);
			(f->y;
		}
		f->y = 0;
		(f->x)++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
	mlx_loop(f->mlx);
}

/**
 *
 * @brief Validates command-line arguments
 *
 */

int	main(int argc, char **argv)
{
	t_data *f;

	if (argc != 2 || (argv[1][0] != '1' && argv[1][0] != '2' &&
		argv[1][0] != '3'))
	{
		ft_putendl_fd("Correct usage: './fractol <fractal code>'.", 1);
		ft_putendl_fd("Available: Mandelbrot, Julia and Burningship.", 1);
		ft_putendl_fd("The codes are 1, 2 and 3 respectively.", 1);
		return (0);
	}
	f = malloc(sizeof(t_data));
	init_data(f, argv[1]);
	return (0);
}
