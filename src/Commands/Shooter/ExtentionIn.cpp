#include <Commands/Shooter/ExtentionIn.h>

ExtentionIn::ExtentionIn():
  CommandBase("ExtentionIn")
{
  Requires(extention.get());

}

void ExtentionIn::Initialize() {}

void ExtentionIn::Execute() {
  shooter->SetExtension(shooter->extention_in);



}

bool ExtentionIn::IsFinished() {
  return false;
}

void ExtentionIn::End() {

}

void ExtentionIn::Interrupted() {
  this->End();
}
