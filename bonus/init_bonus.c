/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:14:47 by tsaari            #+#    #+#             */
/*   Updated: 2024/11/18 13:43:57 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	init_player(t_player *player)
{
	player->dir = 0.0f;
	player->px = 100.0;
	player->py = 100.0;
	player->dposx = cos(player->px) * 5;
	player->dposy = sin(player->py) * 5;
	player->col_front = false;
	player->col_back = false;
	player->col_right = false;
	player->col_left = false;
}

static void	init_scene(t_data *data)
{
	int	row;

	data->scene.no = NULL;
	data->scene.so = NULL;
	data->scene.ea = NULL;
	data->scene.we = NULL;
	data->scene.cols = 0;
	data->scene.rows = 0;
	data->scene.ceiling = COL_BLUE;
	data->scene.floor = COL_GREEN;
	data->scene.ceiling_rgb[0] = -1;
	data->scene.ceiling_rgb[1] = -1;
	data->scene.ceiling_rgb[2] = -1;
	data->scene.floor_rgb[0] = -1;
	data->scene.floor_rgb[1] = -1;
	data->scene.floor_rgb[2] = -1;
	data->scene.minimap_status = 1;
	data->scene.wand_pos = 1;
	data->scene.wand_visible = false;
	data->scene.door_timer = 0;
	data->scene.wand_timer = 0;
	data->scene.door_x = 0;
	data->scene.door_y = 0;
	data->scene.last_ray_dir = 0;
}

void	init_check(t_check *check)
{
	check->player_count = 0;
	check->longest_line = 0;
	check->cur_file_line = 0;
	check->map_lines = 0;
}

void	init_data(t_data *data, char **argv)
{
	data->m = NULL;
	data->image = NULL;
	data->txtr = NULL;
	data->txtrs = NULL;
	data->walls = NULL;
	data->wand = NULL;
	data->file = argv[1];
	data->s_height = 1080;
	data->s_width = 1920;
	data->buffer = NULL;
	init_scene(data);
	init_player(&data->scene.player);
}

void	init_ray(t_data *data, t_ray *ray, double ray_angle)
{
	ray->angle = ray_angle;
	ray->is_door = false;
	ray->open_door = false;
	ray->map = data->scene.map;
	ray->pxpy[0] = data->scene.player.px;
	ray->pxpy[1] = data->scene.player.py;
	ray->rxry[0] = ray->pxpy[0];
	ray->rxry[1] = ray->pxpy[1];
	ray->xoyo[0] = 0;
	ray->xoyo[1] = 0;
	ray->dist = 0;
	ray->dist_h = 0;
	ray->dist_v = 0;
	ray->hor_x = 0;
	ray->open_door = false;
	ray->cols = data->scene.cols;
	ray->rows = data->scene.rows;
	ray->wall = NULL;
	ray->wall_height = 0;
	ray->tex_x = 0;
}
