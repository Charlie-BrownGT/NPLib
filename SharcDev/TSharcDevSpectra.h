#ifndef TSharcDevSPECTRA_H
#define TSharcDevSPECTRA_H
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

// NPLib headers
#include "NPVSpectra.h"
#include "TSharcDevData.h"
#include "TSharcDevPhysics.h"

// Forward Declaration
class TSharcDevPhysics;


class TSharcDevSpectra : public VSpectra {
  //////////////////////////////////////////////////////////////
  // constructor and destructor
  public:
    TSharcDevSpectra();
    TSharcDevSpectra(unsigned int NumberOfDetectors);
    ~TSharcDevSpectra();

  //////////////////////////////////////////////////////////////
  // Initialization methods
  private:
    void InitRawSpectra();
    void InitPreTreatedSpectra();
    void InitPhysicsSpectra();

  //////////////////////////////////////////////////////////////
  // Filling methods
  public:
    void FillRawSpectra(TSharcDevData*);
    void FillPreTreatedSpectra(TSharcDevData*);
    void FillPhysicsSpectra(TSharcDevPhysics*);

  //////////////////////////////////////////////////////////////
  // Detector parameters 
  private:
    unsigned int fNumberOfDetector;
    unsigned int fStripFront;
    unsigned int fStripBack;
    unsigned int fPad;
};

#endif
