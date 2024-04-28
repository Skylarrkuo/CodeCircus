#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �����ṹ��
struct Activity {
    int start;
    int end;
    int index;

    Activity(int s, int e, int i) : start(s), end(e), index(i) {}
};

// �ȽϺ�����������ʱ������
bool compareActivity(const Activity &a, const Activity &b) {
    return a.end < b.end;
}

vector<int> activitySelection(vector<Activity> &activities) {
    vector<int> selectedActivities;
    // ������ʱ������
    sort(activities.begin(), activities.end(), compareActivity);

    // ��һ���һ���ᱻѡ��
    selectedActivities.push_back(activities[0].index);

    int lastEndTime = activities[0].end;
    // �ӵڶ������ʼ�����������ʼʱ����ڵ�����һ��ѡ�л�Ľ���ʱ�䣬��ô��ѡ��
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

    // ������
    cout << "ѡ�еĻ���ϣ�" << endl;
    for (int i = 0; i < selectedActivities.size(); ++i) {
        cout << "(" << activities[selectedActivities[i] - 1].start << "," << activities[selectedActivities[i] - 1].end << ") ";
    }
    cout << endl;

    return 0;
}