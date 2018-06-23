#!/bin/sh
#Ask if it is morning and answer accordingly

echo "Is is morning?"
read timeofday 
case "$timeofday" in
y* | Y* ) echo "Good Morning!";;
N* | n* ) echo "Good Afternoon.";;
* ) echo "I don't understand you.";;
I* | i*) echo "How'd you get here?";;
esac
exit 0

