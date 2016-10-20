#pragma once

#include "CommandBase.h"

class OuttakeShootAuto: public CommandBase {
private:
  std::unique_ptr<Timer> t;
  bool t_running;
public:
  OuttakeShootAuto();
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();
};
