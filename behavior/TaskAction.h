#include "Task.h"

namespace Task
{
	class Move : public Task::Action
	{
		Path path;
		Position nextPos;
		Pathfinding::Pathfinder* pathfinder;
	public:
		void init();
		bool run();
	};

	class Push : public Task::Action
	{
		Position nextEntityPos, nextTargetPos;
	public:
		void init();
		bool run();
	};

	class Pull : public Task::Action
	{
		Position nextEntityPos, nextTargetPos;
	public:
		void init();
		bool run();
	};

	class Pickup : public Task::Action
	{
	public:
		bool run();
	};

	class Drop : public Task::Action
	{
	public:
		bool run();
	};
}