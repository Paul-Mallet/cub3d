/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:47:21 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/29 11:25:55 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	which_player_dir(t_data *data)
{
	printf("data->parsing.orientation: %s\n", data->parsing.orientation);
	if (ft_strcmp(data->parsing.orientation, "North") == 0)
	{
		data->player.dir_x = 0.0;
		data->player.dir_y = -1.0;
		data->cam.plane_x = -0.66;
		data->cam.plane_y = 0.0;
	}
	else if (ft_strcmp(data->parsing.orientation, "South") == 0)
	{
		data->player.dir_x = 0.0;
		data->player.dir_y = 1.0;
		data->cam.plane_x = 0.66;
		data->cam.plane_y = 0.0;
	}
	else if (ft_strcmp(data->parsing.orientation, "East") == 0)
	{
		data->player.dir_x = 1.0;
		data->player.dir_y = 0.0;
		data->cam.plane_x = 0.0;
		data->cam.plane_y = -0.66;
	}
	else if (ft_strcmp(data->parsing.orientation, "West") == 0)
	{
		data->player.dir_x = -1.0;
		data->player.dir_y = 0.0;
		data->cam.plane_x = 0.0;
		data->cam.plane_y = 0.66;
	}
}

static void	init_data(t_data *data)
{
	convert_map_to_int(data);
	printf("(double)data->parsing.player_x: %f\n"
		"(double)data->parsing.player_y: %f\n",
		(double)data->parsing.player_x, (double)data->parsing.player_y);
	data->player.pos_x = (double)data->parsing.player_x;
	data->player.pos_y = (double)data->parsing.player_y;
	which_player_dir(data);
	data->grid.map_x = (int)data->player.pos_x;
	data->grid.map_y = (int)data->player.pos_y;
	data->grid.wall.is_hit = 0;
}

void	init(t_data *data)
{
	init_data(data);
	// init_mlx(data);
}
