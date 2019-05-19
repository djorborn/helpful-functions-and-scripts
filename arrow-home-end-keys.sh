#!/bin/bash
#for term in vt100 linux screen xterm
#  { echo "$term:"
#    infocmp -L1 $term|egrep 'key_(left|right|up|down|home|end)'
#  }

while read -sN1 key # 1 char (not delimiter), silent
do
  # catch multi-char special key sequences
  read -sN1 -t 0.0001 k1
  read -sN1 -t 0.0001 k2
  read -sN1 -t 0.0001 k3
  key+=${k1}${k2}${k3}

  case "$key" in
    $'\e[A'|$'\e0A')  # cursor up,: previous item
    	((cur > 1)) && ((cur--))
      	echo up;;
    $'\e[D'|$'\e0D') # left
    	((cur > 1)) && ((cur--))
    	echo left;;
    $'\e[B'|$'\e0B')  # cursor down: next item
    	((cur < $#-1)) && ((cur++))
    	echo down;;
    $'\e[C'|$'\e0C')  # right: next item
    	((cur < $#-1)) && ((cur++))
      	echo right;;

    $'\e[1~'|$'\e0H'|$'\e[H')  # home: first item
      	cur=0
      	echo home;;

    $'\e[4~'|$'\e0F'|$'\e[F')  # end: last item
      	((cur=$#-1))
      	echo end;;

    ' ')  # space: mark/unmark item
    	array_contains ${cur} "${sel[@]}" && \
    	sel=($(array_remove $cur "${sel[@]}")) \
      	|| sel+=($cur);;

    q|'') # q, carriage return: quit
    	echo "${sel[@]}" && return;;
	esac                  

done