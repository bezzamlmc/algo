#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

//#define TEST1 1

struct Segment {
  int start, end;
  bool operator < (const Segment &s){
      if (start < s.start)
          return true;
      if (start > s.start)
          return false;
      return (end < s.end);
  }
  bool operator > (const Segment &s){
      if (start > s.start)
          return true;
      if (start < s.start)
          return false;
      return (end > s.end);
  }
  bool operator == (const Segment &s){
      return ((start == s.start) && (end == s.end));
  }
};

bool compare_ends(const Segment &s1, const Segment &s2)
{
    return (s1.end < s2.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;
// We find the segment with minimum end value and then remove all the segments which contain
// the points within this segment

// Sort segments by minimun end time
    sort(segments.begin(),segments.end(), compare_ends);

#if defined TEST1
    cout << "Sorted " << endl;
    cout << "list size before processing  " << segments.size() << endl;
#endif
    do  {
        int minEnd = segments[0].end;
        points.push_back(minEnd);
#if defined TEST1
        cout << "minEnd " << minEnd << endl;
#endif
        for (int i = 0; i < (int)segments.size();) {
#if defined TEST1
            cout << "Attempted removal " << i << " " << segments[i].start << " " << segments[i].end << endl;
#endif
            if ((minEnd >= segments[i].start) && (minEnd <= segments[i].end)) {
                segments.erase(segments.begin() + i );
#if defined TEST1

                cout << "Removed " << i << endl;
                cout << "list size after remove " << segments.size() << endl;
#endif

            }
            else
                i++;
        }
#if defined TEST1
        cout << "list size " << segments.size() << endl;
#endif
    } while (segments.size() > 0);
#if defined TEST1
  cout << " Number of points " << points.size() << endl;
#endif
  return points;
}

int main() {
  int n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    cout << points[i] << " ";
  }
}
