#!/bin/sh
#Test to see if variables persist outside the program

read myvar
echo $myvar
echo "please echo myvar"

exit 0
% /bin/sh persistest.sh
% chmod +x persistest.sh
%./persistest.sh
