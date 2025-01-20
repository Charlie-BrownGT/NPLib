#ifndef TbasicScintillatorSPECTRA_H
#define TbasicScintillatorSPECTRA_H
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

// NPLib headers
#include "NPVSpectra.h"
#include "TbasicScintillatorData.h"
#include "TbasicScintillatorPhysics.h"

// Forward Declaration
class TbasicScintillatorPhysics;


class TbasicScintillatorSpectra : public VSpectra {
  //////////////////////////////////////////////////////////////
  // constructor and destructor
  public:
    TbasicScintillatorSpectra();
    TbasicScintillatorSpectra(unsigned int NumberOfDetectors);
    ~TbasicScintillatorSpectra();

  //////////////////////////////////////////////////////////////
  // Initialization methods
  private:
    void InitRawSpectra();
    void InitPreTreatedSpectra();
    void InitPhysicsSpectra();

  //////////////////////////////////////////////////////////////
  // Filling methods
  public:
    void FillRawSpectra(TbasicScintillatorData*);
    void FillPreTreatedSpectra(TbasicScintillatorData*);
    void FillPhysicsSpectra(TbasicScintillatorPhysics*);

  //////////////////////////////////////////////////////////////
  // Detector parameters 
  private:
    unsigned int fNumberOfDetectors;
    const unsigned int fNumberOfStrips=25;
};

#endif
