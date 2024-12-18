/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:45:41 by kkauhane          #+#    #+#             */
/*   Updated: 2024/11/13 12:04:31 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//reads line and fills every row
static void	fill_row(t_data *data, char *line, int row)
{
	int	i;
	int	cols;

	i = 0;
	cols = -1;
	if (line[i] == '\n' || ft_strlen(line) < 2)
		ft_free_data_and_error(data, "invalid file", line);
	while (++cols < SPACE_AROUND_MAP)
		data->scene.map[row][cols] = ' ';
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == '1' || line[i] == '0')
			data->scene.map[row][cols] = line[i] - 48;
		else
			data->scene.map[row][cols] = line[i];
		i++;
		cols++;
	}
	while (cols < data->scene.cols)
	{
		data->scene.map[row][cols] = ' ';
		cols++;
	}
}

//extra rows added with ' ' 
static void	fill_extra_row(t_data *data, int *row, int last)
{
	int	i;

	i = 0;
	while (*row < last)
	{
		while (i < data->scene.cols)
		{
			data->scene.map[*row][i] = ' ';
			i++;
		}
		(*row)++;
		i = 0;
	}
}

/* ==============================
 *	after checks this fills 2D arrow with map content and adds
 * ' ' around everything
 * ==============================
 */

void	fill_map(t_data *data, t_check *check, int row, int lines)
{
	char	*line;

	line = NULL;
	fill_extra_row(data, &row, SPACE_AROUND_MAP);
	while (lines <= check->cur_file_line)
	{
		line = get_next_line_cub(data, data->fd);
		free(line);
		lines++;
	}
	while (lines <= check->cur_file_line + check->map_lines)
	{
		line = get_next_line_cub(data, data->fd);
		if (!line)
			break ;
		fill_row(data, line, row);
		free(line);
		lines++;
		row++;
	}
	fill_extra_row(data, &row, check->map_lines + 2 * SPACE_AROUND_MAP);
}

void	flood_fill(t_data *data, t_point size, t_point cur, int to_fill)
{
	int	**matrix;

	matrix = data->scene.map;
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	if (matrix[cur.y][cur.x] != 1 && matrix[cur.y][cur.x] != 32
		&& matrix[cur.y][cur.x] != -1)
	{
		ft_free_data_and_error(data, "invalid file, map not closed", NULL);
		return ;
	}
	if (matrix[cur.y][cur.x] == 1 || matrix[cur.y][cur.x] == -1)
		return ;
	matrix[cur.y][cur.x] = -1;
	flood_fill(data, size, (t_point){cur.x - 1, cur.y}, to_fill);
	flood_fill(data, size, (t_point){cur.x + 1, cur.y}, to_fill);
	flood_fill(data, size, (t_point){cur.x, cur.y - 1}, to_fill);
	flood_fill(data, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	fill_maze_if_spaces(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->scene.rows)
	{
		j = 0;
		while (j < data->scene.cols)
		{
			if (data->scene.map[i][j] == 32)
				data->scene.map[i][j] = 0;
			j++;
		}
		i++;
	}
}
