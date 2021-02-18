#!/bin/bash
CMACRO="TagAndProbe_Ele.C"  # TagAndProbe_Ele.C or TagAndProbe_Mu.C
EXEC="tnp"
cd /afs/cern.ch/work/a/arun/Latinos/RunIILegacy/TriggerEff/2017/CMSSW_9_4_13/src/TagAndProbe_Trigger/TagAndProbeMacros/
#eval `scramv1 runtime -csh`
#g++ Run_TnP.cxx -o $EXEC  -std=c++0x `root-config --libs --cflags` -include $CMACRO
#g++ Run_TnP.cxx -o tnp_Ele2017CDE -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Ele_2017CDE.C
g++ Run_TnP.cxx -o tnp_Ele2017CDE_tightid -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Ele_2017CDE.C
./tnp_Ele2017CDE_tightid list2017CDE_EGM.txt  efficiency
