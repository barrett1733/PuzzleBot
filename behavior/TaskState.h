#include "Task.h"

namespace Task
{
	class BarrierOn : public Task::Action
	{
	public:
		bool run();
	};

	class BarrierOff : public Task::Action
	{
	public:
		bool run();
	};

	class VisibleOn : public Task::Action
	{
	public:
		bool run();
	};

	class VisibleOff : public Task::Action
	{
	public:
		bool run();
	};
}