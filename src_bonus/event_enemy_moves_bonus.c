/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_enemy_moves_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:04:23 by kevso             #+#    #+#             */
/*   Updated: 2024/12/23 17:04:28 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	enemy_move_right(t_game *game, t_enemy *tmp)
{
	if (game->map.map[tmp->y][tmp->x + 1] == 'P')
		end_game(game);
	game->map.map[tmp->y][tmp->x] = '0';
	tmp->x++;
	game->map.map[tmp->y][tmp->x] = '2';
}

void	enemy_move_down(t_game *game, t_enemy *tmp)
{
	if (game->map.map[tmp->y + 1][tmp->x] == 'P')
		end_game(game);
	game->map.map[tmp->y][tmp->x] = '0';
	tmp->y++;
	game->map.map[tmp->y][tmp->x] = '2';
}

void	enemy_move_left(t_game *game, t_enemy *tmp)
{
	if (game->map.map[tmp->y][tmp->x - 1] == 'P')
		end_game(game);
	game->map.map[tmp->y][tmp->x] = '0';
	tmp->x--;
	game->map.map[tmp->y][tmp->x] = '2';
}

void	enemy_move_up(t_game *game, t_enemy *tmp)
{
	if (game->map.map[tmp->y - 1][tmp->x] == 'P')
		end_game(game);
	game->map.map[tmp->y][tmp->x] = '0';
	tmp->y--;
	game->map.map[tmp->y][tmp->x] = '2';
}
