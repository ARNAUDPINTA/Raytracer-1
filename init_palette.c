/*
** init_palette.c for raytracer in /home/pinta/rendu/INFOGRAPHIE/gfx_raytracer1
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Feb 17 03:29:53 2016 pinta_a
** Last update Thu Mar 10 22:33:27 2016 pinta_a
*/

#include <lapin.h>
#include "struct.h"
#include "proto.h"

void	my_init_palette(t_loop *loop)
{
  loop->palette[0].full = BLACK;
  loop->palette[1].full = WHITE;
  loop->palette[2].full = RED;
  loop->palette[3].full = BLUE;
  loop->palette[4].full = YELLOW;
  loop->palette[5].full = PURPLE;
  loop->palette[6].full = GREEN;
  loop->palette[7].full = TEAL;
}
