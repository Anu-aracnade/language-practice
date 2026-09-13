#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class SnapshotArray {
private:
    vector<vector<pair<int, int>>> history;
    int snap_id = 0;

public:
    SnapshotArray(int length) {
        history.resize(length);
        for (int i = 0; i < length; ++i) {
            history[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        if (!history[index].empty() && history[index].back().first == snap_id) {
            history[index].back().second = val;
        } else {
            history[index].push_back({snap_id, val});
        }
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(history[index].begin(), history[index].end(), make_pair(snap_id, numeric_limits<int>::max()));
        return prev(it)->second;
    }
};

int main() {
    SnapshotArray* obj = new SnapshotArray(3);
    obj->set(0, 5);
    cout << obj->snap() << endl;
    obj->set(0, 6);
    cout << obj->get(0, 0) << endl;
    delete obj;
    return 0;
}
