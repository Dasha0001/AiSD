using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForRBTree
{
	TEST_CLASS(UnitTestForRBTree)
	{
	public:
		
		TEST_METHOD(insertFind)
		{
			RBTree<int, int> newTree;
			newTree.insert(55, 5);
			newTree.insert(40, 88);
			newTree.insert(65, 10);
			newTree.insert(75, 15);
			newTree.insert(60, 6);
			newTree.insert(57, 11);

			Assert::IsTrue(newTree.Find(55) == 5);

			Assert::IsTrue(newTree.Find(40) == 88);
			Assert::IsTrue(newTree.Find(57) == 11);
			Assert::IsTrue(newTree.Find(65) == 10);
			Assert::IsTrue(newTree.Find(75) == 15);
			Assert::IsTrue(newTree.Find(60) == 6);


		}

		TEST_METHOD(remove)
		{
			RBTree<int, int> newTree;
			newTree.insert(55, 5);
			newTree.insert(40, 88);
			newTree.insert(65, 10);
			newTree.insert(75, 15);
			newTree.insert(60, 6);
			newTree.insert(57, 11);

			newTree.remove(40);
			newTree.remove(60);
			newTree.remove(57);
			newTree.remove(75);
			newTree.remove(65);

			auto keys = newTree.get_keys();
			auto value = newTree.get_values();

			Assert::AreEqual(keys->GetData(0), 55);
			Assert::AreEqual(value->GetData(0), 5);



			RBTree<int, int> newTree1;
			newTree1.insert(55, 5);
			newTree1.insert(40, 88);
			newTree1.insert(65, 10);
			newTree1.insert(75, 15);
			newTree1.insert(60, 6);
			newTree1.insert(57, 11);

			newTree1.remove(40);


			Assert::IsTrue(newTree1.Find(55) == 5);
			Assert::IsTrue(newTree1.Find(57) == 11);
			Assert::IsTrue(newTree1.Find(65) == 10);
			Assert::IsTrue(newTree1.Find(75) == 15);
			Assert::IsTrue(newTree1.Find(60) == 6);



		}

		TEST_METHOD(get_keys)
		{
			RBTree<int, int> newTree;
			newTree.insert(55, 5);
			newTree.insert(40, 88);
			newTree.insert(65, 10);
			newTree.insert(75, 15);
			newTree.insert(60, 6);
			newTree.insert(57, 11);

			newTree.remove(40);
			newTree.remove(60);
			newTree.remove(57);
			newTree.remove(75);


			auto keys = newTree.get_keys();
			auto value = newTree.get_values();

			Assert::AreEqual(keys->GetData(0), 55);
			Assert::AreEqual(keys->GetData(1), 65);


		}

		TEST_METHOD(get_values)
		{
			RBTree<int, int> newTree;
			newTree.insert(55, 5);
			newTree.insert(40, 88);
			newTree.insert(65, 10);
			newTree.insert(75, 15);
			newTree.insert(60, 6);
			newTree.insert(57, 11);

			newTree.remove(40);
			newTree.remove(60);
			newTree.remove(57);
			newTree.remove(75);


			auto keys = newTree.get_keys();
			auto value = newTree.get_values();


			Assert::AreEqual(value->GetData(0), 5);
			Assert::AreEqual(value->GetData(1), 10);

		}

		TEST_METHOD(RBclear) {
			RBTree<int, int> newTree;
			newTree.insert(55, 5);
			newTree.insert(15, 10);
			newTree.insert(2, 10);
			newTree.insert(40, 88);
			newTree.insert(10, 10);
			newTree.insert(9, 10);



			newTree.clear();

			Assert::IsNull(newTree.root);

		}
	};
}
