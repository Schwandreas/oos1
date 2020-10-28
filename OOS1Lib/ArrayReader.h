#pragma once
#include <memory>
#include <string>

// ReSharper disable once CppInconsistentNaming
namespace OOS1Library
{
	template <typename TItemType>
	class ArrayReader
	{


	public:
		std::unique_ptr<TItemType[]> arrayPtr;

		/**
		 * \brief A console dynamic array reader.
		 * \param arraySize Size of the dynamic array to create.
		 * \param typeName Name for prompting type info.
		 */
		explicit ArrayReader(int arraySize, std::string typeName)
		{
			this->arrayPtr = std::unique_ptr<TItemType[]>(new TItemType[arraySize]());
			this->arraySize = arraySize;
			this->currentItem = 0;
			this->typeName = typeName;
		}
		
		bool readNext();
		void readAll();
	private:
		std::string typeName;
		int arraySize;
		int currentItem;
	};

	/**
		 * \brief Prompt user for next item. Adds item to current array pointer location.
		 * \return Success indicator if next item slot is available.
		 */
	template <typename TItemType>
	bool ArrayReader<TItemType>::readNext()
	{
		std::cout << "\nPlease enter an " << this->typeName << " value: ";
		std::cin >> this->arrayPtr[this->currentItem];
		std::cout << this->arrayPtr[this->currentItem];
		++this->currentItem;
		return this->currentItem != this->arraySize;
	}

	/**
	 * \brief f Prompt user for all items.
	 */
	template <typename TItemType>
	void ArrayReader<TItemType>::readAll()
	{
		while (readNext())
		{
		}
	}
}
