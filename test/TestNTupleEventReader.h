#include "cute/cute.h"
#include "cute/cute_suite.h"
#include <boost/scoped_ptr.hpp>

#include "../interface/Event.h"
#include "../interface/TopPairEventCandidate.h"
#include "../interface/Readers/NTupleEventReader.h"
#include "InputFiles.h"

using namespace BAT;

struct TestNTupleEventReader {
private:
    boost::scoped_ptr<NTupleEventReader> TTbarReader;
    boost::scoped_ptr<NTupleEventReader> QCDenri1Reader;
    boost::scoped_ptr<NTupleEventReader> QCDenri2Reader;
    boost::scoped_ptr<NTupleEventReader> QCDenri3Reader;

    boost::scoped_ptr<NTupleEventReader> QCDbce1Reader;
    boost::scoped_ptr<NTupleEventReader> QCDbce2Reader;
    boost::scoped_ptr<NTupleEventReader> QCDbce3Reader;

    boost::scoped_ptr<NTupleEventReader> WjetsReader;
    boost::scoped_ptr<NTupleEventReader> ZJetsReader;
    boost::scoped_ptr<NTupleEventReader> TWReader;
    boost::scoped_ptr<NTupleEventReader> TChanReader;
    boost::scoped_ptr<NTupleEventReader> DataReader;
    boost::scoped_ptr<NTupleEventReader> DataReader2;
    boost::scoped_ptr<NTupleEventReader> AllMCReader;

public:
    TestNTupleEventReader() :
        TTbarReader(new NTupleEventReader()),
        QCDenri1Reader(new NTupleEventReader()),
        QCDenri2Reader(new NTupleEventReader()),
        QCDenri3Reader(new NTupleEventReader()),
        QCDbce1Reader(new NTupleEventReader()),
        QCDbce2Reader(new NTupleEventReader()),
        QCDbce3Reader(new NTupleEventReader()),
        WjetsReader(new NTupleEventReader()),
        ZJetsReader(new NTupleEventReader()),
        TWReader(new NTupleEventReader()),
        TChanReader(new NTupleEventReader()),
        DataReader(new NTupleEventReader()),
        DataReader2(new NTupleEventReader()),
        AllMCReader(new NTupleEventReader()) {

        TTbarReader->addInputFile(InputFile::TTJets);
        QCDenri1Reader->addInputFile(InputFile::QCD_EMEnriched_Pt20to30);
        QCDenri2Reader->addInputFile(InputFile::QCD_EMEnriched_Pt30to80);
        QCDenri3Reader->addInputFile(InputFile::QCD_EMEnriched_Pt80to170);

        QCDbce1Reader->addInputFile(InputFile::QCD_BCtoE_Pt20to30);
        QCDbce2Reader->addInputFile(InputFile::QCD_BCtoE_Pt30to80);
        QCDbce3Reader->addInputFile(InputFile::QCD_BCtoE_Pt80to170);

        WjetsReader->addInputFile(InputFile::WJets);
        ZJetsReader->addInputFile(InputFile::ZJets);
        TWReader->addInputFile(InputFile::singleTop_And_W);
        TChanReader->addInputFile(InputFile::singleTopTChannel);
        DataReader->addInputFile(InputFile::data);
        DataReader->addInputFile(InputFile::data2);
        DataReader2->addInputFile(InputFile::data2);
        DataReader2->addInputFile(InputFile::data);

        AllMCReader->addInputFile(InputFile::TTJets);
        AllMCReader->addInputFile(InputFile::QCD_EMEnriched_Pt20to30);
        AllMCReader->addInputFile(InputFile::QCD_EMEnriched_Pt30to80);
        AllMCReader->addInputFile(InputFile::QCD_EMEnriched_Pt80to170);
        AllMCReader->addInputFile(InputFile::QCD_BCtoE_Pt20to30);
        AllMCReader->addInputFile(InputFile::QCD_BCtoE_Pt30to80);
        AllMCReader->addInputFile(InputFile::QCD_BCtoE_Pt80to170);
        AllMCReader->addInputFile(InputFile::WJets);
        AllMCReader->addInputFile(InputFile::ZJets);
        AllMCReader->addInputFile(InputFile::singleTop_And_W);
        AllMCReader->addInputFile(InputFile::singleTopTChannel);
        AllMCReader->addInputFile(InputFile::singleTopSChannel);
        AllMCReader->addInputFile(InputFile::singleAntiTop_And_W);
        AllMCReader->addInputFile(InputFile::singleAntiTopTChannel);
        AllMCReader->addInputFile(InputFile::singleAntiTopSChannel);
        AllMCReader->addInputFile(InputFile::GJets_Pt40to100);
        AllMCReader->addInputFile(InputFile::GJets_Pt100to200);
        AllMCReader->addInputFile(InputFile::GJets_Pt200toInf);

    }

