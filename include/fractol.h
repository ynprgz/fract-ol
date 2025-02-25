/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:09:51 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/25 13:26:01 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define HEIGHT 700
# define WIDTH 700

typedef struct s_data
{
	int		f_code;
	void	*mlx;
	void	*window;
	void	*image;
	int		color;
	int		max_iters;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	re_factor;
	double	im_factor;
	double	z_re;
	double	z_im;
	double	c_re;
	double	c_im;
	double	move_factor;
}	t_data;

// utils.c
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	set(t_data *f, char *one, char *two);
void	put_message(void);
int		exit_program(t_data *f);

// print_pixels.c
void	put_pixel(t_data *f, int x, int y, int color);

// draw.c
void	draw_fractal(t_data *f);

// mandelbrot.c
void	mandelbrot(t_data *f);

// julia.c
void	julia(t_data *f);

// burningship.c
void	burningship(t_data *f);

// pixel_to_complexplane.c
void	pixel_to_complexplane(t_data *f);
void	set_coord(t_data *f);

// events.c
int		handle_keys(int keycode, t_data *f);
int		handle_close(t_data *f);
int		handle_mouse(int keycode, int x, int y, t_data *f);
void	zoom(t_data *f, int mouse_x, int mouse_y, double zoom_factor);
int		handle_arrows(int keycode, t_data *f);

// check_args.c
int		check_args(int argc, char **argv);

#endif
