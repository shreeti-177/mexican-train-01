#include "pch.h"
#include "CppUnitTest.h"
#include "../Mexican_Train/Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
	TEST_CLASS(Game)
	{
	public:
		
		TEST_METHOD(Here)
		{
			Game game;
			int n = 10;
			//int a = game.Here;
			Assert::AreEqual(n, 10);
		}
	};
}
