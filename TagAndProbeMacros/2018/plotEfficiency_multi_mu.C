{
/*
TFile *f1 = TFile::Open("finalRootFiles/efficiency_2018A_SingleMu_nominal.root");
TFile *f2 = TFile::Open("finalRootFiles/efficiency_2018B_SingleMu_nominal.root");
TFile *f3 = TFile::Open("finalRootFiles/efficiency_2018C_SingleMu_nominal.root");
TFile *f4 = TFile::Open("finalRootFiles/efficiency_2018D_SingleMu_nominal.root");
*/

TFile *f1 = TFile::Open("finalRootFiles/efficiency_nominal_Mu122018A.root");
TFile *f2 = TFile::Open("finalRootFiles/efficiency_nominal_Mu122018B.root");
TFile *f3 = TFile::Open("finalRootFiles/efficiency_nominal_Mu122018C.root");
TFile *f4 = TFile::Open("finalRootFiles/efficiency_nominal_Mu122018D.root");


/*
  KEY: TH1F	IsoMu24_pt_total;1	IsoMu24_pt
  KEY: TH1F	IsoMu24_eta_total;1	IsoMu24_eta
  KEY: TH1F	IsoMu24_pt_pass;1	IsoMu24_pt
  KEY: TH1F	IsoMu24_eta_pass;1	IsoMu24_eta
  KEY: TH1F	Mu50_pt_total;1	Mu50_pt
  KEY: TH1F	Mu50_eta_total;1	Mu50_eta
  KEY: TH1F	Mu50_pt_pass;1	Mu50_pt
  KEY: TH1F	Mu50_eta_pass;1	Mu50_eta
  KEY: TH1F	IsoMu27_pt_total;1	IsoMu27_pt
  KEY: TH1F	IsoMu27_eta_total;1	IsoMu27_eta
  KEY: TH1F	IsoMu27_pt_pass;1	IsoMu27_pt
  KEY: TH1F	IsoMu27_eta_pass;1	IsoMu27_eta
  KEY: TH1F	Mu17_Mu8_leg1_pt_total;1	Mu17_Mu8_leg1_pt
  KEY: TH1F	Mu17_Mu8_leg1_eta_total;1	Mu17_Mu8_leg1_eta
  KEY: TH1F	Mu17_Mu8_leg1_pt_pass;1	Mu17_Mu8_leg1_pt
  KEY: TH1F	Mu17_Mu8_leg1_eta_pass;1	Mu17_Mu8_leg1_eta
  KEY: TH1F	Mu17_Mu8_leg1_pt_Iso_pass;1	Mu17_Mu8_leg1_pt_Iso
  KEY: TH1F	Mu17_Mu8_leg1_eta_Iso_pass;1	Mu17_Mu8_leg1_eta_Iso
  KEY: TH1F	Mu17_Mu8_leg2_pt_total;1	Mu17_Mu8_leg2_pt
  KEY: TH1F	Mu17_Mu8_leg2_eta_total;1	Mu17_Mu8_leg2_eta
  KEY: TH1F	Mu17_Mu8_leg2_pt_pass;1	Mu17_Mu8_leg2_pt
  KEY: TH1F	Mu17_Mu8_leg2_eta_pass;1	Mu17_Mu8_leg2_eta
  KEY: TH1F	Mu17_Mu8_leg2_pt_Iso_pass;1	Mu17_Mu8_leg2_pt_Iso
  KEY: TH1F	Mu17_Mu8_leg2_eta_Iso_pass;1	Mu17_Mu8_leg2_eta_Iso
*/
/*
  KEY: TH1F	Mu12_pt_total;1	Mu12_pt
  KEY: TH1F	Mu12_eta_total;1	Mu12_eta
  KEY: TH2F	Mu12_pt_eta_total;1	Mu12_pt_eta
  KEY: TH1F	Mu12_pt_pass;1	Mu12_pt
  KEY: TH1F	Mu12_eta_pass;1	Mu12_eta
  KEY: TH2F	Mu12_pt_eta_pass;1	Mu12_pt_eta
  KEY: TH1F	Mu23_pt_total;1	Mu23_pt
  KEY: TH1F	Mu23_eta_total;1	Mu23_eta
  KEY: TH2F	Mu23_pt_eta_total;1	Mu23_pt_eta
  KEY: TH1F	Mu23_pt_pass;1	Mu23_pt
  KEY: TH1F	Mu23_eta_pass;1	Mu23_eta
  KEY: TH2F	Mu23_pt_eta_pass;1	Mu23_pt_eta
*/

  TH1F *h_total_2018A = (TH1F*)f1->Get("Mu23_eta_total");
  TH1F *h_total_2018B = (TH1F*)f2->Get("Mu23_eta_total");
  TH1F *h_total_2018C = (TH1F*)f3->Get("Mu23_eta_total");
  TH1F *h_total_2018D = (TH1F*)f4->Get("Mu23_eta_total");


  TH1F *h_pass_2018A = (TH1F*)f1->Get("Mu23_eta_pass");
  TH1F *h_pass_2018B = (TH1F*)f2->Get("Mu23_eta_pass");
  TH1F *h_pass_2018C = (TH1F*)f3->Get("Mu23_eta_pass");
  TH1F *h_pass_2018D = (TH1F*)f4->Get("Mu23_eta_pass");


  TGraphAsymmErrors *gra_2018A=0;
  TGraphAsymmErrors *gra_2018B=0;
  TGraphAsymmErrors *gra_2018C=0;
  TGraphAsymmErrors *gra_2018D=0;


  TMultiGraph *mg = new TMultiGraph();

  gra_2018A = new TGraphAsymmErrors (h_pass_2018A,h_total_2018A);
  gra_2018B = new TGraphAsymmErrors (h_pass_2018B,h_total_2018B);
  gra_2018C = new TGraphAsymmErrors (h_pass_2018C,h_total_2018C);
  gra_2018D = new TGraphAsymmErrors (h_pass_2018D,h_total_2018D);

  mg->Add(gra_2018A);
  mg->Add(gra_2018B);
  mg->Add(gra_2018C);
  mg->Add(gra_2018D);

  gra_2018A->SetLineColor(1);
  gra_2018B->SetLineColor(2);
  gra_2018C->SetLineColor(3);
  gra_2018D->SetLineColor(4);

  gra_2018A->SetMarkerStyle(20);
  gra_2018B->SetMarkerStyle(20);
  gra_2018C->SetMarkerStyle(20);
  gra_2018D->SetMarkerStyle(20);

  gra_2018A->SetMarkerColor(1);
  gra_2018B->SetMarkerColor(2);
  gra_2018C->SetMarkerColor(3);
  gra_2018D->SetMarkerColor(4);

  mg->SetTitle("Mu23_eta; Trig Efficiency");
  TCanvas *c = new TCanvas("c","",200,10,600,500);
//  c->SetGridx();
//  c->SetGridy();
//  c->SetLogx();
  mg->Draw("APE");
  mg->SetMinimum(0.0);
  mg->SetMaximum(1.015);
  mg->GetXaxis()->CenterTitle(1);
  mg->GetXaxis()->SetTitleOffset(1.2);
  mg->GetYaxis()->CenterTitle(1);
  mg->GetYaxis()->SetTitleOffset(1.4);

   TLegend *legend = new TLegend(0.5,0.3,0.7,0.6);
   legend->AddEntry(gra_2018A,"2018A","p");
   legend->AddEntry(gra_2018B,"2018B","p");
   legend->AddEntry(gra_2018C,"2018C","p");
   legend->AddEntry(gra_2018D,"2018D","p");
   legend->Draw();

c->SaveAs("/afs/cern.ch/user/a/arun/www/HWW/TrigEff2018/results_Mu/TrigEff_2018_Mu23_eta.png");
}
