/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:34:17 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/06 19:01:56 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Verifie si l'input utilisateur + la map est valide */
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
	if ((int)ft_strlen(parse->content[0]) - 1 > 30 || parse->lines > 15)
		return (0);
	return (1);
}

/* Initialise la fenetre du jeu */
int	init_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map.width * 64,
			game->map.height * 64, "so_long");
	if (!game->win)
		return (0);
	return (1);
}

void	put_walls(t_game *game)
{
	t_texture	wall;
	int			i;
	int			j;

	wall.path = "./assets/wall.xpm";
	wall.img = mlx_xpm_file_to_image(game->mlx, wall.path, &wall.width,
			&wall.height);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, wall.img,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, wall.img);
}

void	put_coins(t_game *game)
{
	t_texture	wall;
	int			i;
	int			j;

	wall.path = "./assets/coin.xpm";
	wall.img = mlx_xpm_file_to_image(game->mlx, wall.path, &wall.width,
			&wall.height);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, wall.img,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, wall.img);
}

void	put_player(t_game *game)
{
	t_texture	wall;
	int			i;
	int			j;

	wall.path = "./assets/goblin.xpm";
	wall.img = mlx_xpm_file_to_image(game->mlx, wall.path, &wall.width,
			&wall.height);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, wall.img,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, wall.img);
}

void	put_background(t_game *game)
{
	t_texture	wall;
	int			i;
	int			j;

	wall.path = "./assets/back.xpm";
	wall.img = mlx_xpm_file_to_image(game->mlx, wall.path, &wall.width,
			&wall.height);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, wall.img,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, wall.img);
}

void	put_exit(t_game *game)
{
	t_texture	wall;
	int			i;
	int			j;

	wall.path = "./assets/door_closed.xpm";
	wall.img = mlx_xpm_file_to_image(game->mlx, wall.path, &wall.width,
			&wall.height);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, wall.img,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, wall.img);
}

/* Initialise les textures du jeu */
int	init_textures(t_game *game)
{
	put_walls(game);
	put_background(game);
	put_coins(game);
	put_player(game);
	put_exit(game);
	return (1);
}

/* Initialise les variables du jeu */
int	init(t_parse *parse, t_game *game)
{
	game->player.x = parse->player_x;
	game->player.y = parse->player_y;
	game->player.hp = 100;
	game->player.moves = 0;
	game->player.coins = 0;
	game->coins = parse->c;
	game->exit_status = 0;
	game->map.height = parse->lines;
	game->map.width = ft_strlen(parse->content[0]) - 1;
	game->map.map = parse->content;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	if (!init_window(game))
		return (0);
	if (!init_textures(game))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_parse	parse;
	t_game	game;

	if (!parsing(ac, av, &parse))
		return (write(2, "Error\n", 6), 1);
	if (!init(&parse, &game))
		return (write(2, "Error\n", 6), 1);
	mlx_loop(game.mlx);
	return (free_tabs(parse.content), 0);
}
