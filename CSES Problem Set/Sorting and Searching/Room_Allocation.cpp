#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 2e5;  // Maximum number of events

int N;  // Number of events
int roomAssignments[MAX_N];  // Store room assignments for each event
vector<pair<pair<int, int>, int>> events(MAX_N);  // Store start and end times with original indices

int main() {
    cin >> N;  // Input number of events
    events.resize(N);

    // Input each event's start and end times
    for (int i = 0; i < N; i++) {
        cin >> events[i].first.first >> events[i].first.second;
        events[i].second = i;  // Store the original index for later use
    }

    // Sort events by their start times
    sort(events.begin(), events.end());

    int lastRoom = 0;  // Count of rooms used
    priority_queue<pair<int, int>> pq;  // Min-heap to store departure times

    for (int i = 0; i < N; i++) {
        // If no rooms are occupied or the earliest room frees up before the current event starts
        if (pq.empty() || -pq.top().first >= events[i].first.first) {
            lastRoom++;  // Use a new room
            // Push the departure time (negative for min-heap) and room number
            pq.push(make_pair(-events[i].first.second, lastRoom));
            roomAssignments[events[i].second] = lastRoom;  // Assign room to the event
        } else {
            // Reuse the earliest room
            pair<int, int> minRoom = pq.top();  // Get the room that will be free soon
            pq.pop();  // Remove it from the heap
            pq.push(make_pair(-events[i].first.second, minRoom.second));  // Update with new departure time
            roomAssignments[events[i].second] = minRoom.second;  // Assign the reused room to the event
        }
    }

    cout << lastRoom << "\n";  // Output the total number of rooms used
    for (int i = 0; i < N; i++) {
        cout << roomAssignments[i] << " ";  // Output room assignments for each event
    }
}
