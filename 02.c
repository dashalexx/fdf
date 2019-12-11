/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:47:47 by tquence           #+#    #+#             */
/*   Updated: 2019/10/25 19:18:51 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc -I /Users/tquence/std/fdf/minilibx 03.c -L /Users/tquence/std/fdf/minilibx -lmlx -framework OpenGL -framework AppKit

#include <unistd.h>
#include "minilibx_macos/mlx.h"

void    ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_abs(int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

int     deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

//mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)
//{
//
//}

void drawLine(int x1, int y1, int x2, int y2) {
	void	*p;
	void    *wind;

	p = mlx_init();
	wind = mlx_new_window(p, 800, 800, "priv");
	const int deltaX = ft_abs(x2 - x1);
	const int deltaY = ft_abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;

	while(x1 != x2 || y1 != y2)
	{
		mlx_pixel_put(p, wind, x1, y1, 0xFFFFFF);
		const int error2 = error * 2;
		if(error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if(error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
	mlx_key_hook(wind, deal_key, (void *)0);
	mlx_loop(p);

}

int main()
{
	drawLine(200, 200, 250, 250);
	return (0);
}
