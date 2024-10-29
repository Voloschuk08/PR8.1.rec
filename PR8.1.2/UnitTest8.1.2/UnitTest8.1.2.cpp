#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8.1.2/PR8.1.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest812
{
	TEST_CLASS(UnitTest812)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char* str = "hello no world";
			char dest[50];
			dest[0] = '\0';

			ReplaceNoWithStars(dest, str, 0, dest);

			Assert::AreEqual("hello *** world", dest, "The pair 'no' should be replaced with '***'.");
		}
	};
}
