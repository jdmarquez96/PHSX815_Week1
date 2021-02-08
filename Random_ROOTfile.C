#include "TRandom.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TVector3.h"
#include "TRandom.h"
#include <iostream>
#include "TFile.h"
#include "TTree.h"

//
//
using namespace std;

// function name for a ROOT macro matches filename
void Random_ROOTfile(){


//Reading in file created

//pulling the tree from file
TFile *input = new TFile("randomnumbers.root","READ");
TTree *entries = (TTree*)input->Get("test");
	//test *event = new test(entries);
	//event->Loop();

int nentries = int(entries->GetEntries());


float finalnumbers = 0;


entries->SetBranchAddress("RNDNUM", &finalnumbers);


  // declare a 1D histogram
  TH1D *hist = new TH1D("hist","hist", 100,  -0.1, 1.1);

  // loop filling histogram with random numbers (uniform between (0, 1))
  for(int i = 0; i < nentries; i++){
    entries->GetEntry(i);
    hist->Fill(finalnumbers);
  }

  // Draw the histogram to a canvas
  hist->SetTitle("Random numbers headache extravagenza");
  hist->GetXaxis()->SetTitle("number value");
  hist->GetYaxis()->SetTitle("number of entries");
  hist->Draw();

}


