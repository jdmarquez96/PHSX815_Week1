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
using namespace std;

// function name for a ROOT macro matches filename
void Random_ROOTfilecreation(long seed = 5555){

  // declare a TRandom instance using the seed
  TRandom random(seed);

	TFile *output = new TFile("randomnumbers.root","RECREATE");

	TTree *numbers =new TTree("test","test");



// 	unsigned int pointIn;		// Array length
// 	float reading[points];	// Data array
//	numbers->Branch("pointIn",&pointIn,"pointIn/I"); // Variable for data length: This is very important. Without this the next branch will not work.
//	numbers->Branch("reading",reading,"reading[pointIn]/F"); //

	float RNDNUM;

	numbers->Branch("RNDNUM",&RNDNUM);

	int N = 1000000;
	for(int i = 0; i < N; i++){
	   RNDNUM = random.Rndm();
		numbers->Fill();
			}


output->Write();




//  int N = 1000000;
//  for(int i = 0; i < N; i++){
//    Fill(random.Rndm());
//  }
}


