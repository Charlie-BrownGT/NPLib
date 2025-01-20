/*****************************************************************************
 * Copyright (C) 2009-2025   this file is part of the NPTool Project       *
 *                                                                           *
 * For the licensing terms see $NPTOOL/Licence/NPTool_Licence                *
 * For the list of contributors see $NPTOOL/Licence/Contributors             *
 *****************************************************************************/

/*****************************************************************************
 * Original Author: Guy Carter-Richardson  contact address: Guy.Carter-Richardson@york.ac.uk                        *
 *                                                                           *
 * Creation Date  : January 2025                                           *
 * Last update    :                                                          *
 *---------------------------------------------------------------------------*
 * Decription:                                                               *
 *  This class describe  basicScintillator simulation                             *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Comment:                                                                  *
 *                                                                           *
 *****************************************************************************/

// C++ headers
#include <sstream>
#include <cmath>
#include <limits>
//G4 Geometry object
#include "G4Tubs.hh"
#include "G4Box.hh"

//G4 sensitive
#include "G4SDManager.hh"
#include "G4MultiFunctionalDetector.hh"

//G4 various object
#include "G4Material.hh"
#include "G4Transform3D.hh"
#include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4THitsMap.hh"

// NPTool header
#include "basicScintillator.hh"
#include "CalorimeterScorers.hh"
#include "InteractionScorers.hh"
#include "RootOutput.h"
#include "MaterialManager.hh"
#include "NPSDetectorFactory.hh"
#include "NPOptionManager.h"
#include "NPSHitsMap.hh"

#include "SiliconScorers.hh"

// CLHEP header
#include "CLHEP/Random/RandGauss.h"

using namespace std;
using namespace CLHEP;

namespace basicScintillator_NS{
  //Old Parameters 
  // Energy and time Resolution
  //const double EnergyThreshold = 0.1*MeV;
  //const double ResoTime = 4.5*ns ;
  //const double ResoEnergy = 1.0*MeV ;
  //const double Radius = 50*mm ; 
  //const double Width = 100*mm ;
  //const double Thickness = 300*mm ;
  //const string Material = "BC400";

  const double EnergyThreshold = 0.1*MeV;
  const double ResoTime = 0.213*ns;         // Unit is ns/2.35 ,  FWHM = 500 ps
  const double ResoEnergy = 0.017*MeV ;     // Unit is MeV/2.35 , FWHM = 40 keV
  const double Radius = 50*mm ;
  const double Width = 68*mm ;
  const double Thickness = 3000*micrometer ;
  //const double Thickness = 300*mm ;
  const string Material = "Si";
  const G4int  NumberOfStrips = 25 ;
}

// basicScintillator Specific Method
basicScintillator::basicScintillator(){
  m_Event = new TbasicScintillatorData() ;
  m_basicScintillatorScorer = 0;
  m_SquareDetector = 0;
  m_CylindricalDetector = 0;


  // RGB Color + Transparency
  m_VisSquare = new G4VisAttributes(G4Colour(0, 1, 0, 0.5));   
  m_VisCylinder = new G4VisAttributes(G4Colour(0, 0, 1, 0.5));   

}

basicScintillator::~basicScintillator(){
}

void basicScintillator::AddDetector(G4ThreeVector POS, string  Shape){
  // Convert the POS value to R theta Phi as Spherical coordinate is easier in G4 
  m_R.push_back(POS.mag());
  m_Theta.push_back(POS.theta());
  m_Phi.push_back(POS.phi());
  m_Shape.push_back(Shape);
}

void basicScintillator::AddDetector(double  R, double  Theta, double  Phi, string  Shape){
  m_R.push_back(R);
  m_Theta.push_back(Theta);
  m_Phi.push_back(Phi);
  m_Shape.push_back(Shape);
}

G4LogicalVolume* basicScintillator::BuildSquareDetector(){
  if(!m_SquareDetector){
    G4Box* box = new G4Box("basicScintillator_Box",basicScintillator_NS::Width*0.5,
        basicScintillator_NS::Width*0.5,basicScintillator_NS::Thickness*0.5);

    G4Material* DetectorMaterial = MaterialManager::getInstance()->GetMaterialFromLibrary(basicScintillator_NS::Material);
    m_SquareDetector = new G4LogicalVolume(box,DetectorMaterial,"logic_basicScintillator_Box",0,0,0);
    m_SquareDetector->SetVisAttributes(m_VisSquare);
    m_SquareDetector->SetSensitiveDetector(m_basicScintillatorScorer);
  }
  return m_SquareDetector;
}

