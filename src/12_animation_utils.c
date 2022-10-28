/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_animation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:31:26 by fquist            #+#    #+#             */
/*   Updated: 2022/01/20 20:10:37 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	refresh_background(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->s_y / IMG_HEIGHT))
	{
		if (data->map->map[data->map->y][data->map->x] == '0'
			|| data->map->map[data->map->y][data->map->x] == 'P'
			|| data->map->map[data->map->y][data->map->x] == '2')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->background, data->map->x * IMG_WIDTH,
				data->map->y * IMG_HEIGHT);
		if (data->map->x < (data->s_x / IMG_WIDTH))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}