/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_mlx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:36:45 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/08 04:38:20 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* "Dessine" la texture walls.xpm sur la fenetre la ou y'a des '1' sur la map */
void	put_walls(t_game *game)
{
	t_texture	w;
	int			fd;
	int			i;
	int			j;

	w.path = "./assets/wall.xpm";
	fd = open(w.path, O_RDONLY);
	if (fd < 0)
		return ;
	close(fd);
	w.img = mlx_xpm_file_to_image(game->mlx, w.path, &w.width, &w.height);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, w.img,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, w.img);
}

/* "Dessine" la texture coin.xpm sur la fenetre la ou y'a des 'C' sur la map */
void	put_coins(t_game *game)
{
	t_texture	w;
	int			fd;
	int			i;
	int			j;

	w.path = "./assets/coin.xpm";
	fd = open(w.path, O_RDONLY);
	if (fd < 0)
		return ;
	close(fd);
	w.img = mlx_xpm_file_to_image(game->mlx, w.path, &w.width, &w.height);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, w.img,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, w.img);
}

/* "Dessine" la texture goblin.xpm sur la fenetre la ou y'a 'P' sur la map */
void	put_player(t_game *game)
{
	t_texture	w;
	int			fd;
	int			i;
	int			j;

	w.path = "./assets/goblin.xpm";
	fd = open(w.path, O_RDONLY);
	if (fd < 0)
		return ;
	close(fd);
	w.img = mlx_xpm_file_to_image(game->mlx, w.path, &w.width, &w.height);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, w.img,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, w.img);
}

/* "Dessine" la texture back.xpm sur la fenetre la ou y'a des '0' sur la map */
void	put_background(t_game *game)
{
	t_texture	w;
	int			fd;
	int			i;
	int			j;

	w.path = "./assets/back.xpm";
	fd = open(w.path, O_RDONLY);
	if (fd < 0)
		return ;
	close(fd);
	w.img = mlx_xpm_file_to_image(game->mlx, w.path, &w.width, &w.height);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, w.img,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, w.img);
}

/* Dessine la porte de sortie ouverte/fermee sur le 'E' de la map */
void	put_exit(t_game *game)
{
	t_texture	w;
	int			fd;

	w.path = "./assets/door_closed.xpm";
	fd = open(w.path, O_RDONLY);
	if (fd < 0)
		return ;
	close(fd);
	if (game->exit_status == 1)
	{
		w.path = "./assets/door_open.xpm";
		fd = open(w.path, O_RDONLY);
		if (fd < 0)
			return ;
		close(fd);
	}
	w.img = mlx_xpm_file_to_image(game->mlx, w.path, &w.width, &w.height);
	mlx_put_image_to_window(game->mlx, game->win, w.img,
		game->map.exit_x * 64, game->map.exit_y * 64);
	mlx_destroy_image(game->mlx, w.img);
}
