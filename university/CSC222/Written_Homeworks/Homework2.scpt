Script started on Wed 22 Jan 2014 10:48:05 PM CST
[01;32mjared@jared-tosh[01;34m ~/CSC_CYEN/university/CSC222/Written_Homeworks $[00m cd ..
[01;32mjared@jared-tosh[01;34m ~/CSC_CYEN/university/CSC222 $[00m cd Programs/
[01;32mjared@jared-tosh[01;34m ~/CSC_CYEN/university/CSC222/Programs $[00m ./[K[Kmore[K[K[K[Kcat countf.sh 
#!/bin/sh

#create file to count all files, including directories

#recursive function to count files
filecount()
{
	cd "$1"
	local count=$((0))
	for file in *
	do
		if test -d "$file"
		then
		filecount "$file"
		ret=$?
		count=$(($ret+$count))
		fi
		count=$(($count+1))
	done
	cd ..
	return $count
}

total=0

if test $# = 0
then
	for file in *
	do
		
		if test -d "$file"
		then
		filecount "$file"
		ret=$?
		total=$(($ret+$total))
		fi
		total=$(($total+1))
	done
else
	while test "$1" != ""
	do
	filecount "$1"
	ret=$?
	total=$(($total+$ret))
	shift
	done
fi

#check hidden files
hidden=$(find -type f -name ".*"| wc -l)
total=$(($total+$hidden))

echo "The number of files found is: $total"
exit 0
[01;32mjared@jared-tosh[01;34m ~/CSC_CYEN/university/CSC222/Programs $[00m ./countf.sh 
The number of files found is: 13
[01;32mjared@jared-tosh[01;34m ~/CSC_CYEN/university/CSC222/Programs $[00m ./countf.sh Cprogs/
The number of files found is: 6
[01;32mjared@jared-tosh[01;34m ~/CSC_CYEN/university/CSC222/Programs $[00m exit
exit

Script done on Wed 22 Jan 2014 10:48:39 PM CST
