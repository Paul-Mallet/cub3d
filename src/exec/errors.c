/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:27:35 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/27 09:47:27 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_err(char *msg, t_data *data)
{
	if (data->parsing.map_int)
		free_map(data);
	perror(msg);
	exit(EXIT_FAILURE);
}
