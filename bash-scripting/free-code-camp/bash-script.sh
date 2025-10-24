#!/bin/bash

# echo Hello World!

## declaring variables and printing its value using echo

# FIRST_NAME=Aditya
# LAST_NAME=Paul

# echo Hello $FIRST_NAME $LAST_NAME

## taking input from the user(read) and printing its value

# echo What is your first name?
# read FIRST_NAME
#
# echo What is your last name?
# read LAST_NAME
#
# echo Hello $FIRST_NAME $LAST_NAME

## Positional argument
## Arguments are a specific positions - Commands can take in argument at a specific position,counting form one (0 is reserved for the shell)

## $echo  Hello  there!
##   0     1      2

# echo Hello $1 $2

## Piping

## piping | - used to redirect some commands output to some other command
## example - ls -l /usr/bin/ | grep bash -> filters all the filenames with 'bash' in its

## Output redirection

# '>' or '>>'
#
# '>' - symbol to write to a file (overwrites its content)
# '>>' - symbol to append at the end
#
# ex - echo Hello World > hello.txt
# ex - echo Hello World >> hello.txt
#
## Input redirection
#
# wc -w hello.txt [output -> 6 hello.txt] ... we dont want the hello.txt text at the end
# so we do
# wc -w < hello.txt [output -> 6] ... here we are sending the contents of the file instead of the file itself
# wc -w << EOF
# > i will enter
# > some text here
# > EOF
#
# this returns 6 ... the '<<' lets us enter multiple lines of string
#
# wc -w <<< "hello there!" -> 3
#
# Test operations -->
#
# [ hello = hello ]
# echo $? -> 0
#
# [ 1 = 0 ]
# echo $? -> 1
# [ 1 -eq 1] --> if they are actually numbers
#

## if/elif statements

# if [ ${1,,} = aditya ]; then
#     echo "Oh, you're the boss here. welcome!"
# elif [ ${1,,} = help]; then
#     echo "Just enter your username, duh!"
# else
#     echo "I dont know who u are!"
# fi
#
# swich-case
# checking for multiple values
#
# case ${1,,} in
# aditya | admin)
#     echo "oh ! yes boss"
#     ;;
# help)
#     echo "enter your username"
#     ;;
# *)
#     echo "you are not the boss"
#     ;;
# esac
#
## Arrays

# MY_FIRST_LIST=(zero one two three four five)
#
# echo $MY_FIRST_LIST ##--> displays only the 1st item
#
# echo ${MY_FIRST_LIST[@]} ##--> displays the whole list
#
# echo ${MY_FIRST_LIST[0]} ##--> displays specific item based on index
#
# loop over an array using for loop
#
# for item in ${MY_FIRST_LIST[@]}; do echo -n $item | wc -c; one
#
# Functions--
# up="before"
# since="function"
#
# showuptime() {
#     local up=$(uptime -p | cut -c4-)
#     local since=$(uptime -s)
#     cat <<EOF
# ------
# This machine has been up for ${up}
# It has been running since ${since}
# ------
# EOF
# }
# showuptime#!/bin/bash

# echo Hello World!

## declaring variables and printing its value using echo

# FIRST_NAME=Aditya
# LAST_NAME=Paul

# echo Hello $FIRST_NAME $LAST_NAME

## taking input from the user(read) and printing its value

# echo What is your first name?
# read FIRST_NAME
#
# echo What is your last name?
# read LAST_NAME
#
# echo Hello $FIRST_NAME $LAST_NAME

## Positional argument
## Arguments are a specific positions - Commands can take in argument at a specific position,counting form one (0 is reserved for the shell)

## $echo  Hello  there!
##   0     1      2

# echo Hello $1 $2

## Piping

## piping | - used to redirect some commands output to some other command
## example - ls -l /usr/bin/ | grep bash -> filters all the filenames with 'bash' in its

## Output redirection

# '>' or '>>'
#
# '>' - symbol to write to a file (overwrites its content)
# '>>' - symbol to append at the end
#
# ex - echo Hello World > hello.txt
# ex - echo Hello World >> hello.txt
#
## Input redirection
#
# wc -w hello.txt [output -> 6 hello.txt] ... we dont want the hello.txt text at the end
# so we do
# wc -w < hello.txt [output -> 6] ... here we are sending the contents of the file instead of the file itself
# wc -w << EOF
# > i will enter
# > some text here
# > EOF
#
# this returns 6 ... the '<<' lets us enter multiple lines of string
#
# wc -w <<< "hello there!" -> 3
#
# Test operations -->
#
# [ hello = hello ]
# echo $? -> 0
#
# [ 1 = 0 ]
# echo $? -> 1
# [ 1 -eq 1] --> if they are actually numbers
#

## if/elif statements

# if [ ${1,,} = aditya ]; then
#     echo "Oh, you're the boss here. welcome!"
# elif [ ${1,,} = help]; then
#     echo "Just enter your username, duh!"
# else
#     echo "I dont know who u are!"
# fi
#
# swich-case
# checking for multiple values
#
# case ${1,,} in
# aditya | admin)
#     echo "oh ! yes boss"
#     ;;
# help)
#     echo "enter your username"
#     ;;
# *)
#     echo "you are not the boss"
#     ;;
# esac
#
## Arrays

# MY_FIRST_LIST=(zero one two three four five)
#
# echo $MY_FIRST_LIST ##--> displays only the 1st item
#
# echo ${MY_FIRST_LIST[@]} ##--> displays the whole list
#
# echo ${MY_FIRST_LIST[0]} ##--> displays specific item based on index
#
# loop over an array using for loop
#
# for item in ${MY_FIRST_LIST[@]}; do echo -n $item | wc -c; one
#
# Functions--
# up="before"
# since="function"
#
# showuptime() {
#     local up=$(uptime -p | cut -c4-)
#     local since=$(uptime -s)
#     cat <<EOF
# ------
# This machine has been up for ${up}
# It has been running since ${since}
# ------
# EOF
# }
# showuptime
