#!/bin/bash
CMACRO="TagAndProbe_Ele.C"  # TagAndProbe_Ele.C or TagAndProbe_Mu.C
EXEC="tnp"
cd /afs/cern.ch/work/a/arun/Latinos/RunIILegacy/TriggerEff/CMSSW_10_2_11/src/TagAndProbe_Trigger/TagAndProbeMacros/
#eval `scramv1 runtime -csh`
#g++ Run_TnP.cxx -o $EXEC  -std=c++0x `root-config --libs --cflags` -include $CMACRO
#g++ Run_TnP.cxx -o tnp_Ele2018 -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Ele2018_Public.C
#g++ Run_TnP.cxx -o tnp_Ele2018 -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Ele2018A.C
g++ Run_TnP.cxx -o tnp_Ele2018_looseid -std=c++0x `root-config --libs --cflags` -include TagAndProbe_Ele2018A.C
./tnp_Ele2018_looseid list2018_EGM.txt  efficiency
