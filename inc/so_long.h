/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:34:59 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/06 17:13:50 by kevisout         ###   ########.fr       */
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
	int				fd;
	int				lines;
	int				p;
	int				c;
	int				e;
	int				player_x;
	int				player_y;
	int				exit_x;
	int				exit_y;
	char			*file;
	char			**content;
	char			**mapx;
}	t_parse;

typedef struct s_texture
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_texture;

typedef struct s_player
{
	int		x;
	int		y;
	int		hp;
	int		moves;
	int		coins;
}	t_player;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			coins;
	int			exit_status;
	t_map		map;
	t_player	player;
}	t_game;

/* PARSING */
int		parse_args(char **str, t_parse *parse);
int		parse_map_walls(t_parse *parse);
int		parse_map_info(t_parse *parse);
int		parse_path(t_parse *parse);

/* PARSING UTILS */
int		fill_content(t_parse *parse);
void	free_tabs(char **tab);
void	print_map(char **map);

#endif