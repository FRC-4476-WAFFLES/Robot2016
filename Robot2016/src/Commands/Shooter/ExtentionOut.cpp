#include <Commands/Shooter/ExtentionOutIn.h>
#include <Commands/Shooter/Shoot.h>

ExtentionOut::ExtentionOut():
  CommandBase("ExtentionOut")
{

}

void ExtentionOut::Initialize() {}

void ExtentionOut::Execute() {
  shooter->SetExtention(extention_out);



}

bool ExtentionOut::IsFinished() {
  return false;
}

void ExtentionOut::End() {

}

void ExtentionOut::Interrupted() {
  this->End();
}
