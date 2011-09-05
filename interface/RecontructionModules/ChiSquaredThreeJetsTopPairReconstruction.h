/*
 * ChiSquaredThreeJetsTopPairReconstruction.h
 *
 *  Created on: 2 Sep 2011
 *      Author: kreczko
 */

#ifndef CHISQUAREDTHREEJETSTOPPAIRRECONSTRUCTION_H_
#define CHISQUAREDTHREEJETSTOPPAIRRECONSTRUCTION_H_

#include "ChiSquaredBasedTopPairReconstruction.h"

namespace BAT {

class ChiSquaredThreeJetsTopPairReconstruction: public BAT::ChiSquaredBasedTopPairReconstruction {
public:
	ChiSquaredThreeJetsTopPairReconstruction(const ElectronPointer electron, const METPointer met, const JetCollection jets);
	virtual ~ChiSquaredThreeJetsTopPairReconstruction();
	bool meetsJetFromWRequirement(unsigned short jet1Index, unsigned short jet2Index);
	bool meetsInitialCriteria() const;
};

} /* namespace BAT */
#endif /* CHISQUAREDTHREEJETSTOPPAIRRECONSTRUCTION_H_ */
