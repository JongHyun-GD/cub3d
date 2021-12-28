#!/bin/bash

##
# make_test.sh
##

clear
MAP_DIR="./assets/maps"
LS=`ls $MAP_DIR`

echo "./cub3d assets/maps/doesntexistmap.cub"
./cub3d assets/maps/doesntexistmap.cub
echo ""

for TEST_FILE in $LS
do
	echo "./cub3d $MAP_DIR/$TEST_FILE"
	./cub3d $MAP_DIR/$TEST_FILE
	echo ""
done
