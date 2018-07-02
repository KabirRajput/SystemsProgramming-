#!/bin/bash

if [ "$#" -eq 0 ]; then
    echo "You need to provide a project name."
    exit 1
fi


if [ "$#" -ne 1 ]; then
    echo "The program only accepts one argument which is the name of the project."
    exit 1
fi

projName=$1
#cd /home

#/home/project/cs206/$projName/source
if [ ! -d "project" ]; then
	mkdir project
fi

cd ./project

if [ ! -d "cs206" ]; then
	mkdir cs206
fi

cd ./cs206

if [ -d "$projName" ]; then
	echo "This project name has already been used."
	exit 1
fi

mkdir $projName
cd $projName

mkdir archive backup docs assets database source
cd ./source

echo "#!/bin/bash" > backup.sh
echo "cp ./*.c ../backup" >> backup.sh
echo "cp ./*.h ../backup" >> backup.sh

echo "You project directories have been created."
exit 0

