// Generated by Creer at 03:39AM on October 10, 2015 UTC, git hash: '98604e3773d1933864742cb78acbf6ea0b4ecd7b'
// $This is a class that manages the Anarchy Game and it's GameObjects. Competitors should never have to care about this class's existance.

#include "gameManager.h"
#include "ai.h"
// The Game Objects
#include "building.h"
#include "fireDepartment.h"
#include "forecast.h"
#include "gameObject.h"
#include "player.h"
#include "policeDepartment.h"
#include "warehouse.h"
#include "weatherStation.h"

Anarchy::GameManager::GameManager() :
    Joueur::BaseGameManager()
{
    this->anarchyGame = new Anarchy::Game();
    this->anarchyAI = new Anarchy::AI();

    this->setup(this->anarchyGame, this->anarchyAI);
}

// @overrides
Joueur::BaseGameObject* Anarchy::GameManager::createGameObject(const std::string& gameObjectName)
{
    if (gameObjectName == "Building")
    {
        return new Anarchy::Building();
    }
    else if (gameObjectName == "FireDepartment")
    {
        return new Anarchy::FireDepartment();
    }
    else if (gameObjectName == "Forecast")
    {
        return new Anarchy::Forecast();
    }
    else if (gameObjectName == "GameObject")
    {
        return new Anarchy::GameObject();
    }
    else if (gameObjectName == "Player")
    {
        return new Anarchy::Player();
    }
    else if (gameObjectName == "PoliceDepartment")
    {
        return new Anarchy::PoliceDepartment();
    }
    else if (gameObjectName == "Warehouse")
    {
        return new Anarchy::Warehouse();
    }
    else if (gameObjectName == "WeatherStation")
    {
        return new Anarchy::WeatherStation();
    }

    throw new std::exception(("Game object '" + gameObjectName + "' not found to create new instance of").c_str());
}

// @overrides
void Anarchy::GameManager::setupAI(const std::string& playerID)
{
    Joueur::BaseGameManager::setupAI(playerID);

    this->anarchyAI->player = (Anarchy::Player*)(this->getGameObject(playerID));
    this->anarchyAI->game = this->anarchyGame;
}

// @overrides
boost::property_tree::ptree* Anarchy::GameManager::orderAI(const std::string& order, boost::property_tree::ptree* args)
{
    auto ptrees = this->getOrderArgsPtrees(args);

    if (order == "runTurn")
    {
        auto returned = this->anarchyAI->runTurn(
        );

        return this->serialize(returned);
    }

    delete ptrees;
    return nullptr;
}