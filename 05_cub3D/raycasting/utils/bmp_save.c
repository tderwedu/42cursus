/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:04:28 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/16 19:36:56 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	bmp_save(t_mlx *mlx, t_img *img)
{
	int		x;
	int		y;
	int		fd;

	fd = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC, 77777);
	if (fd < 0)
		return (rc_error(mlx, strerror(errno)));
	bmp_file_header(mlx, fd);
	bmp_info_header(mlx, fd);
	y = mlx->height;
	while (--y >= 0)
	{
		x = -1;
		while (++x < mlx->width)
			write(fd, img->addr + (y * img->sl + x), 4);
	}
	close(fd);
	return (0);
}

/*
** == File Header ==
** Name		Bytes	Description
** FileType	2	Specify a bmp file type. 'BM' for Windows Bitmap.
** FileSize	4	File size in bytes.
** Reserved	2	Reserved. Used by image processing application.
** Reserved	2	It should be initialized to 0.
** Offset 	4	Offset of actual pixel data in bytes.
** -------- -------	-------------------------------------------------
** Total 	14 bytes
*/
void	bmp_file_header(t_mlx *mlx, int fd)
{
	t_u32	tmp;

	write(fd, "BM", 2);
	tmp = 54 + 4 * mlx->height * mlx->width;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
}

/*
** == Bitmap Information Header ==
** Name			  Bytes	Description
** HeaderSize		4 	Size of the header in bytes. 40 for Windows Bitmap.
** Image Width		4 	Width of the final image in pixels.
** Image Height		4 	Height of the final image in pixels.
** Planes			2 	Number of color planes of the target device (1).
** Bits Per Pixel 	2 	Number of bits a pixel takes to represent a color.
** Compression		4	Value of compression to use. 0 when no compression.
** Image Size		4	Size of the compressed image. 0 when no compression.
** XpixelsPerMeter	4	Horizontal resolution. 0 when no preference.
** YpixelsPerMeter	4	Vertical resolution. 0 when no preference.
** Total Colors		4	Nbr of colors in the color pallet. 0 when ignored.
** Important Colors	4	Nbr of important colors. 0 when ignored.
** ---- 	---- 	----
** Total 	40 bytes 	Size of the BITMAPINFOHEADER in bytes.
*/
void	bmp_info_header(t_mlx *mlx, int fd)
{
	t_u32	tmp;

	tmp = 40;
	write(fd, &tmp, 4);
	tmp = mlx->width;
	write(fd, &tmp, 4);
	tmp = mlx->height;
	write(fd, &tmp, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	tmp = 32;
	write(fd, &tmp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}
