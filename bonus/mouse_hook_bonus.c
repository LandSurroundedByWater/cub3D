/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkauhane <kkauhane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:15:21 by kkauhane          #+#    #+#             */
/*   Updated: 2024/11/13 14:24:31 by kkauhane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	my_mouse_hook(t_data *data)
{
	int				x;
	int				y;
	double			change_x;
	int				center_x;
	int				center_y;

	center_x = data->s_width / 2;
	center_y = data->s_height / 2;
	mlx_get_mouse_pos(data->m, &x, &y);
	change_x = x - center_x;
	if (change_x != 0)
		turn_player(&data->scene.player, change_x * SENSITIVITY);
	mlx_set_mouse_pos(data->m, center_x, center_y);
	mlx_set_cursor_mode(data->m, MLX_MOUSE_HIDDEN);
}
