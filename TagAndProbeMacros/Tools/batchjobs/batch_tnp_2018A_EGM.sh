#!/bin/bash
cd /afs/cern.ch/work/a/arun/Latinos/TriggerEff/UL2018/CMSSW_10_6_18/src/TagAndProbe_Trigger/TagAndProbeMacros/2018
g++ Run_TnP.cxx -o tnp_2018A -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Ele2018A.C
./tnp_2018A list_2018A_EGM.txt EGM_2018A_Fall17V2
