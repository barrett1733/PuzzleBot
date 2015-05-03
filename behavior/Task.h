#pragma once
#include"../manager/EntityManager.h"
#include "../manager/LevelManager.h"

namespace Task
{
	class Action
	{
	protected:
		std::string entityName, targetName;
		Entity *entity, *target;
	public:
		static EntityManager* entityManager;
		static LevelManager* levelManager;
		void init();
		virtual bool run() { return 0; }
	};

	class Move : public Action
	{
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