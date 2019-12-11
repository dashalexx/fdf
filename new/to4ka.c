/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to4ka.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:31:40 by tquence           #+#    #+#             */
/*   Updated: 2019/12/11 18:31:41 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../minilibx_macos/mlx.h"
#include <stdlib.h>

int	ft_abs(int a)
{
    if (a < 0)
        a *= -1;
    return (a);
}

int     deal_key(int key, void *param)
{
    if (key == 53)
        exit (0);
    return (0);
}


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
        mlx_pixel_put(p, wind, x1, y1, 0xFF00FF);
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
    drawLine(700, 200, 250, 700);
    return (0);
}