G4LogicalVolume* basicScintillator::BuildCylindricalDetector(){
  if(!m_CylindricalDetector){
    G4Tubs* tub = new G4Tubs("basicScintillator_Cyl",0,basicScintillator_NS::Radius,basicScintillator_NS::Thickness*0.5,0,360*deg);

    G4Material* DetectorMaterial = MaterialManager::getInstance()->GetMaterialFromLibrary(basicScintillator_NS::Material);
    m_CylindricalDetector = new G4LogicalVolume(tub,DetectorMaterial,"logic_basicScintillator_tub",0,0,0);
    m_CylindricalDetector->SetVisAttributes(m_VisSquare);
    m_CylindricalDetector->SetSensitiveDetector(m_basicScintillatorScorer);

  }
  return m_CylindricalDetector;
}

// Virtual Method of NPS::VDetector class

// Read stream at Configfile to pick-up parameters of detector (Position,...)
// Called in DetecorConstruction::ReadDetextorConfiguration Method

void basicScintillator::ReadConfiguration(NPL::InputParser parser){
  vector<NPL::InputBlock*> blocks = parser.GetAllBlocksWithToken("basicScintillator");
  if(NPOptionManager::getInstance()->GetVerboseLevel())
    cout << "//// " << blocks.size() << " detectors found " << endl; 

  vector<string> cart = {"POS","Shape"};
  vector<string> sphe = {"R","Theta","Phi","Shape"};

  for(unsigned int i = 0 ; i < blocks.size() ; i++){
    if(blocks[i]->HasTokenList(cart)){
      if(NPOptionManager::getInstance()->GetVerboseLevel())
        cout << endl << "////  basicScintillator " << i+1 <<  endl;
    
      G4ThreeVector Pos = NPS::ConvertVector(blocks[i]->GetTVector3("POS","mm"));
      string Shape = blocks[i]->GetString("Shape");
      AddDetector(Pos,Shape);
    }
    else if(blocks[i]->HasTokenList(sphe)){
      if(NPOptionManager::getInstance()->GetVerboseLevel())
        cout << endl << "////  basicScintillator " << i+1 <<  endl;
      double R = blocks[i]->GetDouble("R","mm");
      double Theta = blocks[i]->GetDouble("Theta","deg");
      double Phi = blocks[i]->GetDouble("Phi","deg");
      string Shape = blocks[i]->GetString("Shape");
      AddDetector(R,Theta,Phi,Shape);
    }
    else{
      cout << "ERROR: check your input file formatting " << endl;
      exit(1);
    }
  }
}

// Construct detector and inialise sensitive part.
// Called After DetecorConstruction::AddDetector Method

void basicScintillator::ConstructDetector(G4LogicalVolume* world){
  for (unsigned short i = 0 ; i < m_R.size() ; i++) {

    G4double wX = m_R[i] * sin(m_Theta[i] ) * cos(m_Phi[i] ) ;
    G4double wY = m_R[i] * sin(m_Theta[i] ) * sin(m_Phi[i] ) ;
    G4double wZ = m_R[i] * cos(m_Theta[i] ) ;
    G4ThreeVector Det_pos = G4ThreeVector(wX, wY, wZ) ;
    // So the face of the detector is at R instead of the middle
    Det_pos+=Det_pos.unit()*basicScintillator_NS::Thickness*0.5;
    // Building Detector reference frame
    G4double ii = cos(m_Theta[i]) * cos(m_Phi[i]);
    G4double jj = cos(m_Theta[i]) * sin(m_Phi[i]);
    G4double kk = -sin(m_Theta[i]);
    G4ThreeVector Y(ii,jj,kk);
    G4ThreeVector w = Det_pos.unit();
    G4ThreeVector u = w.cross(Y);
    G4ThreeVector v = w.cross(u);
    v = v.unit();
    u = u.unit();

    G4RotationMatrix* Rot = new G4RotationMatrix(u,v,w);

    if(m_Shape[i] == "Cylindrical"){
      new G4PVPlacement(G4Transform3D(*Rot,Det_pos),
          BuildCylindricalDetector(),
          "basicScintillator",world,false,i+1);
    }

    else if(m_Shape[i] == "Square"){
      new G4PVPlacement(G4Transform3D(*Rot,Det_pos),
          BuildSquareDetector(),
          "basicScintillator",world,false,i+1);
    }
  }
}

// Add Detector branch to the EventTree.
// Called After DetecorConstruction::AddDetector Method

void basicScintillator::InitializeRootOutput(){
  RootOutput *pAnalysis = RootOutput::getInstance();
  TTree *pTree = pAnalysis->GetTree();
  if(!pTree->FindBranch("basicScintillator")){
    pTree->Branch("basicScintillator", "TbasicScintillatorData", &m_Event) ;
  }
  pTree->SetBranchAddress("basicScintillator", &m_Event) ;
}

// Read sensitive part and fill the Root tree.
// Called at in the EventAction::EndOfEventAvtion

