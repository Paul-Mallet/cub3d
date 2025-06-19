/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:27:20 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/19 11:04:29 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


int	verif_values(t_data *data)
{
	if (data->color_c == -1 || data->color_f == -1)
		return (0);
	if (!data->text_ea || !data->text_we || !data->text_no || !data->text_so)
		return (0);
	return (1);
}

int	check_color(t_data *data, int *components, char identifier)
{
	unsigned int	color;
	int				i;

	i = 0;
	while (i < 3)
	{
		if (components[i] < 0 || components[i] > 255)
			return (printf("color value %d must be between 0 and 255\n",
					components[i]), 1);
		i++;
	}
	color = (components[0] << 16) | (components[1] << 8) | components[2];
	if (identifier == 'C' && data->color_c == -1)
		data->color_c = color;
	if (identifier == 'F' && data->color_f == -1)
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
			return (error_map(data), 1);
	}
	return (0);
}

int	get_texture(t_data *data, char *line)
{
	char	**split_line;
	char	*trimmed;

	split_line = ft_split(line, ' ');
	if (!split_line || !split_line[0] || !split_line[1])
		return (free_tab(split_line),
			ft_printf("Error: invalid texture line\n"), 1);
	trimmed = ft_strtrim(split_line[1], "\n");
	if (!trimmed)
		return (free_tab(split_line),
			ft_printf("Error: malloc failed\n"), 1);
	if (ft_strcmp(split_line[0], "WE") == 0)
	{
		if (data->text_we)
			return (free_tab(split_line), free(trimmed),
				ft_printf("Duplicate WE texture\n"), 1);
		data->text_we = ft_strdup(trimmed);
	}
	else if (ft_strcmp(split_line[0], "EA") == 0)
	{
		if (data->text_ea)
			return (free_tab(split_line), free(trimmed),
				ft_printf("Duplicate EA texture\n"), 1);
		data->text_ea = ft_strdup(trimmed);
	}
	else if (ft_strcmp(split_line[0], "NO") == 0)
	{
		if (data->text_no)
			return (free_tab(split_line), free(trimmed),
				ft_printf("Duplicate NO texture\n"), 1);
		data->text_no = ft_strdup(trimmed);
	}
	else if (ft_strcmp(split_line[0], "SO") == 0)
	{
		if (data->text_so)
			return (free_tab(split_line), free(trimmed),
				ft_printf("Duplicate SO texture\n"), 1);
		data->text_so = ft_strdup(trimmed);
	}
	else
		return (free_tab(split_line), free(trimmed),
			ft_printf("Unknown texture identifier: %s\n", split_line[0]), 1);
	return (free_tab(split_line), free(trimmed), 0);
}

int	get_textures_and_colors(t_data *data)
{
	int		i;
	char	identifier;

	i = 0;
	while (data->file[i])
	{
		identifier = data->file[i][0];
		if (identifier == 'C' || identifier == 'F')
		{
			if (get_color(data, data->file[i]) == 1)
				return (1);
		}
		else if (identifier == 'S' || identifier == 'N'
			|| identifier == 'W' || identifier == 'E')
			get_texture(data, data->file[i]);
		else if (verif_values(data) && ft_strchr(data->file[i], '1'))
			return (read_map(data, i), 0);
		i++;
	}
	return (ft_printf("map not found\n"), 1);
}
