/*
** struct.h for raytracer in /home/pinta/rendu/INFOGRAPHIE
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Thu Feb  4 17:29:50 2016 pinta_a
** Last update Sun Mar 13 20:10:08 2016 pinta_a
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct		s_pars
{
  int			i;
  int			j;
  int			k;
}			t_pars;

typedef struct		s_posz
{
  double		x;
  double		y;
  double		z;
}			t_posz;

typedef struct		s_equa
{
  double		a;
  double		b;
  double		c;
  double		d;
}			t_equa;

typedef struct		s_view
{
  double		angle;
  struct s_posz		pos;
}			t_view;

typedef struct		s_ray
{
  struct s_posz		pos;
  struct s_posz		vec;
}			t_ray;

typedef struct		s_set
{
  int			color;
  int			type;
  double		dist;
  t_color		col;
  struct s_ray		ray;
}			t_set;

typedef struct		s_light
{
  int			shadow;
  double		id;
  double		is;
  struct s_ray		light;
  struct s_ray		refl;
  struct s_set		tmp;
}			t_light;

typedef struct		s_info
{
  int			color;
  int			type;
  double		data;
  struct s_posz		pos;
  struct s_posz		vec;
}			t_info;

typedef struct		s_geom
{
  int			nb_sphere;
  int			nb_cylinder;
  int			nb_cone;
  int			nb_plan;
  int			nb_light;
  struct s_info		*sphere;
  struct s_info		*cylinder;
  struct s_info		*cone;
  struct s_info		*plan;
  struct s_info		*light;
}			t_geom;

typedef struct		s_move
{
  int			left;
  int			right;
  int			up;
  int			down;
  int			front;
  int			back;
  int			rot_r;
  int			rot_l;
  int			actu;
}			t_move;

typedef struct		s_loop
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_color		palette[8];
  struct s_move		move;
  struct s_geom		geom;
  struct s_view		view;
}			t_loop;

#endif /* !STRUCT_H_ */
