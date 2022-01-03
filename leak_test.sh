#!/bin/bash

##
# leak_test.sh
##
valgrind --track-origins=yes --leak-check=full --error-limit=no ./cub3d
