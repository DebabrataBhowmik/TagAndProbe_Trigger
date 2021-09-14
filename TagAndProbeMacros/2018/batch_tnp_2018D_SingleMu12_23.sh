#!/bin/bash
CMACRO="TagAndProbe_Ele.C"  # TagAndProbe_Ele.C or TagAndProbe_Mu.C
EXEC="tnp"
cd /afs/cern.ch/work/a/arun/Latinos/RunIILegacy/TriggerEff/CMSSW_10_2_11/src/TagAndProbe_Trigger/TagAndProbeMacros/
#eval `scramv1 runtime -csh`
#g++ Run_TnP.cxx -o $EXEC  -std=c++0x `root-config --libs --cflags` -include $CMACRO
g++ Run_TnP.cxx -o tnp_Mu122018D -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Mu12_23_2018D.C
./tnp_Mu122018D list2018D_SingleMu.txt  efficiency
