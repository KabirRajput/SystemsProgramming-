#!/bin/bash 
#Kabir 
#05/10/2017

cd ~
if [ ! -d project ];then
mkdir project
fi 
cd project
if [ ! -d cs206 ];then
mkdir cs206
fi
cd cs206
if [ ! -d $1 ];then
mkdir $1
cd $1
mkdir archive
mkdir backup
mkdir docs
mkdir assets
mkdir database
mkdir source
else
echo "this project has already been used"
exit 1
fi
cd source 
echo "#!/bin/bash">backup.sh
chmod +x ./backup.sh
echo "cp *.c ../backup">>backup.sh
echo "cp *.h ../backup">>backup.sh
echo "exit 0">>backup.sh
echo "Your project directories have been created"
