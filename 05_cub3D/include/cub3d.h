/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:22:36 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/11 19:20:52 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>
# include <time.h>

# include "cub3d_define.h"
# include "cub3d_struct.h"
# include "cub3d_error.h"

/*
** 1: [parsing] ft_parse_file.c
*/

int		ft_get_data(t_cub *data, int argc, char **argv);
int		ft_parse_cubfile(t_cub *data);

/*
** 2: [parsing] ft_get_data.c
*/

int		ft_line_handler(t_cub *data);
int		ft_get_wall(t_cub *data, int i, int flag);
int		ft_get_pavement(t_cub *data, int i, int flag);
int		ft_get_resolution(t_cub *data);

/*
** 3: [parsing] ft_get_map.c
*/

int		ft_parse_map(t_cub *data, int empty);
int		ft_check_map_line(t_cub *data, int empty);
int		ft_create_map(t_cub *data);

/*
** 4: [parsing] ft_check_boundary.c
*/

int		ft_check_boundary_y(t_cub *data);
int		ft_check_boundary_x(t_cub *data);

/*
** [parsing] ft_parse_utils.c
*/

int		ft_get_int(char **ptr);
int32_t	ft_get_color(char *ptr);
void	ft_print_data(t_cub *data);
void	ft_print_map(t_cub *data);

/*
** [parsing] ft_error.c
*/

int		ft_error_arg(t_cub *data, char *str, char *arg);
int		ft_error_parser(t_cub *data, char *str);
int		ft_error_map(t_cub *data, char *str, int y_e, int x_e);

/*
** [parsing] ft_data.c
*/

void	ft_init_data(t_cub *data);
void	ft_free_data(t_cub *data);

/*
** [raycasting] mlx_init_struct.c
*/

int		mlx_init_struct(t_cub *data, t_mlx *mlx);
void	cam_init_struct(t_cub *data, t_cam *cam, double fov);
int		init_mandatory(t_cub *data, t_mlx *mlx);
int		init_bonus(t_cub *data, t_mlx *mlx);

/*
** [raycasting] new_frame.c
*/

int		new_frame(t_mlx *mlx);

/*
** [raycasting] set_mlx.c
*/

int		set_mlx(t_cub *data, int show_win);

/*
** [raycasting / utils] get_tex.c
*/

int		get_floor_ceil(t_cub *data, t_mlx *mlx);
int		get_tex(t_cub *data, t_mlx *mlx);
int		load_tex(t_mlx *mlx, t_tex *tex, char *dir);
void	rotate_tex(t_tex *tex);

/*
** [raycasting / utils] get_tex_bonus.c
*/
int		load_bonus_tex_1(t_mlx *mlx);
int		load_bonus_tex_2(t_mlx *mlx);

/*
** [raycasting] rc_error.c
*/

int		rc_exit(t_mlx *mlx);
int		rc_error(t_mlx *mlx, char *str);
int		rc_error_data(t_cub *data, t_mlx *mlx, char *str);

/*
** [raycasting] rc_free.c
*/

void	rc_free_mlx(t_mlx *mlx);
void	rc_free_map(t_mlx *mlx);
void	rc_free_ptr_map(t_mlx *mlx);

/*
** [raycasting] rc_key_press.c
*/

int		rc_key_press(int keycode, t_mlx *mlx);
void	rc_press_walk(int keycode, t_mlx *mlx, t_cam *cam);
void	rc_press_strafe(int keycode, t_mlx *mlx, t_cam *cam);
void	rc_press_turn(int keycode, t_cam *cam);
void	rc_press_crouch(t_mlx *mlx, t_cam *cam);
void	rc_press_jump(t_mlx *mlx, t_cam *cam);

/*
** [raycasting] rc_key_release.c
*/

int		rc_key_release(int keycode, t_mlx *mlx);
void	rc_release_crouch(t_cam *cam);

/*
** [raycasting] rc_mouse_hook.c
*/

void	rc_mouse_hook(t_mlx *mlx);
void	rc_mouse_pitch(t_mlx *mlx, t_cam *cam, int y);
void	rc_mouse_yaw(t_mlx *mlx, t_cam *cam, int x);
int		rc_button_press(int button, int x, int y, t_mlx *mlx);

/*
** [raycasting] rc_set_raycasting.c
*/

void	raycasting(t_mlx *mlx, t_cam *cam);

/*
** [raycasting] floor_ceil.c
*/

void	floor_ceil(t_mlx *mlx);
void	floor_ceil_rgb(t_mlx *mlx, t_img *img, int id);
void	floor_ceil_tex(t_mlx *mlx, t_cam *cam, t_img *img, int id);

/*
** [raycasting] spr_draws.c
*/

int		spr_new_lst(t_cub *data, t_mlx *mlx);
void	spr_draw(t_mlx *mlx);
void	spr_lst_sort(t_mlx *mlx, t_cam *cam);
void	spr_lst_add(t_mlx *mlx, t_spr *new);

/*
** [raycasting] rc_mini_map.c
*/
void	rc_draw_square_16(t_img *img, int y, int x, t_u32 rgb);
void	draw_mini_map(t_mlx *mlx, t_img *img);

/*
** [raycasting] skybox.c
*/

void	skybox(t_mlx *mlx, t_tex *tex, t_cam *cam);

/*
** [raycasting] rc_doors.c
*/

int		is_door(t_mlx *mlx, t_cam *cam, t_ray *ray);

/*
** [raycasting / bonus] ptr_map_bonus.c
*/

int		ptr_map_create(t_mlx *mlx);
int		ptr_map_fill_door(t_mlx *mlx, void ***ptr, int y, int x);
void	ptr_map_fill_spr(t_mlx *mlx, void ***ptr, int y, int x);
int		ptr_map_fill(t_mlx *mlx, void ***ptr);
void	ptr_map_update(t_mlx *mlx);

/*
** [raycasting] arm.c
*/

void	arm(t_mlx *mlx);
void	check_strike(t_mlx *mlx);
void	check_strike_spr(t_mlx *mlx, double y, double x, double dt);

/*
** [raycasting] set_tex_Yx_loop.c
*/

void	yx_set_tex_x_loop(t_mlx *mlx, t_tex *tex, t_loop *box);
void	yx_set_tex_x_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box);
void	yx_set_tex_y_loop(t_mlx *mlx, t_tex *tex, t_loop *box);
void	yx_set_tex_y_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box);

/*
** [raycasting] set_tex_Xy_loop.c
*/

void	xy_set_tex_y_loop(t_mlx *mlx, t_tex *tex, t_loop *box);
void	xy_set_tex_y_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box);
void	xy_set_tex_x_loop(t_mlx *mlx, t_tex *tex, t_loop *box, double d);
void	xy_set_tex_x_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box, double d);

/*
** [raycasting] kfc_bonus.c
*/

void	kfc_move(t_mlx *mlx, t_cam *cam, t_spr *spr);
void	kfc_tex(t_mlx *mlx, t_cam *cam, t_spr *spr);

/*
** [raycasting/utils] utils.c
*/

int		check_4_walls(t_mlx *mlx, double new_y, double new_x, double dt);

#endif
