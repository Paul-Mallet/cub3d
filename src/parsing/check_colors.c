/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:27:20 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/11 14:52:15 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_color(t_data *data, int *components, char identifier)
{
	unsigned int	color;
	int				i;

	i = 0;
	while (i < 3)
	{
		if (components[i] < 0 || components[i] > 255)
			return (printf("color value %d must be between 0 and 255\n", components[i]), 1);
		i++;
	}
	color = (components[0] << 16) | (components[1] << 8) | components[2];
	if (identifier == 'C' && data->color_c == -1)
		data->color_c = color;
	else if (identifier == 'F' && data->color_f == -1)
		data->color_f = color;
	return (0);
}

int	get_color(t_data *data, char *line)
{
	int		components[3];
	int		i;
	int		j;
	char	identifier;

	i = 0;
	j = 0;
	identifier = line[0];
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	while (j < 3 && line[i])
	{
		components[j++] = ft_atoi(&line[i]);
		while (line[i] && ft_isdigit(line[i]))
			i++;
		while (line[i] && !ft_isdigit(line[i]))
			i++;
	}
	if (j == 3)
	{
		if (check_color(data, components, identifier) == 1)
			return (error_map(data, 1), 1);
	}
	return (0);
}
