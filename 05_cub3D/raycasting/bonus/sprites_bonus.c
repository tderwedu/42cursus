/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:48:49 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/10 15:26:32 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "cub3d.h"

# define SPR_B_Y000	"./textures/chicken_y000.xpm"
# define SPR_B_Y045	"./textures/chicken_y045.xpm"
# define SPR_B_Y090	"./textures/chicken_y090.xpm"
# define SPR_B_Y135	"./textures/chicken_y135.xpm"
# define SPR_B_Y180	"./textures/chicken_y180.xpm"
# define SPR_B_Y225	"./textures/chicken_y225.xpm"
# define SPR_B_Y270	"./textures/chicken_y270.xpm"
# define SPR_B_Y315	"./textures/chicken_y315.xpm"
# define SPR_B_DEAD	"./textures/pillar.xpm"

int	get_tex(t_mlx *mlx, t_tex *tex, char *dir)
{
	tex->img = mlx_xpm_file_to_image(mlx->mlx, dir, &tex->width,
				&tex->height);
	if (!tex->img)
		return (rc_error(mlx, ERR_RC_IMG_XPM));
	tex->addr = (t_u32 *)mlx_get_data_addr(tex->img, &tex->bpp, &tex->sl, &tex->endia);
	if (!tex->addr)
		return (rc_error(mlx, ERR_RC_ADDR_XPM));
	tex->bpp /= 8;
	tex->sl /= 4;
	tex->h_mask = tex->height - 1;
	tex->w_mask = tex->width - 1;
	if (!(tex->bpp == sizeof(t_u32)))
		return (rc_error(mlx, ERR_RC_BPP));
	return (0);
}

int	spr_b_init(t_mlx *mlx)
{
	int i;

	mlx->spr_b = (t_spr_b){3.5, 3.5, 1.0, 0.0,  0.0,  0.0,  0.0, 0, NULL};
	if (get_tex(mlx, &mlx->tex_b[0], SPR_B_Y000))
		return (1);
	if (get_tex(mlx, &mlx->tex_b[1], SPR_B_Y045))
		return (1);
	if (get_tex(mlx, &mlx->tex_b[2], SPR_B_Y090))
		return (1);
	if (get_tex(mlx, &mlx->tex_b[3], SPR_B_Y135))
		return (1);
	if (get_tex(mlx, &mlx->tex_b[4], SPR_B_Y180))
		return (1);
	if (get_tex(mlx, &mlx->tex_b[5], SPR_B_Y225))
		return (1);
	if (get_tex(mlx, &mlx->tex_b[6], SPR_B_Y270))
		return (1);
	if (get_tex(mlx, &mlx->tex_b[7], SPR_B_Y315))
		return (1);
	if (get_tex(mlx, &mlx->tex_b[8], SPR_B_DEAD))
		return (1);
	i = -1;
	while (++i < 9)
		rc_rotate_tex(&mlx->tex_b[i]);
	return (0);
}

int	is_close_2_wall(t_mlx *mlx, double new_y, double new_x)
{
	int ret;

	ret = 0;
	ret += (mlx->map[(int)(new_y)][(int)(new_x)] != 0);
	ret += (mlx->map[(int)(new_y + 0.10)][(int)(new_x)] != 0);
	ret += (mlx->map[(int)(new_y - 0.10)][(int)(new_x)] != 0);
	ret += (mlx->map[(int)(new_y)][(int)(new_x + 0.10)] != 0);
	ret += (mlx->map[(int)(new_y)][(int)(new_x - 0.10)] != 0);
	return (ret);
}

void	spr_b_move(t_mlx *mlx, t_spr_b *spr)
{
	int		tmp;
	double	new_y;
	double	new_x;
	double	new_dir;

	tmp = rand() % 150 - 75;
	if (tmp > -15 && tmp < 15)
	{
		new_dir = atan2(spr->y_dir, spr->x_dir) + tmp * M_PI / 180.0;
		spr->y_dir = sin(new_dir);
		spr->x_dir = cos(new_dir);
	}
	if (tmp > -30 && tmp < 30)
	{
		new_y = spr->y_map + spr->y_dir * SPR_B_SPEED;
		new_x = spr->x_map + spr->x_dir * SPR_B_SPEED;
		if (!is_close_2_wall(mlx, new_y, new_x))
		{
			spr->y_map = new_y;
			spr->x_map = new_x;
		}
		else
		{
			spr->y_dir = -spr->y_dir;
			spr->x_dir = -spr->x_dir;
		}
	}
}


void	spr_b_dist(t_mlx *mlx, t_cam *cam, t_spr_b *spr)
{
	int		tmp;
	double	dir;
	double	det;
	double	dt_x;
	double	dt_y;

	det = 1.0 / (cam->x_plane * cam->y_dir - cam->y_plane * cam->x_dir);
	dt_x = spr->x_map - cam->x_pos;
	dt_y = spr->y_map - cam->y_pos;
	spr->y_tr = det * (-cam->y_plane * dt_x + cam->x_plane * dt_y);
	if (spr->y_tr > 0)
	{
		if (!spr->dead)
		{
			spr->x_tr = det * (cam->y_dir * dt_x - cam->x_dir * dt_y);
			spr->dist = spr->y_tr * spr->y_tr + spr->x_tr * spr->x_tr;
			dir = atan2(cam->y_dir, cam->x_dir) - atan2(spr->y_dir, spr->x_dir);
			tmp = ((int)(dir * 1800 / M_PI) + 2025) % 3600;
			if (tmp < 0)
				tmp += 3600;
			spr->tex = &mlx->tex_b[tmp / 450];
		}
		else
			spr->tex = &mlx->tex_b[0];
	}
}


void	spr_b_draw(t_mlx *mlx)
{
	t_spr_b		*spr;
	t_loop		box;
	int			x_screen;
	int			z_move;

	spr = &mlx->spr_b;
	spr_b_move(mlx, spr);
	spr_b_dist(mlx, mlx->cam, spr);
	if (spr->y_tr > 0)
	{
		box = (t_loop){0, 0, 0, 0, spr->tex->height, 0, 0,
			(int)(mlx->ratio / spr->y_tr), 0, spr->tex->width};
		x_screen = (int)((mlx->width / 2) * (1 + spr->x_tr / spr->y_tr));
		z_move = mlx->cam->pitch + mlx->cam->z_pos / spr->y_tr;
		box.y_range = (int)(mlx->ratio / spr->y_tr);
		box.y = -box.y_range / 2 + mlx->height_2 + z_move;
		box.x = -box.x_range / 2 + x_screen;
		if (box.y_tex_range < box.y_range)
			xy_set_tex_x_loop(mlx, spr->tex, &box, 0x0, spr->y_tr);
		else
			xy_set_tex_x_tex_loop(mlx, spr->tex, &box, 0x0, spr->y_tr);
	}
}
