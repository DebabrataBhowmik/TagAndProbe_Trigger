#!/bin/bash
CMACRO="TagAndProbe_Ele.C"  # TagAndProbe_Ele.C or TagAndProbe_Mu.C
EXEC="tnp"
cd /afs/cern.ch/work/a/arun/Latinos/RunIILegacy/TriggerEff/2017/CMSSW_9_4_13/src/TagAndProbe_Trigger/TagAndProbeMacros/
g++ Run_TnP.cxx -o tnp_Mu2017B -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Mu12_23.C
./tnp_Mu2017B list2017B.txt efficiency