    void testTTbarType() {
        Event currentEvent = TTbarReader->getNextEvent();
        ASSERT_EQUAL(short(DataType::ttbar), short(currentEvent.getDataType()));
    }

    void testQCD_EMEnriched_80_to_170Type() {
        Event currentEvent = QCDenri3Reader->getNextEvent();
        ASSERT_EQUAL(short(DataType::QCD_EMEnriched_Pt80to170), short(currentEvent.getDataType()));
    }

    void testQCD_EMEnriched_30_to_80Type() {
        Event currentEvent = QCDenri2Reader->getNextEvent();
        ASSERT_EQUAL(short(DataType::QCD_EMEnriched_Pt30to80), short(currentEvent.getDataType()));
    }

    void testQCD_EMEnriched_20_to_30Type() {
        Event currentEvent = QCDenri1Reader->getNextEvent();
        ASSERT_EQUAL(short(DataType::QCD_EMEnriched_Pt20to30), short(currentEvent.getDataType()));
    }

    void testQCD_BCtoE_80_to_170Type() {
        Event currentEvent = QCDbce3Reader->getNextEvent();
        ASSERT_EQUAL(short(DataType::QCD_BCtoE_Pt80to170), short(currentEvent.getDataType()));
    }

    void testQCD_BCtoE_30_to_80Type() {
        Event currentEvent = QCDbce2Reader->getNextEvent();
        ASSERT_EQUAL(short(DataType::QCD_BCtoE_Pt30to80), short(currentEvent.getDataType()));
    }

    void testQCD_BCtoE_20_to_30Type() {
        Event currentEvent = QCDbce1Reader->getNextEvent();
        ASSERT_EQUAL(short(DataType::QCD_BCtoE_Pt20to30), short(currentEvent.getDataType()));
    }

    void testWjetsType() {
        Event currentEvent = WjetsReader->getNextEvent();
        ASSERT_EQUAL(short(DataType::Wjets), short(currentEvent.getDataType()));
    }

    void testZjetsType() {
    	ASSERT(ZJetsReader->hasNextEvent());
        Event currentEvent = ZJetsReader->getNextEvent();
        ASSERT_EQUAL(short(DataType::Zjets), short(currentEvent.getDataType()));
    }

    void testTWType() {
    	ASSERT(TWReader->hasNextEvent());
        Event currentEvent = TWReader->getNextEvent();
        ASSERT_EQUAL(short(DataType::singleTop_And_W), short(currentEvent.getDataType()));
    }

    void testTChanType() {
        Event currentEvent = TChanReader->getNextEvent();
        ASSERT_EQUAL(short(DataType::singleTopTChannel), short(currentEvent.getDataType()));
    }

    void testDataType() {
        Event currentEvent = DataReader->getNextEvent();
        ASSERT_EQUAL(short(DataType::DATA), short(currentEvent.getDataType()));
    }

