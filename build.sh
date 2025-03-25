#!/bin/sh

echo "Docker Container Building $1:$2"

set -x -e

# Generar Makefile para MPLAB X
/opt/mplabx/mplab_platform/bin/prjMakefilesGenerator.sh $1@$2 || exit 1

# Compilar con el compilador XC8
make -C $1 CONF=$2 build || exit 2
