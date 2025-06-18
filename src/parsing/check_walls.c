/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:07:37 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/18 12:57:10 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line [i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_char(char c)
{
	return (c == '1' || c == ' ');
}

int check_walls(t_data *data)
{
	if (check_spaces(data) == -1)
		return (-1);	
}
