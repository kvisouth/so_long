/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 03:03:15 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/27 19:22:02 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Actualise la position du joueur */
int	get_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
			}
			j++;
		}
		i++;
	}
	return (1);
}

/* Thread qui incremente clock de 1 toute les 100ms */
void	*clock_thread(void *arg)
{
	t_game	*game;

	game = (t_game *)arg;
	while (1)
	{
		if (game->finish)
			break ;
		game->clock++;
		if (game->clock == 8)
			game->clock = 0;
		usleep(100000);
	}
	return (NULL);
}

/* Free la liste chainee des ennemis */
void	free_enemies(t_enemy *enemies)
{
	t_enemy	*tmp;

	while (enemies)
	{
		tmp = enemies;
		enemies = enemies->next;
		free(tmp);
	}
}

/* Fonction pour free tout et fermer le programme */
int	end_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_tabs(game->map.map);
	free(game->mlx);
	if (game->enemy)
		free_enemies(game->enemy);
	game->finish = 1;
	pthread_join(game->thread, NULL);
	exit(0);
}
