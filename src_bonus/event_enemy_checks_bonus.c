/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_enemy_checks_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:04:32 by kevso             #+#    #+#             */
/*   Updated: 2024/12/23 17:04:46 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ennemy_check_right(t_game *game, t_enemy *tmp)
{
	if (tmp->x + 1 < game->map.width && game->map.map[tmp->y][tmp->x + 1] != '1'
		&& game->map.map[tmp->y][tmp->x + 1] != '2'
		&& game->map.map[tmp->y][tmp->x + 1] != 'E'
		&& game->map.map[tmp->y][tmp->x + 1] != 'C')
		return (1);
	return (0);
}

int	ennemy_check_down(t_game *game, t_enemy *tmp)
{
	if (tmp->y + 1 < game->map.height
		&& game->map.map[tmp->y + 1][tmp->x] != '1'
		&& game->map.map[tmp->y + 1][tmp->x] != '2'
		&& game->map.map[tmp->y + 1][tmp->x] != 'E'
		&& game->map.map[tmp->y + 1][tmp->x] != 'C')
		return (1);
	return (0);
}

int	ennemy_check_left(t_game *game, t_enemy *tmp)
{
	if (tmp->x - 1 >= 0 && game->map.map[tmp->y][tmp->x - 1] != '1'
		&& game->map.map[tmp->y][tmp->x - 1] != '2'
		&& game->map.map[tmp->y][tmp->x - 1] != 'E'
		&& game->map.map[tmp->y][tmp->x - 1] != 'C')
		return (1);
	return (0);
}

int	ennemy_check_up(t_game *game, t_enemy *tmp)
{
	if (tmp->y - 1 >= 0 && game->map.map[tmp->y - 1][tmp->x] != '1'
		&& game->map.map[tmp->y - 1][tmp->x] != '2'
		&& game->map.map[tmp->y - 1][tmp->x] != 'E'
		&& game->map.map[tmp->y - 1][tmp->x] != 'C')
		return (1);
	return (0);
}
