#!/bin/bash

##
# leak_test.sh
##
clear
CHECK_OS="`uname -s`"
if [[ "$CHECK_OS" = "Darwin"* ]]; then
	./cub3d &
	leaks ./cub3d
	ps | grep -v grep | grep ./cub3d
	kill -9 `ps | grep -v grep | grep ./cub3d | awk '{print $1}'`
	ps | grep -v grep | grep ./cub3d
elif [[ "$CHECK_OS" = "Linux"* ]]; then
	echo -e "# COMMAND"
	echo -e "valgrind --track-origins=yes --leak-check=full --error-limit=no ./cub3d\n"
	valgrind --track-origins=yes --leak-check=full --error-limit=no ./cub3d
fi
