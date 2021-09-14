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
int nPass=0;
int nPassMu12=0;

   if (RunSystematic)
   {
        systematicVar.push_back("TagPt_up");
        systematicVar.push_back("TagPt_down");
        systematicVar.push_back("Zmass_up");
        systematicVar.push_back("Zmass_down");
   }

for(int i=0; i<systematicVar.size();i++)
{

   double ptTag = 30;
   double zMassL = 60;
   double zMassR = 120;

   if(systematicVar.at(i).Contains("TagPt_up")) ptTag = 35;
   if(systematicVar.at(i).Contains("TagPt_down")) ptTag = 25;
   if(systematicVar.at(i).Contains("Zmass_up")) {zMassL = 50; zMassR = 130;}
   if(systematicVar.at(i).Contains("Zmass_down")) {zMassL = 70; zMassR = 110;}

   cout<<systematicVar.at(i).Data()<<endl;
   cout<<" ptTag : "<<ptTag<<" , zMassL : "<<zMassL<<" , zMassR : "<<zMassR<<endl;
   output = "";
   output +="efficiency_";
   output += systematicVar.at(i);
   output +="_Mu_Public";
   output +=".root";


   Long64_t nentries = fChain->GetEntriesFast();

   cout << "Total number of entries = " << fChain->GetEntries() << endl;

//   double eta_bins[9]  = {-2.4,-2.1,-1.2,-0.9, 0., 0.9, 1.2, 2.1, 2.4};
//   double nvtx_bins[7] = {0,20,30,40,50,70,100};
   double nvtx_bins[12] = {0,5,10,20,30,40,50,60,70,80,100,150};   
   double eta_bins[14] = {-2.4,-2.1,-1.6,-1.2,-0.8,-0.3,-0.2,0.2,0.3,0.8,1.2,1.6,2.1,2.4};
//   double pt_bins_Mu12[12]   = {0,10,12,13,14,15,20,25,30,40,100,200};
//   double pt_bins_Mu23[12]   = {0,20,23,24,25,26,30,35,40,50,100,200};
   double pt_bins_Mu23[17] = {0,10,20,21,22,23,24,25,26,30,35,40,45,50,60,100,200};
   double pt_bins_Mu12[17] = {0,10,11,12,13,14,15,20,25,30,35,40,45,50,60,100,200};
   TFile *file = new TFile(output.Data(),"RECREATE");

// HLT & L1 Mu12
   TH1F *h_Mu12_pt_total = new TH1F("Mu12_pt_total","Mu12_pt",16,pt_bins_Mu12);
   TH1F *h_Mu12_eta_total = new TH1F("Mu12_eta_total","Mu12_eta",13,eta_bins);
   TH1F *h_Mu12_pt_pass = new TH1F("Mu12_pt_pass","Mu12_pt",16,pt_bins_Mu12);
   TH1F *h_Mu12_eta_pass = new TH1F("Mu12_eta_pass","Mu12_eta",13,eta_bins);

   h_Mu12_pt_total->Sumw2();
   h_Mu12_eta_total->Sumw2();
   h_Mu12_pt_pass->Sumw2();
   h_Mu12_eta_pass->Sumw2();

   TH1F *h_Mu12_l1pt_total = new TH1F("Mu12_l1pt_total","Mu12_l1pt",16,pt_bins_Mu12);
   TH1F *h_Mu12_l1eta_total = new TH1F("Mu12_l1eta_total","Mu12_l1eta",13,eta_bins);
   TH1F *h_Mu12_l1pt_pass = new TH1F("Mu12_l1pt_pass","Mu12_l1pt",16,pt_bins_Mu12);
   TH1F *h_Mu12_l1eta_pass = new TH1F("Mu12_l1eta_pass","Mu12_l1eta",13,eta_bins);

   h_Mu12_l1pt_total->Sumw2();
   h_Mu12_l1eta_total->Sumw2();
   h_Mu12_l1pt_pass->Sumw2();
   h_Mu12_l1eta_pass->Sumw2();

   TH1F *h_Mu12_hltpt_total = new TH1F("Mu12_hltpt_total","Mu12_hltpt",16,pt_bins_Mu12);
   TH1F *h_Mu12_hlteta_total = new TH1F("Mu12_hlteta_total","Mu12_hlteta",13,eta_bins);
   TH1F *h_Mu12_hltpt_pass = new TH1F("Mu12_hltpt_pass","Mu12_hltpt",16,pt_bins_Mu12);
   TH1F *h_Mu12_hlteta_pass = new TH1F("Mu12_hlteta_pass","Mu12_hlteta",13,eta_bins);

   h_Mu12_hltpt_total->Sumw2();
   h_Mu12_hlteta_total->Sumw2();
   h_Mu12_hltpt_pass->Sumw2();
   h_Mu12_hlteta_pass->Sumw2();

// HLT & L1 Mu23
   TH1F *h_Mu23_pt_total = new TH1F("Mu23_pt_total","Mu23_pt",16,pt_bins_Mu23);
   TH1F *h_Mu23_eta_total = new TH1F("Mu23_eta_total","Mu23_eta",13,eta_bins);
   TH1F *h_Mu23_pt_pass = new TH1F("Mu23_pt_pass","Mu23_pt",16,pt_bins_Mu23);
   TH1F *h_Mu23_eta_pass = new TH1F("Mu23_eta_pass","Mu23_eta",13,eta_bins);

   h_Mu23_pt_total->Sumw2();
   h_Mu23_eta_total->Sumw2();
   h_Mu23_pt_pass->Sumw2();
   h_Mu23_eta_pass->Sumw2();


   TH1F *h_Mu23_l1pt_total = new TH1F("Mu23_l1pt_total","Mu23_l1pt",16,pt_bins_Mu23);
   TH1F *h_Mu23_l1eta_total = new TH1F("Mu23_l1eta_total","Mu23_l1eta",13,eta_bins);
   TH1F *h_Mu23_l1pt_pass = new TH1F("Mu23_l1pt_pass","Mu23_l1pt",16,pt_bins_Mu23);
   TH1F *h_Mu23_l1eta_pass = new TH1F("Mu23_l1eta_pass","Mu23_l1eta",13,eta_bins);

   h_Mu23_l1pt_total->Sumw2();
   h_Mu23_l1eta_total->Sumw2();
   h_Mu23_l1pt_pass->Sumw2();
   h_Mu23_l1eta_pass->Sumw2();

   TH1F *h_Mu23_hltpt_total = new TH1F("Mu23_hltpt_total","Mu23_hltpt",16,pt_bins_Mu23);
   TH1F *h_Mu23_hlteta_total = new TH1F("Mu23_hlteta_total","Mu23_hlteta",13,eta_bins);
   TH1F *h_Mu23_hltpt_pass = new TH1F("Mu23_hltpt_pass","Mu23_hltpt",16,pt_bins_Mu23);
   TH1F *h_Mu23_hlteta_pass = new TH1F("Mu23_hlteta_pass","Mu23_hlteta",13,eta_bins);

   h_Mu23_hltpt_total->Sumw2();
   h_Mu23_hlteta_total->Sumw2();
   h_Mu23_hltpt_pass->Sumw2();
   h_Mu23_hlteta_pass->Sumw2();

// nVtx

   TH1F *h_Mu12_nvtx_total = new TH1F("Mu12_nvtx_total","Mu12_nvtx",11,nvtx_bins);
   TH1F *h_Mu12_nvtx_pass = new TH1F("Mu12_nvtx_pass","Mu12_nvtx",11,nvtx_bins);

   TH1F *h_Mu23_nvtx_total = new TH1F("Mu23_nvtx_total","Mu23_nvtx",11,nvtx_bins);
   TH1F *h_Mu23_nvtx_pass = new TH1F("Mu23_nvtx_pass","Mu23_nvtx",11,nvtx_bins);


   h_Mu12_nvtx_total->Sumw2();
   h_Mu12_nvtx_pass->Sumw2();
   h_Mu23_nvtx_total->Sumw2();
   h_Mu23_nvtx_pass->Sumw2();


   TH1F *h_Mu12_l1nvtx_total = new TH1F("Mu12_l1nvtx_total","Mu12_l1nvtx",11,nvtx_bins);
   TH1F *h_Mu12_l1nvtx_pass = new TH1F("Mu12_l1nvtx_pass","Mu12_l1nvtx",11,nvtx_bins);

   TH1F *h_Mu23_l1nvtx_total = new TH1F("Mu23_l1nvtx_total","Mu23_l1nvtx",11,nvtx_bins);
   TH1F *h_Mu23_l1nvtx_pass = new TH1F("Mu23_l1nvtx_pass","Mu23_l1nvtx",11,nvtx_bins);


   h_Mu12_l1nvtx_total->Sumw2();
   h_Mu12_l1nvtx_pass->Sumw2();
   h_Mu23_l1nvtx_total->Sumw2();
   h_Mu23_l1nvtx_pass->Sumw2();

   TH1F *h_Mu12_hltnvtx_total = new TH1F("Mu12_hltnvtx_total","Mu12_hltnvtx",11,nvtx_bins);
   TH1F *h_Mu12_hltnvtx_pass = new TH1F("Mu12_hltnvtx_pass","Mu12_hltnvtx",11,nvtx_bins);

   TH1F *h_Mu23_hltnvtx_total = new TH1F("Mu23_hltnvtx_total","Mu23_hltnvtx",11,nvtx_bins);
   TH1F *h_Mu23_hltnvtx_pass = new TH1F("Mu23_hltnvtx_pass","Mu23_hltnvtx",11,nvtx_bins);
      
      
   h_Mu12_hltnvtx_total->Sumw2();
   h_Mu12_hltnvtx_pass->Sumw2();
   h_Mu23_hltnvtx_total->Sumw2();
   h_Mu23_hltnvtx_pass->Sumw2();


// event loop
 
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if(jentry % 50000 ==0)cout<<"Number of events processed : "<<jentry<<endl;
      if(nMu != 2) continue;
      int first  = rand()%2;
      int second = (first+1)%2;      
      if(mu_charge->at(first) * mu_charge->at(second)>0)continue;
      bool tag_MuId = mu_CutBasedIdTight->at(first) && mu_PFIsoTight->at(first);  //should be tight
      bool tag_MuKin = mu_pt->at(first)>ptTag && fabs(mu_eta->at(first))<2.4;
      bool tag_TriggerMatch = passFilterIsoMu24->at(first);

      if(!(tag_MuId && tag_MuKin && tag_TriggerMatch))continue;

      bool probe_MuId = HWW_Muon_Def(second, mu_pt->at(second));
      bool probe_MuKin = fabs(mu_eta->at(second))<2.4;

      if(!(probe_MuId && probe_MuKin)) continue;
      TLorentzVector tag_muLV, probe_muLV, Z_candLV;
      tag_muLV.SetPtEtaPhiM(mu_pt->at(first), mu_eta->at(first), mu_phi->at(first), 0.);
      probe_muLV.SetPtEtaPhiM(mu_pt->at(second), mu_eta->at(second), mu_phi->at(second), 0.);
      Z_candLV = tag_muLV + probe_muLV;

      if (Z_candLV.M()<zMassL || Z_candLV.M() >zMassR) continue;
      nPass++;

// total histograms for L1+HLT eff
 
      h_Mu23_pt_total->Fill(mu_pt->at(second)); 
      if(mu_pt->at(second)>25)h_Mu23_eta_total->Fill(mu_eta->at(second)); 
      if(mu_pt->at(second)>25)h_Mu23_nvtx_total->Fill(nPV); 
   

      h_Mu12_pt_total->Fill(mu_pt->at(second)); 
      if(mu_pt->at(second)>15)h_Mu12_eta_total->Fill(mu_eta->at(second)); 
      if(mu_pt->at(second)>15)h_Mu12_nvtx_total->Fill(nPV);               

// total histograms for L1T only eff

      h_Mu23_l1pt_total->Fill(mu_pt->at(second));
      if(mu_pt->at(second)>25)h_Mu23_l1eta_total->Fill(mu_eta->at(second));
      if(mu_pt->at(second)>25)h_Mu23_l1nvtx_total->Fill(nPV);


      h_Mu12_l1pt_total->Fill(mu_pt->at(second));
      if(mu_pt->at(second)>15)h_Mu12_l1eta_total->Fill(mu_eta->at(second));
      if(mu_pt->at(second)>15)h_Mu12_l1nvtx_total->Fill(nPV);
      
// total histograms for HLT only eff

      if(passFilterMu23_L10p5->at(second)){
      h_Mu23_hltpt_total->Fill(mu_pt->at(second));
      if(mu_pt->at(second)>25){h_Mu23_hlteta_total->Fill(mu_eta->at(second));}
      if(mu_pt->at(second)>25){h_Mu23_hltnvtx_total->Fill(nPV);}
      }
      
      if(passFilterMu12_L10p5->at(second)){
      h_Mu12_hltpt_total->Fill(mu_pt->at(second));
      if(mu_pt->at(second)>15){h_Mu12_hlteta_total->Fill(mu_eta->at(second));}
      if(mu_pt->at(second)>15){h_Mu12_hltnvtx_total->Fill(nPV);}
      }

// passing histograms for L1+HLT eff

      if (passFilterMu23_Ele12_legMu_L10p5->at(second)){
      h_Mu23_pt_pass->Fill(mu_pt->at(second)); 
      if(mu_pt->at(second)>25) h_Mu23_eta_pass->Fill(mu_eta->at(second)); 
      if(mu_pt->at(second)>25) h_Mu23_nvtx_pass->Fill(nPV);
      }

      if (passFilterMu12_Ele23_legMu_L10p5->at(second)){
      h_Mu12_pt_pass->Fill(mu_pt->at(second)); nPassMu12++;
      if(mu_pt->at(second)>15) h_Mu12_eta_pass->Fill(mu_eta->at(second)); 
      if(mu_pt->at(second)>15) h_Mu12_nvtx_pass->Fill(nPV);
      } 

// passing histograms for L1T only eff 

      if (passFilterMu23_L10p5->at(second)){
      h_Mu23_l1pt_pass->Fill(mu_pt->at(second));
      if(mu_pt->at(second)>25) h_Mu23_l1eta_pass->Fill(mu_eta->at(second));
      if(mu_pt->at(second)>25) h_Mu23_l1nvtx_pass->Fill(nPV);
      }

      if (passFilterMu12_L10p5->at(second)){
      h_Mu12_l1pt_pass->Fill(mu_pt->at(second)); nPassMu12++;
      if(mu_pt->at(second)>15) h_Mu12_l1eta_pass->Fill(mu_eta->at(second));
      if(mu_pt->at(second)>15) h_Mu12_l1nvtx_pass->Fill(nPV);
      }

// passing histograms for HLT only eff

      if (passFilterMu23_L10p5->at(second) && passFilterMu23_Ele12_legMu_L10p5->at(second)){
      h_Mu23_hltpt_pass->Fill(mu_pt->at(second));
      if(mu_pt->at(second)>25) h_Mu23_hlteta_pass->Fill(mu_eta->at(second));
      if(mu_pt->at(second)>25) h_Mu23_hltnvtx_pass->Fill(nPV);
      }

      if (passFilterMu12_L10p5->at(second) && passFilterMu12_Ele23_legMu_L10p5->at(second)){
      h_Mu12_hltpt_pass->Fill(mu_pt->at(second)); nPassMu12++;
      if(mu_pt->at(second)>15) h_Mu12_hlteta_pass->Fill(mu_eta->at(second));
      if(mu_pt->at(second)>15) h_Mu12_hltnvtx_pass->Fill(nPV);
      }

   } //event loop
   file->Write();
  } // loop on systematics
   cout<<"program ends"<<endl;
} //program ends



bool TagAndProbe::HWW_Muon_Def(int i, double pt)
{
bool tightMu = mu_CutBasedIdTight->at(i);   // should be tight
bool passIsoTight = mu_PFIsoTight->at(i);
bool pass_dz = fabs(mu_dz->at(i)) < 0.1;

if (!tightMu) return false;
if (!passIsoTight) return false;
//if (!pass_dz) return false;
/*
if (pt <= 20){
if (fabs(mu_d0->at(i)) > 0.01) return false;
}
else {
if (fabs(mu_d0->at(i)) > 0.02) return false;
}
*/
return true;
}
