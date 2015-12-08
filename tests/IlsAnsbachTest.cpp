#define BOOST_TEST_DYN_LINK

#include <functional>
#include <iostream>
#include <fstream>
#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>
#include "../include/PropertyLocation.h"
#include "../include/IlsAnsbach.h"
#include "../include/IOperation.h"

using namespace boost::unit_test;

// forward declarations
static const std::string GetFaxContent1();
static const std::string CreateTemporaryFile(std::function<std::string()> getContent);

BOOST_AUTO_TEST_CASE( ParseFileWithEmptyFilename )
{
    IlsAnsbach* parser = new IlsAnsbach();
    IOperation* result = parser->Parse("");
    
    BOOST_CHECK(result == nullptr);
    
    delete parser;
}

BOOST_AUTO_TEST_CASE( ParseFileWithNotExistingFile )
{
    IlsAnsbach* parser = new IlsAnsbach();
    IOperation* result = parser->Parse("/tmp/sowieso");
    
    BOOST_CHECK(result == nullptr);
    
    delete parser;
}

BOOST_AUTO_TEST_CASE( ParseFileWithExistingFile )
{
    const std::string filename = CreateTemporaryFile(GetFaxContent1);
    
    IlsAnsbach* parser = new IlsAnsbach();
    IOperation* result = parser->Parse(filename);

    if(boost::filesystem::exists(filename))
    {
        boost::filesystem::remove(filename);
    }
    
    std::cout << *result << std::endl;
    
    BOOST_CHECK(result != nullptr);
    
    
    delete result;
    delete parser;
}


static const std::string GetFaxContent1()
{
    std::string a = " \n"
"\n"
"EM n.s ensbac Booms (esii asoso-no ämo(eszuaiwwes ein e es.os.eois äci4=as E\n"
"---------------------- -- Alarmfax der ILS Ansbach ------------------------\n"
"\n"
"Absender : ILS ANSBACH\n"
"Fax :49 (981) 65050-410 Rufnummer:49 (981) 9776240\n"
"Termin .\n"
"\n"
"Einsatznummer: T 5.1 150829 1383\n"
"\n"
"---------------------------- -- EINSATZORT ------------------------------\n"
"Straße : Marktplatz Haus-Nr.: 0 FW\n"
"\n"
"Ort : 91472 Ipsheim - Ipsheim Ipsheim\n"
"\n"
"Objekt : 5.1.3 NEA Feuerwehrgerätehaus Ipsheim\n"
"\n"
"Plannummer:\n"
"\n"
"Station\n"
"\n"
"---------------------------- -- ZIELORT ---------------------------------\n"
"Straße : Haus-Nr.:\n"
"\n"
"Ort :\n"
"\n"
"Objekt\n"
"\n"
"Station\n"
"\n"
"---------------------------- -- EINSATZGRUND ----------------------------\n"
"\n"
"Schlagw.: Technische Hilfe klein !!!\n"
"Stichwort B:\n"
"\n"
"Stichwort R:\n"
"\n"
"Stichwort S:\n"
"\n"
"Stichwort T: THL 1\n"
"\n"
"Prio. : 1\n"
"\n"
"(1 = Notfall / 2 = dringend / 3 = nicht zeitkritisch)\n"
"---------------------------- -- EINSATZMITTEL ----------------------------\n"
"Einsatzmittel : 5.1.3 NEA FF Ipsheim\n"
"\n"
"Alarmiert : 29.08.2015 14:35\n"
"\n"
"Geforderte Ausstattung\n"
"\n"
"---------------------------- -- BEMERKUNG -------------------------------\n"
"---------------------------- -- ENDE FAX -------------------------------\n"
"\n"
"Zur Übernahme eines Einsatzes Kontakt mit der ILS aufnehmen!\n"
"\n"
"Das Alarmfax darf nur zum internen Dienstgebrauch verwendet werden.\n"
"Der Empfänger hat sicherzustellen, dass unbefugte bzw. nicht beteiligte\n"
"Dritte keinen Zugang zu den übermittelten Daten haben - ILS Ansbach -\n"
"\n";

    return a;
}

static const std::string CreateTemporaryFile(std::function<std::string()> getContent)
{
    boost::filesystem::path tmpFilenamePath = boost::filesystem::unique_path();
    tmpFilenamePath.replace_extension("txt");
    
    boost::filesystem::path tmpDirPath = boost::filesystem::temp_directory_path();
    boost::filesystem::path absoluteFilenamePath = tmpDirPath / tmpFilenamePath;
     
    const std::string tmpFilename = absoluteFilenamePath.native();
    
    std::ofstream file;
    file.open(tmpFilename, std::ios::out | std::ios::trunc | std::ios::binary);
    file << getContent();
    file.close();
    
    return tmpFilename;
}
