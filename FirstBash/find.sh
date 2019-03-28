#!/bin/bash
declare oldest_dir
declare oldest_date

function find_oldest_dir
{
        oldest_dir=$1
        oldest_date=$(stat $oldest_dir -c %Y)
        find_dir $oldest_dir
}


function find_dir
{
        for dir in $1/*; do
		if [ -d ${dir} ]; then
			dir_date=$(stat $dir -c %Y)
			if [[ "$dir_date" -lt "$oldest_date" ]]; then
				oldest_date=$dir_date
				oldest_dir=$dir
			fi
			find_oldest_dir "$dir"
		fi
        done
}

function first_test
{
	mkdir first
	cd first
	mkdir 1
	mkdir 2
	mkdir 3 #oldest one
	cd 1
	mkdir 4
	mkdir 5
	cd ../
	cd 2
	mkdir 6
	cd ../
	find_oldest_dir $PWD
	#echo $oldest_dir
        if [ "$oldest_dir" = "/home/bohdan/Desktop/Unix-Programming/FirstBash/first/3" ]; then
		echo "test 1 successfull"
	else
		echo "test 1 failed"
	fi
	cd ../
	rm -r first	
}

function second_test
{
        mkdir first
        cd first
        mkdir 1
        mkdir 2
        mkdir 3
	cd 3
        mkdir 7 #oldest one
	cd ../
        cd 1
        mkdir 4
        mkdir 5
        cd ../
	cd 2
	mkdir 6
	cd ../
        find_oldest_dir $PWD
        #echo $oldest_dir
	if [ "$oldest_dir" = "/home/bohdan/Desktop/Unix-Programming/FirstBash/first/3/7" ]; then
                echo "test 2 successfull"
        else
                echo "test 2 failed"
        fi
        cd ../
        rm -r first
}

function third_test
{
        mkdir first
        cd first
        mkdir 1
        mkdir 2
        mkdir 3
	cd 3
        mkdir 8
        cd 8
        mkdir 9 #oldest one
        cd ../../
	cd 2
        mkdir 6
        cd 6
        mkdir 7
        cd ../../
        cd 1
        mkdir 4
        mkdir 5
        cd ../
        find_oldest_dir $PWD
	#echo $oldest_dir
        if [ "$oldest_dir" = "/home/bohdan/Desktop/Unix-Programming/FirstBash/first/3/8/9" ]; then
                echo "test 3 successfull"
        else
                echo "test 3 failed"
        fi
        cd ../
        rm -r first
}

if [ "$1" = "--help" ]; then
        echo "Usage: find [path] [--tests]"
        echo "       [path] - path where we searching for the oldest dir"
        echo "       [--tests] - runs tests to searching functionality"
elif [ "$1" = "--tests" ]; then
        first_test
        second_test
        third_test
else
        find_oldest_dir $1
	echo $oldest_dir
fi

