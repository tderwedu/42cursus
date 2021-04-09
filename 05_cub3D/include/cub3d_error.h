/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:30:10 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/09 18:23:42 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERROR_H
# define CUB3D_ERROR_H

# define ERR_FILE_EXT	"File extension don’t match '.cub'!"
# define ERR_NUM_ARG	"Wrong number of input argument!"
# define ERR_DEF_TWICE	"Element defined twice!"
# define ERR_WRONG_RES	"The resolution is not valid!"
# define ERR_WRONG_LINE	"Not valid line!"
# define ERR_COLOR		"The color specification is not valid!"
# define ERR_NOT_ELEM	"One element specifier is not valid!!"
# define ERR_TEX_EXT	"Texture path don’t match '.xpm'!"
# define ERR_INCOMP		"The '.cub' file appears to be incomplete"
# define ERR_MAP_CHR	"Invalid char found in the map definition!"
# define ERR_MAP_DIR	"Player initial position defined more than once!"
# define ERR_MAP_EMPTY	"No empty line is allowed in the map definition!"
# define ERR_MAP_NOTCL	"The map is not closed! See below:"
# define ERR_DEBUG		"ERR_DEBUG ERR_DEBUG ERR_DEBUG"

#endif
