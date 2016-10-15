#include <Commands/Shooter/ExtentionOut.h>
#include <Commands/Shooter/Shoot.h>

ExtentionOut::ExtentionOut():
  CommandBase("ExtentionOut")
{

}

void ExtentionOut::Initialize() {}

void ExtentionOut::Execute() {
  shooter->SetExtension(shooter->extention_out);



}

bool ExtentionOut::IsFinished() {
  return false;
}

void ExtentionOut::End() {

}

void ExtentionOut::Interrupted() {
  this->End();
}
