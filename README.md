# TagAndProbe_Trigger

cmsrel CMSSW_10_2_11  
cd CMSSW_10_2_11/src  
cmsenv  
git cms-init  
git clone git@github.com:arunhep/TagAndProbe_Trigger.git
git checkout 2018_public (for making public plots)
git checkout 2018 (for HWW 2018 eff)
scram b -j8  
## For Test Run 
cd $CMSSW_BASE/src/TagAndProbe_Trigger/NtupleProducer/test   
<br>  
cmsRun runNtupler.py  
