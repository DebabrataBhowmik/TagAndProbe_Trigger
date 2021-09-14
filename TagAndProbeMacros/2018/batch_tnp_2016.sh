#!/bin/bash
CMACRO="TagAndProbe_Ele.C"  # TagAndProbe_Ele.C or TagAndProbe_Mu.C
EXEC="tnp"
cd /afs/cern.ch/work/a/arun/Latinos/RunIILegacy/TriggerEff/CMSSW_9_4_12/src/TagAndProbe_Trigger/TagAndProbeMacros/
#g++ Run_TnP.cxx -o $EXEC  -std=c++0x `root-config --libs --cflags` -include $CMACRO
g++ Run_TnP.cxx -o tnp_Ele  -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Ele.C
#./tnp test.txt  efficiency
./tnp_Ele listOfFiles_2016.txt  efficiency
