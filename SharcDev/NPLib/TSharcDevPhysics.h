#ifndef TSharcDevPHYSICS_H
#define TSharcDevPHYSICS_H
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
 *  This class hold SharcDev Treated data                                *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Comment:                                                                  *
 *                                                                           *   
 *                                                                           *
 *****************************************************************************/

//   STL
#include <sstream>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <limits>

// C++ headers 
#include <vector>
#include <map>
#include <string>
using namespace std;

// ROOT headers
#include "TObject.h"
#include "TH1.h"
#include "TVector3.h"
#include "TVector2.h" 
#include "TCanvas.h"
#include "TRandom3.h"
#include "TChain.h"
// NPTool headers
#include "TSharcDevData.h"
#include "TSharcDevSpectra.h"
#include "NPCalibrationManager.h"
#include "NPVDetector.h"
#include "NPInputParser.h"
#include "RootInput.h"
#include "RootOutput.h"
#include "TAsciiFile.h"
#include "NPOptionManager.h"
#include "NPDetectorFactory.h"



// forward declaration
class TSharcDevSpectra;

using namespace std ;

class TSharcDevPhysics : public TObject, public NPL::VDetector {

  // constructor and destructor
public:
    TSharcDevPhysics();
    ~TSharcDevPhysics() {};

  // Inherited from TObject and overriden to avoid warnings
public: 
    void Clear();   
    void Clear(const Option_t*) {};

  // data obtained after BuildPhysicalEvent() and stored in
  // output ROOT file
public:
	vector < TVector2 > Match_Front_Back() ;
    	int  CheckEvent();
    //vector<int>      DetectorNumber;
    //vector<double>   Energy;
    //vector<double>   Time;

  /// A usefull method to bundle all operation to add a detector
  //void AddDetector(TVector3 POS, string shape); 
  //void AddDetector(double R, double Theta, double Phi, string shape); 
  
  // methods inherited from the VDetector ABC class
public:
  	Int_t EventMultiplicity;
  	
  	vector<int> EventType ;
  	vector<int> DetectorNumber ;
  	
  	//   DSSD
	vector<double> Strip_E ;
	vector<double> Strip_T ;
	vector<double> StripFront_E ;
	vector<double> StripFront_T ;
	vector<double> StripBack_E ;
	vector<double> StripBack_T ;
	vector<int>    Strip_Front ;
	vector<int>    Strip_Back ;
	
	vector<double> PAD_E ;
	vector<double> PAD_T ;
	
	vector<double> StripFront_OriginalE; //!
	vector<double> StripBack_OriginalE; //!
	vector<double> DeadLayer; //!
	
	vector<double> Strip_Front_RawE;
	vector<double> Strip_Back_RawE;
    // read stream from ConfigFile to pick-up detector parameters
    //void ReadConfiguration(NPL::InputParser);

    // add parameters to the CalibrationManger
    //void AddParameterToCalibrationManager();

    // method called event by event, aiming at extracting the 
    // physical information from detector
    //void BuildPhysicalEvent();

    // same as BuildPhysicalEvent() method but with a simpler
    // treatment
    //void BuildSimplePhysicalEvent();

    // same as above but for online analysis
    //void BuildOnlinePhysicalEvent()  {BuildPhysicalEvent();};

    // activate raw data object and branches from input TChain
    // in this method mother branches (Detector) AND daughter leaves 
    // (fDetector_parameter) have to be activated
    //void InitializeRootInputRaw();

    // activate physics data object and branches from input TChain
    // in this method mother branches (Detector) AND daughter leaves 
    // (fDetector_parameter) have to be activated
    //void InitializeRootInputPhysics();

    // create branches of output ROOT file
    //void InitializeRootOutput();

    // clear the raw and physical data objects event by event
    //void ClearEventPhysics() {Clear();}      
    //void ClearEventData()    {m_EventData->Clear();}   

    // methods related to the TSharcDevSpectra class
    // instantiate the TSharcDevSpectra class and 
    // declare list of histograms
    //void InitSpectra();

    // fill the spectra
    //void FillSpectra();

    // used for Online mainly, sanity check for histograms and 
    // change their color if issues are found, for example
    //void CheckSpectra();

    // used for Online only, clear all the spectra
    //void ClearSpectra();

    // write spectra to ROOT output file
    //void WriteSpectra();

