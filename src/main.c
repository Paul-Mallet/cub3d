/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:59:24 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/16 11:30:16 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_key(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		ft_printf("Exit\n");
		close_game(data);
	}
	return (0);
}

int	verif_values(t_data *data)
{
	if (data->color_c == -1 || data->color_f == -1)
		return (0);
	if (!data->text_ea || !data->text_we || !data->text_no || !data->text_so)
		return (0);
	return (1);
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

void free_textures_and_images(t_data *data)
{
	if (data->text_we)
		free(data->text_we);
	if (data->text_ea)
		free(data->text_ea);
	if (data->text_no)
		free(data->text_no);
	if (data->text_so)
		free(data->text_so);
	if (data->img_ea)
		mlx_destroy_image(data->mlx, data->img_ea);
	if (data->img_so)
		mlx_destroy_image(data->mlx, data->img_so);
	if (data->img_no)
		mlx_destroy_image(data->mlx, data->img_no);
	if (data->img_we)
		mlx_destroy_image(data->mlx, data->img_we);
	data->text_we = NULL;
	data->text_ea = NULL;
	data->text_no = NULL;
	data->text_so = NULL;
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

int	check_errors(t_data *data)
{
	if (get_textures_and_colors(data) == 1)
		return (-1);
	if (verif_textures(data) == -1)
		return (-1);
	if (check_letter(data) == -1)
		return (printf("Error\ninvalid char detected"), -1);
	if (check_player(data) == -1)
		return (-1);
	return (0);
}

int	close_game(t_data *data)
{
	int	i;

	i = 0;
	if (data->orientation)
		free(data->orientation);
	free_textures_and_images(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_tab(data->map);
	free_tab(data->file);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (printf("Error : invalid arguments\n"));
	if (!check_format(argv[1]))
	{
		ft_printf("Error\nInvalid file\n");
		return (1);
	}
	data.mlx = mlx_init();
	data.text_ea = NULL;
	data.text_we = NULL;
	data.text_no = NULL;
	data.text_so = NULL;
	data.img_ea = NULL;
	data.img_we = NULL;
	data.img_no = NULL;
	data.img_so = NULL;
	data.map = NULL;
	data.orientation = NULL;
	data.player_count = 0;
	data.file_line_number = count_lines(argv[1], &data);
	data.color_c = -1;
	data.color_f = -1;
	read_file(argv[1], &data);
	close_game(&data);
}
