/*
** include.h for include in /home/pinta_a/rendu/INFOGRAPHIE/gfx_raytracer1
** 
** Made by pinta_a
** Login   <pinta_a@epitech.eu>
** 
** Started on  Sun Feb 28 12:05:13 2016 pinta_a
** Last update Mon Mar 14 18:20:47 2016 pinta_a
*/

#ifndef	INCLUDE_H_
# define INCLUDE_H_

# ifndef COL_SUP
#  define COL_SUP(x) (x > 255 ? (255) : (x))
# endif /* !COL_SUP */

# ifndef INF
#  define INF(x) (x < 0 ? (0) : (x))
# endif /* !INF */

# ifndef SUP
#  define SUP(x) (x > 1 ? (1) : (x))
# endif /* !SUP */

# ifndef ABS
#  define ABS(x) (x < 0 ? (-x + 1) : (x))
# endif /* !ABS */

# ifndef IA
#  define IA (0.10)
# endif /* !IA */

# ifndef REFL_NB
#  define REFL_NB (2)
# endif /* !REFL_NB */

# ifndef SHADOW
#  define SHADOW (0.4)
# endif /* !SHADOW */

# ifndef WIDTH
#  define WIDTH (1280)
# endif /* !WIDTH */

# ifndef HEIGHT
#  define HEIGHT (960)
# endif /* !HEIGHT */

# ifndef X_SPEED
#  define X_SPEED (5)
# endif /* !X_SPEED */

# ifndef Y_SPEED
#  define Y_SPEED (5)
# endif /* !Y_SPEED */

# ifndef Z_SPEED
#  define Z_SPEED (5)
# endif /* !Z_SPEED */

# ifndef ROT_SPEED
#  define ROT_SPEED (5)
# endif /* !ROT_SPEED */

#endif /* !INCLUDE_H_ */
