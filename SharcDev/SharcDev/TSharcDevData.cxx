/*****************************************************************************
 * Copyright (C) 2009-2024   this file is part of the NPTool Project       *
 *                                                                           *
 * For the licensing terms see $NPTOOL/Licence/NPTool_Licence                *
 * For the list of contributors see $NPTOOL/Licence/Contributors             *
 *****************************************************************************/

/*****************************************************************************
 * Original Author: Guy Carter-Richardson  contact address: guy.carter-richardson@york.ac.uk                        *
 *                                                                           *
 * Creation Date  : December 2024                                           *
 * Last update    :                                                          *
 *---------------------------------------------------------------------------*
 * Decription:                                                               *
 *  This class hold SharcDev Raw data                                    *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Comment:                                                                  *
 *                                                                           *   
 *                                                                           *
 *****************************************************************************/
#include "TSharcDevData.h"

using namespace std; 

ClassImp(TSharcDevData)

TSharcDevData::TSharcDevData() {
}

TSharcDevData::~TSharcDevData() {
}

void TSharcDevData::Clear() {
	fSharcDev_StripFront_DetectorNbr.clear();
	fSharcDev_StripFront_StripNbr.clear();
	fSharcDev_StripFront_Energy.clear();
	fSharcDev_StripFront_TimeCFD.clear();
	fSharcDev_StripFront_TimeLED.clear();
	fSharcDev_StripFront_Time.clear();

	fSharcDev_StripBack_DetectorNbr.clear();
	fSharcDev_StripBack_StripNbr.clear();
	fSharcDev_StripBack_Energy.clear();
	fSharcDev_StripBack_TimeCFD.clear();
	fSharcDev_StripBack_TimeLED.clear();
	fSharcDev_StripBack_Time.clear();

	fSharcDev_PAD_DetectorNbr.clear();
	fSharcDev_PAD_Energy.clear();
	fSharcDev_PAD_TimeCFD.clear();
	fSharcDev_PAD_TimeLED.clear();
	fSharcDev_PAD_Time.clear();

  // Energy
  //fSharcDev_E_DetectorNbr.clear();
  //fSharcDev_Energy.clear();
  // Time
  //fSharcDev_T_DetectorNbr.clear();
  //fSharcDev_Time.clear();
}

void TSharcDevData::Dump() const {
	// Front
	cout << "SharcDev Strip Front Mult = " << fSharcDev_StripFront_DetectorNbr.size() << endl;
	for (UShort_t i = 0; i < fSharcDev_StripFront_DetectorNbr.size(); i++){
		cout << "DetNbr (Front): " << fSharcDev_StripFront_DetectorNbr[i]
		<< "   Strip: " << fSharcDev_StripFront_StripNbr[i]
		<< "   Energy: " << fSharcDev_StripFront_Energy[i]
		<< "   Time CFD: " << fSharcDev_StripFront_TimeCFD[i]
		<< "   Time LED: " << fSharcDev_StripFront_TimeLED[i] << endl;
	}
	
	// Back  
	cout << "SharcDev Strip Back Mult  = " << fSharcDev_StripBack_DetectorNbr.size() << endl;
	for (UShort_t i = 0; i < fSharcDev_StripBack_DetectorNbr.size(); i++){
		cout << "DetNbr (Back): " << fSharcDev_StripBack_DetectorNbr[i]
		<< "   Strip: " << fSharcDev_StripBack_StripNbr[i]
		<< "   Energy: " << fSharcDev_StripBack_Energy[i]
		<< "   Time CFD: " << fSharcDev_StripBack_TimeCFD[i]
		<< "   Time LED: " << fSharcDev_StripBack_TimeLED[i] << endl;
	}	

	// PAD
	cout << "SharcDev Strip PAD Mult  = " << fSharcDev_PAD_DetectorNbr.size() << endl;
	for (UShort_t i = 0; i < fSharcDev_PAD_DetectorNbr.size(); i++){
		cout << "DetNbr (PAD): " << fSharcDev_PAD_DetectorNbr[i]
		<< "   Energy: " << fSharcDev_PAD_Energy[i]
		<< "   Time CFD: " << fSharcDev_PAD_TimeCFD[i]
		<< "   Time LED: " << fSharcDev_PAD_TimeLED[i] << endl;
	}
	
  // This method is very useful for debuging and worth the dev.
  //cout << "XXXXXXXXXXXXXXXXXXXXXXXX New Event [TSharcDevData::Dump()] XXXXXXXXXXXXXXXXX" << endl;

  // Energy
  //size_t mysize = fSharcDev_E_DetectorNbr.size();
  //cout << "SharcDev_E_Mult: " << mysize << endl;
 
  //for (size_t i = 0 ; i < mysize ; i++){
  //  cout << "DetNbr: " << fSharcDev_E_DetectorNbr[i]
  //       << " Energy: " << fSharcDev_Energy[i];
  //}
  
  // Time
  //mysize = fSharcDev_T_DetectorNbr.size();
  //cout << "SharcDev_T_Mult: " << mysize << endl;
 
  //for (size_t i = 0 ; i < mysize ; i++){
  //  cout << "DetNbr: " << fSharcDev_T_DetectorNbr[i]
  //       << " Time: " << fSharcDev_Time[i];
  //}
}
