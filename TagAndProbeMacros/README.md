### The recipe described here produces the trigger efficiency of electron triggers using Tag and Probe method.
#### The steps are described below.

cmsrel CMSSW_10_6_18  
cd CMSSW_10_6_18/src  
cmsenv  

git clone git@github.com:arunhep/TagAndProbe_Trigger.git

git checkout LPC_HATs2021

scramv1 b

## For Test Run 
cd $CMSSW_BASE/src/TagAndProbe_Trigger/NtupleProducer/test   
<br>  
cmsRun runNtupler.py  
<br>  
