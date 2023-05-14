#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

// typedef struct	s_mlx {
// 	void	*mlx;
// 	void	*window;
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	int     width;
// 	int     height;
// }	t_mlx;

typedef struct s_game {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int     width;
	int     height;

	char **map;
	int height_map;
	int width_map;
	int players;
	int walls;
	int empty_space;
	int map_exit;
	int items;
	int position_player_x;
	int position_player_y;

	void *sprite_player;
	void *sprite_wall;
	void *sprite_place;
	void *sprite_exit;
	void *sprite_items;
	int height_sprite;
	int width_sprite;

} 	t_game;


void print_error(int a);
void read_arr(char **arr);
int len_pointer_arr(char **arr);
char **create_dublicate(char **arr);
void free_arr(char **arr);

// =============== CHECK MAP ========================

void check_first_string_map(t_game *map);
void check_last_string_map(t_game *map);
int check_other_string_map(char *string);
void check_wall_map(t_game *map);
void check_map(t_game *map);

// ============== PARSING FILE TO MAP ===============

void init_map(t_game *map);
void check_open_file(char *open_file);
void check_count_players_and_exits(char *open_file, t_game *map);
void parsing_file(char *av, t_game *map);

// ============== CHECK NO EXIT =====================

void check_no_exit(t_game *map);
void find_player(t_game *map);
void  flood_fill(char **tmp, t_game *map);

// ============== INIT WINDOW WITH MAP ================

void init_window_with_map(t_game *map);
void render_map(t_game *map);
void print_sprites(t_game *map, char c, int y, int x);
void init_sprites(t_game *map);

#endif