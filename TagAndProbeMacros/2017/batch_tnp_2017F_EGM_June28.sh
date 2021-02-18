#!/bin/bash
CMACRO="TagAndProbe_Ele.C"  # TagAndProbe_Ele.C or TagAndProbe_Mu.C
EXEC="tnp"
cd /afs/cern.ch/work/a/arun/Latinos/RunIILegacy/TriggerEff/2017/CMSSW_9_4_13/src/TagAndProbe_Trigger/TagAndProbeMacros/
#eval `scramv1 runtime -csh`
#g++ Run_TnP.cxx -o $EXEC  -std=c++0x `root-config --libs --cflags` -include $CMACRO
#g++ Run_TnP.cxx -o tnp_Ele2017F -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Ele_2017F.C
g++ Run_TnP.cxx -o tnp_Ele2017F_tightid -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Ele_2017F.C
./tnp_Ele2017F_tightid list2017F_EGM.txt  efficiency
