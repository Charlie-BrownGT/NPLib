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
 *  This class hold SharcDev Spectra                                     *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Comment:                                                                  *
 *                                                                           *   
 *                                                                           *
 *****************************************************************************/

#include "TSharcDevSpectra.h"

#ifdef NP_SYSTEM_OF_UNITS_H
  using namespace NPUNITS;
#endif

using namespace std;

TSharcDevSpectra::TSharcDevSpectra(){
  SetName("SharcDev");
  fNumberOfDetector = 0;
  fStripFront=24;
  fStripBack=48;
}

TSharcDevSpectra::TSharcDevSpectra(unsigned int NumberOfDetector) {
  if(NPOptionManager::getInstance()->GetVerboseLevel()>0)
    cout << "************************************************" << endl
      << "TSharcDevSpectra : Initalizing control spectra for " 
      << NumberOfDetector << " Detectors" << endl
      << "************************************************" << endl ;
  SetName("SharcDev");
  fNumberOfDetector = NumberOfDetector;
  fStripFront=24;
  fStripBack=48;

  InitRawSpectra();
  InitPreTreatedSpectra();
  InitPhysicsSpectra();
}

TSharcDevSpectra::~TSharcDevSpectra() {
}

void TSharcDevSpectra::InitRawSpectra() {
  static string name;
  
  for (unsigned int i = 0; i < fNumberOfDetector; i++) {
	name = "SharcDevRaw"+NPL::itoa(i+1);
	// STR_FRONT_E_RAW
	name = "SHARCDEV"+NPL::itoa(i+1)+"_STR_FRONT_E_RAW";
	AddHisto2D(name, name, fStripFront, 1, fStripFront+1, 5000, 0, 1.5e6, "SHARCDEV/RAW/STR_FRONT_E")->Draw("colz");

	// STR_BACK_E_RAW
	name = "SHARCDEV"+NPL::itoa(i+1)+"_STR_BACK_E_RAW";
	AddHisto2D(name, name, fStripBack, 1, fStripBack+1, 5000, 0, 1.5e6, "SHARCDEV/RAW/STR_BACK_E")->Draw("colz");

	// STR_FRONT_EMAX_RAW
	name = "SHARCDEV"+NPL::itoa(i+1)+"_STR_FRONT_EMAX_RAW";
	AddHisto2D(name, name, fStripFront, 1, fStripFront+1, 5000, 0, 1.5e6, "SHARCDEV/RAW/STR_FRONT_EMAX");

	// STR_BACK_EMAX_Raw
	name = "SHARCDEV"+NPL::itoa(i+1)+"_STR_BACK_EMAX_RAW";
	AddHisto2D(name, name, fStripBack, 1, fStripBack+1, 5000, 0, 1.5e6, "SHARCDEV/RAW/STR_BACK_EMAX");

	// PAD_E_RAW
	name = "SHARCDEV"+NPL::itoa(i+1)+"_PAD_E_RAW";
	AddHisto1D(name, name, 500, 0, 2500, "SHARCDEV/RAW/PAD_E")->Draw("");

	// STR_FRONT_RAW_MULT
	name = "SHARCDEV"+NPL::itoa(i+1)+"_STR_FRONT_RAW_MULT";
	AddHisto1D(name, name, fStripFront, 1, fStripFront+1, "SHARCDEV/RAW/MULT")->Draw("");
	gPad->SetLogy();

	// STR_BACK_RAW_MULT
	name = "SHARCDEV"+NPL::itoa(i+1)+"_STR_BACK_RAW_MULT";
	AddHisto1D(name, name, fStripFront, 1, fStripFront+1, "SHARCDEV/RAW/MULT")->Draw("");
	gPad->SetLogy();

	// PAD_RAW_MULT
	name = "SHARCDEV"+NPL::itoa(i+1)+"_PAD_RAW_MULT";
	AddHisto1D(name, name, fNumberOfDetector, 1, fNumberOfDetector+1, "SHARCDEV/RAW/MULT")->Draw("");
	gPad->SetLogy();

	} // end loop on number of detectors

	// STR_PAD_DetN_MAP : useful for mapping issue
	name = "SHARCDEV_STR_PAD_DetN_RAW";
	AddHisto2D(name, name, fNumberOfDetector, 1, fNumberOfDetector+1, fNumberOfDetector, 1, fNumberOfDetector+1, "SHARCDEV/RAW/MAP")->Draw("colz");

}

