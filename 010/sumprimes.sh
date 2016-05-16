#!/bin/bash

#goto lol

p=3;
sum=3;
while [[ p -le 1000000 ]]
do
	result=`factor $p`
	if [[ "$result" == "$p: $p" ]]
	then
		echo "$p prime"
	fi

	p=$[p+2]
done
