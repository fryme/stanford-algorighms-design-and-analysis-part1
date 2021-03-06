#include <iostream>
#include <gtest/gtest.h>
#include "scc.h"

using namespace std;

const string input = "1 7\n7 4\n7 9\n4 1\n9 6\n6 3\n3 9\n6 8\n8 2\n2 5\n5 8\n";

TEST(MincutTest, SCCReadWriteTest)
{
	DirectedGraph g;
	g.ReadFromString(input);
	stringstream s;
	g.Print(s);

	string expectedOut("1 7\n2 5\n3 9\n4 1\n5 8\n6 3 8\n7 4 9\n8 2\n9 6\n");

	ASSERT_TRUE(expectedOut == s.str());
}

TEST(MincutTest, SimpleDFS)
{
	DirectedGraph g;
	g.ReadFromString(input);
	std::vector<uint32_t> newOrder;
	g.DFS(newOrder);
}

TEST(MincutTest, ReverseGraph)
{
	/*
	DirectedGraph g;
	g.ReadFromString(input);
	std::vector<uint32_t> newOrder;
	g.DFS(newOrder);
	DirectedGraph gRev = g.ReverseGraph(newOrder);
	*/
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}