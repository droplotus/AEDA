// By: Gonçalo Leão

#include "exercises.h"

#include <algorithm>
#include <vector>
#include <iostream>

double minimumAverageCompletionTime(std::vector<unsigned int> tasks, std::vector<unsigned int> &orderedTasks) {
    for(int i=0; i<tasks.size()-1; i++){
        for(int j=i+1; j<tasks.size(); j++){
            if(tasks.at(j) < tasks.at(i)) iter_swap(tasks.begin() + i, tasks.begin() + j);
        }
    }
    orderedTasks = tasks;
    double avg = 0.0;
    double total = 0.0;

    for(int i=0; i<orderedTasks.size(); i++){
        avg += orderedTasks.at(i);
        total += avg;
    }

    return total/orderedTasks.size();
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(TP1_Ex7, taskOrdering) {
    std::vector<unsigned int> tasks = {15, 8, 3, 10};
    std::vector<unsigned int> orderedTasks;
    double averageTime = minimumAverageCompletionTime(tasks, orderedTasks);
    EXPECT_EQ(orderedTasks.size(), 4 );
    ASSERT_NEAR(averageTime, 17.75, 0.00001);
    ASSERT_THAT(orderedTasks,  ::testing::ElementsAre(3,8,10,15));
}