/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_coins.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:44:10 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/10 18:45:07 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_coins_textures(t_texture *w)
{
	w->sprite[0] = "./assets/coin0.xpm";
	w->sprite[1] = "./assets/coin1.xpm";
	w->sprite[2] = "./assets/coin2.xpm";
	w->sprite[3] = "./assets/coin1.xpm";
	w->sprite[4] = "./assets/coin0.xpm";
	w->sprite[5] = "./assets/coin1.xpm";
	w->sprite[6] = "./assets/coin2.xpm";
	w->sprite[7] = "./assets/coin1.xpm";
}

/* "Dessine" la texture coin.xpm sur la fenetre la ou y'a des 'C' sur la map */
void	put_coins(t_game *game)
{
	t_texture	w;
	int			i;
	int			j;

	init_coins_textures(&w);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'C')
			{
				w.img = mlx_xpm_file_to_image(game->mlx, w.sprite[game->clock],
						&w.width, &w.height);
				mlx_put_image_to_window(game->mlx, game->win, w.img,
					j * 64, i * 64);
				mlx_destroy_image(game->mlx, w.img);
			}
			j++;
		}
		i++;
	}
}
