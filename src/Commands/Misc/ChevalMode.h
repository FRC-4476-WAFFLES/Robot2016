#pragma once

#include <CommandBase.h>
#include "WPILib.h"

class ChevalMode: public CommandBase {
private:
  int mode;
  double start_angle;
  double start_distance;
  Timer timer;
public:
  ChevalMode();
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();
  bool drive_to(double distance, double angle);
};
