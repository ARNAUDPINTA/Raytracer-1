/*
** init_view.c for raytracer in /home/pinta/rendu/INFOGRAPHIE/gfx_raytracer1
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Feb 17 02:31:07 2016 pinta_a
** Last update Sun Mar 13 18:57:12 2016 pinta_a
*/

#include <lapin.h>
#include <unistd.h>
#include "struct.h"
#include "proto.h"

int		my_init_view(t_bunny_ini *ini,
			     t_view *view,
			     char *forme)
{
  const char	*field[4];

  if ((field[0] = bunny_ini_get_field(ini, forme, "start", 0)) == NULL
      || (field[1] = bunny_ini_get_field(ini, forme, "start", 1)) == NULL
      || (field[2] = bunny_ini_get_field(ini, forme, "start", 2)) == NULL)
    return (1);
  if ((field[3] = bunny_ini_get_field(ini, forme, "start", 3)) == NULL)
    return (2);
  if (bunny_ini_get_field(ini, forme, "start", 5) != NULL)
    return (3);
  if (my_getnbr_d(field[0], &view->pos.x)
      || my_getnbr_d(field[1], &view->pos.y)
      || my_getnbr_d(field[2], &view->pos.z)
      || my_getnbr_d(field[3], &view->angle))
    return (4);
  return (0);
}