void TSharcDevSpectra::InitPreTreatedSpectra(){
  static string name;
  for (unsigned int i = 0; i < fNumberOfDetector; i++) { // loop on number of detectors
    // STR_FRONT_E_CAL
    name = "SHARCDEV"+NPL::itoa(i+1)+"_STR_FRONT_E_CAL";
    AddHisto2D(name, name, fStripFront, 1, fStripFront+1, 500, 0, 25, "SHARCDEV/CAL/STR_FRONT_E");

    // STR_BACK_E_CAL
    name = "SHARCDEV"+NPL::itoa(i+1)+"_STR_BACK_E_CAL";
    AddHisto2D(name, name, fStripBack, 1, fStripBack+1, 500, 0, 25, "SHARCDEV/CAL/STR_BACK_E");

    // PAD_E_CAL
    name = "SHARCDEV"+NPL::itoa(i+1)+"_PAD_E_CAL";
    AddHisto1D(name, name, 100, 0, 50, "SHARCDEV/CAL/PAD_E");

    // STR_FRONT_CAL_MULT
    name = "SHARCDEV"+NPL::itoa(i+1)+"_STR_FRONT_CAL_MULT";
    AddHisto1D(name, name, fStripFront, 1, fStripFront+1, "SHARCDEV/CAL/MULT");

    // STR_BACK_CAL_MULT
    name = "SHARCDEV"+NPL::itoa(i+1)+"_STR_BACK_CAL_MULT";
    AddHisto1D(name, name, fStripFront, 1, fStripFront+1, "SHARCDEV/CAL/MULT");

    // PAD_CAL_MULT
    name = "SHARCDEV"+NPL::itoa(i+1)+"_PAD_CAL_MULT";
    AddHisto1D(name, name, fNumberOfDetector, 1, fNumberOfDetector+1, "SHARCDEV/CAL/MULT");

    // PAD_CAL_ID 
    name = "SHARCDEV"+NPL::itoa(i+1)+"_PAD_CAL_ID";
    AddHisto2D(name, name,100,0,50,500,0,50, "SHARCDEV/CAL/ID");

    // Front-Back Energy Correlation
      name = "SHARCDEV"+NPL::itoa(i+1)+"_FB_COR";
      AddHisto2D(name, name,500,0,25,500,0,25, "SHARCDEV/CAL/FB"); 

  }  // end loop on number of detectors

  // STR_PAD_DetN_MAP : useful for mapping issue
  name = "SHARCDEV_STR_PAD_DetN_CAL";
  AddHisto2D(name, name, fNumberOfDetector, 1, fNumberOfDetector+1, fNumberOfDetector, 1, fNumberOfDetector+1, "SHARCDEV/CAL/MAP")->Draw("colz");

}

void TSharcDevSpectra::InitPhysicsSpectra(){
  static string name;
  // Kinematic Plot 
  name = "SHARCDEV_THETA_E";
  AddHisto2D(name, name,360,0,180,500,0,50,"SHARCDEV/PHY");

  // ID Plot
  // PAD-DE:
  name = "SHARCDEV_PAD_E_E";
  AddHisto1D(name, name,500,0,25,"SHARCDEV/PHY");

  for (unsigned int i = 0; i < fNumberOfDetector; i++) { // loop on number of detectors
    // PAD-DE:
    name = "SHARCDEV"+NPL::itoa(i+1)+"_PAD_E_E";
    AddHisto2D(name, name,100,0,100,500,0,25,"SHARCDEV/PHY");
  }
}

