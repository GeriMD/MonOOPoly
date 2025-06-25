#include "Board.h"
#include "CardField.h"
#include "FreeParkingField.h"
#include "GoToJailField.h"
#include "JailField.h"
#include "PropertyField.h"
#include "ServiceField.h"
#include "StationField.h"
#include "StartField.h"
#include "TaxField.h"
#include <fstream>
#include <stdexcept>
#include "Constants.h"

Board::Board()
{
    std::ifstream file(Constants::FIELDS_FILE_NAME);

    if (!file.is_open())
    {
       throw std::runtime_error("Fields file cannot be opened!");
       
    }

    for (int i = 0; i < 40; i++)
    {
        int type;
        file >> type;
        file.ignore();
     //   std::cout << "Reading" << i << std::endl;
       // std::cout << "Type " << type << std::endl;
        //std::cout << "in1";

        Field* currentField = createField(type);
        //std::cout << "in1";
        currentField->readFromFile(file);


      //  std::cout << currentField->getFieldIndex();
     //  currentField->printDescription();
        fields[currentField->getFieldIndex()] = currentField;
    }
}

Board::~Board()
{
    for (int i = 0; i < 40; i++)
    {
        delete fields[i];
    }
}

Field* Board::createField(int type)
{
    switch (type)
    {
    case 1: return new StartField();
    case 2: return new FreeParkingField();
    case 3: return new GoToJailField();
    case 4: return new JailField();
    case 9: return new PropertyField();
    case 6: return new ServiceField();
    case 7: return new StationField();
    case 8: return new CardField();
    case 5: return new TaxField();
    default:
        throw std::invalid_argument("Field type is invalid!");
    }
   // TODO: throw exception
}

Field& Board::getField(int index) const
{
    if (index < 0 || index > 39)
    {
        throw std::invalid_argument("Index out of bounds!");
    }

    if (fields[index] == nullptr)
    {
        throw std::invalid_argument("There is no such a field.");
    }

    return *fields[index];
}

Board& Board::getInstance()
{
    static Board instance;
    return instance;

}