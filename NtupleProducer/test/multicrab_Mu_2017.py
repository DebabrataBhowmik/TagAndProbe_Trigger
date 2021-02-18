#name = 'TrigEff_HWW_EGamma_2018'

dataset = {
   'Run2017B' : '/SingleMuon/Run2017B-09Aug2019_UL2017-v1/MINIAOD',
   'Run2017C' : '/SingleMuon/Run2017C-09Aug2019_UL2017-v1/MINIAOD',
   'Run2017D' : '/SingleMuon/Run2017D-09Aug2019_UL2017-v1/MINIAOD',
   'Run2017E' : '/SingleMuon/Run2017E-09Aug2019_UL2017-v1/MINIAOD',
   'Run2017F' : '/SingleMuon/Run2017F-09Aug2019_UL2017-v1/MINIAOD',
   }
#nevents = -1 
lumisPerJob = {
   'Run2017B':        200,
   'Run2017C':        200,
   'Run2017D':        200,
   'Run2017E':        200,
   'Run2017F':        200,
   }

listOfSamples = [
   'Run2017B',        
   'Run2017C',        
   'Run2017D',        
   'Run2017E',        
   'Run2017F',        
   ]

if __name__ == '__main__':

   from CRABClient.UserUtilities import config
   config = config()

   from CRABAPI.RawCommand import crabCommand
   from multiprocessing import Process

   def submit(config):
       res = crabCommand('submit', config = config)

   config.General.workArea = 'crab_TrigEff_HWW_Muon_2017'
   config.General.transferLogs = False

   config.JobType.allowUndistributedCMSSW = True
   config.JobType.pluginName = 'Analysis'
   config.JobType.psetName = 'runNtupler_2017.py'
   config.JobType.outputFiles = ['TnP_ntuple.root']

   config.Data.inputDBS = 'global'
   config.Data.splitting = 'LumiBased'
   #config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/PromptReco/Cert_314472-325175_13TeV_PromptReco_Collisions18_JSON.txt'
   config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions17/13TeV/Legacy_2017/Cert_294927-306462_13TeV_UL2017_Collisions17_GoldenJSON.txt'
   config.Data.publication = False
   config.Data.totalUnits = -1
   config.Data.outLFNDirBase = '/store/group/phys_higgs/cmshww/arun/TriggerEff_RunII_ULLegacy/TrigEff_HWW_Muon_2017'

   config.Site.storageSite ='T2_CH_CERN'
 #  config.Site.blacklist = ['T2_BR_SPRACE', 'T2_US_Wisconsin', 'T1_RU_JINR', 'T2_RU_JINR', 'T2_EE_Estonia']

   listOfSamples.reverse()
   for sample in listOfSamples:

      config.General.requestName = sample
      config.Data.splitting = 'Automatic'
      config.Data.inputDataset = dataset[sample]
      config.Data.unitsPerJob = lumisPerJob[sample]
      config.Data.outputDatasetTag = sample
      p = Process(target=submit, args=(config,))
      p.start()
      p.join()
