/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaperalt <yaperalt@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:11:12 by yaperalt          #+#    #+#             */
/*   Updated: 2025/02/15 13:00:58 by yaperalt         ###   ########.fr       */
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

/**
 * @brief Compare string until count count position is reached
 *
 * @param s1 First string to compare
 * @param s2 Second string to compare
 * @param count Number of characters to compare
 *
 * @return == 0 if equal
 */
int	ft_strncmp(const char *s1, const char *s2, size_t count)
{
	size_t	i;

	i = 0;
	if (count == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0'
		&& s1[i] == s2[i] && (i < count - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	put_message(void)
{
	ft_putendl_fd("\n+===================================================+", 1);
	ft_putendl_fd("|                    FRACT'OL                       |", 1);
	ft_putendl_fd("+===================================================+\n", 1);
	ft_putendl_fd("\n    Correct usage: './fractol <fractal code>'.\n", 1);
	ft_putendl_fd("    Available: Mandelbrot, Julia and Burningship.\n", 1);
	ft_putendl_fd("    The codes are 1, 2 and 3 respectively.\n\n", 1);
	ft_putendl_fd("+===================================================+\n", 1);
}
