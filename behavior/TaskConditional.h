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
		//void preRun();
		void init();
		bool run();
	};
}