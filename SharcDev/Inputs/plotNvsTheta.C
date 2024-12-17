// C++ headers
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// ROOT headers
#include "TROOT.h"
#include "TCanvas.h"
#include "TSystem.h"
#include "TFile.h"
#include "TString.h"
#include "TEllipse.h"
#include "TLegend.h"
#include "TTree.h"
#include "TBranch.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"

// nptool headers
#include "TInitialConditions.h"
#include "TInteractionCoordinates.h"
//#include "NPDetectorManager.h"
#include "NPReaction.h"
using namespace NPL;

void plotNvsTheta(const char *dirname="/home/guy/software/nptool/Projects/SharcDev/", const char *ext=".root") {
	
	//setting up the file output names  
   	char pngFile[256]; // Adjust the size if needed
	char pngFile2[256];

	//used to get the file names with .root extension in current working directory
	const int MAX_FILES = 1000;
	TString* filenames[MAX_FILES];
	int file_count = 0;
	
	TSystemDirectory dir(dirname, dirname);
	TList *files = dir.GetListOfFiles();
	if (files) {
		TSystemFile *file;
		TString fname;
		TIter next(files);
		while ((file=(TSystemFile*)next())) {
			fname = file->GetName();
			if (!file->IsDirectory() && fname.EndsWith(ext)) {
				cout << fname.Data() << endl;
				filenames[file_count] = new TString(fname);  //allocate and copy
                file_count++;	
			} 
		}
	}
	
	int strLength;
	char detStat[256];
	Long64_t nEntries;
	double testArr[1024];

	for(int i = 0; i < file_count; i++){
		TFile *file = TFile::Open(filenames[i]->Data(), "READ");
		TTree *tree = (TTree*)file->Get("SimulatedTree");

		//remove the .root suffix in the file name
		strcpy(detStat, filenames[i]->Data());
		strLength = strlen(detStat);
		strLength = strLength - 5;
		detStat[strLength] = '\0';
		strcpy(pngFile, detStat);
		//strcpy(pngFile2, detStat);
		std::cout << detStat << std::endl;
		
		TCanvas *c1 = new TCanvas("c1", "SimulatedResults", 1200, 1000);
		TH1F *hist = new TH1F("hist", "Branch Data;Value;Entries", 1000, 0, 30);
		hist->SetTitle(pngFile);
		hist->GetXaxis()->SetTitle("#Theta_{lab} (deg)");
  		hist->GetYaxis()->SetTitle("Observed Events (N)");
		hist->SetStats(0);
		tree->Draw("fDetected_Angle_Theta>>hist");
		
		strcat(pngFile, ".png");
		c1->SaveAs(pngFile);
		delete c1;
	}
}

