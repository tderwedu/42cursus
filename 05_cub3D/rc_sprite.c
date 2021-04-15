/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:38:51 by tderwedu          #+#    #+#             */
/*   Updated: 2021/04/15 16:52:38 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

static inline int	rc_add_sprite(t_mlx *mlx, t_sprite *prev, t_rc *rc, double d)
{
	t_sprite	*new;

	new = malloc(sizeof(t_sprite));
	if (!new)
		return (rc_error(mlx, ERR_MALLOC));
	new->x_map = rc->x_map;
	new->y_map = rc->y_map;
	new->num = rc->hit;
	new->dist += d;
	if (!prev)
	{
		mlx->sprites = new;
		new->next = NULL;
	}
	else
	{
		new->next = prev->next;
		prev->next = new;
	}
	return (0);
}

int	rc_check_sprite(t_mlx *mlx, t_rc *rc)
{
	t_sprite	*next;
	t_sprite	*prev;
	double		tmp;
	double 		dist;

	next = mlx->sprites;
	tmp = mlx->cam->x_pos - (rc->x_map + 0.5);
	dist = tmp * tmp;
	tmp = mlx->cam->y_pos - (rc->y_map + 0.5);
	dist += tmp * tmp;
	if (!next)
		return (rc_add_sprite(mlx, NULL, rc, dist));
	else
	{
		while (next && next->dist < dist)
		{
			prev = next;
			next = next->next;
		}
		if (prev->x_map == rc->x_map || prev->y_map == rc->y_map)
			return (0);
		return (rc_add_sprite(mlx, prev, rc, dist));
	}
	return (0);
}


void	rc_sprite(t_mlx *mlx)
{
		
    for(int i = 0; i < numSprites; i++)
    {
      //translate sprite position to relative to camera
      double spriteX = sprite[spriteOrder[i]].x - posX;
      double spriteY = sprite[spriteOrder[i]].y - posY;

      //transform sprite with the inverse camera matrix
      // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
      // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
      // [ planeY   dirY ]                                          [ -planeY  planeX ]

      double invDet = 1.0 / (planeX * dirY - dirX * planeY); //required for correct matrix multiplication

      double transformX = invDet * (dirY * spriteX - dirX * spriteY);
      double transformY = invDet * (-planeY * spriteX + planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

      int spriteScreenX = int((w / 2) * (1 + transformX / transformY));

      //calculate height of the sprite on screen
      int spriteHeight = abs(int(h / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
      int drawStartY = -spriteHeight / 2 + h / 2;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + h / 2;
      if(drawEndY >= h) drawEndY = h - 1;

      //calculate width of the sprite
      int spriteWidth = abs( int (h / (transformY)));
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= w) drawEndX = w - 1;

      //loop through every vertical stripe of the sprite on screen
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = int(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
        if(transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
        for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
        {
          int d = (y) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
          int texY = ((d * texHeight) / spriteHeight) / 256;
          Uint32 color = texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
          if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
        }
      }
    }
}
