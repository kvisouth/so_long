/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevso <kevso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:13:57 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/23 13:44:32 by kevso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Initialise les variables p, c, e */
void	init_pce(t_parse *parse)
{
	parse->p = 0;
	parse->c = 0;
	parse->e = 0;
}

/* Check les elements de la map (P, C, E) */
int	parse_pce(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	init_pce(parse);
	while (i < parse->lines)
	{
		j = 0;
		while (parse->content[i][j])
		{
			if (parse->content[i][j] == 'P')
				parse->p++;
			if (parse->content[i][j] == 'C')
				parse->c++;
			if (parse->content[i][j] == 'E')
				parse->e++;
			j++;
		}
		i++;
	}
	if (parse->p != 1 || parse->c < 1 || parse->e != 1)
		return (0);
	return (1);
}

/* Check si il y a autre chose dans la map que les caracteres P, C, E, 1 et 0 */
int	parse_map_junk(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (i < parse->lines)
	{
		j = 0;
		while (parse->content[i][j])
		{
			if (parse->content[i][j] != 'P'
				&& parse->content[i][j] != 'C'
				&& parse->content[i][j] != 'E'
				&& parse->content[i][j] != '1'
				&& parse->content[i][j] != '0'
				&& parse->content[i][j] != '2'
				&& parse->content[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* Parse les elements de la map (P, C, E, 1 et 0) */
int	parse_map_info(t_parse *parse)
{
	if (!parse_pce(parse))
		return (0);
	if (!parse_map_junk(parse))
		return (0);
	return (1);
}
