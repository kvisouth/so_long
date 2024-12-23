/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:06:27 by kevso             #+#    #+#             */
/*   Updated: 2024/12/23 17:24:06 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Get the number of enemies in the map */
void	get_enemies_nbr(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->nbr_enemies = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == '2')
				game->nbr_enemies++;
			j++;
		}
		i++;
	}
}

/* Initialise la liste chainee des ennemis */
int	init_enemies(t_game *game)
{
	t_enemy	*new;
	int		i;

	get_enemies_nbr(game);
	i = game->nbr_enemies;
	game->enemy = NULL;
	while (i > 0)
	{
		new = malloc(sizeof(t_enemy));
		if (!new)
			return (0);
		new->x = 0;
		new->y = 0;
		new->next = game->enemy;
		game->enemy = new;
		i--;
	}
	return (1);
}
