#ifndef	PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

typedef	struct s_global {
	int				n;
	int				m_count;
	bool			is_eating;
  pthread_t		thread;
	long int		last_eat;
	struct s_data	*info;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	fork_l;
}		t_global;

typedef	struct s_data {
	int				philo_eat;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				stop;
	long int		t_start;
	t_global		*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	dead;
}		t_data;

void		ft_usleep(int ms);
int			init_philo(t_data *data);
long long	timestamp();
int			init_data(t_data *data, char **av);
void		*philo_life(void *phi);
void		print(t_global *philo, char *str);
int			is_dead(t_global *philo, int nb);
int			ft_isdigit(int character);
int			ft_atoi(const char *str);

#endif