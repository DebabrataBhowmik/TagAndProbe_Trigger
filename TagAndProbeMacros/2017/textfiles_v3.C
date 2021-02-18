#include <iostream>

void textfiles_v3(int type){

  string file;
  std::ofstream outfile;

  if(type==0) file="Veto";
  if(type==1) file="Loose";
  if(type==2) file="Medium";
  if(type==3) file="Tight";
  if(type==4) file="RECO";

  outfile.open("RECO_SF_textfile_20to30_3March.txt");
  outfile<<std::fixed;

  ifstream datafile;

  datafile.open("../Nominal_RECO/passingRECO_20_30_withcuts.txt");

  ifstream mcfile;
  mcfile.open("../Nominal_RECO/MCEff_RECO_2030_Powheg.txt");

//  ifstream datafileLO;
//  datafileLO.open( "../Nominal_MG_Id/passing"+file+".txt");

  ifstream mcfileLO;
  mcfileLO.open("../Nominal_RECO/MCEff_RECO_2030_Madgraph.txt");

  ifstream datafilefitR;
  datafilefitR.open( "../fitRange_RECO/passingRECO_20_30_withcuts.txt");

//  ifstream mcfilefitR;
//  mcfilefitR.open( "../fitRange_MG_Id/MCEff_"+file+"_MG.txt");

  ifstream datafileExp;
  datafileExp.open("../Exp_RECO/passingRECO_20_30_withcuts.txt");

  ifstream datafileCB;
//  datafileCB.open("../CB_RECO/passingRECO_20_30_withcuts.txt");
// datafileCB.open("../CB_RECO/passingRECO_20_30_NEW.txt");
 datafileCB.open("../CB_RECO/passingRECO_2030_Step4.txt");


  ifstream datafileTagS;
  datafileTagS.open("../TagSyst_RECO/passingRECO_20_30_withcuts.txt");

//  ifstream mcfileTagS;
//  mcfileTagS.open("../TagSyst/MCtruth_passing"+file+".txt");


//  const int nptbins = 5;
//  const int netabins = 5;
//  double ptmin[nptbins+1] = {10.,20.,30.,40.,50.,2000.};
//  double etamin[netabins+1] = {-2.5,-2.0,-1.566,-1.4442,-0.8,0,0.8,1.4442,1.566,2.0,2.5};
// double etamin[netabins+1] = {0,0.8,1.4442,1.566,2.0,2.5};  
  double absdiffLO,absdiff_fitR,absdiffExp,absdiffCB,absdiffTagS;
  while(!datafile.eof()){
//  while(!sffile.eof()){  

    double detamin, detamax, dptmin, dptmax, deff, derr;
    double mcetamin, mcetamax, mcptmin, mcptmax, mceff, mcerr;
    double detaminLO, detamaxLO, dptminLO, dptmaxLO, deffLO, derrLO;
    double mcetaminLO, mcetamaxLO, mcptminLO, mcptmaxLO, mceffLO, mcerrLO;
    double detaminfitR, detamaxfitR, dptminfitR, dptmaxfitR, defffitR, derrfitR;
    double mcetaminfitR, mcetamaxfitR, mcptminfitR, mcptmaxfitR, mcefffitR, mcerrfitR;
    double detaminExp, detamaxExp, dptminExp, dptmaxExp, deffExp, derrExp;
    double detaminCB, detamaxCB, dptminCB, dptmaxCB, deffCB, derrCB;
    double detaminTagS, detamaxTagS, dptminTagS, dptmaxTagS, deffTagS, derrTagS;
    double mcetaminTagS, mcetamaxTagS, mcptminTagS, mcptmaxTagS, mceffTagS, mcerrTagS;


    datafile>>dptmin>>dptmax>>detamin>>detamax>>deff>>derr;
//    cout<<dptmin<<"  "<<dptmax<<"  "<<detamin<<"  "<<detamax<<"  "<<deff<<"  "<<derr<<endl;

//    mcfile>>mcptmin>>mcptmax>>mcetamin>>mcetamax>>mceff>>mcerr;
     mcfile>>mceff>>mcerr;    
    //cout<<mcptmin<<"  "<<mcptmax<<"  "<<mcetamin<<"  "<<mcetamax<<"  "<<mceff<<"  "<<mcerr<<endl;
 //   cout << mceff << " " << mcerr << endl;    

//    datafileLO>>dptminLO>>dptmaxLO>>detaminLO>>detamaxLO>>deffLO>>derrLO;
    //cout<<dptmin<<"  "<<dptmax<<"  "<<detamin<<"  "<<detamax<<"  "<<deff<<"  "<<derr<<endl;
    
    mcfileLO>>mceffLO>>mcerrLO;    
    //cout<<mcptmin<<"  "<<mcptmax<<"  "<<mcetamin<<"  "<<mcetamax<<"  "<<mceff<<"  "<<mcerr<<endl;
    
    datafilefitR>>dptminfitR>>dptmaxfitR>>detaminfitR>>detamaxfitR>>defffitR>>derrfitR;
    //cout<<dptmin<<"  "<<dptmax<<"  "<<detamin<<"  "<<detamax<<"  "<<deff<<"  "<<derr<<endl; 

    datafileExp>>dptminExp>>dptmaxExp>>detaminExp>>detamaxExp>>deffExp>>derrExp;
    //cout<<dptmin<<"  "<<dptmax<<"  "<<detamin<<"  "<<detamax<<"  "<<deff<<"  "<<derr<<endl;
    
    datafileCB>>dptminCB>>dptmaxCB>>detaminCB>>detamaxCB>>deffCB>>derrCB;
    

    datafileTagS>>dptminTagS>>dptmaxTagS>>detaminTagS>>detamaxTagS>>deffTagS>>derrTagS;
//    mcfileTagS>>mcptminTagS>>mcptmaxTagS>>mcetaminTagS>>mcetamaxTagS>>mceffTagS>>mcerrTagS;

/*
    absdiffLO = fabs((deff/mceff) - (deffLO/mceffLO));
    absdiff_fitR = fabs((deff/mceff) - (defffitR/mcefffitR));
    absdiffExp = fabs((deff/mceff) - (deffExp/mceff));
    absdiffCB = fabs((deff/mceff) - (deffCB/mceff));
    absdiffTagS = fabs((deff/mceff) - (deffTagS/mceff));
*/
//minEta   maxEta   minPt   maxPt   effData    statError effMC  statError   systBkgShape    systSigShape   systFitRange systNLOvsLO(or whatever 2 MCs you have)    systPU    systTagSelection

//    outfile<<setprecision(3)<<dptmin<<"\t"<<dptmax<<"\t"<<detamin<<"\t"<<detamax<<"\t"<<deff<<"\t"<<derr<<"\t"<<mceff<<"\t"<<mcerr<<"\t"<<absdiffCB<<"\t"<<absdiffExp<<"\t"<<absdiff_fitR<<"\t"<<absdiffLO<<"\t"<<absdiffTagS<<"\t"<<"-1"<<endl;

 //    outfile<<setprecision(3)<<detamin<<"\t"<<detamax<<"\t"<<dptmin<<"\t"<<dptmax<<"\t"<<deff<<"\t"<<derr<<"\t"<<mceff<<"\t"<<mcerr<<"\t"<<absdiffExp << "\t"<<absdiffCB<<"\t"<<absdiffLO << "\t" << absdiffTagS << "\t" << "-1" << "\t" << "-1" << "\t" << absdiff_fitR<<endl;

//    outfile<<setprecision(3)<<detamin<<"\t"<<detamax<<"\t"<<dptmin<<"\t"<<dptmax<<"\t"<<deff<<"\t"<<derr<<"\t"<<mceff<<"\t"<<mcerr<<"\t"<<absdiffExp << "\t"<<absdiffCB<<"\t"<< "-1" << "\t" << absdiffTagS << "\t" << "-1" << "\t" << "-1" << "\t" << absdiff_fitR<<endl;

//outfile<<setprecision(3)<<detamin<<"\t"<<detamax<<"\t"<<dptmin<<"\t"<<dptmax<<"\t"<<deff<<"\t"<<derr<<"\t"<<mceff<<"\t"<<mcerr<<"\t"<< deffExp << "\t"<<deffCB<<"\t"<< mceffLO << "\t" << deffTagS << "\t" << "-1" << "\t" << "-1" << "\t" << defffitR <<endl;

outfile<<setprecision(3)<<detamin<<"\t"<<detamax<<"\t"<<dptmin<<"\t"<<dptmax<<"\t"<<deff<<"\t"<<derr<<"\t"<<mceff<<"\t"<<mcerr << "\t" << deffExp << "\t"<<deffCB<<"\t"<< mceffLO << "\t" << deffTagS << "\t" << "-1" << "\t" << "-1" << "\t" << defffitR <<endl;



//cout << dptmin << "  " << dptmax << endl;

//   outfile<<setprecision(3)<<sfetamin<<"\t"<<sfetamax<<"\t"<<sfptmin<<"\t"<<sfptmax<<"\t"<<sf<<"\t"<<sferr<<endl;
 

  }

}
