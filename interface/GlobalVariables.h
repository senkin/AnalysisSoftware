/*
 * GlobalVariables.h
 *
 *  Created on: 20 Oct 2011
 *      Author: kreczko
 */

#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_
#include "EventWeightProvider.h"
#include "RecoObjects/Jet.h"
#include "RecoObjects/Electron.h"
#include "RecoObjects/Muon.h"
#include "RecoObjects/MET.h"
#include "TF1.h"
#include "TH1D.h"
#include <string>


namespace BAT {
struct Globals {

	//general
	static unsigned long maxEvents;
	static double luminosity;
	static unsigned short energyInTeV;
	static unsigned long printEveryXEvents;
	static std::string selectedEventsOutputfile;
	static std::string selectedEventsWithMetaDataOutputfile;
	static PileUpReweightingMethod::value pileUpReweightingMethod;
	static boost::shared_ptr<TH1D> estimatedPileup;
	static unsigned int NTupleVersion;
	static bool verbose;

	//Kinematic fit
	static std::string TQAFPath;
	static bool useHitFit;
	static bool produceFitterASCIIoutput;

	//electrons
	static ElectronAlgorithm::value electronAlgorithm;
	static int ElectronScaleFactorSystematic;
//
//	//muons
	static MuonAlgorithm::value muonAlgorithm;
	static int MuonScaleFactorSystematic;
//
//	//jets
	static JetAlgorithm::value jetAlgorithm;
	static boost::array<boost::shared_ptr<TF1>, 12> bL7Corrections;
	static boost::array<boost::shared_ptr<TF1>, 12> lightL7Corrections;
	static int JESsystematic;
	static int BJetSystematic;
	static int LightJetSystematic;
	static int JetSmearingSystematic;
	static bool applyJetSmearing;


	//MET
	static METAlgorithm::value metAlgorithm;
	static bool applySysShiftMetCorrection;
	static bool applyType0MetCorrection;
	static bool applyType1MetCorrection;

	//top pt reweighting
	static bool applyTopPtReweighting;

	//miscellaneous
	static std::string custom_file_suffix;
	static unsigned int pdfWeightNumber;
};

}

#endif /* GLOBALVARIABLES_H_ */
