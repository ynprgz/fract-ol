/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:09:51 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/15 10:05:18 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MiniLibX/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 999
# define WIDTH 999

typedef struct s_data
{
	int		f_code;
	void	*mlx;
	void	*window;
	void	*image;
	int		color;
	int		max_iterations;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}	t_data;

// utils.c
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t count);

// print_pixels.c
void put_pixel(t_data *f, int x, int y, int color);

// draw.c
void	draw_fractal(t_data *f);

#endif
