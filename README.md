# Philosopher Simulation Project

## Introduction

This project simulates the classical "Dining Philosophers" problem using threads and mutexes in C. The objective of the project is to understand and solve the problem of concurrency in which philosophers must share a limited number of resources (forks) without leading to deadlocks or starvation. Each philosopher alternates between eating, thinking, and sleeping, and must acquire two forks to eat.

## Compilation

To compile the project, use the following command:

```sh
gcc -Wall -Wextra -Werror -g -o philo main.c philo.c philo_init.c utils_0.c utils_1.c -lpthread
```

Make sure all the source files and headers are located in the same directory as the compiler is instructed to compile.

## Usage

The program takes 5 or 6 arguments:

```sh
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional)]
```

- **number_of_philosophers**: The number of philosophers and forks.
- **time_to_die**: Time in milliseconds, if a philosopher doesn't start eating before this time, they die.
- **time_to_eat**: Time in milliseconds, the time a philosopher takes to eat.
- **time_to_sleep**: Time in milliseconds, the time a philosopher spends sleeping.
- **number_of_times_each_philosopher_must_eat** (optional): If all philosophers eat at least this number of times, the simulation stops.

### Example:
```sh
./philo 5 800 200 200 7
```
This will simulate 5 philosophers with the given times for death, eating, and sleeping, with each philosopher eating 7 times.

## Description

- **Main Execution**: The `main()` function initializes the data and starts the simulation.
- **Data Initialization**: The `init_data()` function is responsible for initializing all the necessary data for the simulation, such as mutexes, the philosophers' array, and their respective attributes.
- **Philosopher Lifecycle**: Each philosopher runs in a separate thread. The `philo_life()` function controls the behavior of each philosopher, where they alternate between taking forks, eating, sleeping, and thinking.
- **Fork Handling**: Forks are represented by mutexes, and each philosopher must lock two mutexes to start eating.
- **Death Check**: The `check_death()` function runs concurrently to ensure that if a philosopher doesn't eat within the required time, the simulation stops, and the death is printed.

## Functions Overview

### `init_data(t_data *data, char **av)`
Initializes the shared data, including mutexes and the array of philosophers.

### `init_philo(t_data *data)`
Sets up the individual philosophers, initializes their attributes, and creates threads for each one.

### `check_death(void *phi)`
Monitors if a philosopher has exceeded the allowed time without eating.

### `take_fork(t_global *philo)`
Handles the logic for a philosopher to pick up forks. If there's only one philosopher, it waits until it starves, as they can't pick up two forks.

### `philo_eat(t_global *philo)`
Handles the eating logic for a philosopher, including updating the last eating timestamp and sleeping afterward.

### `philo_life(void *phi)`
This function is the main lifecycle for each philosopher, which loops through thinking, taking forks, eating, and sleeping until all philosophers have finished eating.

### `free_all(t_data *data)`
Frees allocated memory and destroys all mutexes to avoid resource leaks.

## Implementation Details

- **Mutexes** are used for each fork and other shared resources like the print statements to ensure correct synchronization between threads.
- **Threads** are used for each philosopher to run their lifecycle concurrently.
- The simulation ensures that all conditions are met, such as ensuring that no two philosophers pick up the same fork simultaneously.

## Important Considerations

- **Deadlock Prevention**: The implementation prevents deadlock by carefully controlling the order in which forks are picked up.
- **Concurrency Handling**: Each philosopher thread synchronizes using mutexes to prevent race conditions on shared resources.
- **Memory Management**: Proper handling of `malloc` and `free` ensures there are no memory leaks during or after the simulation.

## Debugging Tips

- **Valgrind**: Use Valgrind to check for memory leaks or invalid memory usage:
  ```sh
  valgrind ./philo 5 800 200 200 7
  ```
- **Print Statements**: Add more `print()` calls to trace specific parts of the philosopher's lifecycle if unexpected behaviors are observed.

## Compilation Flags

- `-Wall -Wextra -Werror`: Recommended flags for detecting common mistakes.
- `-g`: Adds debug symbols, useful for tools like GDB or Valgrind.
