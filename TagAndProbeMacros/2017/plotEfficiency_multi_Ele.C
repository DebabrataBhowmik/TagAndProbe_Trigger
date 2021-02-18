void plotEfficiency_multi_Ele(TString triggerFile){

TFile *f1 = TFile::Open("efficiency_EGM_2017F_nominal.root");
//TFile *f2 = TFile::Open("efficiency_EGM_2017C_nominal.root");
TFile *f2 = TFile::Open("/afs/cern.ch/work/a/arun/Latinos/RunIILegacy/TriggerEff/2017/CMSSW_9_4_13/src/TagAndProbe_Trigger/TagAndProbeMacros/efficiency_EGM_2017F_nominal.root");
TFile *f3 = TFile::Open("efficiency_EGM_2017D_nominal.root");
TFile *f4 = TFile::Open("efficiency_EGM_2017E_nominal.root");
TFile *f5 = TFile::Open("efficiency_EGM_2017F_nominal.root");
/*
TFile *f1 = TFile::Open("efficiency_nominal2017_EGM_forPublic.root");
TFile *f2 = TFile::Open("efficiency_nominal2017_EGM_forPublic.root");
TFile *f3 = TFile::Open("efficiency_nominal2017_EGM_forPublic.root");
TFile *f4 = TFile::Open("efficiency_nominal2017_EGM_forPublic.root");
*/

     ifstream inFile;
     inFile.open(triggerFile.Data());
     TString trigger_name;

  while(!inFile.eof())
  {

   TH1F *h_total_2017A,*h_total_2017B,*h_total_2017C,*h_total_2017D,*h_total_2017E;
   TH1F *h_pass_2017A,*h_pass_2017B,*h_pass_2017C,*h_pass_2017D,*h_pass_2017E;
  
   TGraphAsymmErrors *gra_2017A=0;
   TGraphAsymmErrors *gra_2017B=0;
   TGraphAsymmErrors *gra_2017C=0;
   TGraphAsymmErrors *gra_2017D=0;
   TGraphAsymmErrors *gra_2017E=0;

   inFile>>trigger_name;
   if(inFile.eof()) break;
   TString total = trigger_name.Data();
   total += "_total";
   cout << total << endl;
   if(total.Contains("_Iso") ) total.ReplaceAll("_Iso","");
   TString pass = trigger_name.Data();
   pass += "_pass"; 

  h_total_2017A = (TH1F*)f1->Get(total.Data());
  h_total_2017B = (TH1F*)f2->Get(total.Data());
  h_total_2017C = (TH1F*)f3->Get(total.Data());
  h_total_2017D = (TH1F*)f4->Get(total.Data());
  h_total_2017E = (TH1F*)f5->Get(total.Data());

  h_pass_2017A = (TH1F*)f1->Get(pass.Data());
  h_pass_2017B = (TH1F*)f2->Get(pass.Data());
  h_pass_2017C = (TH1F*)f3->Get(pass.Data());
  h_pass_2017D = (TH1F*)f4->Get(pass.Data());
  h_pass_2017E = (TH1F*)f5->Get(pass.Data());

  TMultiGraph *mg = new TMultiGraph();

  gra_2017A = new TGraphAsymmErrors (h_pass_2017A,h_total_2017A);
  gra_2017B = new TGraphAsymmErrors (h_pass_2017B,h_total_2017B);
  gra_2017C = new TGraphAsymmErrors (h_pass_2017C,h_total_2017C);
  gra_2017D = new TGraphAsymmErrors (h_pass_2017D,h_total_2017D);
  gra_2017E = new TGraphAsymmErrors (h_pass_2017E,h_total_2017E);

  mg->Add(gra_2017A);
  mg->Add(gra_2017B);
 // mg->Add(gra_2017C);
 // mg->Add(gra_2017D);
 // mg->Add(gra_2017E);


  gra_2017A->SetLineColor(1);
  gra_2017B->SetLineColor(2);
  gra_2017C->SetLineColor(3);
  gra_2017D->SetLineColor(4);
  gra_2017E->SetLineColor(5);

  gra_2017A->SetMarkerStyle(20);
  gra_2017B->SetMarkerStyle(20);
  gra_2017C->SetMarkerStyle(20);
  gra_2017D->SetMarkerStyle(20);
  gra_2017E->SetMarkerStyle(20);

  gra_2017A->SetMarkerColor(1);
  gra_2017B->SetMarkerColor(2);
  gra_2017C->SetMarkerColor(3);
  gra_2017D->SetMarkerColor(4);
  gra_2017E->SetMarkerColor(5);


  mg->SetTitle(h_total_2017A->GetTitle());
  TCanvas *c = new TCanvas("c","",200,10,600,500);
//  c->SetLogx();
  mg->Draw("APE");
  mg->SetMinimum(0.0);
  mg->SetMaximum(1.015);
  mg->GetXaxis()->CenterTitle(1);
  mg->GetXaxis()->SetTitleOffset(1.2);
  mg->GetYaxis()->CenterTitle(1);
  mg->GetYaxis()->SetTitleOffset(1.4);

   TLegend *legend = new TLegend(0.5,0.3,0.7,0.6);
   legend->AddEntry(gra_2017A,"2017F UL","p");
   legend->AddEntry(gra_2017B,"2017F","p");
//   legend->AddEntry(gra_2017B,"2017C","p");
//   legend->AddEntry(gra_2017C,"2017D","p");
//   legend->AddEntry(gra_2017D,"2017E","p");
//   legend->AddEntry(gra_2017E,"2017F","p");
   legend->Draw();

  TString pngFileName = trigger_name.Data() ;
  pngFileName +=  "_efficiency.png";
  c->SaveAs(pngFileName.Data());
  c->Clear();
//  gSystem->Exec("mkdir -p results_Ele");
//  TString dirName = "results_Ele/";
//  dirName+=trigger_name.Data();
 // gSystem->Exec("mkdir -p  "+ dirName);
//  gSystem->Exec("mv " + trigger_name+"*.png  "+dirName);

        delete c;

}//inFile while look
}// end of program