    void testReadDataType() {
    	ASSERT(DataReader->hasNextEvent());
        Event currentEvent = DataReader->getNextEvent();
        ASSERT_EQUAL(true, currentEvent.isRealData());
    }

    void testNumberOfTracksInEvent1() {
    	ASSERT(TTbarReader->hasNextEvent());
        Event currentEvent = TTbarReader->getNextEvent();
        ASSERT_EQUAL(0, currentEvent.Tracks().size());//Tracks deactivated
    }

    void testNumberOfElectronsInEvent1() {
        Event currentEvent = TTbarReader->getNextEvent();
        cout << TTbarReader->getCurrentLocalEventNumber() << endl;
        ASSERT_EQUAL(1, currentEvent.Electrons().size());
    }

    void testNumberOfJetsInEvent1() {
        Event currentEvent = TTbarReader->getNextEvent();
        cout << TTbarReader->getCurrentLocalEventNumber() << endl;
        ASSERT_EQUAL(5, currentEvent.Jets().size());
    }

    void testNumberOfMuonsInEvent1() {
        Event currentEvent = TTbarReader->getNextEvent();
        ASSERT_EQUAL(2, currentEvent.Muons().size());
    }

    void testHasNextEvent() {
        ASSERT_EQUAL(true, TTbarReader->hasNextEvent());
    }

    void testHasNotNextEvent() {
        TTbarReader->skipNumberOfEvents(123456789);
        ASSERT(TTbarReader->hasNextEvent() == false);
    }

    void testGetProccessedNumberOfEvents() {
        TTbarReader->getNextEvent();
        ASSERT_EQUAL(1, TTbarReader->getNumberOfProccessedEvents());
        TTbarReader->getNextEvent();
        ASSERT_EQUAL(2, TTbarReader->getNumberOfProccessedEvents());
    }

    void testGetProccessedNumberOfEventsWithSkippedEvents() {
        TTbarReader->getNextEvent();
        TTbarReader->skipNumberOfEvents(100);
        ASSERT_EQUAL(1, TTbarReader->getNumberOfProccessedEvents());
    }
    void testSkipEvents() {
        TTbarReader->skipNumberOfEvents(10);
        ASSERT_EQUAL(10, TTbarReader->getCurrentLocalEventNumber());
    }

    void testGetCurrentLocalEventNumber() {
        ASSERT_EQUAL(0, TTbarReader->getCurrentLocalEventNumber());
        TTbarReader->getNextEvent();
        ASSERT_EQUAL(1, TTbarReader->getCurrentLocalEventNumber());
    }

    void testSetMaximumNumberOfEventsWithSkippedEvents() {
        TTbarReader->setMaximumNumberOfEvents(5);
        TTbarReader->skipNumberOfEvents(10);
        ASSERT(TTbarReader->hasNextEvent() == false);
    }

    void testSetMaximumNumberOfEvents() {
        unsigned int maxEvents = 5;
        TTbarReader->setMaximumNumberOfEvents(maxEvents);
        while (TTbarReader->hasNextEvent())
            TTbarReader->getNextEvent();
        ASSERT_EQUAL(maxEvents, TTbarReader->getNumberOfProccessedEvents());
    }

    void testMCRunNumber() {
        ASSERT_EQUAL(1, TTbarReader->getNextEvent().runnumber());
    }

    void testMCLumiBlock() {
        ASSERT_EQUAL(5, TTbarReader->getNextEvent().lumiblock());
    }

    void testLocalEventNumber() {
        ASSERT_EQUAL(1, TTbarReader->getNextEvent().localnumber());
    }

    void testInitialEventWeigth() {
    	ASSERT(TTbarReader->hasNextEvent());
        ASSERT_EQUAL(1., TTbarReader->getNextEvent().weight());
    }

    void testPrimaryVertex() {
        ASSERT_EQUAL(true, TTbarReader->getNextEvent().PrimaryVertex()->isGood());
    }

