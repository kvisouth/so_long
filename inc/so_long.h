/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:34:59 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/08 03:48:09 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "structures.h"
# include "X11/X.h"
# include <X11/keysym.h>

/* PARSING */
int		parse_args(char **str, t_parse *parse);
int		parse_map_walls(t_parse *parse);
int		parse_map_info(t_parse *parse);
int		parse_path(t_parse *parse);

/* PARSING UTILS */
int		fill_content(t_parse *parse);
void	free_tabs(char **tab);
void	print_map(char **map);

/* INIT */
int		init(t_parse *parse, t_game *game);

/* INIT TEXTURES */
void	put_exit(t_game *game);
void	put_player(t_game *game);
void	put_coins(t_game *game);
void	put_background(t_game *game);
void	put_walls(t_game *game);
int		init_textures(t_game *game);

/* GAME-EVENTS */
int		handle_keypress(int keycode, t_game *game);
int		get_player_pos(t_game *game);
int		end_game(t_game *game);

#endif