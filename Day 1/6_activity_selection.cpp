/*
Greedy Programming approach
https://en.wikipedia.org/wiki/Greedy_algorithm
https://www.geeksforgeeks.org/greedy-algorithms/
https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
*/

// sample input      6      1 2     3 4     0 6     5 7     8 9     5 9


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//comparison function here
//compares ending time of two pairs(tasks)
bool comp_ending_time(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    //number of activities
    int n;
    cin >> n;

    //vector to store the tasks as pairs of (starting time, ending time)
    vector<pair<int, int> > tasks(n);
    for(int i = 0; i < n; i++)
        cin >> tasks[i].first >> tasks[i].second;

    //sort the tasks in ascending order on the basis of ending time
    sort(tasks.begin(), tasks.end(), comp_ending_time);

    int num_tasks_possible = 0;
    int prev_ending_time = 0;
    for(int i = 0; i < tasks.size(); i++)
    {
        //if i'th task starts after or on ending time of previous task, slect the task
        if(tasks[i].first >= prev_ending_time)
        {
            //select this task
            num_tasks_possible++;

            //set ending time equal to the ending time of this i.e. i'th task
            prev_ending_time = tasks[i].second;
        }
    }

    printf("%d tasks possible \n",num_tasks_possible);
    return 0;
}
