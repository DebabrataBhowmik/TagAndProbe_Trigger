#define TagAndProbe_cxx
#include "TagAndProbe.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void TagAndProbe::Loop(TString output)
{
   if (fChain == 0) return;
  bool RunSystematic=false;
   vector<TString> systematicVar =  {"nominal"};
   
   if (RunSystematic)
   {
	systematicVar.push_back("TagPt_up");
	systematicVar.push_back("TagPt_down");
	systematicVar.push_back("Zmass_up");
	systematicVar.push_back("Zmass_down");
   }

for(int i=0; i<systematicVar.size();i++)
{

   double ptTag = 40; 
   double zMassL = 60; 
   double zMassR = 120;

   if(systematicVar.at(i).Contains("TagPt_up")) ptTag = 40;
   if(systematicVar.at(i).Contains("TagPt_down")) ptTag = 30;
   if(systematicVar.at(i).Contains("Zmass_up")) {zMassL = 50; zMassR = 130;}
   if(systematicVar.at(i).Contains("Zmass_down")) {zMassL = 70; zMassR = 110;}
 
   cout<<systematicVar.at(i).Data()<<endl;
   cout<<" ptTag : "<<ptTag<<" , zMassL : "<<zMassL<<" , zMassR : "<<zMassR<<endl;
   output = "";
   output +="efficiency_";
   output += systematicVar.at(i);
   output +="2018_EGM_";
   output += "forPublic";
   output +=".root";

   std::cout<< "total events : "<<fChain->GetEntries()<<endl;
   TFile *file = new TFile(output.Data(),"RECREATE");
   Long64_t nentries = fChain->GetEntriesFast();
//   std::cout<< "total events : "<<nentries<<endl;
//   double eta_bins[11] = {-2.5,-2.1,-1.6,-1.4,-0.8,0,0.8,1.4,1.6,2.1,2.5};   
   double eta_bins[11] = {-2.5,-2.1,-1.566,-1.4442,-0.8,0,0.8,1.4442,1.566,2.1,2.5};
   double pt_bins_Ele23_Ele12_leg1[14] = {0,20,23,24,25,26,30,35,40,45,50,60,100,200};
   double pt_bins_Ele23_Ele12_leg2[16] = {0,10,12,13,14,15,20,25,30,35,40,45,50,60,100,200};

//   double pt_bins_Ele23_Ele12_leg1[12]   = {0,20,23,24,25,26,30,35,40,50,100,200};
//   double pt_bins_Ele23_Ele12_leg2[12]   = {0,10,12,13,14,15,20,25,30,40,100,200};
//   double nvtx_bins[7] = {0,20,30,40,50,70,100};
   double nvtx_bins[12] = {0,5,10,20,30,40,50,60,70,80,100,150};


// HLT Ele23_Ele12 Ele23 leg
   TH1F *h_Ele23_Ele12_leg1_pt_total = new TH1F("Ele23_Ele12_leg1_pt_total","Ele23_Ele12_leg1_pt",13,pt_bins_Ele23_Ele12_leg1);
   TH1F *h_Ele23_Ele12_leg1_eta_total = new TH1F("Ele23_Ele12_leg1_eta_total","Ele23_Ele12_leg1_eta",10,eta_bins);
   TH1F *h_Ele23_Ele12_leg1_pt_pass = new TH1F("Ele23_Ele12_leg1_pt_pass","Ele23_Ele12_leg1_pt",13,pt_bins_Ele23_Ele12_leg1);
   TH1F *h_Ele23_Ele12_leg1_eta_pass = new TH1F("Ele23_Ele12_leg1_eta_pass","Ele23_Ele12_leg1_eta",10,eta_bins);
      
   h_Ele23_Ele12_leg1_pt_total->Sumw2();
   h_Ele23_Ele12_leg1_eta_total->Sumw2();
   h_Ele23_Ele12_leg1_pt_pass->Sumw2();
   h_Ele23_Ele12_leg1_eta_pass->Sumw2();

// HLT Ele23_Ele12 Ele12 leg
   TH1F *h_Ele23_Ele12_leg2_pt_total = new TH1F("Ele23_Ele12_leg2_pt_total","Ele23_Ele12_leg2_pt",15,pt_bins_Ele23_Ele12_leg2);
   TH1F *h_Ele23_Ele12_leg2_eta_total = new TH1F("Ele23_Ele12_leg2_eta_total","Ele23_Ele12_leg2_eta",10,eta_bins);
   TH1F *h_Ele23_Ele12_leg2_pt_pass = new TH1F("Ele23_Ele12_leg2_pt_pass","Ele23_Ele12_leg2_pt",15,pt_bins_Ele23_Ele12_leg2);
   TH1F *h_Ele23_Ele12_leg2_eta_pass = new TH1F("Ele23_Ele12_leg2_eta_pass","Ele23_Ele12_leg2_eta",10,eta_bins);

   h_Ele23_Ele12_leg2_pt_total->Sumw2();
   h_Ele23_Ele12_leg2_eta_total->Sumw2();
   h_Ele23_Ele12_leg2_pt_pass->Sumw2();
   h_Ele23_Ele12_leg2_eta_pass->Sumw2();

// L1 Ele23

   TH1F *h_Ele23_l1pt_total = new TH1F("Ele23_l1pt_total","Ele23_l1pt",13,pt_bins_Ele23_Ele12_leg1);
   TH1F *h_Ele23_l1eta_total = new TH1F("Ele23_l1eta_total","Ele23_l1eta",10,eta_bins);
   TH1F *h_Ele23_l1pt_pass = new TH1F("Ele23_l1pt_pass","Ele23_l1pt",13,pt_bins_Ele23_Ele12_leg1);
   TH1F *h_Ele23_l1eta_pass = new TH1F("Ele23_l1eta_pass","Ele23_l1eta",10,eta_bins);

   h_Ele23_l1pt_total->Sumw2();
   h_Ele23_l1eta_total->Sumw2();
   h_Ele23_l1pt_pass->Sumw2();
   h_Ele23_l1eta_pass->Sumw2();

// L1 Ele12

   TH1F *h_Ele12_l1pt_total = new TH1F("Ele12_l1pt_total","Ele12_l1pt",15,pt_bins_Ele23_Ele12_leg2);
   TH1F *h_Ele12_l1eta_total = new TH1F("Ele12_l1eta_total","Ele12_l1eta",10,eta_bins);
   TH1F *h_Ele12_l1pt_pass = new TH1F("Ele12_l1pt_pass","Ele12_l1pt",15,pt_bins_Ele23_Ele12_leg2);
   TH1F *h_Ele12_l1eta_pass = new TH1F("Ele12_l1eta_pass","Ele12_l1eta",10,eta_bins);

   h_Ele12_l1pt_total->Sumw2();
   h_Ele12_l1eta_total->Sumw2();
   h_Ele12_l1pt_pass->Sumw2();
   h_Ele12_l1eta_pass->Sumw2();


//HLT Ele23

   TH1F *h_Ele23_hltpt_total = new TH1F("Ele23_hltpt_total","Ele23_hltpt",13,pt_bins_Ele23_Ele12_leg1);
   TH1F *h_Ele23_hlteta_total = new TH1F("Ele23_hlteta_total","Ele23_hlteta",10,eta_bins);
   TH1F *h_Ele23_hltpt_pass = new TH1F("Ele23_hltpt_pass","Ele23_hltpt",13,pt_bins_Ele23_Ele12_leg1);
   TH1F *h_Ele23_hlteta_pass = new TH1F("Ele23_hlteta_pass","Ele23_hlteta",10,eta_bins);

   h_Ele23_hltpt_total->Sumw2();
   h_Ele23_hlteta_total->Sumw2();
   h_Ele23_hltpt_pass->Sumw2();
   h_Ele23_hlteta_pass->Sumw2();

// HLT Ele12

   TH1F *h_Ele12_hltpt_total = new TH1F("Ele12_hltpt_total","Ele12_hltpt",15,pt_bins_Ele23_Ele12_leg2);
   TH1F *h_Ele12_hlteta_total = new TH1F("Ele12_hlteta_total","Ele12_hlteta",10,eta_bins);
   TH1F *h_Ele12_hltpt_pass = new TH1F("Ele12_hltpt_pass","Ele12_hltpt",15,pt_bins_Ele23_Ele12_leg2);
   TH1F *h_Ele12_hlteta_pass = new TH1F("Ele12_hlteta_pass","Ele12_hlteta",10,eta_bins);

   h_Ele12_hltpt_total->Sumw2();
   h_Ele12_hlteta_total->Sumw2();
   h_Ele12_hltpt_pass->Sumw2();
   h_Ele12_hlteta_pass->Sumw2();

// nvtx

   TH1F *h_Ele12_nvtx_total = new TH1F("Ele12_nvtx_total","Ele12_nvtx",11,nvtx_bins);
   TH1F *h_Ele12_nvtx_pass = new TH1F("Ele12_nvtx_pass","Ele12_nvtx",11,nvtx_bins);

   TH1F *h_Ele23_nvtx_total = new TH1F("Ele23_nvtx_total","Ele23_nvtx",11,nvtx_bins);
   TH1F *h_Ele23_nvtx_pass = new TH1F("Ele23_nvtx_pass","Ele23_nvtx",11,nvtx_bins);


   h_Ele12_nvtx_total->Sumw2();
   h_Ele12_nvtx_pass->Sumw2();
   h_Ele23_nvtx_total->Sumw2();
   h_Ele23_nvtx_pass->Sumw2();



   TH1F *h_Ele12_l1nvtx_total = new TH1F("Ele12_l1nvtx_total","Ele12_l1nvtx",11,nvtx_bins);
   TH1F *h_Ele12_l1nvtx_pass = new TH1F("Ele12_l1nvtx_pass","Ele12_l1nvtx",11,nvtx_bins);

   TH1F *h_Ele23_l1nvtx_total = new TH1F("Ele23_l1nvtx_total","Ele23_l1nvtx",11,nvtx_bins);
   TH1F *h_Ele23_l1nvtx_pass = new TH1F("Ele23_l1nvtx_pass","Ele23_l1nvtx",11,nvtx_bins);


   h_Ele12_l1nvtx_total->Sumw2();
   h_Ele12_l1nvtx_pass->Sumw2();
   h_Ele23_l1nvtx_total->Sumw2();
   h_Ele23_l1nvtx_pass->Sumw2();


   TH1F *h_Ele12_hltnvtx_total = new TH1F("Ele12_hltnvtx_total","Ele12_hltnvtx",11,nvtx_bins);
   TH1F *h_Ele12_hltnvtx_pass = new TH1F("Ele12_hltnvtx_pass","Ele12_hltnvtx",11,nvtx_bins);
   
   TH1F *h_Ele23_hltnvtx_total = new TH1F("Ele23_hltnvtx_total","Ele23_hltnvtx",11,nvtx_bins);
   TH1F *h_Ele23_hltnvtx_pass = new TH1F("Ele23_hltnvtx_pass","Ele23_hltnvtx",11,nvtx_bins);
      
      
   h_Ele12_hltnvtx_total->Sumw2();
   h_Ele12_hltnvtx_pass->Sumw2();
   h_Ele23_hltnvtx_total->Sumw2();
   h_Ele23_hltnvtx_pass->Sumw2();


   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if(jentry%50000 == 0)cout<<"number of events processed : "<<jentry<<endl;
      if(nEle!=2) continue;
      int first  = rand()%2;
      int second = (first+1)%2;      
      if(ele_charge->at(first) * ele_charge->at(second)>0)continue;
      bool tag_EleId = passEleIdTight->at(first);
      bool tag_EleKin = ele_pt->at(first)>ptTag && fabs(ele_etaSC->at(first))<2.5;
      bool tag_TriggerMatch = passFilterEle35->at(first);

      if(!(tag_EleId && tag_EleKin && tag_TriggerMatch))continue;

    //  bool probe_EleId = HWW_Electron_NewDef(second, ele_etaSC->at(second));
      bool probe_EleId = passMVAIsoWP90->at(second);  
      bool probe_EleKin = fabs(ele_etaSC->at(second))<2.5;

      if(!(probe_EleId && probe_EleKin)) continue;

      TLorentzVector tag_eleLV, probe_eleLV, Z_candLV;
      tag_eleLV.SetPtEtaPhiM(ele_pt->at(first), ele_etaSC->at(first), ele_phi->at(first), 0.);
      probe_eleLV.SetPtEtaPhiM(ele_pt->at(second), ele_etaSC->at(second), ele_phi->at(second), 0.);
      Z_candLV = tag_eleLV + probe_eleLV;

      if (Z_candLV.M()<zMassL || Z_candLV.M() > zMassR) continue;

//total histos L1+HLT eff

      h_Ele23_Ele12_leg1_pt_total->Fill(ele_pt->at(second)); 
      if(ele_pt->at(second)>35)h_Ele23_Ele12_leg1_eta_total->Fill(ele_etaSC->at(second)); 
      if(ele_pt->at(second)>35)h_Ele23_nvtx_total->Fill(nPV);

      h_Ele23_Ele12_leg2_pt_total->Fill(ele_pt->at(second)); 
      if(ele_pt->at(second)>20)h_Ele23_Ele12_leg2_eta_total->Fill(ele_etaSC->at(second)); 
      if(ele_pt->at(second)>20)h_Ele12_nvtx_total->Fill(nPV);

//total histos L1 eff

      h_Ele23_l1pt_total->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>35)h_Ele23_l1eta_total->Fill(ele_etaSC->at(second));
      if(ele_pt->at(second)>35)h_Ele23_l1nvtx_total->Fill(nPV);

      h_Ele12_l1pt_total->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>20)h_Ele12_l1eta_total->Fill(ele_etaSC->at(second));
      if(ele_pt->at(second)>20)h_Ele12_l1nvtx_total->Fill(nPV);

