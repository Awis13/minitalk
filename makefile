NAME_CLIENT=client
NAME_SERVER=server

CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99

SRC_CLIENT=src/client.c
SRC_SERVER=src/server.c

LIBFT_DIR=src/libft
LIBFT=$(LIBFT_DIR)/libft.a

FT_PRINTF_DIR=src/ft_printf
FT_PRINTF=$(FT_PRINTF_DIR)/libftprintf.a

INCLUDES=-I includes -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(SRC_CLIENT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_CLIENT) $(FT_PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_SERVER) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_SERVER) $(FT_PRINTF) -o $(NAME_SERVER)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

clean:
	make -C $(FT_PRINTF_DIR) clean
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER)

fclean: clean
	make -C $(FT_PRINTF_DIR) fclean
	rm -f $(FT_PRINTF)
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER)

re: fclean all
