#!/bin/sh
#Back up parts of the home directory to the server at jdembrun.com
zip -r /home/jared/fedora.zip /home/jared/CSC_CYEN /home/jared/Pictures /home/jared/Videos /home/jared/Music /home/jared/OtherSchool
scp jared@localhost: fedora.zip jared@s.jdembrun.com:

#Also back up parts of the home directory in Kali
mount /dev/sda5 /mnt/HDD
zip /home/jared/kali.zip "/mnt/HDD/home/jared/Pen Testing With Kali Linux Course Material"
scp jared@localhost: kali.zip jared@s.jdembrun.com: 
umount /dev/sda5

#Clean up the local machine
rm /home/jared/fedora.zip
rm /home/jared/kali.zip
