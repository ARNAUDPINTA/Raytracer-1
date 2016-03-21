##
## Makefile for raytracer in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
## 
## Made by arnaud pinta
## Login   <pinta_a@epitech.net>
## 
## Started on  Thu Feb 25 18:53:18 2016 arnaud pinta
## Last update Sun Mar 13 19:25:57 2016 pinta_a
##

NAME	=	raytracer

SRC	=	init_cylinder.c	\
		find_cylinder.c	\
		init_palette.c	\
		init_sphere.c	\
		find_sphere.c	\
		init_light.c	\
		find_light.c	\
		set_light.c	\
		init_geom.c	\
		init_cone.c	\
		find_cone.c	\
		init_plan.c	\
		find_plan.c	\
		init_view.c	\
		raytracer.c	\
		my_getnbr.c	\
		reflexion.c	\
		tekpixel.c	\
		key_rsp.c	\
		move.c		\
		find.c		\
		free.c		\
		main.c		\
		set.c

LIB	=	-L/home/${USER}/.froot/lib/		\
		-L/usr/local/lib 			\
		-lsfml-graphics 			\
		-lsfml-window 				\
		-lsfml-system 				\
		-lstdc++ -ldl 				\
		-lsfml-audio 				\
		-llapin 				\
		-lm

CFLAGS	+=	-W					\
		-Wall					\
		-ansi					\
		-Werror					\
		-pedantic				\
		-I/home/${USER}/.froot/include/

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc $(OBJ) $(LIB) -o $(NAME)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

