// C++ headers
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// ROOT headers
#include "TROOT.h"
#include "TCanvas.h"
#include "TSystem.h"
#include "TFile.h"
#include "TString.h"
#include "TEllipse.h"
#include "TLegend.h"
#include "TTree.h"
#include "TBranch.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"

// nptool headers
#include "TInitialConditions.h"
#include "TInteractionCoordinates.h"
//#include "NPDetectorManager.h"
#include "NPReaction.h"
using namespace NPL;

void ShowResults(){

  TCanvas *c1 = new TCanvas("c1", "Results", 1000, 1000);
  c1->Divide(2,2);

  // get tree   
  TFile* f1 = new TFile("../../Outputs/Analysis/18F3HeD19Ne360MeV.root");
  TTree* t1 = (TTree*) f1->Get("PhysicsTree");

  TFile* f2 = new TFile("../../Outputs/Analysis/18F3HeD19Ne280MeV.root");
  TTree* t2 = (TTree*) f2->Get("PhysicsTree");

  TFile* f3 = new TFile("../../Outputs/Analysis/18F3HeD19Ne200MeV.root");
  TTree* t3 = (TTree*) f3->Get("PhysicsTree");

  TFile* f4 = new TFile("../../Outputs/Analysis/18F3HeD19Ne120MeV.root");
  TTree* t4 = (TTree*) f4->Get("PhysicsTree");

  // draw kinematic information
  // canvas
  // kinematic line
  c1->cd(1);
  TH2F* hk1 = new TH2F("hk1", "EvsTheta(lab)360MeV", 180*3, 0, 180, 1000, 0, 60);
  t1->Draw("ELab:ThetaLab>>hk1","","col");
  hk1->GetXaxis()->SetTitle("#Theta_{lab} (deg)");
  hk1->GetYaxis()->SetTitle("E_{lab} (MeV)");
  NPL::Reaction* reaction1 = new NPL::Reaction();
  reaction1->ReadConfigurationFile("18F3HeD19Ne360.reaction");
  reaction1->GetKinematicLine3()->Draw("c");
  
  c1->cd(2);
  TH2F* hk2 = new TH2F("hk2", "EvsTheta(lab)280MeV", 180*3, 0, 180, 1000, 0, 60);
  t2->Draw("ELab:ThetaLab>>hk2","","col");
  hk2->GetXaxis()->SetTitle("#Theta_{lab} (deg)");
  hk2->GetYaxis()->SetTitle("E_{lab} (MeV)");
  NPL::Reaction* reaction2 = new NPL::Reaction();
  reaction2->ReadConfigurationFile("18F3HeD19Ne280.reaction");
  reaction2->GetKinematicLine3()->Draw("c");

  c1->cd(3);
  TH2F* hk3 = new TH2F("hk3", "EvsTheta(lab)200MeV", 180*3, 0, 180, 1000, 0, 60);
  t3->Draw("ELab:ThetaLab>>hk3","","col");
  hk3->GetXaxis()->SetTitle("#Theta_{lab} (deg)");
  hk3->GetYaxis()->SetTitle("E_{lab} (MeV)");
  NPL::Reaction* reaction3 = new NPL::Reaction();
  reaction3->ReadConfigurationFile("18F3HeD19Ne200.reaction");
  reaction3->GetKinematicLine3()->Draw("c");

  c1->cd(4);
  TH2F* hk4 = new TH2F("hk4", "EvsTheta(lab)120MeV", 180*3, 0, 180, 1000, 0, 60);
  t4->Draw("ELab:ThetaLab>>hk4","","col");
  hk4->GetXaxis()->SetTitle("#Theta_{lab} (deg)");
  hk4->GetYaxis()->SetTitle("E_{lab} (MeV)");
  NPL::Reaction* reaction4 = new NPL::Reaction();
  reaction4->ReadConfigurationFile("18F3HeD19Ne120.reaction");
  reaction4->GetKinematicLine3()->Draw("c");
}

