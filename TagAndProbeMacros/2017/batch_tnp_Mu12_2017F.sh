#!/bin/bash
CMACRO="TagAndProbe_Ele.C"  # TagAndProbe_Ele.C or TagAndProbe_Mu.C
EXEC="tnp"
cd /afs/cern.ch/work/a/arun/Latinos/RunIILegacy/TriggerEff/2017/CMSSW_9_4_13/src/TagAndProbe_Trigger/TagAndProbeMacros/
#g++ Run_TnP.cxx -o tnp_Mu2017F -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Mu12_23_2017F.C
#./tnp_Mu2017F list2017F.txt efficiency
g++ Run_TnP.cxx -o tnp_Mu2017 -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Mu2017.C
./tnp_Mu2017 list2017.txt efficiency
