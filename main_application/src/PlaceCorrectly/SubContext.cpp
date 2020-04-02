#include "PlaceCorrectly/SubContext.hpp"
#include "PlaceCorrectly/PlacePieceInPuzzle.hpp"

SubContext::SubContext(Context* aParentContext) : parentContext(aParentContext)
{
  setState(std::make_shared<PlacePieceInPuzzle>());
}