/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:07:50 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/06 14:07:58 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Enregistre la position de P et E dans la map */
void	get_exit_and_player_pos(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (i < parse->lines)
	{
		j = 0;
		while (parse->content[i][j])
		{
			if (parse->content[i][j] == 'P')
			{
				parse->player_x = j;
				parse->player_y = i;
			}
			if (parse->content[i][j] == 'E')
			{
				parse->exit_x = j;
				parse->exit_y = i;
			}
			j++;
		}
		i++;
	}
}

/* Copie le contenu de la map dans un tableau de char */
char	**copy_content(t_parse *parse)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (parse->lines + 1));
	if (!map)
		return (NULL);
	while (i < parse->lines)
	{
		map[i] = ft_strdup(parse->content[i]);
		if (!map[i])
			return (NULL);
		i++;
	}
	map[i] = NULL;
	i = 0;
	return (map);
}

/* Check grace a la map de flood_fill si 'E' et les 'C' sont accessibles */
int	check_solvable(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (map[i][j + 1] == '0' || map[i][j - 1] == '0'
					|| map[i + 1][j] == '0' || map[i - 1][j] == '0')
					return (0);
			}
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* Remplit la map de 'X' en s'arettant a la vue d'un '1', 'E' ou 'X' */
static void	flood_fill(char **map, int x, int y, t_parse *parse)
{
	if (y < 0 || x < 0 || y >= parse->lines || x >= (int)ft_strlen(map[y])
		|| map[y][x] == '1' || map[y][x] == 'E' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, parse);
	flood_fill(map, x - 1, y, parse);
	flood_fill(map, x, y + 1, parse);
	flood_fill(map, x, y - 1, parse);
}

/* Check si un chemin est disponible entre P et E dans la map (ALGO BFS)*/
int	parse_path(t_parse *parse)
{
	get_exit_and_player_pos(parse);
	parse->mapx = copy_content(parse);
	if (!parse->mapx)
		return (0);
	flood_fill(parse->mapx, parse->player_x, parse->player_y, parse);
	if (!check_solvable(parse->mapx))
		return (free_tabs(parse->mapx), 0);
	return (free_tabs(parse->mapx), 1);
}
