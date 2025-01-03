/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:05:42 by xhuang            #+#    #+#             */
/*   Updated: 2025/01/03 01:03:40 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
handle keypress, mouse events
Zooming: Increase or decrease the scale parameter.
Rotation: Adjust angles for x, y, z rotation.
Translation: Move the map on the screen.
Exit: Close the window with ESC or the window cross.
*/

if (key == KEY_PLUS)
    map->z_increase += 0.1;
else if (key == KEY_MINUS && map->z_increase > 0.1)
    map->z_increase -= 0.1;


