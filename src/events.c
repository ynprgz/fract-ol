/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 07:26:36 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/25 13:39:13 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	handle_close(t_data *f)
{
	exit_program(f);
	return (0);
}

int	handle_keys(int keycode, t_data *f)
{
	if (keycode == 65307)
		exit_program(f);
	else if (keycode == 61)
		f->color += 0x001100;
	else if (keycode == 45)
		f->color -= 0x001100;
	return (0);
}

int	handle_arrows(int keycode, t_data *f)
{
	handle_keys(keycode, f);
	if (keycode == 65362)
	{
		f->min_im += f->move_factor;
		f->max_im += f->move_factor;
	}
	else if (keycode == 65364)
	{
		f->min_im -= f->move_factor;
		f->max_im -= f->move_factor;
	}
	else if (keycode == 65361)
	{
		f->min_re -= f->move_factor;
		f->max_re -= f->move_factor;
	}
	else if (keycode == 65363)
	{
		f->min_re += f->move_factor;
		f->max_re += f->move_factor;
	}
	draw_fractal(f);
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
	return (0);
}

int	handle_mouse(int keycode, int x, int y, t_data *f)
{
	if (keycode == 4)
		zoom(f, x, y, 1.1);
	else if (keycode == 5)
		zoom(f, x, y, 0.9);
	draw_fractal(f);
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
	return (0);
}

void	zoom(t_data *f, int mouse_x, int mouse_y, double zoom_factor)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = f->min_re + (double)mouse_x / WIDTH * (f->max_re - f->min_re);
	mouse_im = f->max_im - (double)mouse_y / HEIGHT * (f->max_im - f->min_im);
	f->min_re = mouse_re + (f->min_re - mouse_re) / zoom_factor;
	f->max_re = mouse_re + (f->max_re - mouse_re) / zoom_factor;
	f->min_im = mouse_im + (f->min_im - mouse_im) / zoom_factor;
	f->max_im = mouse_im + (f->max_im - mouse_im) / zoom_factor;
	pixel_to_complexplane(f);
}
