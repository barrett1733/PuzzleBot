#include "Task.h"

namespace Task
{
	class IsAtLocation : public Task::Action
	{
	public:
		bool run();
	};

	class CheckBarrier : public Task::Action
	{
	public:
		bool run();
	};

	class CheckVisible : public Task::Action
	{
	public:
		bool run();
	};

	class CanMoveTo : public Task::Action
	{
		Pathfinding::Pathfinder* pathfinder;
	public:
		void init();
		bool run();
	};
}