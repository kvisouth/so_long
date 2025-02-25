/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 03:01:38 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/23 16:47:18 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Sur la map, deplace 'P' d'une case vers le haut et actualise sa position */
int	move_up(t_game *game)
{
	get_player_pos(game);
	if (game->map.map[game->player.y - 1][game->player.x] == '0'
		|| game->map.map[game->player.y - 1][game->player.x] == 'C')
	{
		if (game->map.map[game->player.y - 1][game->player.x] == 'C')
			game->player.coins++;
		game->map.map[game->player.y][game->player.x] = '0';
		game->map.map[game->player.y - 1][game->player.x] = 'P';
		game->player.y--;
		game->player.moves++;
	}
	else if (game->map.map[game->player.y - 1][game->player.x] == 'E'
		|| game->map.map[game->player.y - 1][game->player.x] == '2')
	{
		if (game->exit_status == 1)
		{
			game->player.moves++;
			end_game(game);
		}
		else if (game->map.map[game->player.y - 1][game->player.x] == '2')
			end_game(game);
	}
	return (1);
}

/* Sur la map, deplace 'P' d'une case vers le bas et actualise sa position */
int	move_down(t_game *game)
{
	get_player_pos(game);
	if (game->map.map[game->player.y + 1][game->player.x] == '0'
		|| game->map.map[game->player.y + 1][game->player.x] == 'C')
	{
		if (game->map.map[game->player.y + 1][game->player.x] == 'C')
			game->player.coins++;
		game->map.map[game->player.y][game->player.x] = '0';
		game->map.map[game->player.y + 1][game->player.x] = 'P';
		game->player.y++;
		game->player.moves++;
	}
	else if (game->map.map[game->player.y + 1][game->player.x] == 'E'
		|| game->map.map[game->player.y + 1][game->player.x] == '2')
	{
		if (game->exit_status == 1)
		{
			game->player.moves++;
			end_game(game);
		}
		else if (game->map.map[game->player.y + 1][game->player.x] == '2')
			end_game(game);
	}
	return (1);
}

/* Sur la map, deplace 'P' d'une case vers la gauche et actualise sa position */
int	move_left(t_game *game)
{
	get_player_pos(game);
	if (game->map.map[game->player.y][game->player.x - 1] == '0'
		|| game->map.map[game->player.y][game->player.x - 1] == 'C')
	{
		if (game->map.map[game->player.y][game->player.x - 1] == 'C')
			game->player.coins++;
		game->map.map[game->player.y][game->player.x] = '0';
		game->map.map[game->player.y][game->player.x - 1] = 'P';
		game->player.x--;
		game->player.moves++;
	}
	else if (game->map.map[game->player.y][game->player.x - 1] == 'E'
		|| game->map.map[game->player.y][game->player.x - 1] == '2')
	{
		if (game->exit_status == 1)
		{
			game->player.moves++;
			end_game(game);
		}
		else if (game->map.map[game->player.y][game->player.x - 1] == '2')
			end_game(game);
	}
	return (1);
}

/* Sur la map, deplace 'P' d'une case vers la droite et actualise sa position */
int	move_right(t_game *game)
{
	get_player_pos(game);
	if (game->map.map[game->player.y][game->player.x + 1] == '0'
		|| game->map.map[game->player.y][game->player.x + 1] == 'C')
	{
		if (game->map.map[game->player.y][game->player.x + 1] == 'C')
			game->player.coins++;
		game->map.map[game->player.y][game->player.x] = '0';
		game->map.map[game->player.y][game->player.x + 1] = 'P';
		game->player.x++;
		game->player.moves++;
	}
	else if (game->map.map[game->player.y][game->player.x + 1] == 'E'
		|| game->map.map[game->player.y][game->player.x + 1] == '2')
	{
		if (game->exit_status == 1)
		{
			game->player.moves++;
			end_game(game);
		}
		else if (game->map.map[game->player.y][game->player.x + 1] == '2')
			end_game(game);
	}
	return (1);
}

/* Gere les touches appuyees par l'utilisateur pour le jeu */
int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		end_game(game);
	else if (keycode == XK_w || keycode == XK_Up)
		move_up(game);
	else if (keycode == XK_s || keycode == XK_Down)
		move_down(game);
	else if (keycode == XK_a || keycode == XK_Left)
		move_left(game);
	else if (keycode == XK_d || keycode == XK_Right)
		move_right(game);
	return (0);
}
