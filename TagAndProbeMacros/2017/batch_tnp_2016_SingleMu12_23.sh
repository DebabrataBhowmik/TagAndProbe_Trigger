#!/bin/bash
CMACRO="TagAndProbe_Ele.C"  # TagAndProbe_Ele.C or TagAndProbe_Mu.C
EXEC="tnp"
cd /afs/cern.ch/work/a/arun/Latinos/RunIILegacy/TriggerEff/2017/CMSSW_9_4_13/src/TagAndProbe_Trigger/TagAndProbeMacros
#eval `scramv1 runtime -csh`
#g++ Run_TnP.cxx -o $EXEC  -std=c++0x `root-config --libs --cflags` -include $CMACRO
#g++ Run_TnP.cxx -o tnp_Mu122016 -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Mu12_23_Public.C
#./tnp_Mu122016  list_SingleMu_2016.txt  efficiency
g++ Run_TnP.cxx -o tnp2016 -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Mu12_23_Public.C
./tnp2016 list_SingleMu_2016.txt efficiency
