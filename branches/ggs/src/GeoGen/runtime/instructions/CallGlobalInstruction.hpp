#pragma once

#include <string>

#include "Instruction.hpp"

namespace geogen 
{
	namespace runtime 
	{
		namespace instructions
		{
			class CallGlobalInstruction : public Instruction
			{
			private:
				int functionName;
				int argumentCount;
			public:				
				CallGlobalInstruction(CodeLocation location, std::string functionNameIndex, int argumentCount) : Instruction(location)
				{
					this->functionName = functionName;
					this->argumentCount = argumentCount;
				}

				virtual void Serialize(std::iostream& stream) const { stream << "CallGlobal " << functionName << " " << argumentCount << std::endl; }
			};
		}
	}
}