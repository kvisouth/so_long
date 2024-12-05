/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:34:17 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/05 18:43:24 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Check si un chemin est disponible entre P et E dans la map (ALGO BFS)*/
int	parse_path(t_parse *parse)
{
	(void)parse;
	return (1);
}

int	parsing(int ac, char **av, t_parse *parse)
{
	if (ac != 2)
		return (0);
	if (!parse_args(av, parse))
		return (0);
	if (!fill_content(parse))
		return (0);
	if (!parse_map_walls(parse))
		return (0);
	if (!parse_map_info(parse))
		return (0);
	// if (!parse_path(parse))
	// 	return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_parse	parse;

	if (!parsing(ac, av, &parse))
		return (write(2, "Error\n", 6), 1);
	free_tabs(parse.content);
	return (0);
}
