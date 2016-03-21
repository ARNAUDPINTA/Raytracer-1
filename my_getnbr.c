/*
** my_getnbr.c for my_getnbr.c in /home/pinta_a/rendu/push_swap
**
** Made by arnaud pinta
** Login   <pinta_a@epitech.net>
**
** Started on  Wed Nov 18 15:06:17 2015 arnaud pinta
** Last update Fri Mar 11 15:20:00 2016 pinta_a
*/

int	my_getnbr_d(const char *nbr, double *nb)
{
  int	i;
  int	m;

  i = 0;
  m = 1;
  *nb = 0;
  while (nbr[i] == '-')
    {
      m = -m;
      i = i + 1;
    }
  while (nbr[i] >= '0' && nbr[i] <= '9')
    {
      *nb = *nb * 10 + (nbr[i] - 48);
      i = i + 1;
    }
  if (nbr[i] != '\0')
    return (1);
  *nb = *nb * m;
  return (0);
}

int	my_getnbr_i(const char *nbr, int *nb)
{
  int	i;
  int	m;

  i = 0;
  m = 1;
  *nb = 0;
  while (nbr[i] == '-')
    {
      m = -m;
      i = i + 1;
    }
  while (nbr[i] >= '0' && nbr[i] <= '9')
    {
      *nb = *nb * 10 + (nbr[i] - 48);
      i = i + 1;
    }
  if (nbr[i] != '\0')
    return (1);
  *nb = *nb * m;
  return (0);
}