void TSharcDevSpectra::FillRawSpectra(TSharcDevData* RawData){
  static string index;
  static string name;

  // STR_FRONT_E 
  unsigned int mysize = RawData->GetMultiplicityFront();
  double EFMAX = 0 ;
  int SFMAX = 0;
  int DFMAX = 0 ;
  for (unsigned int i = 0; i < mysize; i++) {
    index = "SHARCDEV/RAW/STR_FRONT_E/SHARCDEV"+NPL::itoa(RawData->GetFront_DetectorNbr(i))+"_STR_FRONT_E_RAW";
    if(RawData->GetFront_Energy(i) > EFMAX){
      EFMAX = RawData->GetFront_Energy(i);
      SFMAX = RawData->GetFront_StripNbr(i);
      DFMAX = RawData->GetFront_DetectorNbr(i);
    }
    
    FillSpectra(index
      ,RawData->GetFront_StripNbr(i), 
          RawData->GetFront_Energy(i));
  }
 
  if(DFMAX!=0){
    index = "SHARCDEV/RAW/STR_FRONT_EMAX/SHARCDEV"+NPL::itoa(DFMAX)+"_STR_FRONT_EMAX_RAW";
    FillSpectra(index,SFMAX, EFMAX);
  }
 
  // STR_BACK_E
  mysize = RawData->GetMultiplicityBack();
  double EBMAX = 0 ;
  int SBMAX = 0;
  int DBMAX = 0 ;
 
  for (unsigned int i = 0; i < mysize; i++) {
     index = "SHARCDEV/RAW/STR_BACK_E/SHARCDEV"+NPL::itoa( RawData->GetBack_DetectorNbr(i) )+"_STR_BACK_E_RAW";
    if(RawData->GetBack_Energy(i) > EBMAX){
      EBMAX = RawData->GetBack_Energy(i);
      SBMAX = RawData->GetBack_StripNbr(i);
      DBMAX = RawData->GetBack_DetectorNbr(i);
    }
   
    FillSpectra(index
      ,RawData->GetBack_StripNbr(i),
          RawData->GetBack_Energy(i));
  }
 
  if(DBMAX!=0){
    index = "SHARCDEV/RAW/STR_BACK_EMAX/SHARCDEV"+NPL::itoa(DBMAX)+"_STR_BACK_EMAX_RAW";
    FillSpectra(index,SBMAX, EBMAX);
  }

  // PAD_E
  mysize = RawData->GetMultiplicityPAD();
  for (unsigned int i = 0; i < mysize; i++) {
    index = "SHARCDEV/RAW/PAD_E/SHARCDEV"+NPL::itoa(RawData->GetPAD_DetectorNbr(i))+"_PAD_E_RAW";

    FillSpectra(index
      ,RawData->GetPAD_Energy(i));
  }

  // STR_FRONT MULT
  int myMULT[fNumberOfDetector];
  for( unsigned int i = 0; i < fNumberOfDetector; i++)
    myMULT[i] = 0 ; 

  for(unsigned int i = 0 ; i < RawData->GetMultiplicityFront();i++){
    myMULT[RawData->GetFront_DetectorNbr(i)-1] += 1;  
  }

  for( unsigned int i = 0; i < fNumberOfDetector; i++){
    index = "SHARCDEV/RAW/MULT/SHARCDEV"+NPL::itoa(i+1)+"_STR_FRONT_RAW_MULT";
    FillSpectra(index
      ,myMULT[i]);
  }

  // STR_BACK MULT
  for( unsigned int i = 0; i < fNumberOfDetector; i++)
    myMULT[i] = 0 ; 

  mysize = RawData->GetMultiplicityBack();
  for(unsigned int i = 0 ; i < mysize;i++){
    myMULT[RawData->GetBack_DetectorNbr(i)-1] += 1;  
  }

  for( unsigned int i = 0; i < fNumberOfDetector; i++){
    index= "SHARCDEV/RAW/MULT/SHARCDEV"+NPL::itoa(i+1)+"_STR_BACK_RAW_MULT";
    
    FillSpectra(index
      ,myMULT[i]);
  }

  // PAD MULT
  for( unsigned int i = 0; i < fNumberOfDetector; i++)
    myMULT[i] = 0 ; 
  mysize = RawData->GetMultiplicityPAD();
  for(unsigned int i = 0 ; i < mysize ;i++){
    myMULT[RawData->GetPAD_DetectorNbr(i)-1] += 1;  
  }

  for( unsigned int i = 0; i < fNumberOfDetector; i++){
  index="SHARCDEV/RAW/MULT/SHARCDEV"+NPL::itoa(i+1)+"_PAD_RAW_MULT";
    FillSpectra(index
      ,myMULT[i]);
  }

  //DSSD-PAD Ndet Map 
  mysize = RawData->GetMultiplicityFront();
  unsigned int mysizePAD = RawData->GetMultiplicityPAD();
  for (unsigned int i = 0; i < mysize ; i++) {
    for (unsigned int j = 0; j < mysizePAD; j++) {
        index = "SHARCDEV/RAW/MAP";
        name = "SHARCDEV_STR_PAD_DetN_RAW";
        FillSpectra(index,name
          ,RawData->GetFront_DetectorNbr(i), 
              RawData->GetPAD_DetectorNbr(i));
    }
  }

}

