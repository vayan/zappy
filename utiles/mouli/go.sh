#!/bin/sh
## go.sh for  in /home/vailla_y/Projet/Tek2/zappy/zappy-2015-2014s-haulot_a/IA/test
## 
## Made by yann vaillant
## Login   <vailla_y@epitech.net>
## 
## Started on  Fri Jul 13 16:07:31 2012 yann vaillant
## Last update Fri Jul 13 16:08:25 2012 yann vaillant
##

while [ 1 ]
do
sh test.sh $3 | nc $1 $2 &
usleep 50000
done