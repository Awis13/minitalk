#ifndef MINITALK_H
#define MINITALK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "include/ft_printf.h"
#include "include/libft.h"

void signal_handler(int sig);
char bits_to_char(int bits[8]);

#endif // MINITALK_H
