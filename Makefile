##
## EPITECH PROJECT, 2020
## MUL_my_rpg_2019
## File description:
## Makefile
##

#flag#

CPPFLAGS=       $(INCLUDE) $(CSFML) $(LDFLAGS) $(CFLAGS)

CFLAGS  =       -Wall -Wextra -Wshadow

DBGFLAGS=       -g3

LDFLAGS =       -lm

INCLUDE =       -I./include

CSFML   =       -lcsfml-graphics -lcsfml-system -lcsfml-window

LIBFLAG = -L ./lib -lmy -lm

#src#

SRC	=	src/main.c				\
		src/menu/set_clic.c			\
		src/menu/set_menu.c			\
		src/menu/game_menu.c			\
		src/game/events.c			\
		src/game/main_loop.c			\
		src/game/hash_table.c			\
		src/game/function_malloc.c		\
		src/game/dialog.c			\
		src/game/window.c			\
		src/game/print.c			\
		src/game/fight.c			\
		src/game/graphic_fight.c		\
		src/game/draw_fight.c			\
		src/game/event_fight.c			\
		src/game/my_itoa.c			\
		src/game/load_buttons.c			\
		src/game/draw_buttons.c			\
		src/game/player_turn.c			\
		src/player/parser_player.c		\
		src/player/save_player.c		\
		src/player/load_player.c		\
		src/player/lib_parser.c			\
		src/player/func_player.c		\
		src/player/modif_stat_player.c		\
		src/monster/parser_monster.c		\
		src/monster/func_monster.c		\
		src/monster/load_monster.c		\
		src/market/market.c			\
		src/market/page_1_market.c		\
		src/market/page_2_market.c		\
		src/market/page_3_market.c		\
		src/market/page_4_market.c		\
		src/market/page_5_market.c		\
		src/market/create_market.c		\
		src/market/event_market.c		\
		src/market/func_market.c	\
		src/display_player/display_playerpng.c	\
		src/display_player/destroy_player.c	\
		src/display_player/hitbox.c		\
		src/display_player/up_down_hitbox.c	\
		src/display_player/move_player.c	\
		src/map/get_the_map.c			\
		src/map/get_block_asset.c		\
		src/map/get_block.c			\
		src/map/get_asset.c			\
		src/map/draw_map.c			\
		src/map/rand_road_grass.c		\
		src/map/change_map.c			\
		src/map/get_the_info.c			\
		src/map/set_pos.c			\
		src/map/set_new_pos.c			\
		src/map/get_the_pnj.c			\
		src/map/change_pnj.c			\
		src/map/set_new_map.c			\
		src/map/print_histories.c		\
		src/map/set_view.c			\
		src/map/set_all_diag.c			\
		src/map/draw_block_asset.c		\
		src/map/set_moov_enemies.c		\
		src/map/set_mob.c			\
		src/map/get_block_biss.c		\
		src/map/set_moov_tree.c			\
		src/map/free_map.c			\
		lib/my_str_to_word_array_pipe.c		\
		lib/my/func_lib/my_strcat.c		\
		src/inventory/inventory.c	\
		src/inventory/create_inv.c	\
		src/inventory/check_po.c	\
		src/particle/setup_particles.c		\
		src/particle/draw_particles.c		\
		src/inventory/check_arm.c		\
		src/inventory/pr_all.c		\
		src/inventory/ev_inv.c		\
		src/inventory/pla.c		\
		src/map/up_do.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CC	?=	gcc

RM	?=	rm -f

F_RM	=	rm -rf

TARGET	=	load.zip

DIR	=	load

#rules#

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(INCLUDE) $(CSFML) $(LIBFLAG)

debug:	CFLAGS += $(DBGFLAGS)
debug:	fclean
debug:	$(NAME)

zip:
	zip $(TARGET) -r $(DIR)
	$(F_RM) $(DIR)

unzip:
	unzip $(TARGET)
	$(F_RM) $(TARGET)

clean:
	$(RM) $(NAME)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) vgcore*

re:	fclean all

.PHONY: fclean clean re all debug
