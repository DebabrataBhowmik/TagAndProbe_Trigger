void plotEfficiency_multi_Mu(TString triggerFile){


TFile *f1 = TFile::Open("efficiency_nominal_Muon_2017B.root");
TFile *f2 = TFile::Open("efficiency_nominal_Muon_2017CDE.root");
TFile *f3 = TFile::Open("efficiency_nominal_Muon_2017D.root");
TFile *f4 = TFile::Open("efficiency_nominal_Muon_2017E.root");
TFile *f5 = TFile::Open("efficiency_nominal_Muon_2017F.root");


     ifstream inFile;
     inFile.open(triggerFile.Data());
     TString trigger_name;

  while(!inFile.eof())
  {

   TH1F *h_total_2018A,*h_total_2018B,*h_total_2018C,*h_total_2018D,*h_total_2018F;
   TH1F *h_pass_2018A,*h_pass_2018B,*h_pass_2018C,*h_pass_2018D,*h_pass_2018F;
  
   TGraphAsymmErrors *gra_2018A=0;
   TGraphAsymmErrors *gra_2018B=0;
   TGraphAsymmErrors *gra_2018C=0;
   TGraphAsymmErrors *gra_2018D=0;
   TGraphAsymmErrors *gra_2018F=0;

   inFile>>trigger_name;
   if(inFile.eof()) break;
   TString total = trigger_name.Data();
   total += "_total";
   if(total.Contains("_Iso") ) total.ReplaceAll("_Iso","");
   TString pass = trigger_name.Data();
   pass += "_pass"; 

  h_total_2018A = (TH1F*)f1->Get(total.Data());
  h_total_2018B = (TH1F*)f2->Get(total.Data());
  h_total_2018C = (TH1F*)f3->Get(total.Data());
  h_total_2018D = (TH1F*)f4->Get(total.Data());
  h_total_2018F = (TH1F*)f5->Get(total.Data());

  h_pass_2018A = (TH1F*)f1->Get(pass.Data());
  h_pass_2018B = (TH1F*)f2->Get(pass.Data());
  h_pass_2018C = (TH1F*)f3->Get(pass.Data());
  h_pass_2018D = (TH1F*)f4->Get(pass.Data());
  h_pass_2018F = (TH1F*)f5->Get(pass.Data());

  TMultiGraph *mg = new TMultiGraph();

//for(int i; i < h_total_2018A->GetNbinsX(); i++) {
//cout << "bin = " << h_total_2018A->GetBinLowEdge(i) << "  " << "total = " << h_total_2018A->GetBinContent(i) << "   " << "pass = " << h_pass_2018A->GetBinContent(i) << endl;
//} 

  gra_2018A = new TGraphAsymmErrors (h_pass_2018A,h_total_2018A);
  gra_2018B = new TGraphAsymmErrors (h_pass_2018B,h_total_2018B);
  gra_2018C = new TGraphAsymmErrors (h_pass_2018C,h_total_2018C);
  gra_2018D = new TGraphAsymmErrors (h_pass_2018D,h_total_2018D);
  gra_2018F = new TGraphAsymmErrors (h_pass_2018F,h_total_2018F);

  mg->Add(gra_2018A);
  mg->Add(gra_2018B);
//  mg->Add(gra_2018C);
//  mg->Add(gra_2018D);
  mg->Add(gra_2018F);


  gra_2018A->SetLineColor(1);
  gra_2018B->SetLineColor(2);
  gra_2018C->SetLineColor(3);
  gra_2018D->SetLineColor(4);
  gra_2018F->SetLineColor(5);

  gra_2018A->SetMarkerStyle(20);
  gra_2018B->SetMarkerStyle(20);
  gra_2018C->SetMarkerStyle(20);
  gra_2018D->SetMarkerStyle(20);
  gra_2018F->SetMarkerStyle(20);

  gra_2018A->SetMarkerColor(1);
  gra_2018B->SetMarkerColor(2);
  gra_2018C->SetMarkerColor(3);
  gra_2018D->SetMarkerColor(4);
  gra_2018F->SetMarkerColor(5);

//cout << "N = " << gra_2018A->GetN() << endl;
//float ev;
//for ( Int_t k = 0; k <= gra_2018A->GetN() ; k++)
//    {
    //  ev = gra_2018A->Eval(gra_2018A->GetX(),0,"S");     
    //  cout << k << "  " << ev << endl;
  //    cout << gra_2018A->GetX() << endl;  
//    }

  mg->SetTitle(h_total_2018A->GetTitle());
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
   legend->AddEntry(gra_2018A,"2017B","p");
   legend->AddEntry(gra_2018B,"2017CDE","p");
//   legend->AddEntry(gra_2018C,"2017D","p");
//   legend->AddEntry(gra_2018D,"2017E","p");
   legend->AddEntry(gra_2018F,"2017F","p");

/*   legend->AddEntry(gra_2018A,"2018A","p");
   legend->AddEntry(gra_2018B,"2018B","p");
   legend->AddEntry(gra_2018C,"2018C","p");
   legend->AddEntry(gra_2018D,"2018D","p");
*/
   legend->Draw();

  TString pngFileName = trigger_name.Data() ;
//  pngFileName += "_HLTOnly";
  pngFileName +=  "_efficiency.png";
  c->SaveAs(pngFileName.Data());
  c->Clear();
  gSystem->Exec("mkdir -p results");
  TString dirName = "results/";
 // dirName+=trigger_name.Data();
 // gSystem->Exec("mkdir -p  "+ dirName);
  gSystem->Exec("mv " + trigger_name+"*.png  "+dirName);

        delete c;

}//inFile while look
}// end of program
