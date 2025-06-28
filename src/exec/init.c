/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:47:21 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/28 19:07:38 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_data(t_data *data)
{
	convert_map_to_int(data);
	data->player.pos_x = 22.0;
	data->player.pos_y = 12.0;
	data->player.dir_x = -1.0;
	data->player.dir_y = 0.0;
	data->cam.plane_x = 0.0;
	data->cam.plane_y = 0.66;
	data->grid.map_x = (int)data->player.pos_x;
	data->grid.map_y = (int)data->player.pos_y;
	data->grid.wall.is_hit = 0;
}

void	init(t_data *data)
{
	init_data(data);
	// init_mlx(data);
}