// total histos HLT Only

      if (passL1EG23->at(second) || passL1EG20Iso->at(second) || passL1EG23Iso->at(second)){
      h_Ele23_hltpt_total->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>35)h_Ele23_hlteta_total->Fill(ele_etaSC->at(second));
      if(ele_pt->at(second)>35)h_Ele23_hltnvtx_total->Fill(nPV);
      }
      if (passL1EG10->at(second) || passL1EG17->at(second)){
      h_Ele12_hltpt_total->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>20)h_Ele12_hlteta_total->Fill(ele_etaSC->at(second));
      if(ele_pt->at(second)>20)h_Ele12_hltnvtx_total->Fill(nPV);
}


// passing histos L1+HLT eff

      if (passFilterEle23_12_leg1->at(second)){
      h_Ele23_Ele12_leg1_pt_pass->Fill(ele_pt->at(second)); 
      if(ele_pt->at(second)>35)h_Ele23_Ele12_leg1_eta_pass->Fill(ele_etaSC->at(second)); 
      if(ele_pt->at(second)>35)h_Ele23_nvtx_pass->Fill(nPV);
      } 

      if (passFilterEle23_12_leg2->at(second)){
      h_Ele23_Ele12_leg2_pt_pass->Fill(ele_pt->at(second)); 
      if(ele_pt->at(second)>20)h_Ele23_Ele12_leg2_eta_pass->Fill(ele_etaSC->at(second)); 
      if(ele_pt->at(second)>20)h_Ele12_nvtx_pass->Fill(nPV);
      }

