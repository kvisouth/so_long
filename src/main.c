/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:34:17 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/04 17:02:00 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	parse_arg(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 4] != '.'
		|| str[i - 3] != 'b'
		|| str[i - 2] != 'e'
		|| str[i - 1] != 'r')
		return (0);
	return (1);
}

int	parsing(int ac, char **av, t_parse *parse)
{
	if (ac != 2)
		return (0);
	if (!parse_arg(av[1]))
		return (0);
	parse->file = av[1];
	parse->fd = open(parse->file, O_RDONLY);
	if (parse->fd < 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_parse	parse;

	if (!parsing(ac, av, &parse))
		return (write(2, "Error\n", 6), 1);
	return (0);
}
