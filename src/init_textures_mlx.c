/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_mlx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:36:45 by kevisout          #+#    #+#             */
/*   Updated: 2025/01/08 17:22:49 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* "Dessine" la texture walls.xpm sur la fenetre la ou y'a des '1' sur la map */
void	put_walls(t_game *game)
{
	t_texture	w;
	int			i;
	int			j;

	w.path = "./assets/wall.xpm";
	w.img = mlx_xpm_file_to_image(game->mlx, w.path, &w.width, &w.height);
	if (w.img == NULL)
		return ;
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

/* "Dessine" la texture back.xpm sur la fenetre la ou y'a des '0' sur la map */
void	put_background(t_game *game)
{
	t_texture	w;
	int			i;
	int			j;

	w.path = "./assets/back.xpm";
	w.img = mlx_xpm_file_to_image(game->mlx, w.path, &w.width, &w.height);
	if (w.img == NULL)
		return ;
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

/* Ouvre la porte avec une petite animation */
void	open_door_animation(t_game *game)
{
	t_texture	w;

	game->door_status = 1;
	w.sprite[0] = "./assets/door0.xpm";
	w.sprite[1] = "./assets/door1.xpm";
	w.sprite[2] = "./assets/door2.xpm";
	w.sprite[3] = "./assets/door3.xpm";
	w.sprite[4] = "./assets/door4.xpm";
	w.sprite[5] = "./assets/door5.xpm";
	w.sprite[6] = "./assets/door6.xpm";
	w.sprite[7] = "./assets/door7.xpm";
	w.img = mlx_xpm_file_to_image(game->mlx, w.sprite[game->clock],
			&w.width, &w.height);
	if (w.img == NULL)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, w.img,
		game->map.exit_x * 64, game->map.exit_y * 64);
	mlx_destroy_image(game->mlx, w.img);
	if (game->clock == 7)
		game->door_status = 2;
}

/* Dessine la porte de sortie ouverte/fermee sur le 'E' de la map */
void	put_exit(t_game *game)
{
	t_texture	w;

	if (game->exit_status == 0)
		w.path = "./assets/door_closed.xpm";
	if (game->exit_status == 1)
	{
		if (game->door_status == 0 || game->door_status == 1)
			open_door_animation(game);
		if (game->door_status == 2)
			w.path = "./assets/door_open.xpm";
	}
	if (game->door_status != 1)
	{
		w.img = mlx_xpm_file_to_image(game->mlx, w.path, &w.width, &w.height);
		if (w.img == NULL)
			return ;
		mlx_put_image_to_window(game->mlx, game->win, w.img,
			game->map.exit_x * 64, game->map.exit_y * 64);
		mlx_destroy_image(game->mlx, w.img);
	}
}