// passing histos L1 Only

      if (passL1EG23->at(second) || passL1EG20Iso->at(second) || passL1EG23Iso->at(second)){
      h_Ele23_l1pt_pass->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>35)h_Ele23_l1eta_pass->Fill(ele_etaSC->at(second));
      if(ele_pt->at(second)>35)h_Ele23_l1nvtx_pass->Fill(nPV);
      }

      if (passL1EG10->at(second) || passL1EG17->at(second)){
      h_Ele12_l1pt_pass->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>20)h_Ele12_l1eta_pass->Fill(ele_etaSC->at(second));
      if(ele_pt->at(second)>20)h_Ele12_l1nvtx_pass->Fill(nPV);
      }

// passing histos HLT only
 
      if ((passL1EG23->at(second) || passL1EG20Iso->at(second) || passL1EG23Iso->at(second)) && (passFilterEle23_12_leg1->at(second))){
      h_Ele23_hltpt_pass->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>35)h_Ele23_hlteta_pass->Fill(ele_etaSC->at(second));
      if(ele_pt->at(second)>35)h_Ele23_hltnvtx_pass->Fill(nPV);
      }

      if ((passL1EG10->at(second) || passL1EG17->at(second)) && (passFilterEle23_12_leg2->at(second))){
      h_Ele12_hltpt_pass->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>20)h_Ele12_hlteta_pass->Fill(ele_etaSC->at(second));
      if(ele_pt->at(second)>20)h_Ele12_hltnvtx_pass->Fill(nPV);
      }

      // if (Cut(ientry) < 0) continue;
    }