void basicScintillator::ReadSensitive(const G4Event* event){
  m_Event->Clear();

  /*
  ///////////
  // Calorimeter scorer
  CalorimeterScorers::PS_Calorimeter* Scorer= (CalorimeterScorers::PS_Calorimeter*) m_basicScintillatorScorer->GetPrimitive(0);

  unsigned int size = Scorer->GetMult(); 
  for(unsigned int i = 0 ; i < size ; i++){
    vector<unsigned int> level = Scorer->GetLevel(i); 
    double Energy = RandGauss::shoot(Scorer->GetEnergy(i),basicScintillator_NS::ResoEnergy);
    if(Energy>basicScintillator_NS::EnergyThreshold){
      double Time = RandGauss::shoot(Scorer->GetTime(i),basicScintillator_NS::ResoTime);
      int DetectorNbr = level[0];
      m_Event->Set_Energy(DetectorNbr,StripNbr,Energy);
      m_Event->Set_Time(DetectorNbr,Time); 
    }
  }
  */
  
  // Strip scorer
  G4THitsMap<G4double*>* StripHitMap;
  std::map<G4int, G4double**>::iterator Strip_itr;
  G4int StripCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID("basicScintillatorScorer/StripScorer");
  //StripHitMap = (G4THitsMap<G4double*>*)(event->GetHCofThisEvent()->GetHC(StripCollectionID));
  StripHitMap = (G4THitsMap<G4double*>*)(event->GetHCofThisEvent()->GetHC(StripCollectionID));

  Int_t eventID = event->GetEventID();
  double Energy;
  double Threshold;
  
  // Loop on the Strip map
  for (Strip_itr = StripHitMap->GetMap()->begin() ; Strip_itr != StripHitMap->GetMap()->end() ; Strip_itr++){
    G4double* Info = *(Strip_itr->second);
    Energy = RandGauss::shoot(Info[0], basicScintillator_NS::ResoEnergy);
    Threshold = basicScintillator_NS::EnergyThreshold;
    if(Energy > Threshold){
        double Time     = RandGauss::shoot(Info[1], basicScintillator_NS::ResoTime);
        int DetNbr      = (int) Info[7];
        int StripNbr    = (int) Info[8];
        //m_Event->SetEnergy(DetNbr, StripNbr, Energy);
        //m_Event->SetTime(DetNbr, StripNbr, Time);
    }
  }
  if (Energy > Threshold){
    //cout << "EventID: " << eventID << endl;
    //cout << "Energy : " << Energy << endl;
    //cout << "Threshold : " << Threshold << endl;
    m_Event->SetEventID(eventID);
  }
}
 
void basicScintillator::InitializeScorers() { 
  // This check is necessary in case the geometry is reloaded
  bool already_exist = false; 
  m_basicScintillatorScorer = CheckScorer("basicScintillatorScorer",already_exist) ;

  if(already_exist) 
    return ;

  // Otherwise the scorer is initialised
  vector<int> level; level.push_back(0);
  G4VPrimitiveScorer* Calorimeter= new CalorimeterScorers::PS_Calorimeter("Calorimeter",level, 0) ;
  G4VPrimitiveScorer* Interaction= new InteractionScorers::PS_Interactions("Interaction",ms_InterCoord, 0) ;

  //New Scorer
  G4VPrimitiveScorer* StripScorer =
    new  SILICONSCORERS::PS_Silicon_Rectangle("StripScorer",0,
        basicScintillator_NS::Width,     // Width
        basicScintillator_NS::Width,     // Length (here same as Width for a square det.)
        basicScintillator_NS::NumberOfStrips,    // Width segmentation
        1);                         // Length segmentation

  //and register it to the multifunctionnal detector
  m_basicScintillatorScorer->RegisterPrimitive(Calorimeter);
  m_basicScintillatorScorer->RegisterPrimitive(Interaction);

  //New Primitive
  m_basicScintillatorScorer->RegisterPrimitive(StripScorer);

  G4SDManager::GetSDMpointer()->AddNewDetector(m_basicScintillatorScorer) ;
}

////////////////////////////////////////////////////////////////////////////////
//            Construct Method to be pass to the DetectorFactory              //
////////////////////////////////////////////////////////////////////////////////
NPS::VDetector* basicScintillator::Construct(){
  return  (NPS::VDetector*) new basicScintillator();
}

////////////////////////////////////////////////////////////////////////////////
//            Registering the construct method to the factory                 //
////////////////////////////////////////////////////////////////////////////////
extern"C" {
  class proxy_nps_basicScintillator{
    public:
      proxy_nps_basicScintillator(){
        NPS::DetectorFactory::getInstance()->AddToken("basicScintillator","basicScintillator");
        NPS::DetectorFactory::getInstance()->AddDetector("basicScintillator",basicScintillator::Construct);
      }
  };

  proxy_nps_basicScintillator p_nps_basicScintillator;
}
