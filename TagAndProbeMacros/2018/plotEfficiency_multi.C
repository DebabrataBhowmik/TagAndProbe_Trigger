void plotEfficiency_multi(TString triggerFile){

TFile *f1 = TFile::Open("finalRootFiles/efficiency_2018A_EGM_nominal.root");
TFile *f2 = TFile::Open("finalRootFiles/efficiency_2018B_EGM_nominal.root");
TFile *f3 = TFile::Open("finalRootFiles/efficiency_2018C_EGM_nominal.root");
TFile *f4 = TFile::Open("finalRootFiles/efficiency_2018D_EGM_nominal.root");


     ifstream inFile;
     inFile.open(triggerFile.Data());
     TString trigger_name;

/*
  KEY: TH1F	Ele32_pt_total;1	Ele32_pt
  KEY: TH1F	Ele32_pt_pass;1	Ele32_pt
  KEY: TH1F	Ele32_eta_pass;1	Ele32_eta
  KEY: TH1F	Ele35_pt_total;1	Ele35_pt
  KEY: TH1F	Ele35_eta_total;1	Ele35_eta
  KEY: TH1F	Ele35_pt_pass;1	Ele35_pt
  KEY: TH1F	Ele35_eta_pass;1	Ele35_eta
  KEY: TH1F	Ele23_Ele12_leg1_pt_total;1	Ele23_Ele12_leg1_pt
  KEY: TH1F	Ele23_Ele12_leg1_eta_total;1	Ele23_Ele12_leg1_eta
  KEY: TH1F	Ele23_Ele12_leg1_pt_pass;1	Ele23_Ele12_leg1_pt
  KEY: TH1F	Ele23_Ele12_leg1_eta_pass;1	Ele23_Ele12_leg1_eta
  KEY: TH1F	Ele23_Ele12_leg2_pt_total;1	Ele23_Ele12_leg2_pt
  KEY: TH1F	Ele23_Ele12_leg2_eta_total;1	Ele23_Ele12_leg2_eta
  KEY: TH1F	Ele23_Ele12_leg2_pt_pass;1	Ele23_Ele12_leg2_pt
  KEY: TH1F	Ele23_Ele12_leg2_eta_pass;1	Ele23_Ele12_leg2_eta
*/

  while(!inFile.eof())
  {

   TH1F *h_total_2018A,*h_total_2018B,*h_total_2018C,*h_total_2018D;
   TH1F *h_pass_2018A,*h_pass_2018B,*h_pass_2018C,*h_pass_2018D;
  
   TGraphAsymmErrors *gra_2018A=0;
   TGraphAsymmErrors *gra_2018B=0;
   TGraphAsymmErrors *gra_2018C=0;
   TGraphAsymmErrors *gra_2018D=0;

   inFile>>trigger_name;
   if(inFile.eof()) break;
   TString total = trigger_name.Data();
   total += "_total";
   if(total.Contains("_Iso") ) total.ReplaceAll("_Iso","");
   TString pass = trigger_name.Data();
   pass += "_pass"; 

  TH1F *h_total_2018A = (TH1F*)f1->Get("Ele35_eta_total");
  TH1F *h_total_2018B = (TH1F*)f2->Get("Ele35_eta_total");
  TH1F *h_total_2018C = (TH1F*)f3->Get("Ele35_eta_total");
  TH1F *h_total_2018D = (TH1F*)f4->Get("Ele35_eta_total");


  TH1F *h_pass_2018A = (TH1F*)f1->Get("Ele35_eta_pass");
  TH1F *h_pass_2018B = (TH1F*)f2->Get("Ele35_eta_pass");
  TH1F *h_pass_2018C = (TH1F*)f3->Get("Ele35_eta_pass");
  TH1F *h_pass_2018D = (TH1F*)f4->Get("Ele35_eta_pass");


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

  mg->SetTitle("Ele35_eta; Trig Efficiency");
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

c->SaveAs("TrigEff_2018_Ele35_eta.png");

}//inFile while look

}// end of program