  // specific methods to SharcDev array
public:
	void ReadConfiguration(NPL::InputParser) ;
	void AddParameterToCalibrationManager() ;	
	void InitializeRootInputRaw() ;	
	void InitializeRootInputPhysics() ;	
	void InitializeRootOutput() ;	
	void BuildPhysicalEvent() ;	
	void BuildSimplePhysicalEvent() ;	
	void BuildOnlinePhysicalEvent()  {BuildPhysicalEvent();};	
	void ClearEventPhysics() {Clear();}    	  
	void ClearEventData()    {m_EventData->Clear();}	
	void InitSpectra();	
	void FillSpectra();	
	void CheckSpectra();	
	void ClearSpectra();	
	void WriteSpectra();
	
public:

	void ClearPreTreatedData()   {m_PreTreatedData->Clear();}
	void PreTreat();
	bool IsValidChannel(const string& DetectorType, const int& telescope , const int& channel);
	void InitializeStandardParameter();
	void ReadAnalysisConfig();
	void AddBoxDetector( double Z);
	void AddQQQDetector( double R,double Phi,double Z);
	void SetRawDataPointer(TSharcDevData* rawDataPointer) {m_EventData = rawDataPointer;}
	
	TSharcDevData* GetRawData()        const {return m_EventData;}
    TSharcDevData* GetPreTreatedData() const {return m_PreTreatedData;}
    	
	inline double GetStripPositionX( const int& N , const int& Front , const int& Back )   const{ return m_StripPositionX[N-1][Front-1][Back-1] ; }  ;
	inline double GetStripPositionY( const int& N , const int& Front , const int& Back )   const{ return m_StripPositionY[N-1][Front-1][Back-1] ; }  ;
	inline double GetStripPositionZ( const int& N , const int& Front , const int& Back )   const{ return m_StripPositionZ[N-1][Front-1][Back-1] ; }  ;
	
	inline double GetNumberOfDetector() const { return m_NumberOfDetector; };
	
	inline int GetEventMultiplicity() const { return EventMultiplicity; };
	
	TVector3 GetPositionOfInteraction(const int& i, bool random=false) const;   
	TVector3 GetDetectorNormal(const int& i) const;
	double   GetDeadLayer(const int& i) const;
	
private:
	bool m_Take_E_Front;//!
	bool m_Take_T_Back;//!
	
	unsigned int m_MaximumStripMultiplicityAllowed  ;//!
	
	double m_StripEnergyMatchingSigma  ; //!
    double m_StripEnergyMatchingNumberOfSigma  ; //!
    	
    double m_StripFront_E_RAW_Threshold ;//!
	double m_StripFront_E_Threshold ;//!
	double m_StripBack_E_RAW_Threshold ;//!
	double m_StripBack_E_Threshold ;//!
	double m_PAD_E_RAW_Threshold ;//!
	double m_PAD_E_Threshold ;//!
	
private:
	TSharcDevData*         m_EventData;//!
	TSharcDevData*         m_PreTreatedData;//!
	TSharcDevPhysics*      m_EventPhysics;//!
	
private:
	map< int, vector<bool> > m_FrontChannelStatus;//!
	map< int, vector<bool> > m_BackChannelStatus;//! 
	map< int, vector<bool> > m_PADChannelStatus;//!
	
private: 
	int m_NumberOfDetector;//!
	vector< vector < vector < double > > >   m_StripPositionX;//!
	vector< vector < vector < double > > >   m_StripPositionY;//!
	vector< vector < vector < double > > >   m_StripPositionZ;//!
	vector< TVector3 > m_DetectorNormal;//!
	vector< TVector3 > m_U;//!
	vector< TVector3 > m_V;//!
	TRandom3* m_Rand;//!
	double m_BoxPitchBack ;//!
	double m_BoxPitchFront;//!
	double m_QQQPitchBack ;//!
	double m_QQQPitchFront;//!	
	
private:
	TSharcDevSpectra* m_Spectra; // !
	
public:
	map< string , TH1*> GetSpectra(); 
	
public:
	static NPL::VDetector* Construct();
	ClassDef(TSharcDevPhysics,1)  // SharcPhysics structure
};

namespace SharcDev_LOCAL
{
	double fStrip_Front_E(const TSharcDevData* Data, const int& i);
  	double fStrip_Front_T(const TSharcDevData* Data, const int& i);
  	
  	double fStrip_Back_E(const TSharcDevData* Data, const int& i);
  	double fStrip_Back_T(const TSharcDevData* Data, const int& i);
  	
  	double fPAD_E(const TSharcDevData* Data, const int& i);
  	double fPAD_T(const TSharcDevData* Data, const int& i);
}
#endif