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
 *  This class hold basicScintillator Treated  data                               *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Comment:                                                                  *
 *                                                                           *   
 *                                                                           *
 *****************************************************************************/

#include "TbasicScintillatorPhysics.h"

//   STL
#include <sstream>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <limits>
using namespace std;

//   NPL
#include "RootInput.h"
#include "RootOutput.h"
#include "NPDetectorFactory.h"
#include "NPOptionManager.h"

//   ROOT
#include "TChain.h"

ClassImp(TbasicScintillatorPhysics)


///////////////////////////////////////////////////////////////////////////
TbasicScintillatorPhysics::TbasicScintillatorPhysics()
   : m_EventData(new TbasicScintillatorData),
     m_PreTreatedData(new TbasicScintillatorData),
     m_EventPhysics(this),
     m_Spectra(0),
     m_E_RAW_Threshold(0), // adc channels
     m_E_Threshold(0),     // MeV
     m_NumberOfDetectors(0) {
}

///////////////////////////////////////////////////////////////////////////
/// A usefull method to bundle all operation to add a detector
void TbasicScintillatorPhysics::AddDetector(TVector3 , string ){
  // In That simple case nothing is done
  // Typically for more complex detector one would calculate the relevant 
  // positions (stripped silicon) or angles (gamma array)
  m_NumberOfDetectors++;
} 

///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::AddDetector(double R, double Theta, double Phi, string shape){
  // Compute the TVector3 corresponding
  TVector3 Pos(R*sin(Theta)*cos(Phi),R*sin(Theta)*sin(Phi),R*cos(Theta));
  // Call the cartesian method
  AddDetector(Pos,shape);
} 
  
///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::BuildSimplePhysicalEvent() {
  BuildPhysicalEvent();
}



///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::BuildPhysicalEvent() {
  // apply thresholds and calibration
  PreTreat();

  // Old Method of Treating Data
  // match energy and time together
  //unsigned int mysizeE = m_PreTreatedData->GetMultEnergy();
  //unsigned int mysizeT = m_PreTreatedData->GetMultTime();
  //for (UShort_t e = 0; e < mysizeE ; e++) {
  //  for (UShort_t t = 0; t < mysizeT ; t++) {
  //    if (m_PreTreatedData->GetE_DetectorNbr(e) == m_PreTreatedData->GetT_DetectorNbr(t)) {
  //      DetectorNumber.push_back(m_PreTreatedData->GetE_DetectorNbr(e));
  //      Energy.push_back(m_PreTreatedData->Get_Energy(e));
  //      Time.push_back(m_PreTreatedData->Get_Time(t));
  //    }
  //  }
  //}

  // match energy and time together
  for (UShort_t e = 0; e < m_PreTreatedData->GetMultEnergy(); e++) {
    for (UShort_t t = 0; t < m_PreTreatedData->GetMultTime(); t++) {
      if (m_PreTreatedData->GetE_DetectorNbr(e) == m_PreTreatedData->GetT_DetectorNbr(t)
          && m_PreTreatedData->GetE_StripNbr(e) == m_PreTreatedData->GetT_StripNbr(t) ) {
        DetectorNumber.push_back(m_PreTreatedData->GetE_DetectorNbr(e));
        StripNumber.push_back(m_PreTreatedData->GetE_StripNbr(e)); 
        Energy.push_back(m_PreTreatedData->Get_Energy(e));
        Time.push_back(m_PreTreatedData->Get_Time(t));
      }
    }
  }

  for (UShort_t i = 0; i < m_PreTreatedData->GetEventID(); i++){
    EventID.push_back(m_PreTreatedData->Get_EventID(i));
  }
}

