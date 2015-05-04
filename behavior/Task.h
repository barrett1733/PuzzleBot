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
	public:
		std::string entityName, targetName;
		static EntityManager* entityManager;
		static LevelManager* levelManager;
		void init();
		virtual bool run() = 0;
	};

	class Move : public Action
	{
		Path path;
		Position nextPos;
		Pathfinding::Pathfinder* pathfinder;
		void createPath(GridBool&);
	public:
		bool run();
	};

	class Push : public Action
	{
		bool run();
	};

	class Pull : public Action
	{
		bool run();
	};

	class Pickup : public Action
	{
		bool run();
	};

	class Drop : public Action
	{
		bool run();
	};

	class Trigger : public Action
	{
		bool run();
	};
}