#include "controller/Init.hpp"
#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

namespace controller
{
  Init::Init(){

  };

  Init::~Init(){};

  void Init::entryAction(Context*)
  {
  }

  void Init::doActivity(Context* aContext)
  {
  }

  void Init::exitAction(Context* aContext)
  {
    aContext->currentConfiguration() = aContext->goalConfiguration();
  }
} // namespace controller