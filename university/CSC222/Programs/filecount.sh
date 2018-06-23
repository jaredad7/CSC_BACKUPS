#!/bin/sh
#This program will count the number of files in it's own directory and all sub-directories recursively
#It may take any number of arguments which are directories and begin in the specified directory. 
#By default, it will start in the current directory.

displayhelp()
{
	echo "\tcountf.sh [OPTION1] [OPTION2] ..."
	echo "\talias filecount\n\n"
	echo "Searches current directory and sub-directories recursively and returns the number of files there. Arguments are sub-directories of the curent directory which will be used as a starting point and search from there. Each directory can be counted an indefinite number of times this way. Countf.sh will not track which files have been counted. If more than one directory is specified, each will be counted one at a time.\n\n"

}

#check if user wants help or if user has entered unnacceptable parameters
#if user has entered only acceptable parameters, execute as normal
for dir in $*
	do
		if ! test -e $dir
		then
		echo $dir " is not a directory.\n"
		displayhelp
		exit 1
		fi
	done
echo -n "The number of files found is: "
find $* |wc -l
exit 0
