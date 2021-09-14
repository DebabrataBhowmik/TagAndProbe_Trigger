#define TagAndProbe_cxx
#include "TagAndProbe.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void TagAndProbe::Loop(TString output)
{
//   In a ROOT session, you can do:
//      root> .L TagAndProbe.C
//      root> TagAndProbe t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
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

   double ptTag = 28;
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
   output +="tests_SingleMu12_looseL1T";   
//   output += systematicVar.at(i);
   output +=".root";


   Long64_t nentries = fChain->GetEntriesFast();

   double pt_bins_Mu12[17] = {0,10,11,12,13,14,15,20,25,30,35,40,45,50,60,100,200};

   TFile *file = new TFile(output.Data(),"RECREATE");

// HLT_Mu12

   TH1F *h_Mu12_pt_total = new TH1F("Mu12_pt_total","Mu12_pt",16,pt_bins_Mu12);

   TH1F *h_Mu12_pt_pass = new TH1F("Mu12_pt_pass","Mu12_pt",16,pt_bins_Mu12);
   TH1F *h_Mu12_ptHLT_pass = new TH1F("Mu12_ptHLT_pass","Mu12_pt",16,pt_bins_Mu12);
   TH1F *h_Mu12_ptL1T_pass = new TH1F("Mu12_ptL1T_pass","Mu12_pt",16,pt_bins_Mu12);
   TH1F *h_Mu12_pt_pass_L10p5 = new TH1F("Mu12_pt_pass_L10p5","Mu12_pt",16,pt_bins_Mu12);
   TH1F *h_Mu12_pt_pass_L10p3 = new TH1F("Mu12_pt_pass_L10p3","Mu12_pt",16,pt_bins_Mu12);

   h_Mu12_pt_total->Sumw2();

   h_Mu12_pt_pass->Sumw2();
   h_Mu12_ptHLT_pass->Sumw2();
   h_Mu12_ptL1T_pass->Sumw2();
   h_Mu12_pt_pass_L10p5->Sumw2();
   h_Mu12_pt_pass_L10p3->Sumw2();

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
      bool tag_TriggerMatch = passFilterIsoMu24->at(first);

      if(!(tag_MuId && tag_MuKin && tag_TriggerMatch))continue;

      bool probe_MuId = HWW_Muon_Def(second, mu_pt->at(second));
      bool probe_MuKin = fabs(mu_eta->at(second))<2.4;

      if(!(probe_MuId && probe_MuKin)) continue;

      TLorentzVector tag_muLV, probe_muLV, Z_candLV;
      tag_muLV.SetPtEtaPhiE(mu_pt->at(first), mu_eta->at(first), mu_phi->at(first), mu_energy->at(first));
      probe_muLV.SetPtEtaPhiE(mu_pt->at(second), mu_eta->at(second), mu_phi->at(second), mu_energy->at(second));
      Z_candLV = tag_muLV + probe_muLV;      

      if (Z_candLV.M()<zMassL || Z_candLV.M() >zMassR) continue;
      
      h_Mu12_pt_total->Fill(mu_pt->at(second)); 

      if (passFilterMu12_Ele23_legMu->at(second)){
      h_Mu12_pt_pass->Fill(mu_pt->at(second)); 
      }
 
      if (passFilterMu12_Ele23_legMu_L10p5->at(second)){
      h_Mu12_pt_pass_L10p5->Fill(mu_pt->at(second));
      }

      if (passFilterMu12_Ele23_legMu_L10p3->at(second)){
      h_Mu12_pt_pass_L10p3->Fill(mu_pt->at(second));
      }

 //     if (passFilterMu12_HLTOnly->at(second)){
 //     h_Mu12_ptHLT_pass->Fill(mu_pt->at(second));
 //     }

 //     if (passFilterMu12_L1TOnly->at(second)){
 //     h_Mu12_ptL1T_pass->Fill(mu_pt->at(second));
 //     }
      // if (Cut(ientry) < 0) continue;
   }

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







