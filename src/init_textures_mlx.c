/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_mlx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:36:45 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/08 03:27:47 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	if (game->exit_status == 1)
		wall.path = "./assets/door_open.xpm";
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
