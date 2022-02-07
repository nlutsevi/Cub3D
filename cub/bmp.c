/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:31:37 by nlutsevi          #+#    #+#             */
/*   Updated: 2022/02/07 04:19:29 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	create_header(t_bmp *bmp, t_global *g)
{
	bmp->byte_type[0] = 0x42;
	bmp->byte_type[1] = 0x4D;
	bmp->byte_size = (g->map.res.x * g->map.res.y * 4) + 54;
	bmp->byte_reserved = 0x00000000;
	bmp->byte_offset = 0x36;
	bmp->header_size = 40;
	bmp->image_width = g->map.res.x;
	bmp->image_height = g->map.res.y * -1;
	bmp->color_planes = 1;
	bmp->bits_per_pixel = 32;
	bmp->compression = 0;
	bmp->image_size = (g->map.res.x * g->map.res.y * 4);
	bmp->bits_xpels_per_meter = 2835;
	bmp->bits_ypels_per_meter = 2835;
	bmp->total_colors = 0;
	bmp->important_colors = 0;
}

void	write_header(int file, t_bmp bmp)
{
	int			r;

	r = 0;
	r = write(file, &bmp.byte_type, 2);
	r = write(file, &bmp.byte_size, 4);
	r = write(file, &bmp.byte_reserved, 4);
	r = write(file, &bmp.byte_offset, 4);
	r = write(file, &bmp.header_size, 4);
	r = write(file, &bmp.image_width, 4);
	r = write(file, &bmp.image_height, 4);
	r = write(file, &bmp.color_planes, 2);
	r = write(file, &bmp.bits_per_pixel, 2);
	r = write(file, &bmp.compression, 4);
	r = write(file, &bmp.image_size, 4);
	r = write(file, &bmp.bits_xpels_per_meter, 4);
	r = write(file, &bmp.bits_ypels_per_meter, 4);
	r = write(file, &bmp.total_colors, 4);
	r = write(file, &bmp.important_colors, 4);
}

void	write_file(int file, int image_size, t_global *g)
{
	char	*pixel_array;
	int		i;
	int		j;

	if (!(pixel_array = malloc(sizeof(char) * image_size)))
		ft_error(RED"No space for .bmp screenshot"WHITE);
	i = 0;
	j = 0;
	image_size /= 4;
	while (i < image_size)
	{
		pixel_array[j++] = g->img.data[i] & 255;
		pixel_array[j++] = (g->img.data[i] & 255 << 8) >> 8;
		pixel_array[j++] = (g->img.data[i] & 255 << 16) >> 16;
		pixel_array[j++] = 0;
		i++;
	}
	j = write(file, pixel_array, image_size *= 4);
	free(pixel_array);
}

int		screenshot(t_global *g)
{
	int		file;
	t_bmp	bmp;

	bzero(&bmp, sizeof(t_bmp));
	if (!((file = open("cub3D.bmp", O_WRONLY \
	| O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) > 0))
		ft_error(RED".bmp screenshot couldn't be created"WHITE);
	create_header(&bmp, g);
	write_header(file, bmp);
	write_file(file, bmp.image_size, g);
	close(file);
	return (1);
}
