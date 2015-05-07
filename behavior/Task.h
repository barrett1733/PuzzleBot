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
		void loadObjects();
	public:
		std::string entityName, targetName;
		static EntityManager* entityManager;
		static LevelManager* levelManager;
		virtual void preRun() {};
		virtual bool run() = 0;
	};

	class Move : public Action
	{
		Path path;
		Position nextPos;
		Pathfinding::Pathfinder* pathfinder;
	public:
		void preRun();
		bool run();
	};

	class Push : public Action
	{
	public:
		void preRun();
		bool run();
	};

	class Pull : public Action
	{
	public:
		void preRun();
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