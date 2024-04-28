#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义活动结构体
struct Activity {
    int start;
    int end;
    int index;

    Activity(int s, int e, int i) : start(s), end(e), index(i) {}
};

// 比较函数，按结束时间排序
bool compareActivity(const Activity &a, const Activity &b) {
    return a.end < b.end;
}

vector<int> activitySelection(vector<Activity> &activities) {
    vector<int> selectedActivities;
    // 按结束时间排序
    sort(activities.begin(), activities.end(), compareActivity);

    // 第一个活动一定会被选中
    selectedActivities.push_back(activities[0].index);

    int lastEndTime = activities[0].end;
    // 从第二个活动开始遍历，如果开始时间大于等于上一个选中活动的结束时间，那么就选中
    for (int i = 1; i < activities.size(); ++i) {
        if (activities[i].start >= lastEndTime) {
            selectedActivities.push_back(activities[i].index);
            lastEndTime = activities[i].end;
        }
    }

    return selectedActivities;
}

int main() {
    int n;
    cin >> n;

    vector<Activity> activities;
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        activities.push_back(Activity(start, end, i + 1));
    }

    vector<int> selectedActivities = activitySelection(activities);

    // 输出结果
    cout << "选中的活动集合：" << endl;
    for (int i = 0; i < selectedActivities.size(); ++i) {
        cout << "(" << activities[selectedActivities[i] - 1].start << "," << activities[selectedActivities[i] - 1].end << ") ";
    }
    cout << endl;

    return 0;
}