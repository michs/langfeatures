#!/bin/bash

if [ ! -f proj_list.dat ] ; then
    echo "Please start the script from the workspace root."
fi

PROJ_LIST=$(cat proj_list.dat)
CONF_LIST="debug release"

for proj in $PROJ_LIST ; do
    if [ -d "$proj" ] ; then
        for conf in $CONF_LIST ; do
            mkdir -p $proj/$conf/src
        done
    fi
done
