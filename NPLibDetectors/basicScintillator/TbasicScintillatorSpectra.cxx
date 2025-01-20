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
 *  This class hold basicScintillator Spectra                                     *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Comment:                                                                  *
 *                                                                           *   
 *                                                                           *
 *****************************************************************************/

// class header 
#include "TbasicScintillatorSpectra.h"

// STL
#include <iostream>  
#include <string>
using namespace std;

// NPTool header
#include "NPOptionManager.h"



////////////////////////////////////////////////////////////////////////////////
TbasicScintillatorSpectra::TbasicScintillatorSpectra() 
   : fNumberOfDetectors(0) {
  SetName("basicScintillator");
}



////////////////////////////////////////////////////////////////////////////////
TbasicScintillatorSpectra::TbasicScintillatorSpectra(unsigned int NumberOfDetectors) {
  if(NPOptionManager::getInstance()->GetVerboseLevel()>0)
    cout << "************************************************" << endl
      << "TbasicScintillatorSpectra : Initalizing control spectra for " 
      << NumberOfDetectors << " Detectors" << endl
      << "************************************************" << endl ;
  SetName("basicScintillator");
  fNumberOfDetectors = NumberOfDetectors;

  InitRawSpectra();
  InitPreTreatedSpectra();
  InitPhysicsSpectra();
}



////////////////////////////////////////////////////////////////////////////////
TbasicScintillatorSpectra::~TbasicScintillatorSpectra() {
}



////////////////////////////////////////////////////////////////////////////////
void TbasicScintillatorSpectra::InitRawSpectra() {
  // Old Init Raw Spectra
  //static string name;
  //for (unsigned int i = 0; i < fNumberOfDetectors; i++) { // loop on number of detectors
    // Energy 
  //  name = "basicScintillator"+NPL::itoa(i+1)+"_ENERGY_RAW";
  //  AddHisto1D(name, name, 4096, 0, 16384, "basicScintillator/RAW");
    // Time 
  //  name = "basicScintillator"+NPL::itoa(i+1)+"_TIME_RAW";
  //  AddHisto1D(name, name, 4096, 0, 16384, "basicScintillator/RAW");
  //} // end loop on number of detectors

  static string name;
  for (unsigned int i = 0; i < fNumberOfDetectors; i++) { // loop on number of detectors
    for (unsigned int j = 0; j < fNumberOfStrips; j++) { // loop on number of stripss
       // Energy 
       name = "basicScintillator"+NPL::itoa(i+1)+"_ENERGY_RAW";
       AddHisto2D(name, name, fNumberOfStrips, 1, fNumberOfStrips, 4096, 0, 16384,"basicScintillator/RAW");
       // Time  
       name = "basicScintillator"+NPL::itoa(i+1)+"_TIME_RAW";
       AddHisto2D(name, name, fNumberOfStrips, 1, fNumberOfStrips, 4096, 0, 16384, "basicScintillator/RAW");
    } // end loop on number of detectors
  } // end loop on number of strips

  // Event ID
  name = "basicScintillator_ID";
  AddHisto1D(name, name, 4096, 0, 16384, "basicScintillator/RAW");
}



////////////////////////////////////////////////////////////////////////////////
void TbasicScintillatorSpectra::InitPreTreatedSpectra() {
  // Old Init Pretreated Spectra
  //static string name;
  //for (unsigned int i = 0; i < fNumberOfDetectors; i++) { // loop on number of detectors
    // Energy 
  //  name = "basicScintillator"+NPL::itoa(i+1)+"_ENERGY_CAL";
  //  AddHisto1D(name, name, 500, 0, 25, "basicScintillator/CAL");
    // Time
  //  name = "basicScintillator"+NPL::itoa(i+1)+"_TIME_CAL";
  //  AddHisto1D(name, name, 500, 0, 25, "basicScintillator/CAL");
  //}  // end loop on number of detectors

  static string name;
  for (unsigned int i = 0; i < fNumberOfDetectors; i++) { // loop on number of detectors
    for (unsigned int j = 0; j < fNumberOfStrips; j++) { // loop on number of stripss
    // Energy 
    name = "basicScintillator"+NPL::itoa(i+1)+"_ENERGY_CAL";
    AddHisto2D(name, name, fNumberOfStrips, 1, fNumberOfStrips, 4096, 0, 25,"basicScintillator/CAL");
    // Time  
    name = "basicScintillator"+NPL::itoa(i+1)+"_TIME_CAL";
    AddHisto2D(name, name, fNumberOfStrips, 1, fNumberOfStrips, 4096, 0, 50, "basicScintillator/CAL");
    } // end loop on number of detectors
  } // end loop on number of strips

  // Event ID
  name = "basicScintillator_ID";
  AddHisto1D(name, name, 4096, 0, 16384, "basicScintillator/CAL");
}



