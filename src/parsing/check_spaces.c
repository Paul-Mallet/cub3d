/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:50:26 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/19 11:39:03 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_char(char c)
{
	return (c == '1' || c == ' ' || c == 'V');
}

static int	check_neighbor(t_data *data, int i, int j, int di, int dj)
{
	int	new_i;
	int	new_j;
	int	len;

	new_i = i + di;
	new_j = j + dj;
	if (new_i < 0 || new_i >= data->map_line_number)
		return (0);
	len = ft_strlen(data->map[new_i]);
	if (new_j < 0 || new_j >= len)
		return (0);
	if (!is_valid_char(data->map[new_i][new_j]))
		return (-1);
	if (data->map[new_i][new_j] == ' ')
		return (check_space(data, new_i, new_j));
	return (0);
}

int	check_space(t_data *data, int i, int j)
{
	int	res;

	res = check_neighbor(data, i, j, -1, 0);
	if (res == -1)
		return (-1);
	res = check_neighbor(data, i, j, 0, 1);
	if (res == -1)
		return (-1);
	res = check_neighbor(data, i, j, 0, -1);
	if (res == -1)
		return (-1);
	res = check_neighbor(data, i, j, 1, 0);
	if (res == -1)
		return (-1);
	return (0);
}

int	check_spaces(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] == ' ')
			j++;
		while (data->map[i][j])
		{
			if (data->map[i][j] == ' ')
				if (check_space(data, i, j) == -1)
					return (printf("\033[1;31mError\n\033[1;33mcharacter %c at"
							" x : %d, y : %d is not surrounded by walls"
							"\033[0m\n", data->map[i][j], j + 1, i + 1), -1);
			j++;
		}
		i++;
	}
	return (0);
}
