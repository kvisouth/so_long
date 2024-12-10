/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:34:17 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/10 19:37:48 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Verifie si l'input utilisateur + la map est valide */
/*  Ajouter ca pour ajouter un check map trop grosse  */
/*	if ((int)ft_strlen(parse->content[0]) - 1 > 30 || parse->lines > 15)
		return (0); 												  */
int	parsing(int ac, char **av, t_parse *parse)
{
	if (ac != 2)
		return (0);
	if (!parse_args(av, parse))
		return (0);
	if (!fill_content(parse))
		return (0);
	if (!parse_map_walls(parse))
		return (0);
	if (!parse_map_info(parse))
		return (0);
	if (!parse_path(parse))
		return (0);
	return (1);
}

/* Cette fonction est appliquee a toute les frames du jeu */
int	update_game(t_game *game)
{
	game->x++;
	if (game->x > 1000)
		game->x = 0;
	if (game->player.coins == game->coins)
		game->exit_status = 1;
	if (game->x % 50 == 0)
	{
		if (game->clock == 7)
			game->clock = 0;
		else
			game->clock++;
	}
	put_background(game);
	put_coins(game);
	put_player(game);
	put_exit(game);
	return (0);
}

int	hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, &update_game, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &handle_keypress, game);
	return (1);
}

int	main(int ac, char **av)
{
	t_parse	parse;
	t_game	game;

	if (!parsing(ac, av, &parse))
		return (write(2, "Error\n", 6), free_tabs(parse.content), 1);
	if (!init(&parse, &game))
		return (write(2, "Error\n", 6), free_tabs(parse.content), 1);
	if (!hooks(&game))
		return (write(2, "Error\n", 6), free_tabs(parse.content), 1);
	mlx_loop(game.mlx);
	return (0);
}
