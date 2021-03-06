cmake_minimum_required(VERSION 3.8)
project(ft_printf)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main_test.c
        srcs/core.c
        libs/libft/ft_strlen.c
        libs/libft/ft_strcmp.c
        libs/libft/ft_strnstr.c
        libs/libft/ft_putchar_fd.c
        libs/libft/ft_putnbr_fd.c
        includes/structs.h
        libs/libft/ft_atoi.c
        libs/libft/ft_isalnum.c
        libs/libft/ft_isdigit.c
        libs/libft/ft_isalpha.c
        libs/libft/ft_islower.c
        libs/libft/ft_isupper.c
        libs/libft/ft_itoa_base.c
        libs/libft/ft_strchr.c
        libs/libft/ft_isprint.c
        libs/libft/ft_strnew.c
        libs/libft/ft_memalloc.c
        libs/libft/ft_bzero.c
        libs/libft/ft_strcat.c
        libs/libft/ft_strsub.c
        libs/libft/ft_strncpy.c
        libs/libft/ft_strjoin.c
        libs/libft/ft_strcpy.c
        libs/libft/ft_strnstr.c
        includes/core.h includes/prototypes.h srcs/types/chars.c srcs/types/strings.c srcs/types/numbers.c srcs/types/others.c srcs/flags.c srcs/types/pointers.c srcs/types/numbers_l.c srcs/utils/bases.c srcs/utils/numbers.c tests/assert_x.c tests/functions.h srcs/types/arrays.c srcs/utils/pad.c srcs/utils/flags.c srcs/utils/get_numbers.c srcs/utils/write.c srcs/utils/wchars.c srcs/types/floats.c srcs/utils/floats.c tests/pays42.c srcs/utils/colors.c srcs/types/binary.c)

add_executable(ft_printf ${SOURCE_FILES})
