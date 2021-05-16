/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:30:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/16 18:29:42 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERROR_H
# define CUB3D_ERROR_H

# define ERR_ARG_NBR		"Wrong number of input argument!"
# define ERR_ARG_OPT		"Invalid option"
# define ERR_DEF_TWICE		"Element defined twice!"
# define ERR_FILE_EXT		"File extension don’t match '.cub'!"
# define ERR_READ_FILE		"An error occured while reading the .cub file!"
# define ERR_WRONG_RES		"The resolution is not valid!"
# define ERR_WRONG_LINE		"Not valid line!"
# define ERR_COLOR			"The color specification is not valid!"
# define ERR_NOT_ELEM		"One element specifier is not valid!!"
# define ERR_TEX_EXT		"Texture path don’t match '.xpm'!"
# define ERR_INCOMP			"The '.cub' file appears to be incomplete"
# define ERR_MAP_CHR		"Invalid char found in the map definition!"
# define ERR_MAP_DIR		"The cam's initial position is not defined!"
# define ERR_MAP_DIR2		"cam initial position defined more than once!"
# define ERR_MAP_EMPTY		"No empty line is allowed in the map definition!"
# define ERR_MAP_MSG		"The maps is missing!"
# define ERR_MAP_MSG		"The maps is missing!"
# define ERR_MAP_NOTCL		"The map is not closed! See below:"
# define ERR_DEBUG			"ERR_DEBUG ERR_DEBUG ERR_DEBUG"

# define ERR_RC_INIT		"NULL pointer from mlx_init()!"
# define ERR_RC_WIN			"NULL pointer from mlx_new_window()!"
# define ERR_RC_BPP			"The number of bits per pixel is not an int!"
# define ERR_RC_IMG_XPM		"NULL pointer from mlx_xpm_file_to_image()!"
# define ERR_RC_ADDR_XPM	"NULL pointer from mlx_get_data_addr() (xpm)!"

# define ERR_MALLOC			"Malloc returned NULL!"

#endif
