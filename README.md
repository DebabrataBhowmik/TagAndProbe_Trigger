# TagAndProbe_Trigger

cmsrel CMSSW_10_6_18  
cd CMSSW_10_6_18/src  
cmsenv  

git clone git@github.com:arunhep/TagAndProbe_Trigger.git

git checkout LPC_HATs2021

scramv1 b

## For Test Run and producing the input file (flat root tree) for tag and probe analysis 
```
cd $CMSSW_BASE/src/TagAndProbe_Trigger/NtupleProducer/test   
voms-proxy-init --voms cms
cmsRun runNtupler.py
```

