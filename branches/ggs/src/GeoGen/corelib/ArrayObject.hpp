#pragma once

#include <string>
#include <vector>

#include "../runtime/ManagedObject.hpp"

namespace geogen
{
	namespace corelib
	{
		class ArrayObject : public runtime::ManagedObject
		{
		public:
			typedef std::map<ManagedObject*, ManagedObject*> BackingCollection;
			typedef BackingCollection::iterator iterator;
			typedef BackingCollection::const_iterator const_iterator;
			typedef BackingCollection::reverse_iterator reverse_iterator;
			typedef BackingCollection::const_reverse_iterator const_reverse_iterator;
		private:
			BackingCollection array;
			int maxIntegerKey;
		public:
			ArrayObject(runtime::VirtualMachine* vm, runtime::TypeDefinition const* type) : ManagedObject(vm, type)
			{
			};

			virtual ~ArrayObject();

			inline BackingCollection& GetBackingCollection() { return this->array; }
			inline BackingCollection const& GetBackingCollection() const { return this->array; }

			inline const_iterator Begin() const { return *(const_iterator*)(&this->array.begin()); }
			inline const_iterator End() const { return *(const_iterator*)(&this->array.end()); }

			inline iterator Begin() { return this->array.begin(); }
			inline iterator End() { return this->array.end(); }

			inline const_reverse_iterator RBegin() const { return *(const_reverse_iterator*)(&this->array.rbegin()); }
			inline const_reverse_iterator REnd() const { return *(const_reverse_iterator*)(&this->array.rend()); }

			inline reverse_iterator RBegin() { return this->array.rbegin(); }
			inline reverse_iterator REnd() { return this->array.rend(); }

			void Set(runtime::VirtualMachine* vm, CodeLocation location, ManagedObject* key, ManagedObject* value);
			ManagedObject* Get(runtime::VirtualMachine* vm, CodeLocation location, ManagedObject* key);

			ManagedObject* Front(runtime::VirtualMachine* vm, CodeLocation location);
			ManagedObject* Back(runtime::VirtualMachine* vm, CodeLocation location);

			//ManagedObject* PushFront(runtime::VirtualMachine* vm, ManagedObject* object);
			ManagedObject* PushBack(runtime::VirtualMachine* vm, CodeLocation location, ManagedObject* object);

			void PopFront(runtime::VirtualMachine* vm, CodeLocation location, ManagedObject* object);
			void PopBack(runtime::VirtualMachine* vm, CodeLocation location, ManagedObject* object);

			bool ContainsKey(runtime::VirtualMachine* vm, CodeLocation location, ManagedObject* object);
			bool ContainsValue(runtime::VirtualMachine* vm, CodeLocation location, ManagedObject* object);

			//void Insert(runtime::VirtualMachine* vm, unsigned index, ManagedObject* object);
			//void RemoveAt(runtime::VirtualMachine* vm, CodeLocation location, unsigned index);
			void Remove(runtime::VirtualMachine* vm, CodeLocation location, ManagedObject* object);

			inline unsigned Count() const { return this->array.size(); };

			virtual std::string GetStringValue() const;
		};
	}
}