#include <iostream>
#include <queue>

using namespace std;

int prv[100001];
int dist[100001];
int N, K;
deque<int> q, r;

void func(int ncur, int cur) {
    if (ncur >= 0 && ncur <= 100001 && dist[ncur] == 0) {
        dist[ncur] = dist[cur] + 1;
        prv[ncur] = cur;
        q.push_back(ncur);
    }
}

int main() {
    cin >> N >> K;
    q.push_back(N);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        
        if (cur == K) {
            cout << dist[cur] << endl;
            r.push_front(cur);
            while (cur != N) {
                r.push_front(prv[cur]);
                cur = prv[cur];
            }
            while (!r.empty()) {
                cout << r.front() << " ";
                r.pop_front();
            }
            cout << endl;
            return 0;
        }
        func(cur-1, cur);
        func(cur+1, cur);
        func(cur*2, cur);
    }
}