void TSharcDevSpectra::FillPreTreatedSpectra(TSharcDevData* PreTreatedData){
  static string index;
  static string name;

  // Front-Back
  unsigned int mysizeF = PreTreatedData->GetMultiplicityFront();
  unsigned int mysizeB = PreTreatedData->GetMultiplicityBack();
  unsigned int mysizePAD = PreTreatedData->GetMultiplicityPAD(); 

  for (unsigned int i = 0; i < mysizeF; i++) {
    for (unsigned int j = 0; j < mysizeB; j++) {
      if(PreTreatedData->GetFront_DetectorNbr(i)==PreTreatedData->GetBack_DetectorNbr(j)){
        index="SHARCDEV/CAL/FB/";
        name="SHARCDEV"+NPL::itoa(PreTreatedData->GetFront_DetectorNbr(i))+"_FB_COR";

      FillSpectra(index, name
        ,PreTreatedData->GetFront_Energy(i),
                PreTreatedData->GetBack_Energy(j) );
      }
    }
  } 

  // STR_FRONT_E
  unsigned int mysize = PreTreatedData->GetMultiplicityFront();
  for (unsigned int i = 0; i < mysize; i++) {
    index = "SHARCDEV/CAL/STR_FRONT_E";
    name="SHARCDEV"+NPL::itoa(PreTreatedData->GetFront_DetectorNbr(i))+"_STR_FRONT_E_CAL";

    FillSpectra(index,name
      ,PreTreatedData->GetFront_StripNbr(i), 
          PreTreatedData->GetFront_Energy(i));
  }
  // STR_BACK_E
  mysize = PreTreatedData->GetMultiplicityBack();
  for (unsigned int i = 0; i < mysize; i++) {
   index = "SHARCDEV/CAL/STR_BACK_E";
   string name = "SHARCDEV"+NPL::itoa( PreTreatedData->GetBack_DetectorNbr(i))+"_STR_BACK_E_CAL";

    FillSpectra(index,name
      ,PreTreatedData->GetBack_StripNbr(i), 
          PreTreatedData->GetBack_Energy(i));
  }
  // PAD_E
  mysize = PreTreatedData->GetMultiplicityPAD();
  for (unsigned int i = 0; i < mysize ; i++) {
    index= "SHARCDEV/CAL/PAD_E";
    name="SHARCDEV"+NPL::itoa(PreTreatedData->GetPAD_DetectorNbr(i))+"_PAD_E_CAL";

    FillSpectra(index,name
      ,PreTreatedData->GetPAD_Energy(i));
  }

  // STR_FRONT MULT
  int myMULT[fNumberOfDetector];
  for( unsigned int i = 0; i < fNumberOfDetector; i++)
    myMULT[i] = 0 ; 

  mysize = PreTreatedData->GetMultiplicityFront(); 
  for(unsigned int i = 0 ; i < mysize ;i++){
    myMULT[PreTreatedData->GetFront_DetectorNbr(i)-1] += 1;  
  }

  for( unsigned int i = 0; i < fNumberOfDetector; i++){
    index= "SHARCDEV/CAL/MULT";
    name= "SHARCDEV"+NPL::itoa(i+1)+"_STR_FRONT_CAL_MULT";
    FillSpectra(index,name,myMULT[i]);
  }

  // STR_BACK MULT
  for( unsigned int i = 0; i < fNumberOfDetector; i++)
    myMULT[i] = 0 ; 

  mysize = PreTreatedData->GetMultiplicityBack();
  for(unsigned int i = 0 ; i < mysize ;i++){
    myMULT[PreTreatedData->GetBack_DetectorNbr(i)-1] += 1;  
  }

  for( unsigned int i = 0; i < fNumberOfDetector; i++){
    index= "SHARCDEV/CAL/MULT";
    name = "SHARCDEV"+NPL::itoa(i+1)+"_STR_BACK_CAL_MULT";
    FillSpectra(index,name
      ,myMULT[i]);
  }

  // PAD MULT
  for( unsigned int i = 0; i < fNumberOfDetector; i++)
    myMULT[i] = 0 ; 

  mysize =  PreTreatedData->GetMultiplicityPAD();
  for(unsigned int i = 0 ; i < mysize ;i++){
    myMULT[PreTreatedData->GetPAD_DetectorNbr(i)-1] += 1;  
  }

  for( unsigned int i = 0; i < fNumberOfDetector; i++){
    index = "SHARCDEV/CAL/MULT/";
    name="SHARCDEV"+NPL::itoa(i+1)+"_PAD_CAL_MULT";
    FillSpectra(index,name
      ,myMULT[i]);
  }

  //E-PAD ID
  mysize = PreTreatedData->GetMultiplicityFront();
  mysizePAD = PreTreatedData->GetMultiplicityPAD();
  for (unsigned int i = 0; i < mysize ; i++) {
    for (unsigned int j = 0; j < mysizePAD; j++) {

      if(PreTreatedData->GetFront_DetectorNbr(i) == PreTreatedData->GetPAD_DetectorNbr(j)){ 
        index = "SHARCDEV/CAL/ID";
        
        name = "SHARCDEV"+NPL::itoa(PreTreatedData->GetFront_DetectorNbr(i))+"_PAD_CAL_ID";

        FillSpectra(index,name
          ,PreTreatedData->GetPAD_Energy(j), 
              PreTreatedData->GetFront_Energy(i));
      }
    }
  }

  //DSSD-PAD Ndet Map 
  mysize = PreTreatedData->GetMultiplicityFront();
  mysizePAD = PreTreatedData->GetMultiplicityPAD();
  for (unsigned int i = 0; i < mysize ; i++) {
    for (unsigned int j = 0; j < mysizePAD; j++) {
        index = "SHARCDEV/CAL/MAP";
        name = "SHARCDEV_STR_PAD_DetN_CAL";
        FillSpectra(index,name
          ,PreTreatedData->GetFront_DetectorNbr(i), 
              PreTreatedData->GetPAD_DetectorNbr(i));
    }
  }

}

void TSharcDevSpectra::FillPhysicsSpectra(TSharcDevPhysics* Physics){
  static string index="SHARCDEV/PHY";
  static string name;
  // Kine plot
  unsigned int mysize = Physics->Strip_E.size();
  for(unsigned int i = 0 ; i < mysize ; i++){
    double Theta = Physics->GetPositionOfInteraction(i).Angle(TVector3(0,0,1));
    Theta = Theta/deg;
    double Etot=Physics->Strip_E[i];

    if(Physics->PAD_E[i]>0){
      name = "SHARCDEV_PAD_E_E"; 
      Etot += Physics->PAD_E[i];
      FillSpectra(index,name,Physics->PAD_E[i],Physics->Strip_E[i]);
      name = "SHARCDEV"+NPL::itoa(Physics->DetectorNumber[i])+"_PAD_E_E";
      FillSpectra(index,name,Physics->PAD_E[i],Physics->Strip_E[i]);

    }
    name = "SHARCDEV_THETA_E";
    FillSpectra(index,name,Theta,Etot);
  }
}