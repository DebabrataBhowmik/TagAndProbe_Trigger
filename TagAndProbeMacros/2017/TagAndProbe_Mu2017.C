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
//   output +="2018A_SingleMu12_23_";
   output +="Mu17_Mu8_2017";   
   output += systematicVar.at(i);
   output +=".root";


   Long64_t nentries = fChain->GetEntriesFast();

   double eta_bins[14] = {-2.4,-2.1,-1.6,-1.2,-0.8,-0.3,-0.2,0.2,0.3,0.8,1.2,1.6,2.1,2.4};
   double pt_bins_Mu17_Mu8_leg1[18] = {0,10,15,16,17,18,19,20,22,25,30,35,40,45,50,60,100,200};
   double pt_bins_Mu17_Mu8_leg2[18] = {0,6,7,8,9,10,12,15,20,25,30,35,40,45,50,60,100,200};

   TFile *file = new TFile(output.Data(),"RECREATE");

// HLT Mu17_Mu8 Ele23 leg
   TH1F *h_Mu17_Mu8_leg1_eta_total = new TH1F("Mu17_Mu8_leg1_eta_total","Mu17_Mu8_leg1_eta",13,eta_bins);
   TH1F *h_Mu17_Mu8_leg1_eta_pass = new TH1F("Mu17_Mu8_leg1_eta_pass","Mu17_Mu8_leg1_eta",13,eta_bins);
      
   h_Mu17_Mu8_leg1_eta_total->Sumw2();
   h_Mu17_Mu8_leg1_eta_pass->Sumw2();

// HLT Mu17_Mu8 Ele12 leg
   TH1F *h_Mu17_Mu8_leg2_eta_total = new TH1F("Mu17_Mu8_leg2_eta_total","Mu17_Mu8_leg2_eta",13,eta_bins);
   TH1F *h_Mu17_Mu8_leg2_eta_pass = new TH1F("Mu17_Mu8_leg2_eta_pass","Mu17_Mu8_leg2_eta",13,eta_bins);


   h_Mu17_Mu8_leg2_eta_total->Sumw2();
   h_Mu17_Mu8_leg2_eta_pass->Sumw2();

cout << "Total number of entries = " << fChain->GetEntries() << endl;

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
      bool tag_TriggerMatch = passFilterIsoMu27->at(first);

      if(!(tag_MuId && tag_MuKin && tag_TriggerMatch))continue;

      bool probe_MuId = HWW_Muon_Def(second, mu_pt->at(second));
      bool probe_MuKin = fabs(mu_eta->at(second))<2.4;

      if(!(probe_MuId && probe_MuKin)) continue;

      TLorentzVector tag_muLV, probe_muLV, Z_candLV;
      tag_muLV.SetPtEtaPhiE(mu_pt->at(first), mu_eta->at(first), mu_phi->at(first), mu_energy->at(first));
      probe_muLV.SetPtEtaPhiE(mu_pt->at(second), mu_eta->at(second), mu_phi->at(second), mu_energy->at(second));
      Z_candLV = tag_muLV + probe_muLV;

      if (Z_candLV.M()<zMassL || Z_candLV.M() >zMassR) continue;

      if(mu_pt->at(second)>20)h_Mu17_Mu8_leg1_eta_total->Fill(mu_eta->at(second)); 
      if(mu_pt->at(second)>12)h_Mu17_Mu8_leg2_eta_total->Fill(mu_eta->at(second)); 
      if(passFilterMu17_Mu8_leg1->at(second)){
      if(mu_pt->at(second)>20)h_Mu17_Mu8_leg1_eta_pass->Fill(mu_eta->at(second)); 
      }
      if(passFilterMu17_Mu8_leg2->at(second)){
      if(mu_pt->at(second)>12)h_Mu17_Mu8_leg2_eta_pass->Fill(mu_eta->at(second)); 
      } 
      // if (Cut(ientry) < 0) continue;
   }

cout << "h_Mu17_Mu8_leg1_eta_total   = " << h_Mu17_Mu8_leg1_eta_total->Integral() << endl;
cout << "h_Mu17_Mu8_leg1_eta_pass   = " << h_Mu17_Mu8_leg1_eta_pass->Integral() << endl;

//cout << "h_Mu12_pt_total   = " << h_Mu23_pt_total->Integral() << endl;
//cout << "h_Mu12_pt_pass   = " << h_Mu12_pt_pass->Integral() << endl;

//cout << "h_Mu50_pt_total   = " << h_Mu50_pt_total->Integral() << endl;
//cout << "h_Mu50_pt_pass   = " << h_Mu50_pt_pass->Integral() << endl;

   file->Write();
  }
   cout<<"program ends"<<endl;
}



bool TagAndProbe::HWW_Muon_Def(int i, double pt)
{
bool tightMu = mu_CutBasedIdTight->at(i);   // should be tight
bool passIsoTight = mu_PFIsoTight->at(i);
bool pass_dz = fabs(mu_dz->at(i)) < 0.1;

if (!tightMu) return false;
if (!passIsoTight) return false;
if (!pass_dz) return false;

if (pt <= 20){
if (fabs(mu_d0->at(i)) > 0.01) return false;
}
else {
if (fabs(mu_d0->at(i)) > 0.02) return false;
}

return true;
}







