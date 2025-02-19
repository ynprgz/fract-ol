/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:11:12 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/19 07:47:06 by yaperalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/**
 * @brief Display the string on the screen
 *
 * @param s is the string to display
 * @param fd is the file descriptor to write
 *
 * @return doesn't return anything
 */
void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

void	put_message(void)
{
	ft_putendl_fd("\n+===================================================+", 1);
	ft_putendl_fd("|                    FRACT'OL                       |", 1);
	ft_putendl_fd("+===================================================+\n", 1);
	ft_putendl_fd("\n   Usage: ./fractol <fractal code> <type>.\n", 1);
	ft_putendl_fd("   Available: Mandelbrot, Julia and Burningship.\n", 1);
	ft_putendl_fd("   The codes are 1, 2 and 3 respectively.\n", 1);
	ft_putendl_fd("   You can choose between different types of Julia\n", 1);
	ft_putendl_fd("   The types are 0, 1, 2 and 3 respectively\n", 1);
	ft_putendl_fd("   Type '0' is the standard for available fractals\n\n", 1);
	ft_putendl_fd("+===================================================+\n", 1);
}

void	set(t_data *f, char *one, char *two)
{
	f->f_code = (one[0] - '0');
	if (two[0] == '0')
	{
		f->c_re = -0.8;
		f->c_im = 0.156;
	}
	else if (two[0] == '1')
	{
		f->c_re = -0.4;
		f->c_im = 0.6;
	}
	else if (two[0] == '2')
	{
		f->c_re = -0.7269;
		f->c_im = 0.1889;
	}
	else if (two[0] == '3')
	{
		f->c_re = 0.285;
		f->c_im = 0.01;
	}
}
