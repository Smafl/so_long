/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:55:16 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/07 20:23:57 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	render_map(t_map_params *map_params)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x != map_params->width * STEP)
	{
		while (y != map_params->height * STEP)
		{
			put_images(map_params, &x, &y);
			y += STEP;
		}
		y = 0;
		put_images(map_params, &x, &y);
		x += STEP;
	}
}
