/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:30:22 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/27 17:47:48 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

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
	char	*sprite[8];
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

typedef struct s_enemy
{
	int				x;
	int				y;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_map
{
	int		width;
	int		height;
	int		exit_x;
	int		exit_y;
	char	**map;
}	t_map;

typedef struct s_game
{
	int			x;
	void		*mlx;
	void		*win;
	int			coins;
	int			exit_status;
	int			door_status;
	int			clock;
	int			nbr_enemies;
	t_map		map;
	t_player	player;
	t_enemy		*enemy;
}	t_game;

#endif