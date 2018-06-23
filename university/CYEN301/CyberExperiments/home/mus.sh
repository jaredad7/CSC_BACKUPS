#!/bin/sh
#Will turn on a user's speaker's and play jazzy nyan
amixer sset 'Master' unmute
amixer sset 'Master' 100%

while test true
do
	firefox  ~/CSC_CYEN/university/CYEN301/CyberExperiments/home/nyanjazz.mp3
	sleep 2
	~/CSC_CYEN/university/CYEN301/CyberExperiments/home/mus.sh
done
exit 0
