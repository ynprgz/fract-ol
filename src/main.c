/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:34:14 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/25 13:40:07 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief Initalize variables values and MiniLibX instance
 * @param code argv[1] for fractal type
 * @param type argv[2] for julia fractal type
 */
void	init_data(t_data *f, char *code, char *type)
{
	f->mlx = mlx_init();
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol");
	f->image = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->image, &f->bpp, &f->line_length, &f->endian);
	f->max_iters = 50;
	set(f, code, type);
	set_coord(f);
	f->color = 0xFCBE11;
	pixel_to_complexplane(f);
	draw_fractal(f);
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
	mlx_key_hook(f->window, &handle_arrows, f);
	mlx_mouse_hook(f->window, &handle_mouse, f);
	mlx_hook(f->window, 17, 0, &handle_close, f);
	mlx_loop(f->mlx);
}

/**
 * @brief Validates command-line arguments, allocates memory and initilize
 * variables.
 */
int	main(int argc, char **argv)
{
	t_data	*f;

	if (check_args(argc, argv))
		return (1);
	f = malloc(sizeof(t_data));
	if (!f)
		return (1);
	init_data(f, argv[1], argv[2]);
	return (0);
}
