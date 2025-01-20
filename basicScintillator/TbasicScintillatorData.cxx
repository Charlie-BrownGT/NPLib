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
 *  This class hold basicScintillator Raw data                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Comment:                                                                  *
 *                                                                           *   
 *                                                                           *
 *****************************************************************************/
#include "TbasicScintillatorData.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std; 

ClassImp(TbasicScintillatorData)


//////////////////////////////////////////////////////////////////////
TbasicScintillatorData::TbasicScintillatorData() {
  //long unsigned int size = fbasicScintillator_EventID.size();
  //cout << "Size : " << size << endl;
}



//////////////////////////////////////////////////////////////////////
TbasicScintillatorData::~TbasicScintillatorData() {
}



//////////////////////////////////////////////////////////////////////
void TbasicScintillatorData::Clear() {
  // Original Energy Clear
  // Energy
  //fbasicScintillator_E_DetectorNbr.clear();
  //fbasicScintillator_Energy.clear();

  // Energy
  fbasicScintillator_E_DetectorNbr.clear();
  fbasicScintillator_E_StripNbr.clear();
  fbasicScintillator_Energy.clear();

  // Original Time Clear
  // Time
  //fbasicScintillator_T_DetectorNbr.clear();
  //fbasicScintillator_Time.clear();

  // Time
  fbasicScintillator_T_DetectorNbr.clear();
  fbasicScintillator_T_StripNbr.clear();
  fbasicScintillator_Time.clear();

  //EventID
  fbasicScintillator_EventID.clear();
}



//////////////////////////////////////////////////////////////////////
void TbasicScintillatorData::Dump() const {
  // This method is very useful for debuging and worth the dev.
  cout << "XXXXXXXXXXXXXXXXXXXXXXXX New Event [TbasicScintillatorData::Dump()] XXXXXXXXXXXXXXXXX" << endl;

  // Energy
  size_t mysize = fbasicScintillator_E_DetectorNbr.size();
  cout << "basicScintillator_E_Mult: " << mysize << endl;
 
  for (size_t i = 0 ; i < mysize ; i++){
    cout << "DetNbr: " << fbasicScintillator_E_DetectorNbr[i]
         << " Energy: " << fbasicScintillator_Energy[i];
  }
  
  // Time
  mysize = fbasicScintillator_T_DetectorNbr.size();
  cout << "basicScintillator_T_Mult: " << mysize << endl;
 
  for (size_t i = 0 ; i < mysize ; i++){
    cout << "DetNbr: " << fbasicScintillator_T_DetectorNbr[i]
         << " Time: " << fbasicScintillator_Time[i];
  }

  // EventID
  mysize = fbasicScintillator_EventID.size();
  cout << "fbasicScintillator_EventID: " << mysize << endl;
 
  for (size_t i = 0 ; i < mysize ; i++){
    cout << "EventID: " << fbasicScintillator_EventID[i];
  }
}
