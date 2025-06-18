/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:26:16 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/17 14:27:56 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_orientation(t_data *data, char c)
{
	if (c == 'N')
		data->orientation = ft_strdup("North");
	if (c == 'S')
		data->orientation = ft_strdup("South");
	if (c == 'E')
		data->orientation = ft_strdup("East");
	if (c == 'W')
		data->orientation = ft_strdup("West");
}
