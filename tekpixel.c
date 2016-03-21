/*
** tekpixel.c for raytracer in /home/pinta_a/rendu/INFOGRAPHIE/flashlight_2020
** 
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
** 
** Started on  Fri Feb 26 18:55:43 2016 arnaud pinta
** Last update Fri Mar 11 15:20:21 2016 pinta_a
*/

#include <lapin.h>
#include "struct.h"

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 unsigned int color)
{
  int	position;

  position = pix->clipable.clip_width * pos->y + pos->x;
  if (pos->x >= 0 && pos->x < pix->clipable.clip_width
      && pos->y >= 0 && pos->y < pix->clipable.clip_height)
    ((int *)pix->pixels)[position] = color;
}

