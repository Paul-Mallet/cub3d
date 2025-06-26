/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:09:50 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/26 16:10:28 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_up(t_data *data)
{
	t_player	*player;
	t_speed		*speed;
	t_keys		*keys;

	player = &data->player;
	speed = &data->speed;
	keys = &data->keys;
	if (world_map[keys->next_map_x_up][keys->curr_map_y] == 0)
		player->pos_x += player->dir_x * speed->mov;
	if (world_map[keys->curr_map_x][keys->next_map_y_up] == 0)
		player->pos_y += player->dir_y * speed->mov;
}

void	handle_down(t_data *data)
{
	t_player	*player;
	t_speed		*speed;
	t_keys		*keys;

	player = &data->player;
	speed = &data->speed;
	keys = &data->keys;
	if (world_map[keys->next_map_x_down][keys->curr_map_y] == 0)
		player->pos_x -= player->dir_x * speed->mov;
	if (world_map[keys->curr_map_x][keys->next_map_y_down] == 0)
		player->pos_y -= player->dir_y * speed->mov;
}

void	handle_right(t_data *data)
{
	t_player	*player;
	t_speed		*speed;
	t_keys		*keys;
	t_cam		*cam;

	player = &data->player;
	speed = &data->speed;
	keys = &data->keys;
	cam = &data->cam;
	if (world_map[keys->next_map_x_right][keys->curr_map_y] == 0)
		player->pos_x += cam->plane_x * speed->mov;
	if (world_map[keys->curr_map_x][keys->next_map_y_right] == 0)
		player->pos_y += cam->plane_y * speed->mov;
}

void	handle_left(t_data *data)
{
	t_player	*player;
	t_speed		*speed;
	t_keys		*keys;
	t_cam		*cam;

	player = &data->player;
	speed = &data->speed;
	keys = &data->keys;
	cam = &data->cam;
	if (world_map[keys->next_map_x_left][keys->curr_map_y] == 0)
		player->pos_x -= cam->plane_x * speed->mov;
	if (world_map[keys->curr_map_x][keys->next_map_y_left] == 0)
		player->pos_y -= cam->plane_y * speed->mov;
}
