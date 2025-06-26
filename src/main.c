/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:59:24 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/26 17:33:55 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_errors(t_data *data)
{
	if (get_textures_and_colors(data) == -1
		//|| verif_textures(data) == -1
		|| check_player(data) == -1
		||check_player_surrounded(data) == -1)
		return (-1);
	if (check_letter(data) == -1)
		return (ft_printf("Error\ninvalid char detected\n"), -1);
	return (0);
}

int	init_parsing(t_data *data, char **argv)
{
	data->parsing.text_ea = NULL;
	data->parsing.text_we = NULL;
	data->parsing.text_no = NULL;
	data->parsing.text_so = NULL;
	data->parsing.img_ea = NULL;
	data->parsing.img_we = NULL;
	data->parsing.img_no = NULL;
	data->parsing.img_so = NULL;
	data->parsing.player_x = 0;
	data->parsing.player_y = 0;
	data->parsing.map = NULL;
	data->parsing.file = NULL;
	data->parsing.orientation = NULL;
	data->parsing.player_count = 0;
	data->parsing.file_line_number = count_lines(argv[1], data);
	if (data->parsing.file_line_number == -1)
		return (1);
	data->parsing.color_c = -1;
	data->parsing.color_f = -1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (printf("Error : invalid arguments\n"));
	if (!check_format(argv[1]))
		return (ft_printf("Error\nInvalid file format\n"), 1);
	if (init_parsing(&data, argv) == 1)
		return (1);
	read_file(argv[1], &data);
	init(&data);
	if (check_errors(&data) == -1)
		return (free_parsing(&data), 1);
	for (int i = 0; data.parsing.map[i]; i++)
		printf("%s\n", data.parsing.map[i]);
	// data.parsing.map_col_number = count_cols(&data);
	// if (check_walls(&data) == -1)
	// 	return (free_parsing(&data), 1);
	// mlx_hook(data.mlx.mlx_win,
	// 	DestroyNotify, StructureNotifyMask, &handle_close, &data);
	// mlx_hook(data.mlx.mlx_win,
	// 	KeyPress, KeyPressMask, &handle_keys, &data);
	// render(&data);
	// mlx_loop(data.mlx.mlx_co);
	// return (0);
}
