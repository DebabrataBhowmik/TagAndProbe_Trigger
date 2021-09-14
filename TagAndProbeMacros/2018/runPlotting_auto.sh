#!/bin/bash

#now="$(date)"
#now="$(date+'%d_%m_%Y')"
#echo $now
AllFiles="AllRootFiles.txt"
#HistFiles_Ele="histNames_Ele_multi.txt"
#HistFiles_Ele="histNames_Ele_crosscheck.txt"
#HistFiles_Mu="histNames_Mu_multi.txt"
HistFiles_Mu="histNames_Mu_multi_test.txt"
#root -l -b -q "plotEfficiency_multi_Ele.C(\"$HistFiles_Ele\")"  
root -l -b -q "plotEfficiency_multi_Mu.C(\"$HistFiles_Mu\")"
#rm -rf TriggerResults_2018
#dirname="TriggerResults_2018"+"$now"
#mkdir "$dirname"
#mkdir TriggerResults_2018
#mv results_Ele TriggerResults_2018
#mv results_Mu12 TriggerResults_2018

