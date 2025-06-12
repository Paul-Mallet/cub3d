/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:35:23 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/12 13:36:59 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_char(char c)
{
	if (c == 'N' || c == '0' || c == '1' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_letter(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = data->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_char(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
