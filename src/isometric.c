/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:59:38 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/30 15:59:39 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void isometric_proj()
{
	//a = angle
	destination.x = source.x * cos(a) + source.y * cos(a + 2) + source.z * cos(a - 2)
	destination.y = source.x * sin(a) + source.y * sin(a + 2) + source.z * sin(a - 2)

}