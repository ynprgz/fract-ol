/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:09:51 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/13 17:53:45 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MiniLibX/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include

# define HEIGHT 800
# define WIDTH 800

typedef struct s_data
{
	int		x;
	int		y;
	double	r;
	double	i;
	void	*mlx;
	void	*image;
}	t_data;

// utils.c
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t count);

#endif
