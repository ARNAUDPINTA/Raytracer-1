/*
** init_plan.c for raytracer in /home/pinta/rendu/INFOGRAPHIE/gfx_raytracer1
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Feb 17 02:11:51 2016 pinta_a
** Last update Fri Mar 11 15:12:38 2016 pinta_a
*/

#include <lapin.h>
#include "struct.h"
#include "proto.h"

int		my_copy_field_plan(const char *field[8],
				   t_info *plan,
				   int i)
{
  if (my_getnbr_d(field[0], &plan[i].pos.x)
      || my_getnbr_d(field[1], &plan[i].pos.y)
      || my_getnbr_d(field[2], &plan[i].pos.z))
    return (1);
  if (my_getnbr_d(field[3], &plan[i].vec.x)
      || my_getnbr_d(field[4], &plan[i].vec.y)
      || my_getnbr_d(field[5], &plan[i].vec.z))
    return (2);
  if (my_getnbr_i(field[6], &plan[i].color)
      || my_getnbr_i(field[7], &plan[i].type))
    return (3);
  if (plan[i].color < 0 || plan[i].color > 7)
    return (4);
  return (0);
}

int		_my_init_plan(t_bunny_ini *ini,
			      t_info *plan,
			      char *forme,
			      int nb)
{
  const char	*field[8];
  t_pars	pars;

  pars.i = 0;
  pars.j = 1;
  while (pars.i < nb)
    {
      pars.k = 0;
      while (pars.k < 8)
	{
	  field[pars.k] = bunny_ini_get_field(ini, forme, "plan", pars.j);
	  if (field[pars.k] == NULL)
	    return (1);
	  pars.k = pars.k + 1;
	  pars.j = pars.j + 1;
	}
      if (my_copy_field_plan(field, plan, pars.i))
	return (2);
      pars.i = pars.i + 1;
    }
  if (bunny_ini_get_field(ini, forme, "plan", pars.j) != NULL)
    return (3);
  return (0);
}

int		my_init_plan(t_bunny_ini *ini,
			     t_geom *geom,
			     char *forme)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, forme, "plan", 0)) == NULL)
    return (1);
  if (my_getnbr_i(field, &geom->nb_plan))
    return (2);
  if (geom->nb_plan < 0)
    return (3);
  if (geom->nb_plan == 0
      && bunny_ini_get_field(ini, forme, "plan", 1) != NULL)
    return (4);
  if (geom->nb_plan == 0)
    return (0);
  if ((geom->plan = bunny_malloc(sizeof(t_info) * geom->nb_plan)) == NULL)
    return (5);
  if (_my_init_plan(ini, geom->plan, forme, geom->nb_plan))
    return (6);
  return (0);
}