///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::PreTreat() {
  // This method typically applies thresholds and calibrations
  // Might test for disabled channels for more complex detector

  // clear pre-treated object
  ClearPreTreatedData();

  // instantiate CalibrationManager
  static CalibrationManager* Cal = CalibrationManager::getInstance();

  // Energy
  for (UShort_t i = 0; i < m_EventData->GetMultEnergy(); ++i) {
    if (m_EventData->Get_Energy(i) > m_E_RAW_Threshold) {
      Double_t Energy = Cal->ApplyCalibration("basicScintillator/D"+NPL::itoa(m_EventData->GetE_DetectorNbr(i))+"_STRIP"+NPL::itoa(m_EventData->GetE_StripNbr(i))+"_ENERGY",m_EventData->Get_Energy(i));
      if (Energy > m_E_Threshold) {
        m_PreTreatedData->SetEnergy(m_EventData->GetE_DetectorNbr(i), m_EventData->GetE_StripNbr(i), Energy);
      }
    }
  }

  // Time 
  for (UShort_t i = 0; i < m_EventData->GetMultTime(); ++i) {
    Double_t Time = Cal->ApplyCalibration("basicScintillator/D"+NPL::itoa(m_EventData->GetT_DetectorNbr(i))+"_STRIP"+NPL::itoa(m_EventData->GetT_StripNbr(i))+"_TIME",m_EventData->Get_Time(i));
    m_PreTreatedData->SetTime(m_EventData->GetT_DetectorNbr(i), m_EventData->GetT_StripNbr(i), Time);
  }

  // EventID
  for (UShort_t i = 0; i < m_EventData->GetEventID(); i++){
    Int_t EventID = Cal->ApplyCalibration("basicScintillator/D"+NPL::itoa(m_EventData->Get_EventID(i))+"_ID",m_EventData->Get_EventID(i));
    m_PreTreatedData->SetEventID(m_EventData->Get_EventID(i));
  }

  // Old Energy Pretreat
  // Energy
  //unsigned int mysize = m_EventData->GetMultEnergy();
  //for (UShort_t i = 0; i < mysize ; ++i) {
  //  if (m_EventData->Get_Energy(i) > m_E_RAW_Threshold) {
  //    Double_t Energy = Cal->ApplyCalibration("basicScintillator/ENERGY"+NPL::itoa(m_EventData->GetE_DetectorNbr(i)),m_EventData->Get_Energy(i));
  //    if (Energy > m_E_Threshold) {
  //      m_PreTreatedData->SetEnergy(m_EventData->GetE_DetectorNbr(i), Energy);
  //    }
  //  }
  //}

  // Old Time Pretreat 
  // Time 
  //mysize = m_EventData->GetMultTime();
  //for (UShort_t i = 0; i < mysize; ++i) {
  //  Double_t Time= Cal->ApplyCalibration("basicScintillator/TIME"+NPL::itoa(m_EventData->GetT_DetectorNbr(i)),m_EventData->Get_Time(i));
  //  m_PreTreatedData->SetTime(m_EventData->GetT_DetectorNbr(i), Time);
  //}
}



///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::ReadAnalysisConfig() {
  bool ReadingStatus = false;

  // path to file
  string FileName = "./configs/ConfigbasicScintillator.dat";

  // open analysis config file
  ifstream AnalysisConfigFile;
  AnalysisConfigFile.open(FileName.c_str());

  if (!AnalysisConfigFile.is_open()) {
    cout << " No ConfigbasicScintillator.dat found: Default parameter loaded for Analayis " << FileName << endl;
    return;
  }
  cout << " Loading user parameter for Analysis from ConfigbasicScintillator.dat " << endl;

  // Save it in a TAsciiFile
  TAsciiFile* asciiConfig = RootOutput::getInstance()->GetAsciiFileAnalysisConfig();
  asciiConfig->AppendLine("%%% ConfigbasicScintillator.dat %%%");
  asciiConfig->Append(FileName.c_str());
  asciiConfig->AppendLine("");
  // read analysis config file
  string LineBuffer,DataBuffer,whatToDo;
  while (!AnalysisConfigFile.eof()) {
    // Pick-up next line
    getline(AnalysisConfigFile, LineBuffer);

    // search for "header"
    string name = "ConfigbasicScintillator";
    if (LineBuffer.compare(0, name.length(), name) == 0) 
      ReadingStatus = true;

    // loop on tokens and data
    while (ReadingStatus ) {
      whatToDo="";
      AnalysisConfigFile >> whatToDo;

      // Search for comment symbol (%)
      if (whatToDo.compare(0, 1, "%") == 0) {
        AnalysisConfigFile.ignore(numeric_limits<streamsize>::max(), '\n' );
      }

      else if (whatToDo=="E_RAW_THRESHOLD") {
        AnalysisConfigFile >> DataBuffer;
        m_E_RAW_Threshold = atof(DataBuffer.c_str());
        cout << whatToDo << " " << m_E_RAW_Threshold << endl;
      }

      else if (whatToDo=="E_THRESHOLD") {
        AnalysisConfigFile >> DataBuffer;
        m_E_Threshold = atof(DataBuffer.c_str());
        cout << whatToDo << " " << m_E_Threshold << endl;
      }

      else {
        ReadingStatus = false;
      }
    }
  }
}



///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::Clear() {
  DetectorNumber.clear();
  DetectorNumber.clear();
  Energy.clear();
  Time.clear();
  EventID.clear();
}



