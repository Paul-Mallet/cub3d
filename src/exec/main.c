/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:47:23 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/26 16:08:14 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(void)
{
	t_data		data;

	init(&data);
	mlx_hook(data.mlx.mlx_win,
		DestroyNotify, StructureNotifyMask, &handle_close, &data);
	mlx_hook(data.mlx.mlx_win,
		KeyPress, KeyPressMask, &handle_keys, &data);
	render(&data);
	mlx_loop(data.mlx.mlx_co);
	return (0);
}
