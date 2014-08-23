#include "HeightProfileTypeDefinition.hpp"
#include "../runtime/ManagedObject.hpp"

#include "HeightProfileAbsFunctionDefinition.hpp"
#include "HeightProfileAddFunctionDefinition.hpp"
#include "HeightProfileBlurFunctionDefinition.hpp"
#include "HeightProfileClampHeightsFunctionDefinition.hpp"
#include "HeightProfileCombineFunctionDefinition.hpp"
#include "HeightProfileCropHeightsFunctionDefinition.hpp"

#include "HeightProfileFlatFunctionDefinition.hpp"
#include "HeightProfileFromArrayFunctionDefinition.hpp"
#include "HeightProfileGradientFunctionDefinition.hpp"

using namespace geogen;
using namespace corelib;
using namespace runtime;
using namespace std;

HeightProfileTypeDefinition::HeightProfileTypeDefinition() : RendererTypeDefinition(GG_STR("HeightProfile")) 
{
	this->GetFunctionDefinitions().AddItem(new HeightProfileAbsFunctionDefinition(this));
	this->GetFunctionDefinitions().AddItem(new HeightProfileAddFunctionDefinition(this));
	this->GetFunctionDefinitions().AddItem(new HeightProfileBlurFunctionDefinition(this));
	this->GetFunctionDefinitions().AddItem(new HeightProfileClampHeightsFunctionDefinition(this));
	this->GetFunctionDefinitions().AddItem(new HeightProfileCombineFunctionDefinition(this));
	this->GetFunctionDefinitions().AddItem(new HeightProfileCropHeightsFunctionDefinition(this));

	this->GetStaticFunctionDefinitions().AddItem(new HeightProfileFlatFunctionDefinition(this));
	this->GetStaticFunctionDefinitions().AddItem(new HeightProfileFromArrayFunctionDefinition(this));
	this->GetStaticFunctionDefinitions().AddItem(new HeightProfileGradientFunctionDefinition(this));
}