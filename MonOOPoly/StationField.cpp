#include "StationField.h"
#include "CommandFactory.h"

StationField::StationField() : Field()
{
    name = "Default";
}

StationField::StationField(const MyString& name, int index, const MyString& description) : Field(index, description)
{
    this->name = name;
}

void StationField::setOwner(Player* owner)
{
    this->owner = owner;
    this->owner->addStation();
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
    if (owner == nullptr)
    {
        std::cout << "This station does not have an owner. Do you want to buy it? Please enter buy_property/cancel." << std::endl;
        std::cout << "Answer: ";

        MyString answer;
        std::cin >> answer;

        CommandFactory& factory = CommandFactory::getInstance();

        factory.readCommand(answer)->executeCommand();
    }
    else {
        std::cout << "This station has an owner. You must pay him rent." << std::endl;
        player.setPlayerMoney(player.getPlayersMoney() - owner->getStationCount() * 50);
        this->owner->setPlayerMoney(this->owner->getPlayersMoney() + owner->getStationCount() * 50);
    }
}
