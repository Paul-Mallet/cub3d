/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:03:58 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/27 11:30:37 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../includes/cub3d.h"

char *new_exec_line(char *line, t_data *data)
{
    int i;
    char *str;

    str = malloc(sizeof(char) * (data->parsing.map_col_number + 2));
    if (!str)
        return (NULL);
    i = 0;
    while (line[i])
    {
        if (line[i] == ' ')
            str[i] = '2';
		else if (check_player_char(line[i]) == 1)
			str[i] = '0';
        else
            str[i] = line[i];
        i++;
    }
    while (i <= data->parsing.map_col_number)
    {
        str[i] = '2';
        i++;
    }
    str[i] = '\0';
    return (str);
}

char **copy_map(t_data *data)
{
    char **copy;
    int i;

    copy = malloc(sizeof(char *) * (data->parsing.map_line_number + 1));
    if (!copy)
        return NULL;
    i = 0;
    while (data->parsing.map[i])
    {
        copy[i] = new_exec_line(data->parsing.map[i], data);
        if (!copy[i])
        {
            while (i > 0)
                free(copy[--i]);
            free(copy);
            return NULL;
        }
        i++;
    }
    copy[i] = NULL;
    return copy;
}
