/*
** set_light.c for set_light in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Sun Mar 13 19:25:17 2016 pinta_a
** Last update Sun Mar 13 20:12:46 2016 pinta_a
*/

#include <lapin.h>
#include <math.h>
#include "include.h"
#include "struct.h"
#include "proto.h"

void		set_shadow(t_color *col, int shadow)
{
  int		i;

  i = 0;
  while (i < shadow)
    {
      col->argb[0] = (double)col->argb[0] * SHADOW;
      col->argb[1] = (double)col->argb[1] * SHADOW;
      col->argb[2] = (double)col->argb[2] * SHADOW;
      i = i + 1;
    }
}

void		set_light_d(t_color *col, double coef)
{
  col->argb[0] = COL_SUP((double)col->argb[0] * coef);
  col->argb[1] = COL_SUP((double)col->argb[1] * coef);
  col->argb[2] = COL_SUP((double)col->argb[2] * coef);
  if (coef <= 0)
    col->full = BLACK;
}

void		set_light_s(t_color *col, double coef)
{
  col->argb[0] = (col->argb[0]
		  + COL_SUP((double)col->argb[0] * (1 - coef) + 255 * coef));
  col->argb[1] = (col->argb[1]
		  + COL_SUP((double)col->argb[1] * (1 - coef) + 255 * coef));
  col->argb[2] = (col->argb[2]
		  + COL_SUP((double)col->argb[2] * (1 - coef) + 255 * coef));
}

void		set_light(t_set *set,
			  double id,
			  double is,
			  int shadow)
{
  if (shadow == 0)
    set_light_s(&set->col, is);
  set_light_d(&set->col, id);
  set_shadow(&set->col, shadow);
}
