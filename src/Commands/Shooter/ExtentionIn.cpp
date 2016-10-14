#include <Commands/Shooter/ExtentionInIn.h>
#include <Commands/Shooter/Shoot.h>

ExtentionIn::ExtentionIn():
  CommandBase("ExtentionIn")
{


}

void ExtentionIn::Initialize() {}

void ExtentionIn::Execute() {
  shooter->SetExtention(extention_in);



}

bool ExtentionIn::IsFinished() {
  return false;
}

void ExtentionIn::End() {

}

void ExtentionIn::Interrupted() {
  this->End();
}
