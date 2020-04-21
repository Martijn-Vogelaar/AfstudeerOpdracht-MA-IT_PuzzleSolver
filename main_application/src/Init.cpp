#include "Init.hpp"
#include <memory>
#include "Ready.hpp"
#include "Context.hpp"
Init::Init()
{
}

Init::~Init() {}

void Init::entryAction(Context *)
{
}

void Init::doActivity(Context *context)
{
    context->setState(std::make_shared<Ready>());
}

void Init::exitAction(Context *)
{
}
