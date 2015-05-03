#pragma once
#include"../manager/EntityManager.h"
#include "../manager/LevelManager.h"

namespace Task
{
	class Action
	{
	protected:
		static EntityManager* entityManager;
		static LevelManager* levelManager;
		std::string entityName, targetName;
		Entity *entity, *target;
	public:
		void init();
		virtual bool run();
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