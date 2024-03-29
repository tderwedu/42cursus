/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <tderwedu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:22:36 by tderwedu          #+#    #+#             */
/*   Updated: 2021/05/19 09:42:31 by tderwedu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <mlx.h>

# include "cub3d_define.h"
# include "cub3d_struct.h"
# include "cub3d_error.h"

/*
** #################
** # 1 - PARSING   #
** #################
*/

/*
** 0 : [parsing] ft_parse_file.c
*/

int		ft_get_data(t_cub *data, int argc, char **argv);
int		ft_parse_cubfile(t_cub *data);

/*
** 2 : [parsing] ft_get_data.c
*/

int		ft_line_handler(t_cub *data);
int		ft_get_wall(t_cub *data, int i, int flag);
int		ft_get_floor_ceil(t_cub *data, int i, int flag);
int		ft_get_resolution(t_cub *data);

/*
** 3 : [parsing] ft_get_map.c
*/

int		ft_parse_map(t_cub *data, int empty);
int		ft_create_map(t_cub *data);

/*
** 3-b : [parsing] ft_check_map_line.c
*/

int		ft_check_map_line(t_cub *data, int empty);

/*
** 4 : [parsing] ft_check_boundary.c
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
** [parsing] ft_init_free.c
*/

void	ft_init_data(t_cub *data);
int		ft_free_data(t_cub *data);

/*
** ####################
** # 2 - RAYCASTING   #
** ####################
*/

/*
** 1 : [raycasting] set_mlx.c
*/

int		set_mlx(t_cub *data);
int		save_frame(t_cub *data);

/*
** 2 : [raycasting] mlx_init_struct.c
*/

int		mlx_init_struct(t_cub *data, t_mlx *mlx, int win);
void	cam_init_struct(t_cub *data, t_cam *cam, double fov);
int		init_mandatory(t_cub *data, t_mlx *mlx);
int		init_bonus(t_cub *data, t_mlx *mlx);

/*
** 3 : [raycasting] new_frame.c
*/

int		new_frame(t_mlx *mlx);
int		new_img(t_mlx *mlx, t_img *img);

/*
** 4 : [raycasting / draw] floor_ceil.c
*/

void	floor_ceil(t_mlx *mlx);
void	floor_ceil_rgb(t_mlx *mlx, t_img *img, int id);
void	floor_ceil_tex(t_mlx *mlx, t_cam *cam, t_img *img, int id);

/*
** 5 : [raycasting / draw] raycasting.c
*/

void	raycasting(t_mlx *mlx, t_cam *cam);

/*
** 6 : [raycasting / draw] sprites.c
*/

int		spr_new_lst(t_cub *data, t_mlx *mlx);
void	spr_lst_sort(t_mlx *mlx, t_cam *cam);
void	spr_lst_add(t_mlx *mlx, t_spr *new);
void	spr_draw(t_mlx *mlx);

/*
** #########################
** # 3 - EVENTS HANDLING   #
** #########################
*/

/*
** [raycasting / events] rc_key_press_1.c
*/

int		key_press(int keycode, t_mlx *mlx);
void	press_walk(int keycode, t_mlx *mlx, t_cam *cam);
void	press_strafe(int keycode, t_mlx *mlx, t_cam *cam);
void	press_turn(int keycode, t_cam *cam);

/*
** [raycasting / events] rc_key_press_2.c
*/

void	press_crouch(t_mlx *mlx, t_cam *cam);
void	press_jump(t_mlx *mlx, t_cam *cam);

/*
** [raycasting / events] rc_key_release.c
*/

int		key_release(int keycode, t_mlx *mlx);
void	release_crouch(t_cam *cam);

/*
** #########################
** # 3 - RAYCASTING UTILS  #
** #########################
*/

/*
** [raycasting / utils] bmp_save.c
*/

int		bmp_save(t_mlx *mlx, t_img *img);
void	bmp_file_header(t_mlx *mlx, int fd);
void	bmp_info_header(t_mlx *mlx, int fd);

/*
** [raycasting / utils] rc_error.c
*/

int		rc_exit(t_mlx *mlx);
int		rc_error(t_mlx *mlx, char *str);
int		rc_error_tex(t_mlx *mlx, char *str, char *tex);
int		rc_error_data(t_cub *data, t_mlx *mlx, char *str);

