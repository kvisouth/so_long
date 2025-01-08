/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_player_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:43:30 by kevisout          #+#    #+#             */
/*   Updated: 2025/01/08 17:32:40 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Goblin qui respire */
void	init_goblin_textures(t_texture *w)
{
	w->sprite[0] = "./assets/gob_0.xpm";
	w->sprite[1] = "./assets/gob_1.xpm";
	w->sprite[2] = "./assets/gob_2.xpm";
	w->sprite[3] = "./assets/gob_3.xpm";
	w->sprite[4] = "./assets/gob_4.xpm";
	w->sprite[5] = "./assets/gob_5.xpm";
	w->sprite[6] = "./assets/gob_6.xpm";
	w->sprite[7] = "./assets/gob_7.xpm";
}

/* "Dessine" la texture goblin.xpm sur la fenetre la ou y'a 'P' sur la map */
void	put_player(t_game *game)
{
	t_texture	w;
	int			i;
	int			j;

	init_goblin_textures(&w);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'P')
			{
				w.img = mlx_xpm_file_to_image(game->mlx, w.sprite[game->clock],
						&w.width, &w.height);
				if (w.img == NULL)
					return ;
				mlx_put_image_to_window(game->mlx, game->win, w.img,
					j * 64, i * 64);
				mlx_destroy_image(game->mlx, w.img);
			}
			j++;
		}
		i++;
	}
}
