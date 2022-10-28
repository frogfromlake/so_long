/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:43:36 by fquist            #+#    #+#             */
/*   Updated: 2022/01/20 20:10:07 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	animate_player_left(t_data *data, int timer);
static int	animate_player_right(t_data *data, int timer);
static int	animate_player_up(t_data *data, int timer);

int	animate_hook_up_down(t_data *data)
{
	refresh_background(data);
	if (data->then == 0)
		data->then = clock();
	animate_hook_left_right(data);
	if (data->key == W)
	{
		if (data->is_moving == true)
			animate_player_up(data, data->timer);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->player->p_u1,
				data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	}
	else if (data->key == S)
	{
		if (data->is_moving == true)
			animate_player_up(data, data->timer);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->player->p_u1,
				data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	}
	time_calc(data);
	return (0);
}

int	animate_hook_left_right(t_data *data)
{
	if (data->then == 0)
		data->then = clock();
	if (data->key == A)
	{
		if (data->is_moving == true)
			animate_player_left(data, data->timer);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->player->p_l,
				data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	}
	else if (data->key == D)
	{
		if (data->is_moving == true)
			animate_player_right(data, data->timer);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->player->p_r,
				data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	}
	time_calc(data);
	return (0);
}

static int	animate_player_left(t_data *data, int timer)
{
	if (data->i == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_l1,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_l2,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_l3,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 4)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_l4,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 5)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_l5,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 6)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_l6,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
		if (timer)
			data->i = 0;
	}
	if (timer)
		data->i++;
	return (0);
}

static int	animate_player_right(t_data *data, int timer)
{
	if (data->i == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_r1,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_r2,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_r3,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 4)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_r4,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 5)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_r5,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 6)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_r6,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
		if (timer)
			data->i = 0;
	}
	if (timer)
		data->i++;
	return (0);
}

static int	animate_player_up(t_data *data, int timer)
{
	if (data->i == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_u1,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_u2,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_u3,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 4)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_u4,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 5)
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_u5,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	else if (data->i == 6)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->player->p_u6,
			data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
		if (timer)
			data->i = 0;
	}
	if (timer)
		data->i++;
	return (0);
}