////////////////////////////////////////////////////////////////////////////////
void TbasicScintillatorSpectra::InitPhysicsSpectra() {
  static string name;
  // Kinematic Plot 
  name = "basicScintillator_ENERGY_TIME";
  AddHisto2D(name, name, 500, 0, 500, 500, 0, 50, "basicScintillator/PHY");

  // Kinematic Plot 
  name = "basicScintillator_ID";
  AddHisto1D(name, name, 4096, 0, 16384, "basicScintillator/PHY");
}



////////////////////////////////////////////////////////////////////////////////
void TbasicScintillatorSpectra::FillRawSpectra(TbasicScintillatorData* RawData) {
  static string name;
  static string family;

  // Energy 
  unsigned int sizeE = RawData->GetMultEnergy();
  for (unsigned int i = 0; i < sizeE; i++) {
    name = "basicScintillator"+NPL::itoa(RawData->GetE_DetectorNbr(i))+"_ENERGY_RAW";
    family = "basicScintillator/RAW";

    //Old Fill Energy Spectra
    //FillSpectra(family,name,RawData->Get_Energy(i));
    //FillSpectra(family,name) -> Fill(RawData->GetE_StripNbr(i), RawData->Get_Energy(i));
    FillSpectra(family,name,RawData->GetE_StripNbr(i),RawData->Get_Energy(i));
  }

  // Time
  unsigned int sizeT = RawData->GetMultTime();
  for (unsigned int i = 0; i < sizeT; i++) {
    name = "basicScintillator"+NPL::itoa(RawData->GetT_DetectorNbr(i))+"_TIME_RAW";
    family = "basicScintillator/RAW";

    //Old Fill Time Spectra
    //FillSpectra(family,name,RawData->Get_Time(i));
    FillSpectra(family,name,RawData->GetT_StripNbr(i),RawData->Get_Time(i));
  }

  //EventID
  unsigned int sizeID = RawData->GetEventID();
  for (unsigned int i = 0; i < sizeID; i++){
    name = "basicScintillator_ID_RAW";
    FillSpectra(family,name,RawData->Get_EventID(i));
  }
}



////////////////////////////////////////////////////////////////////////////////
void TbasicScintillatorSpectra::FillPreTreatedSpectra(TbasicScintillatorData* PreTreatedData) {
  static string name;
  static string family;
  
  // Energy 
  unsigned int sizeE = PreTreatedData->GetMultEnergy();
  for (unsigned int i = 0; i < sizeE; i++) {
    name = "basicScintillator"+NPL::itoa(PreTreatedData->GetE_DetectorNbr(i))+"_ENERGY_CAL";
    family = "basicScintillator/CAL";

    //Old Fill Pretreated Energy
    //FillSpectra(family,name,PreTreatedData->Get_Energy(i));
    //FillSpectra(family,name) -> Fill(PreTreatedData->GetE_StripNbr(i), PreTreatedData->Get_Energy(i));
    FillSpectra(family,name,PreTreatedData->GetE_StripNbr(i),PreTreatedData->Get_Energy(i));
  }

  // Time
  unsigned int sizeT = PreTreatedData->GetMultTime();
  for (unsigned int i = 0; i < sizeT; i++) {
    name = "basicScintillator"+NPL::itoa(PreTreatedData->GetT_DetectorNbr(i))+"_TIME_CAL";
    family = "basicScintillator/CAL";

    //Old Fill Pretreated Time
    //FillSpectra(family,name,PreTreatedData->Get_Time(i));
    //FillSpectra(family,name) -> Fill(PreTreatedData->GetT_StripNbr(i), PreTreatedData->Get_Time(i));
    FillSpectra(family,name,PreTreatedData->GetT_StripNbr(i),PreTreatedData->Get_Time(i));
  }

  //EventID
  unsigned int sizeID = PreTreatedData->GetEventID();
  for (unsigned int i = 0; i < sizeID; i++){
    name = "basicScintillator_ID_CAL";
    FillSpectra(family,name,PreTreatedData->Get_EventID(i));
  }
}



////////////////////////////////////////////////////////////////////////////////
void TbasicScintillatorSpectra::FillPhysicsSpectra(TbasicScintillatorPhysics* Physics) {
  static string name;
  static string family;
  family= "basicScintillator/PHY";

  // Energy vs time
  unsigned int sizeE = Physics->Energy.size();
  for(unsigned int i = 0 ; i < sizeE ; i++){
    name = "basicScintillator_ENERGY_TIME";
    FillSpectra(family,name,Physics->Energy[i],Physics->Time[i]);
  }

  //EventID
  unsigned int sizeID = Physics->EventID.size();
  for (unsigned int i = 0; i < sizeID; i++){
    name = "basicScintillator_ID_PHY";
    FillSpectra(family,name,Physics->EventID[i]);
  }
}

