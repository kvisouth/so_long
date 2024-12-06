/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:34:17 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/06 19:38:40 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* Verifie si l'input utilisateur + la map est valide */
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
	if (!parse_path(parse))
		return (0);
	if ((int)ft_strlen(parse->content[0]) - 1 > 30 || parse->lines > 15)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_parse	parse;
	t_game	game;

	if (!parsing(ac, av, &parse))
		return (write(2, "Error\n", 6), 1);
	if (!init(&parse, &game))
		return (write(2, "Error\n", 6), 1);
	mlx_loop(game.mlx);
	return (free_tabs(parse.content), 0);
}
