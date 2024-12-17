#ifndef __SharcDevDATA__
#define __SharcDevDATA__
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

// STL
#include <vector>
using namespace std;

// ROOT
#include "TObject.h"
#include "TNamed.h"

// C++ headers
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class TSharcDevData : public TObject {
  // data members are hold into vectors in order 
  // to allow multiplicity treatment
  private: 
    // Energy
    vector<UShort_t>   fSharcDev_StripFront_DetectorNbr;
	vector<UShort_t>   fSharcDev_StripFront_StripNbr;
	vector<Double_t>   fSharcDev_StripFront_Energy;
	vector<Double_t>   fSharcDev_StripFront_TimeCFD;
	vector<Double_t>   fSharcDev_StripFront_TimeLED;
	vector<Double_t>   fSharcDev_StripFront_Time;
	
	vector<UShort_t>   fSharcDev_StripBack_DetectorNbr;
	vector<UShort_t>   fSharcDev_StripBack_StripNbr;
	vector<Double_t>   fSharcDev_StripBack_Energy;
	vector<Double_t>   fSharcDev_StripBack_TimeCFD;
	vector<Double_t>   fSharcDev_StripBack_TimeLED;
	vector<Double_t>   fSharcDev_StripBack_Time;
	
	vector<UShort_t>   fSharcDev_PAD_DetectorNbr;
	vector<Double_t>   fSharcDev_PAD_Energy;
	vector<Double_t>   fSharcDev_PAD_TimeCFD;
	vector<Double_t>   fSharcDev_PAD_TimeLED;
	vector<Double_t>   fSharcDev_PAD_Time;

    // Time
    //vector<UShort_t>   fSharcDev_T_DetectorNbr;
    //vector<Double_t>   fSharcDev_Time;

  // Constructor and destructor
  public: 
    TSharcDevData();
    ~TSharcDevData();
    
  // Inherited from TObject and overriden to avoid warnings
  public:
    void Clear();
    void Clear(const Option_t*) {};
    void Dump() const;

  // Getters and Setters
  // Prefer inline declaration to avoid unnecessary called of 
  // frequently used methods
  // add //! to avoid ROOT creating dictionnary for the methods

  public:
    //////////////////////    SETTERS    ////////////////////////
    // Energy
	inline void SetFront_DetectorNbr(const UShort_t& DetNbr)  {fSharcDev_StripFront_DetectorNbr.push_back(DetNbr);}
	inline void SetFront_StripNbr(const UShort_t& StripNbr)   {fSharcDev_StripFront_StripNbr.push_back(StripNbr);}
	inline void SetFront_Energy(const Double_t& Energy)       {fSharcDev_StripFront_Energy.push_back(Energy);}
	inline void SetFront_TimeCFD(const Double_t& TimeCFD)     {fSharcDev_StripFront_TimeCFD.push_back(TimeCFD);}
	inline void SetFront_TimeLED(const Double_t& TimeLED)     {fSharcDev_StripFront_TimeLED.push_back(TimeLED);}
	inline void SetFront_Time(const Double_t& Time)           {fSharcDev_StripFront_Time.push_back(Time);}
    
	inline void SetBack_DetectorNbr(const UShort_t& DetNbr)   {fSharcDev_StripBack_DetectorNbr.push_back(DetNbr);}
	inline void SetBack_StripNbr(const UShort_t& StripNbr)    {fSharcDev_StripBack_StripNbr.push_back(StripNbr);}
	inline void SetBack_Energy(const Double_t& Energy)        {fSharcDev_StripBack_Energy.push_back(Energy);}
	inline void SetBack_TimeCFD(const Double_t& TimeCFD)      {fSharcDev_StripBack_TimeCFD.push_back(TimeCFD);}
	inline void SetBack_TimeLED(const Double_t& TimeLED)      {fSharcDev_StripBack_TimeLED.push_back(TimeLED);}
	inline void SetBack_Time(const Double_t& Time)            {fSharcDev_StripBack_Time.push_back(Time);}
	
	inline void SetPAD_DetectorNbr(const UShort_t& DetNbr)    {fSharcDev_PAD_DetectorNbr.push_back(DetNbr);}
	inline void SetPAD_Energy(const Double_t& Energy)         {fSharcDev_PAD_Energy.push_back(Energy);}
	inline void SetPAD_TimeCFD(const Double_t& TimeCFD)       {fSharcDev_PAD_TimeCFD.push_back(TimeCFD);}
	inline void SetPAD_TimeLED(const Double_t& TimeLED)       {fSharcDev_PAD_TimeLED.push_back(TimeLED);}
	inline void SetPAD_Time(const Double_t& Time)             {fSharcDev_PAD_Time.push_back(Time);}
	
	inline void SetFront(const UShort_t& DetNbr,const UShort_t& StripNbr,const Double_t& Energy,const Double_t& TimeCFD,const Double_t& TimeLED,const Double_t& Time = 0){
		SetFront_DetectorNbr(DetNbr);
		SetFront_StripNbr(StripNbr);
		SetFront_Energy(Energy);
		SetFront_TimeCFD(TimeCFD);
		SetFront_TimeLED(TimeLED);
		SetFront_Time(Time);
	};
	inline void SetBack(const UShort_t &DetNbr,const UShort_t &StripNbr,const Double_t &Energy,const Double_t &TimeCFD,const Double_t &TimeLED,const Double_t &Time = 0){
		SetBack_DetectorNbr(DetNbr);
		SetBack_StripNbr(StripNbr);
		SetBack_Energy(Energy);
		SetBack_TimeCFD(TimeCFD);
		SetBack_TimeLED(TimeLED);
		SetBack_Time(Time);
	};
	inline void SetPAD(const UShort_t &DetNbr,const Double_t &Energy,const Double_t &TimeCFD,const Double_t &TimeLED,const Double_t &Time = 0){
		SetPAD_DetectorNbr(DetNbr);
		SetPAD_Energy(Energy);
		SetPAD_TimeCFD(TimeCFD);
		SetPAD_TimeLED(TimeLED);
		SetPAD_Time(Time);
	};

    //inline void SetEnergy(const UShort_t& DetNbr,const Double_t& Energy){
    //  fSharcDev_E_DetectorNbr.push_back(DetNbr);
    //  fSharcDev_Energy.push_back(Energy);
    //};//!

    // Time
    //inline void SetTime(const UShort_t& DetNbr,const Double_t& Time)	{
    //  fSharcDev_T_DetectorNbr.push_back(DetNbr);     
    //  fSharcDev_Time.push_back(Time);
    //};//!

    //////////////////////    GETTERS    ////////////////////////
    // Energy
	inline UShort_t GetFront_DetectorNbr(const unsigned int &i) const {return fSharcDev_StripFront_DetectorNbr[i];}//!
	inline UShort_t GetFront_StripNbr(const unsigned int &i)    const {return fSharcDev_StripFront_StripNbr[i];}//!
	inline Double_t GetFront_Energy(const unsigned int &i)      const {return fSharcDev_StripFront_Energy[i];}//!
	inline Double_t GetFront_TimeCFD(const unsigned int &i)     const {return fSharcDev_StripFront_TimeCFD[i];}//!
	inline Double_t GetFront_TimeLED(const unsigned int &i)     const {return fSharcDev_StripFront_TimeLED[i];}//!
	inline Double_t GetFront_Time(const unsigned int &i)        const {return fSharcDev_StripFront_Time[i];}//!
    
	inline UShort_t GetBack_DetectorNbr(const unsigned int &i) const {return fSharcDev_StripBack_DetectorNbr[i];}//!
	inline UShort_t GetBack_StripNbr(const unsigned int &i)    const {return fSharcDev_StripBack_StripNbr[i];}//!
	inline Double_t GetBack_Energy(const unsigned int &i)      const {return fSharcDev_StripBack_Energy[i];}//!
	inline Double_t GetBack_TimeCFD(const unsigned int &i)     const {return fSharcDev_StripBack_TimeCFD[i];}//!
	inline Double_t GetBack_TimeLED(const unsigned int &i)     const {return fSharcDev_StripBack_TimeLED[i];}//!
	inline Double_t GetBack_Time(const unsigned int &i)        const {return fSharcDev_StripBack_Time[i];}//!
	  
	inline UShort_t GetPAD_DetectorNbr(const unsigned int &i) const {return fSharcDev_PAD_DetectorNbr[i];}//!
	inline Double_t GetPAD_Energy(const unsigned int &i)      const {return fSharcDev_PAD_Energy[i];}//!
	inline Double_t GetPAD_TimeCFD(const unsigned int &i)     const {return fSharcDev_PAD_TimeCFD[i];}//!
	inline Double_t GetPAD_TimeLED(const unsigned int &i)     const {return fSharcDev_PAD_TimeLED[i];}//!
	inline Double_t GetPAD_Time(const unsigned int &i)    	  const {return fSharcDev_PAD_Time[i];}//!
	
	inline unsigned int GetMultiplicityFront() const {return fSharcDev_StripFront_DetectorNbr.size();}//!
	inline unsigned int GetMultiplicityBack()  const {return fSharcDev_StripBack_DetectorNbr.size();}//!
	inline unsigned int GetMultiplicityPAD()   const {return fSharcDev_PAD_DetectorNbr.size();}//!
    
    //inline UShort_t GetMultEnergy() const
    //  {return fSharcDev_E_DetectorNbr.size();}
    //inline UShort_t GetE_DetectorNbr(const unsigned int &i) const 
    //  {return fSharcDev_E_DetectorNbr[i];}//!
    //inline Double_t Get_Energy(const unsigned int &i) const 
    //  {return fSharcDev_Energy[i];}//!

    // Time
    //inline UShort_t GetMultTime() const
    //  {return fSharcDev_T_DetectorNbr.size();}
    //inline UShort_t GetT_DetectorNbr(const unsigned int &i) const 
    //  {return fSharcDev_T_DetectorNbr[i];}//!
    //inline Double_t Get_Time(const unsigned int &i) const 
    //  {return fSharcDev_Time[i];}//!

	// Required for ROOT dictionnary
	ClassDef(TSharcDevData,1)  // SharcDevData structure
};
#endif
