/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:35:23 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/12 15:19:16 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_char(char c)
{
	if (c == 'N' || c == '0' || c == '1' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (printf("ICI %c\n", c), 0);
}

int is_whitespace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
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
			while (map[i][j] && is_whitespace(map[i][j]))
				j++;
			if (map [i][j] && !check_char(map[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