///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::ReadConfiguration(NPL::InputParser parser) {
  vector<NPL::InputBlock*> blocks = parser.GetAllBlocksWithToken("basicScintillator");
  if(NPOptionManager::getInstance()->GetVerboseLevel())
    cout << "//// " << blocks.size() << " detectors found " << endl; 

  vector<string> cart = {"POS","Shape"};
  vector<string> sphe = {"R","Theta","Phi","Shape"};

  for(unsigned int i = 0 ; i < blocks.size() ; i++){
    if(blocks[i]->HasTokenList(cart)){
      if(NPOptionManager::getInstance()->GetVerboseLevel())
        cout << endl << "////  basicScintillator " << i+1 <<  endl;
    
      TVector3 Pos = blocks[i]->GetTVector3("POS","mm");
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

///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::InitSpectra() {
  m_Spectra = new TbasicScintillatorSpectra(m_NumberOfDetectors);
}



///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::FillSpectra() {
  m_Spectra -> FillRawSpectra(m_EventData);
  m_Spectra -> FillPreTreatedSpectra(m_PreTreatedData);
  m_Spectra -> FillPhysicsSpectra(m_EventPhysics);
}



///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::CheckSpectra() {
  m_Spectra->CheckSpectra();
}



///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::ClearSpectra() {
  // To be done
}



///////////////////////////////////////////////////////////////////////////
map< string , TH1*> TbasicScintillatorPhysics::GetSpectra() {
  if(m_Spectra)
    return m_Spectra->GetMapHisto();
  else{
    map< string , TH1*> empty;
    return empty;
  }
}

///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::WriteSpectra() {
  m_Spectra->WriteSpectra();
}



///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::AddParameterToCalibrationManager() {
  CalibrationManager* Cal = CalibrationManager::getInstance();
  for (int i = 0; i < m_NumberOfDetectors; ++i) {
    Cal->AddParameter("basicScintillator", "D"+ NPL::itoa(i+1)+"_ENERGY","basicScintillator_D"+ NPL::itoa(i+1)+"_ENERGY");
    Cal->AddParameter("basicScintillator", "D"+ NPL::itoa(i+1)+"_TIME","basicScintillator_D"+ NPL::itoa(i+1)+"_TIME");

    for(int j = 0 ; j < 25 ; j++){ //loop on 25 strips for example
      Cal->AddParameter("basicScintillator", "D"+ NPL::itoa(i+1)+ "_STRIP"+ NPL::itoa(j+1)+"_ENERGY","basicScintillator_D"+ NPL::itoa(i+1)+"_STRIP"+ NPL::itoa(j+1)+"_ENERGY");   
      Cal->AddParameter("basicScintillator", "D"+ NPL::itoa(i+1)+ "_STRIP"+ NPL::itoa(j+1)+"_TIME","basicScintillator_D"+ NPL::itoa(i+1)+"_STRIP"+ NPL::itoa(j+1)+"_TIME");
    }
  }
}



///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::InitializeRootInputRaw() {
  TChain* inputChain = RootInput::getInstance()->GetChain();
  inputChain->SetBranchStatus("basicScintillator",  true );
  inputChain->SetBranchAddress("basicScintillator", &m_EventData );
}



///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::InitializeRootInputPhysics() {
  TChain* inputChain = RootInput::getInstance()->GetChain();
  inputChain->SetBranchAddress("basicScintillator", &m_EventPhysics);
}



///////////////////////////////////////////////////////////////////////////
void TbasicScintillatorPhysics::InitializeRootOutput() {
  TTree* outputTree = RootOutput::getInstance()->GetTree();
  outputTree->Branch("basicScintillator", "TbasicScintillatorPhysics", &m_EventPhysics);
}



////////////////////////////////////////////////////////////////////////////////
//            Construct Method to be pass to the DetectorFactory              //
////////////////////////////////////////////////////////////////////////////////
NPL::VDetector* TbasicScintillatorPhysics::Construct() {
  return (NPL::VDetector*) new TbasicScintillatorPhysics();
}



////////////////////////////////////////////////////////////////////////////////
//            Registering the construct method to the factory                 //
////////////////////////////////////////////////////////////////////////////////
extern "C"{
class proxy_basicScintillator{
  public:
    proxy_basicScintillator(){
      NPL::DetectorFactory::getInstance()->AddToken("basicScintillator","basicScintillator");
      NPL::DetectorFactory::getInstance()->AddDetector("basicScintillator",TbasicScintillatorPhysics::Construct);
    }
};

proxy_basicScintillator p_basicScintillator;
}

