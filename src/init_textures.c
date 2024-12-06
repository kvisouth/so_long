/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:35:42 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/06 19:37:24 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
