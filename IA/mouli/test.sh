#!/bin/sh
## test.sh for  in /home/vailla_y/Projet/Tek2/zappy/zappy-2015-2014s-haulot_a/IA/test
## 
## Made by yann vaillant
## Login   <vailla_y@epitech.net>
## 
## Started on  Fri Jul 13 16:00:39 2012 yann vaillant
## Last update Fri Jul 13 16:07:17 2012 yann vaillant
##

y1="youpi"
y2=$y1$y1
y3=$y2$y2
y4=$y3$y3
y5=$y4$y4
y6=$y5$y5
y7=$y6$y6
y8=$y7$y7$y7$y7

echo $1

usleep 500

for i in 1 2 3 4 5
do 
echo "prend nourriture"
echo "avance"
echo "fork"
usleep 500000
done

for i in $y1 $y2 $y3 $y4 $y5 $y6 $y7 $y8 $y8 $y8  
do
echo "prend nourriture"
echo "avance"
echo "broadcast $i"
echo "droite"
echo "broadcast $i"
usleep 50000
done

sh test.sh $1
