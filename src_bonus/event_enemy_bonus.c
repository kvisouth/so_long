/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:57:36 by kevso             #+#    #+#             */
/*   Updated: 2024/12/23 17:05:42 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Goblin qui respire */
void	init_enemy_textures(t_texture *w)
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
void	anim_enemy(t_game *game)
{
	t_texture	w;
	int			i;
	int			j;

	init_enemy_textures(&w);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == '2')
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

/* Initialise la position de chaque ennemi */
void	get_enemies_pos(t_game *game)
{
	t_enemy	*tmp;
	int		i;
	int		j;

	tmp = game->enemy;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == '2')
			{
				tmp->x = j;
				tmp->y = i;
				tmp = tmp->next;
			}
			j++;
		}
		i++;
	}
}

/* Bouge chaque ennemi vers le 0 le plus proche */
void	move_enemies(t_game *game)
{
	t_enemy	*tmp;

	tmp = game->enemy;
	while (tmp)
	{
		if (ennemy_check_right(game, tmp))
			enemy_move_right(game, tmp);
		else if (ennemy_check_down(game, tmp))
			enemy_move_down(game, tmp);
		else if (ennemy_check_left(game, tmp))
			enemy_move_left(game, tmp);
		else if (ennemy_check_up(game, tmp))
			enemy_move_up(game, tmp);
		tmp = tmp->next;
	}
}

void	put_enemy(t_game *game)
{
	anim_enemy(game);
	get_enemies_pos(game);
	if (game->x % 300 == 0)
		move_enemies(game);
}
