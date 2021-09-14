void plotEfficiency_Mu12(){

//TFile *f1 = TFile::Open("efficiency_tests_SingleMu12.root");
TFile *f1 = TFile::Open("efficiency_tests_SingleMu12_looseL1T.root");

   TH1F *h_total_2018A,*h_total_2018B,*h_total_2018C,*h_total_2018D;
   TH1F *h_pass_2018A,*h_pass_2018B,*h_pass_2018C,*h_pass_2018D;
  
   TGraphAsymmErrors *gra_2018A=0;
   TGraphAsymmErrors *gra_2018B=0;
   TGraphAsymmErrors *gra_2018C=0;

  h_total_2018A = (TH1F*)f1->Get("Mu12_pt_total");

  h_pass_2018A = (TH1F*)f1->Get("Mu12_pt_pass");
  h_pass_2018B = (TH1F*)f1->Get("Mu12_pt_pass_L10p5");
  h_pass_2018C = (TH1F*)f1->Get("Mu12_pt_pass_L10p3");
//  h_pass_2018B = (TH1F*)f1->Get("Mu12_ptHLT_pass");
//  h_pass_2018C = (TH1F*)f1->Get("Mu12_ptL1T_pass");

  TMultiGraph *mg = new TMultiGraph();

  gra_2018A = new TGraphAsymmErrors(h_pass_2018A,h_total_2018A);
  gra_2018B = new TGraphAsymmErrors(h_pass_2018B,h_total_2018A);
  gra_2018C = new TGraphAsymmErrors(h_pass_2018C,h_total_2018A);

  mg->Add(gra_2018A);
  mg->Add(gra_2018B);
  mg->Add(gra_2018C);


  gra_2018A->SetLineColor(1);
  gra_2018B->SetLineColor(2);
  gra_2018C->SetLineColor(3);

  gra_2018A->SetMarkerStyle(20);
  gra_2018B->SetMarkerStyle(20);
  gra_2018C->SetMarkerStyle(20);

  gra_2018A->SetMarkerColor(1);
  gra_2018B->SetMarkerColor(2);
  gra_2018C->SetMarkerColor(3);


  mg->SetTitle(h_total_2018A->GetTitle());
  TCanvas *c = new TCanvas("c","",200,10,800,600);
//  c->SetLogx();
  mg->Draw("APE");
  mg->SetMinimum(0.0);
  mg->SetMaximum(1.015);
  mg->GetXaxis()->CenterTitle(1);
  mg->GetXaxis()->SetTitleOffset(1.2);
  mg->GetYaxis()->CenterTitle(1);
  mg->GetYaxis()->SetTitleOffset(1.4);

   TLegend *legend = new TLegend(0.5,0.3,0.7,0.6);
   legend->AddEntry(gra_2018A,"L1+HLT (dR=0.1)","p");
   legend->AddEntry(gra_2018B,"L1+HLT (dR=0.5)","p");
   legend->AddEntry(gra_2018C,"L1+HLT (dR=0.3)","p");
//   legend->AddEntry(gra_2018A,"L1+HLT","p");
//   legend->AddEntry(gra_2018B,"HLT Only","p");
//   legend->AddEntry(gra_2018C,"L1 Only","p");
   legend->Draw();

  c->SaveAs("efficiency_Mu12_pt_looseL1.png");
  c->Clear();
        delete c;

}// end of program