file->Write(); 
  }
 
}

bool TagAndProbe::HWW_Electron_NewDef(int i, double eta)
{

double sieie = ele_full5x5_sigmaIetaIeta->at(i);
double dEtaSC = ele_dEtaSeed->at(i);
double dPhiIn = ele_dPhiIn->at(i);
double hoe = ele_hOverE->at(i);
double eInvMinusPInv = ele_ooEmooP->at(i);
double dr03TkSumPt_overPt = ele_dr03TkSumPt->at(i);
double dr03EcalRecHitSumEt_overPt = ele_dr03EcalRecHitSumEt->at(i);
double dr03HcalDepth1TowerSumEt_overPt = ele_dr03HcalDepth1TowerSumEt->at(i);
double lostHits = ele_expectedMissingInnerHits->at(i);
bool convVeto = ele_passConversionVeto->at(i);
double relIso = ele_relCombIsoWithEA->at(i);

if(fabs(eta) < 1.479){    // Barrel
double hoe_compareWith = 0.05 +(1.12/ele_energySC->at(i)) + (0.0368*(rho/ele_energySC->at(i)));
if (sieie >= 0.0128) return false;
if (fabs(dEtaSC) >= 0.00523) return false;
if (fabs(dPhiIn) >= 0.159) return false;
if (hoe >= hoe_compareWith) return false;
if (fabs(eInvMinusPInv) >= 0.193) return false;
if (!(lostHits <= 2)) return false;
if (!convVeto) return false;
if (relIso >= 0.168) return false;
if (!passMVAIsoWP90) return false;
if (ele_d0->at(i)>=0.05) return false;
if (ele_dz->at(i)>=0.1) return false;
}

else{
double hoe_compareWith = 0.05 +(0.5/ele_energySC->at(i)) + (0.201*(rho/ele_energySC->at(i)));
if (sieie >= 0.03) return false;
if (fabs(dEtaSC) >= 0.00984) return false;
if (fabs(dPhiIn) >= 0.157) return false;
if (hoe >= hoe_compareWith) return false;
if (fabs(eInvMinusPInv) >= 0.014) return false;
if (!(lostHits <= 3)) return false;
if (!convVeto) return false;
if (relIso >= 0.185) return false;
if (!passMVAIsoWP90) return false;
if (ele_d0->at(i)>=0.1) return false;
if (ele_dz->at(i)>=0.2) return false;
}

return true;

}
