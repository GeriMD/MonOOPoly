#include "StationField.h"

StationField::StationField() : Field()
{
    name = "Default";
}

StationField::StationField(const MyString& name, int index, const MyString& description) : Field(index, description)
{
    this->name = name;
}

void StationField::setOwner(const MyString& ownerName)
{
    this->ownerName = ownerName;
  
}

Field* StationField::clone() const
{
    return new StationField(*this);
}

void StationField::readFromFile(std::ifstream& is)
{
    char buffer[1024];
    is.getline(buffer, 1024);
    description = buffer;

    is >> index;
    is.ignore();

    char buffer2[1024];
    is.getline(buffer2, 1024);
    name = buffer2;
}

void StationField::printFieldInformation() const
{
    std::cout << description << std::endl;
    std::cout << index << std::endl;
    std::cout << name << std::endl;

}

void StationField::applyEffect(Player& player)
{
    Monopoly& monopoly = Monopoly::getInstance();
    Player* owner = monopoly.getPlayerByName(ownerName);
    if (owner == nullptr)
    {
        again:
        std::cout << "This station does not have an owner. Do you want to buy it? Yes/No [y/n]" << std::endl;
        std::cout << "Answer: ";
        char answer;
        std::cin >> answer;

        switch (answer) {
        case 'y':
        case 'Y': { ownerName = player.getName(); player.addStation(); break; }
        case 'n':
        case 'N': std::cout << "You did not buy this station." <<std::endl;  break;
        default:
            system("cls");
            goto again;
        }
    }
    else {
        std::cout << "This station has an owner. You must pay rent to: " << ownerName << std::endl;
        
        player.setPlayerMoney(player.getPlayersMoney() - owner->getStationCount() * 50);
        owner->setPlayerMoney(owner->getPlayersMoney() + owner->getStationCount() * 50);
    }
}
const MyString& StationField::getOwnerName() const {
    return ownerName;
}