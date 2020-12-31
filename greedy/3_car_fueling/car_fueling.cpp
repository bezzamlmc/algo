#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::endl;

//#define TEST1 1

bool is_feasible(int dist, int tank, vector<int>& stops)
{
 // Assuming the car starts with a full tank the minimum # of stops is dist/tank -1
    bool status = true;
    int minStops = int ((float)dist/(float)tank + 0.5) - 1;
    if (minStops > (int)stops.size())
        return false;
// If the stations are spaced by more than tank, there is no solution
    if (stops[0] > tank)
        return false;
    for (int i=0;i< (int)stops.size()-1;i++) {
        if ((stops[i+1] - stops[i]) > tank) {
            status = false;
            break;
        }
    }
    if ((dist - stops[stops.size()-1]) > tank)
            return false;
    return status;
}

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    bool status = is_feasible(dist,tank,stops);
    if (!status)
        return -1;
    int current = 0;
    int stopIndex = 0;
    int newStop = 0;
    int nStops = 0;
    int totalStops = (int) stops.size();
    while ((dist - current) > tank) {
 // Find the furthest stop such that (traveled - stop_location) <= tank
 #if defined TEST1
        cout << "Refueling after " << current << endl;
 #endif
        while((stopIndex < totalStops) && (stops[stopIndex]-current) <= tank) {
            newStop = stopIndex;
#if defined TEST1
            cout << "stop " << stopIndex << " " << stops[stopIndex] << " " << current <<endl;
#endif
            stopIndex++;
        }
        current = stops[newStop];
        nStops++;
#if defined TEST1
        cout << "Stop " << nStops <<endl;
        cout << "Distance to destination " << dist - current << endl;
#endif
    }
    return nStops;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
