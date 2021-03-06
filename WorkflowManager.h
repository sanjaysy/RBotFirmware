// RBotFirmware
// Rob Dobson 2016

#pragma once

#include "application.h"
#include "CommandQueue.h"

class WorkflowManager
{
private:
    CommandQueue _cmdQueue;

public:
    WorkflowManager()
    {
    }

    ~WorkflowManager()
    {
    }

    // Init
    void init(const char* configStr)
    {
        Log.info("Constructing WorkflowManager from %s", configStr);
        String cmdQueueCfg = ConfigManager::getString("CommandQueue", "NONE", configStr);

        _cmdQueue.init(cmdQueueCfg);
    }

    // Check if new queue full
    bool isFull()
    {
        return _cmdQueue.isFull();
    }

    // Add to workflow
    bool add(const char* pCmdStr)
    {
        return _cmdQueue.add(pCmdStr);
    }

    // Get from workflow
    bool get(String& cmdStr)
    {
        return _cmdQueue.get(cmdStr);
    }

    // Get from workflow
    bool get(CommandElem& cmdElem)
    {
        return _cmdQueue.get(cmdElem);
    }

};
