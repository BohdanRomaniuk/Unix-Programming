#!/bin/bash
function get_file_name
{
	echo ${1%.*}
}

function get_ext
{
	echo ${1##*.}
}

function remove_duplicates {
	declare -a allFiles 
	for file in $1/*; do
		if [ -f ${file} ]; then
			allFiles+=($file)	
		fi
	done
	for (( i = 0; i < ${#allFiles[@]} ; i++ )) do
		for (( j = $i; j <  ${#allFiles[@]}; j++ )) do
			name1=$(get_file_name ${allFiles[$i]})
			name2=$(get_file_name ${allFiles[$j]})
			ext1=$(get_ext ${allFiles[$i]})
                        ext2=$(get_ext ${allFiles[$j]})
			if [ "$name1" = "$name2" ] && [ "$ext1" != "$ext2" ]; then
				if [ "$ext1" != "$2" ] && [ -e "${allFiles[$i]}" ]; then
					rm ${allFiles[$i]}
				fi
				if [ "$ext2" != "$2" ] && [ -e "${allFiles[$j]}" ]; then
					rm ${allFiles[$j]}
				fi
			fi
		done
	done
}

#remove_duplicates /home/bohdan/second cpp

function first_test
{
	files=(modest.cpp modest.txt modest.sh roman.txt roman.cpp vlad.txt)
	mkdir second
	cd second
	for (( i = 0; i < ${#files[@]} ; i++ )) do
		touch ${files[$i]}
	done
	remove_duplicates $PWD cpp
	if [ ! -e ${files[1]} ] && [ ! -e ${files[2]} ] && [ ! -e ${files[3]} ]; then
		echo "test 1 successfull"
	else
		echo "test 1 failed"
	fi
	cd ../
	rm -r second
}

function second_test
{
        files=(modest.cpp modest.txt modest.sh roman.txt roman.cpp vlad.txt)
        mkdir second
        cd second
        for (( i = 0; i < ${#files[@]} ; i++ )) do
                touch ${files[$i]}
        done
        remove_duplicates $PWD txt
        if [ ! -e ${files[0]} ] && [ ! -e ${files[2]} ] && [ ! -e ${files[4]} ] && [ -e ${files[5]} ]; then
                echo "test 2 successfull"
        else
                echo "test 2 failed"
        fi
        cd ../
        rm -r second
}

function third_test
{
        files=(modest.cpp modest.txt modest.sh roman.txt roman.cpp vlad.txt roman.h vlad1.txt)
        mkdir second
        cd second
        for (( i = 0; i < ${#files[@]} ; i++ )) do
                touch ${files[$i]}
        done
        remove_duplicates $PWD txt
        if [ ! -e ${files[0]} ] && [ ! -e ${files[2]} ] && [ ! -e ${files[4]} ] && [ ! -e ${files[6]} ]; then
                echo "test 3 successfull"
        else
                echo "test 3 failed"
        fi
        cd ../
        rm -r second
}

if [ "$1" = "--help" ]; then
        echo "Usage: delete [path] [allowedExt] [--tests]"
        echo "       [path] - path where we deleting similar files"
	echo "       [allowedExt] - extensions of files which not deletes"
        echo "       [--tests] - runs tests to delete functionality"
elif [ "$1" = "--tests" ]; then
        first_test
        second_test
        third_test
else
        remove_duplicates $1 $2
fi
