/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:34:24 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/23 16:21:52 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Initialise la fenetre du jeu */
int	init_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map.width * 64,
			game->map.height * 64, "so_long");
	if (!game->win)
		return (0);
	return (1);
}

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

/* Initialise les variables du jeu */
int	init(t_parse *parse, t_game *game)
{
	game->player.x = parse->player_x;
	game->player.y = parse->player_y;
	game->player.hp = 100;
	game->player.moves = 1;
	game->player.coins = 0;
	game->coins = parse->c;
	game->clock = 0;
	game->x = 0;
	game->exit_status = 0;
	game->door_status = 0;
	game->map.height = parse->lines;
	game->map.width = ft_strlen(parse->content[0]) - 1;
	game->map.map = parse->content;
	game->map.exit_x = parse->exit_x;
	game->map.exit_y = parse->exit_y;
	if (!init_enemies(game))
		return (0);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	if (!init_window(game))
		return (0);
	if (!init_textures(game))
		return (0);
	return (1);
}
