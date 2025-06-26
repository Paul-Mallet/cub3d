/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:26:16 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/26 15:59:43 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_orientation(t_data *data, char c, int x, int y)
{
	data->player_x = x;
	data->player_y = y;
	if (c == 'N')
		data->orientation = ft_strdup("North");
	if (c == 'S')
		data->orientation = ft_strdup("South");
	if (c == 'E')
		data->orientation = ft_strdup("East");
	if (c == 'W')
		data->orientation = ft_strdup("West");
}

int	check_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_player_surrounded(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (check_player_char(data->map[i][j]))
			{
				if (i == 0 || j == 0 || !data->map[i + 1]
					|| !data->map[i][j + 1])
					return (printf("Error\nPlayer at the"
							" edge of the map\n"), -1);
				if (data->map[i - 1][j] == ' ' || data->map[i + 1][j] == ' ' ||
					data->map[i][j - 1] == ' ' || data->map[i][j + 1] == ' ')
					return (printf("Error\nPlayer is not "
							"properly surrounded\n"), -1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] && check_player_char(data->map[i][j])
				&& data->player_count == 1)
				return (printf("Error\nToo many players\n"), -1);
			if (data->map[i][j] && check_player_char(data->map[i][j]))
			{
				data->player_count++;
				get_orientation(data, data->map[i][j], i, j);
			}
			j++;
		}
		i++;
	}
	if (data->player_count != 1)
		return (printf("No player found\n"));
	return (0);
}
