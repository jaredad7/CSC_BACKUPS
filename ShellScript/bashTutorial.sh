#!/bin/sh
######
#Given a particular directory or file name:
#Recursively get the file size in bytes of each file involved
#Add all of these bytes together
#Calculate num of Gigabytes
#Calculate num of Megabytes
#Calculate num of Kilobytes
#Calculate num of Bytes
#Display this in a readout
#Verbose option says which directory we are reading currently
#Additional 'fancy display' option
#Help method prints usage if no file given
######

#Some flags
verbose="false"
fancy="false"
input_file=""

#Our total bytes
total=0

#Our help method for this program
print_help()
{

}

#Our recursive method for this program
recurse()
{
	#If the file is a directory

		#The recursive part

}

#Display the output of the program.
display()
{
	#Break up into GB, MB, KB, and B

	#Display
}


#main

#We calculate total
recurse $input_file

#We display the total in a breakdown
display
