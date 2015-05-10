#pragma once
#include "../manager/EntityManager.h"
#include "../manager/LevelManager.h"
#include "../pathfinding/pathfinder.h"

namespace Task
{
	class Action
	{
	protected:
		Entity *entity, *target;
		GridBool *grid;
		bool result;
	public:
		std::string entityName, targetName;
		static EntityManager* entityManager;
		static LevelManager* levelManager;
		void preRun();
		virtual void init() {}
		virtual bool run() = 0;
		bool getResult();
	};
}