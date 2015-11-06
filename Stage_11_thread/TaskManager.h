#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "stdafx.h"
#include <iostream>
#include "TaskPool.h"
#include "LogManager.h"

#define LOGMSG(MSG) stage_11::TaskManager::getGlobalLogger().log(MSG);
#define LOGERR(MSG) stage_11::TaskManager::getGlobalLogger().logError(MSG);

namespace stage_11{

	class TaskManager{
	public:
		TaskManager(unsigned int threadcount);
		~TaskManager();

		static void pushTask(Task* t){
			singleton->tp.pushTask(t);
		}
		static void pushTaskList(std::list<Task*>& t){
			singleton->tp.pushTaskList(t);
		}
		static TaskManager& getSingleton(){
			return *singleton;
		}
		static LogManager& getGlobalLogger(){
			return singleton->globalLogger;
		}
	private:
		static TaskManager* singleton;
	protected:
		TaskPool tp;
		LogManager globalLogger;
	};
}

#endif