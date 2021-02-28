// By: Gonçalo Leão

#include "exercises.h"
#include <algorithm>

bool Activity::operator==(const Activity &a2) const {
    return start == a2.start && finish == a2.finish;
}

bool Activity::operator<(const Activity &a2) const {
    return finish < a2.finish;
}

void ordenar(std::vector<Activity> A){
    for(int i=0; i<A.size()-2; i++){
        for(int j=i+1; j<A.size()-1; j++){
            if(A.at(j) < A.at(i)) iter_swap(A.begin()+i, A.begin()+j);
        }
    }
}

std::vector<Activity> earliestFinishScheduling(std::vector<Activity> A) {
    ordenar(A);
    std::vector<Activity> res;
    Activity min = A.at(0);
    int it;

    for(int i = 0; i < A.size(); i++)
        if(A.at(i)<min){
            it = i;
            min = A.at(i);
        }

    res.push_back(min);
    A.erase(A.begin() + it);

    for(int j = 0; j < A.size(); j++) {
        if(A.at(j).start > min.finish){
            min = A.at(j);
            res.push_back(A.at(j));
        }
    }
    return res;

}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(TP1_Ex6, activityScheduling) {
    std::vector<Activity> A = {{10,20}, {30, 35}, {5, 15}, {10, 40}, {40, 50}};
    std::vector<Activity> V = earliestFinishScheduling(A);
    EXPECT_EQ(V.size(), 3 );
    ASSERT_THAT(earliestFinishScheduling(A),  ::testing::ElementsAre(Activity(5, 15), Activity(30, 35), Activity(40, 50)));
}