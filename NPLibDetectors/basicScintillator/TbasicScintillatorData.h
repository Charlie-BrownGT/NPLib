#ifndef __basicScintillatorDATA__
#define __basicScintillatorDATA__
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

// STL
#include <vector>
#include <sstream>
#include <cmath>
#include <limits>
#include <string>
#include <iostream>
using namespace std;

// ROOT
#include "TObject.h"

class TbasicScintillatorData : public TObject {
  //////////////////////////////////////////////////////////////
  // data members are hold into vectors in order 
  // to allow multiplicity treatment
  private: 
    // Energy
    vector<UShort_t>   fbasicScintillator_E_DetectorNbr;
    vector<UShort_t>   fbasicScintillator_E_StripNbr;
    vector<Double_t>   fbasicScintillator_Energy;

    // Time
    vector<UShort_t>   fbasicScintillator_T_DetectorNbr;
    vector<UShort_t>   fbasicScintillator_T_StripNbr;
    vector<Double_t>   fbasicScintillator_Time;

    // EventID
    vector<Int_t>      fbasicScintillator_EventID;

  //////////////////////////////////////////////////////////////
  // Constructor and destructor
  public: 
    TbasicScintillatorData();
    ~TbasicScintillatorData();
    

  //////////////////////////////////////////////////////////////
  // Inherited from TObject and overriden to avoid warnings
  public:
    void Clear();
    void Clear(const Option_t*) {};
    void Dump() const;


  //////////////////////////////////////////////////////////////
  // Getters and Setters
  // Prefer inline declaration to avoid unnecessary called of 
  // frequently used methods
  // add //! to avoid ROOT creating dictionnary for the methods
  public:
    //////////////////////    SETTERS    ////////////////////////
    // Original Energy Setters
    // Energy
    //inline void SetEnergy(const UShort_t& DetNbr,const Double_t& Energy){
      //fbasicScintillator_E_DetectorNbr.push_back(DetNbr);
      //fbasicScintillator_Energy.push_back(Energy);
    //};//!

    // Energy
    inline void SetE_DetectorNbr(const UShort_t& DetNbr)
      {fbasicScintillator_E_DetectorNbr.push_back(DetNbr);} //!
    inline void SetE_StripNbr(const UShort_t& StripNbr)
      {fbasicScintillator_E_DetectorNbr.push_back(StripNbr);} //!

    inline void Set_Energy(const Double_t& Energy)
      {fbasicScintillator_Energy.push_back(Energy);}//!

    inline void SetEnergy(const UShort_t& DetNbr,const Double_t& Energy){
      fbasicScintillator_E_DetectorNbr.push_back(DetNbr);
      fbasicScintillator_Energy.push_back(Energy);
    };//!

    // Prefer global setter so that all vectors have the same size
    inline void SetEnergy(const UShort_t& DetNbr,const UShort_t& StripNbr, const Double_t& Energy) {
      SetE_DetectorNbr(DetNbr);
      SetE_StripNbr(StripNbr);
      Set_Energy(Energy);
    };//!

    //Original Time Setters
    // Time
    //inline void SetTime(const UShort_t& DetNbr,const Double_t& Time)	{
      //fbasicScintillator_T_DetectorNbr.push_back(DetNbr);     
      //fbasicScintillator_Time.push_back(Time);
    //};//!

    // Time
    inline void SetT_DetectorNbr(const UShort_t& DetNbr)
      {fbasicScintillator_T_DetectorNbr.push_back(DetNbr);} //!
    inline void SetT_StripNbr(const UShort_t& StripNbr)
      {fbasicScintillator_T_StripNbr.push_back(StripNbr);} //!
    inline void Set_Time(const Double_t& Time)
      {fbasicScintillator_Time.push_back(Time);}//!

    // Prefer global setter so that all vectors have the same size
    inline void SetTime(const UShort_t& DetNbr, const UShort_t& StripNbr, const Double_t& Time)	{
      SetT_DetectorNbr(DetNbr);
      SetT_StripNbr(StripNbr);
      Set_Time(Time);
    };//!

    // EventID Setters
    inline void Set_EventID(const Int_t& EventID)   {fbasicScintillator_EventID.push_back(EventID);} //!
    inline void SetEventID(const Int_t& EventID)    {Set_EventID(EventID);} //!
    


    //////////////////////    GETTERS    ////////////////////////
    // Original Energy Getters
    // Energy
    //inline UShort_t GetMultEnergy() const
    //  {return fbasicScintillator_E_DetectorNbr.size();}
    //inline UShort_t GetE_DetectorNbr(const unsigned int &i) const 
    //  {return fbasicScintillator_E_DetectorNbr[i];}//!
    //inline Double_t Get_Energy(const unsigned int &i) const 
    //  {return fbasicScintillator_Energy[i];}//!

    // Energy
    inline UShort_t GetMultEnergy() const
      {return fbasicScintillator_E_DetectorNbr.size();}
    inline UShort_t GetE_DetectorNbr(const unsigned int &i) const 
      {return fbasicScintillator_E_DetectorNbr[i];}//!
    inline UShort_t GetE_StripNbr(const unsigned int &i) const 
      {return fbasicScintillator_E_StripNbr[i];}//!
    inline Double_t Get_Energy(const unsigned int &i) const 
      {return fbasicScintillator_Energy[i];}//!

    // Original Time Getters
    // Time
    //inline UShort_t GetMultTime() const
    //  {return fbasicScintillator_T_DetectorNbr.size();}
    //inline UShort_t GetT_DetectorNbr(const unsigned int &i) const 
    //  {return fbasicScintillator_T_DetectorNbr[i];}//!
    //inline Double_t Get_Time(const unsigned int &i) const 
    //  {return fbasicScintillator_Time[i];}//!

    // Time
    inline UShort_t GetMultTime() const
      {return fbasicScintillator_T_DetectorNbr.size();}
    inline UShort_t GetT_DetectorNbr(const unsigned int &i) const 
      {return fbasicScintillator_T_DetectorNbr[i];}//!
    inline UShort_t GetT_StripNbr(const unsigned int &i) const 
      {return fbasicScintillator_T_StripNbr[i];}//!
    inline Double_t Get_Time(const unsigned int &i) const 
      {return fbasicScintillator_Time[i];}//!

    // EventID
    inline Int_t Get_EventID(const unsigned int &i)//!
      {return fbasicScintillator_EventID[i];}//!

    inline Int_t GetEventID()//!
      {return fbasicScintillator_EventID.size();}//!
    

  //////////////////////////////////////////////////////////////
  // Required for ROOT dictionnary
  ClassDef(TbasicScintillatorData,1)  // basicScintillatorData structure
};

#endif
