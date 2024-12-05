/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:34:59 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/05 17:53:47 by kevisout         ###   ########.fr       */
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

typedef struct s_parse
{
	int		fd;
	int		lines;
	char	*file;
	char	**content;
	int		p;
	int		c;
	int		e;
}	t_parse;

// typedef struct s_game
// {
// 	int		x;
// 	int		y;
// 	int		player;
// 	int		collectible;
// 	int		exit;
// }	t_game;

// typedef struct s_map
// {
// 	char	**map;
// 	int		width;
// 	int		height;

// }	t_map;

/* PARSING */
int		parse_args(char **str, t_parse *parse);
int		parse_map_walls(t_parse *parse);
int		parse_map_info(t_parse *parse);

/* PARSING UTILS */
int		fill_content(t_parse *parse);
void	free_tabs(char **tab);

#endif