    void testHLTTrigger() {
        TopPairEventCandidate candidate = TopPairEventCandidate(TTbarReader->getNextEvent());
        ASSERT_EQUAL(true, candidate.passesElectronHighLevelTrigger());
    }

    void testEventChainConstant() {
        ASSERT_EQUAL(0, strcmp("rootTupleTree/tree", NTupleEventReader::EVENT_CHAIN));
    }

    void testTTbarEventMET() {
        Event event = TTbarReader->getNextEvent();
        ASSERT_EQUAL_DELTA(58.6601,event.MET()->et(), 0.001);
    }

    void testSeenTTbar() {
        const boost::array<bool, DataType::NUMBER_OF_DATA_TYPES> seenTypes = TTbarReader->getSeenDatatypes();

        for (unsigned short index = 0; index < DataType::NUMBER_OF_DATA_TYPES; ++index) {
            if (index == DataType::ttbar)
                ASSERT_EQUAL(true, seenTypes.at(index));
                else
                ASSERT_EQUAL(false, seenTypes.at(index));
        }
    }

    void testSeenAllMC() {
        const boost::array<bool, DataType::NUMBER_OF_DATA_TYPES> seenTypes = AllMCReader->getSeenDatatypes();

        for (unsigned short index = 0; index < DataType::NUMBER_OF_DATA_TYPES; ++index) {
            if (index == DataType::DATA || index >= DataType::Zprime_M500GeV_W5GeV || index == DataType::VQQ){
            	if(seenTypes.at(index))
            		cout << index << endl;
            	ASSERT_EQUAL(false, seenTypes.at(index));
            }

            else {
                std::string msg("index ");
                std::stringstream stream;
                stream << index;
                msg += stream.str();
                ASSERT_EQUALM(msg.c_str(), true, seenTypes.at(index));
            }

        }
    }

    void testAddInputFileNoFileThrowsException() {
        boost::scoped_ptr<NTupleEventReader> reader(new NTupleEventReader());
        ASSERT_THROWS(reader->addInputFile("dfjndkjvnvh"), NoFileFoundException);
    }

    void testGenJetsMC() {
		Event event = TTbarReader->getNextEvent();
		ASSERT_EQUAL(6, event.GenJets().size());
	}

	void testGenJetsDATA() {
		Event event = DataReader->getNextEvent();
		ASSERT_EQUAL(0, event.GenJets().size());
	}

};

extern cute::suite make_suite_TestNTupleEventReader() {
    cute::suite s;

    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testTTbarType));

    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testQCD_EMEnriched_20_to_30Type));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testQCD_EMEnriched_30_to_80Type));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testQCD_EMEnriched_80_to_170Type));

    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testQCD_BCtoE_20_to_30Type));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testQCD_BCtoE_30_to_80Type));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testQCD_BCtoE_80_to_170Type));

    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testWjetsType));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testZjetsType));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testTWType));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testTChanType));

    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testDataType));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testReadDataType));

    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testNumberOfTracksInEvent1));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testNumberOfElectronsInEvent1));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testNumberOfJetsInEvent1));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testNumberOfMuonsInEvent1));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testHasNextEvent));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testHasNotNextEvent));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testGetProccessedNumberOfEvents));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testGetProccessedNumberOfEventsWithSkippedEvents));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testSkipEvents));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testGetCurrentLocalEventNumber));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testSetMaximumNumberOfEventsWithSkippedEvents));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testSetMaximumNumberOfEvents));

    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testMCRunNumber));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testMCLumiBlock));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testLocalEventNumber));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testInitialEventWeigth));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testPrimaryVertex));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testHLTTrigger));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testEventChainConstant));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testTTbarEventMET));

    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testSeenTTbar));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testSeenAllMC));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testAddInputFileNoFileThrowsException));

    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testGenJetsMC));
    s.push_back(CUTE_SMEMFUN(TestNTupleEventReader, testGenJetsDATA));

    return s;
}
