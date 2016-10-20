#pragma once

#include "CommandBase.h"

class IntakeAuto: public CommandBase {
public:
  IntakeAuto();
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();
};
