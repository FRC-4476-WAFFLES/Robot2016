#pragma once

#include "CommandBase.h"

class OuttakeShootAuto: public CommandBase {
private:
  Timer t;
public:
  OuttakeShootAuto();
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();
};