/*
** [raycasting / utils] get_tex.c
*/

int		get_tex(t_cub *data, t_mlx *mlx);
int		get_floor_ceil(t_cub *data, t_mlx *mlx);
int		load_tex(t_mlx *mlx, t_tex *tex, char *dir);
void	rotate_tex(t_tex *tex);

/*
** [raycasting / utils] rc_free.c
*/

void	rc_free_mlx(t_mlx *mlx);
void	rc_free_map(t_mlx *mlx);

/*
** [raycasting] set_tex_yx_loop.c
*/

void	set_tex_yx_x_loop(t_mlx *mlx, t_tex *tex, t_loop *box);
void	set_tex_yx_x_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box);
void	set_tex_yx_y_loop(t_mlx *mlx, t_tex *tex, t_loop *box);
void	set_tex_yx_y_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box);

/*
** [raycasting] set_tex_xy_loop.c
*/

void	set_tex_xy_y_loop(t_mlx *mlx, t_tex *tex, t_loop *box);
void	set_tex_xy_y_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box);
void	set_tex_xy_x_loop(t_mlx *mlx, t_tex *tex, t_loop *box, double d);
void	set_tex_xy_x_tex_loop(t_mlx *mlx, t_tex *tex, t_loop *box, double d);

/*
** #########################
** # 4 - RAYCASTING BONUS  #
** #########################
*/

/*
** [raycasting / bonus] arm.c
*/

void	arm(t_mlx *mlx);
void	check_strike(t_mlx *mlx);
void	check_strike_spr(t_mlx *mlx, double y, double x, double dt);

/*
** [raycasting / bonus] check_4_stuff.c
*/

int		check_4_walls(t_mlx *mlx, double new_y, double new_x, double dt);
int		check_4_collisions(t_mlx *mlx, double new_y, double new_x, double dt);
void	check_4_knife(t_mlx *mlx, t_cam *cam);
void	check_4_kfc(t_mlx *mlx, t_cam *cam);

/*
** [raycasting / bonus] rc_doors.c
*/

int		is_door(t_mlx *mlx, t_cam *cam, t_ray *ray);

/*
** [raycasting / bonus] get_tex_bonus.c
*/

int		load_bonus_tex_1(t_mlx *mlx);
int		load_bonus_tex_2(t_mlx *mlx);

/*
** [raycasting / bonus] kfc_bonus.c
*/

void	kfc_move(t_mlx *mlx, t_cam *cam, t_spr *spr);
void	kfc_tex(t_mlx *mlx, t_cam *cam, t_spr *spr);

/*
** [raycasting / bonus] life_bar.c
*/

void	life_bar(t_mlx *mlx);

/*
** [raycasting / bonus] mini_map_bonus_1.c
*/

void	draw_mini_map(t_mlx *mlx);
void	mmap_set_info(t_mlx *mlx, t_mini *map);
void	mmap_upate_limits(t_mlx *mlx, t_mini *map);
void	mmap_draw_mmap(t_mlx *mlx, t_mini *map);

/*
** [raycasting / bonus] mini_map_bonus_1.c
*/

void	mmap_draw_square(t_mlx *mlx, int y_0, int x_0, t_u32 rgb);
void	mmap_draw_edge(t_mlx *mlx, t_mini *map);
void	mmap_draw_player_pos(t_mlx *mlx, t_img *img, t_mini *map);

/*
** [raycasting / bonus] mouse_bonus.c
*/

void	mouse_hook(t_mlx *mlx);
void	mouse_pitch(t_mlx *mlx, t_cam *cam, int y);
void	mouse_yaw(t_mlx *mlx, t_cam *cam, int x);
int		button_press(int button, int x, int y, t_mlx *mlx);

/*
** [raycasting / bonus] ptr_map_bonus.c
*/

int		ptr_map_create(t_mlx *mlx);
void	ptr_map_fill_door(t_mlx *mlx, void ***ptr, int y, int x);
void	ptr_map_fill_spr(t_mlx *mlx, void ***ptr, int y, int x);
void	ptr_map_fill(t_mlx *mlx, void ***ptr);
void	ptr_map_update(t_mlx *mlx);

/*
** [raycasting / bonus] skybox.c
*/

void	skybox(t_mlx *mlx, t_tex *tex, t_cam *cam);

#endif
