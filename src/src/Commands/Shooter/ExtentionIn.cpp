#include <Commands/Shooter/ExtentionIn.h>
#include <Commands/Shooter/Shoot.h>
#include <Commands/Shooter/ShooterUp.h>

ExtentionIn::ExtentionIn():
  CommandBase("ExtentionIn")
{


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
