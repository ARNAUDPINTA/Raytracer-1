/*
** proto.h for raytracer in /home/pinta/rendu/INFOGRAPHIE/gfx_raytracer1
**
** Made by pinta_a
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Feb 17 01:26:02 2016 pinta_a
** Last update Thu Mar 17 12:42:42 2016 pinta_a
*/

#ifndef PROTO_H_
# define PROTO_H_

#include "struct.h"

/*
** move.c
*/

void			my_move(t_loop *loop);

/*
** key_rsp.c
*/

void			move_x_rsp(t_bunny_event_state state,
				   t_bunny_keysym key,
				   t_loop *loop);
void			move_z_rsp(t_bunny_event_state state,
				   t_bunny_keysym key,
				   t_loop *loop);
void			move_y_rsp(t_bunny_event_state state,
				   t_bunny_keysym key,
				   t_loop *loop);
void			move_angle_rsp(t_bunny_event_state state,
				       t_bunny_keysym key,
				       t_loop *loop);
t_bunny_response	key_rsp(t_bunny_event_state state,
				t_bunny_keysym key,
				void *data);

/*
** set.c
*/

void			init_set(t_set *set);

/*
** find_cylinder.c
*/

void			my_copy_set_cylinder(t_info *cylinder,
					     t_set *set,
					     t_posz *pos,
					     double dist);
void			_my_resolv_equa_cylinder(t_info *cylinder,
						 t_set *set,
						 t_ray *ray,
						 double sol);
void			my_resolv_equa_cylinder(t_info *cylinder,
						t_equa *equa,
						t_ray *ray,
						t_set *set);
void			my_equa_cylinder(t_info *cylinder,
					 t_ray *ray,
					 t_set *set);
void			my_find_cylinder(t_geom *geom,
					 t_ray *ray,
					 t_set *set);

/*
** find_sphere.c
*/

void			my_copy_set_sphere(t_info *cylinder,
					   t_set *set,
					   t_posz *pos,
					   double dist);
void			_my_resolv_equa_sphere(t_info *cylinder,
					       t_set *set,
					       t_ray *ray,
					       double sol);
void			my_resolv_equa_sphere(t_info *sphere,
					      t_equa *equa,
					      t_ray *ray,
					      t_set *set);
void			my_equa_sphere(t_info *cylinder,
				       t_ray *ray,
				       t_set *set);
void			my_find_sphere(t_geom *geom,
				       t_ray *ray,
				       t_set *set);

/*
** find_plan.c
*/

void			my_copy_set_plan(t_info *plan,
					 t_set *set,
					 t_posz *pos,
					 double dist);
void			_my_equa_plan(t_info *plan,
				      t_ray *ray,
				      t_set *set,
				      double sol);
void			my_equa_plan(t_info *plan,
				     t_ray *ray,
				     t_set *set);
void			my_find_plan(t_geom *geom,
				     t_ray *ray,
				     t_set *set);

/*
** find_light.c
*/

t_ray			init_light_ray(t_info *light,
				       t_set *set);
void			find_light(t_loop *loop,
				   t_ray *ray,
				   t_set *set);

/*
** set_light.c
*/

void			set_shadow(t_color *col, int shadow);
void			set_light_d(t_color *col, double coef);
void			set_light_s(t_color *col, double coef);
void			set_light(t_set *set,
				  double id,
				  double is,
				  int shadow);

/*
** find_cone.c
*/

void			my_copy_set_cone(t_info *cone,
					 t_set *set,
					 t_posz *pos,
					 double dist);
void			_my_resolv_equa_cone(t_info *cone,
					     t_set *set,
					     t_ray *ray,
					     double sol);
void			my_resolv_equa_cone(t_info *cone,
					    t_equa *equa,
					    t_ray *ray,
					    t_set *set);
void			my_equa_cone(t_info *cone,
				     t_ray *ray,
				     t_set *set);
void			my_find_cone(t_geom *geom,
				     t_ray *ray,
				     t_set *set);

/*
** find.c
*/

double			my_sol(double sol1, double sol2);
void			my_find(t_loop *loop,
				t_ray *ray,
				t_set *set,
				int rec);

/*
** init_cylinder.c
*/

int			my_copy_field_cylinder(const char *field[6],
					       t_info *cylinder,
					       int i);
int			_my_init_cylinder(t_bunny_ini *ini,
					  t_info *cylinder,
					  char *forme,
					  int nb);
int			my_init_cylinder(t_bunny_ini *ini,
					 t_geom *geom,
					 char *forme);

/*
** init_sphere.c
*/

int			my_copy_field_sphere(const char *field[6],
					     t_info *sphere,
					     int i);
int			_my_init_sphere(t_bunny_ini *ini,
					t_info *sphere,
					char *forme,
					int nb);
int			my_init_sphere(t_bunny_ini *ini,
				       t_geom *geom,
				       char *forme);

/*
** init_plan.c
*/

int			my_copy_field_plan(const char *field[8],
					   t_info *plan,
					   int i);
int			_my_init_plan(t_bunny_ini *ini,
				      t_info *plan,
				      char *forme,
				      int nb);
int			my_init_plan(t_bunny_ini *ini,
				     t_geom *geom,
				     char *forme);

/*
** init_cone.c
*/

int			my_copy_field_cone(const char *field[6],
					   t_info *cone,
					   int i);
int			_my_init_cone(t_bunny_ini *ini,
				      t_info *cone,
				      char *forme,
				      int nb);
int			my_init_cone(t_bunny_ini *ini,
				     t_geom *geom,
				     char *forme);

/*
** init_light.c
*/

int			my_copy_field_light(const char *field[3],
					    t_info *light,
					    int i);
int			_my_init_light(t_bunny_ini *ini,
				       t_info *light,
				       char *forme,
				       int nb);
int			my_init_light(t_bunny_ini *ini,
				      t_geom *geom,
				      char *forme);

/*
** init_view.c
*/

int			my_init_view(t_bunny_ini *ini,
				     t_view *view,
				     char *forme);

/*
** init_geom.c
*/

int			my_init_geom(t_loop *loop,
				     char *file,
				     char *forme);

/*
** init_palette.c
*/

void			my_init_palette(t_loop *loop);

/*
** reflexion.c
*/

double			my_scalaire(t_posz *u, t_posz *v);
t_ray			my_ray_reflexion(t_ray *ray, t_set *set);

/*
** my_getnbr.c
*/

int			my_getnbr_d(const char *nbr, double *nb);
int			my_getnbr_i(const char *nbr, int *nb);

/*
** tekpixel.c
*/

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 unsigned int color);

/*
** free.c
*/

void			my_free(t_loop *loop);

/*
** raytracer.c
*/

t_posz			my_vector_u(t_posz *vec);
t_ray			my_ray(t_bunny_position *pos,
			       t_view *view);
void			my_raytracer(t_loop *loop);

#endif /* !PROTO_H_ */
