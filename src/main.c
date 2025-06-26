/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:59:24 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/26 15:09:14 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_errors(t_data *data)
{
	if (get_textures_and_colors(data) == -1
		|| verif_textures(data) == -1
		|| check_player(data) == -1
		||check_player_surrounded(data) == -1)
		return (-1);
	if (check_letter(data) == -1)
		return (ft_printf("Error\ninvalid char detected\n"), -1);
	return (0);
}

int	init_data(t_data *data, char **argv)
{
	data->text_ea = NULL;
	data->text_we = NULL;
	data->text_no = NULL;
	data->text_so = NULL;
	data->img_ea = NULL;
	data->img_we = NULL;
	data->img_no = NULL;
	data->img_so = NULL;
	data->player_x = 0;
	data->player_y = 0;
	data->map = NULL;
	data->file = NULL;
	data->orientation = NULL;
	data->player_count = 0;
	data->file_line_number = count_lines(argv[1], data);
	if (data->file_line_number == -1)
		return (1);
	data->color_c = -1;
	data->color_f = -1;
	data->mlx = mlx_init();
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (printf("Error : invalid arguments\n"));
	if (init_data(&data, argv) == 1)
		return (1);
	if (!check_format(argv[1]))
		return (ft_printf("Error\nInvalid file\n"), close_game(&data), 1);
	read_file(argv[1], &data);
	if (check_errors(&data) == -1)
		return (close_game(&data), 1);
	data.map_col_number = count_cols(&data);
	if (check_walls(&data) == -1)
		return (close_game(&data));
	close_game(&data);
	return (0);
}
