#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Item {
    double unit_value;
    int quantity;

    Item(double _unit_value, int _quantity):
        unit_value(_unit_value),quantity(_quantity) {}

    bool operator > (const Item & other) const
    {
        return(unit_value > other.unit_value);
    }

    bool operator < (const Item & other) const
    {
        return(unit_value < other.unit_value);
    }

    bool operator == (const Item & other) const
    {
        return(unit_value == other.unit_value);
    }
};


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

// Create items list: price per unit and available quantity
  vector<Item> items; // vector of items: unit value and quantity
  for (int i = 0; i < (int)weights.size(); i++) {
    double value = (double) values[i]/(double)weights[i];
    items.push_back(Item(value,weights[i]));
  }

// Sort by value in ascending order
  sort(items.begin(),items.end());

// Grab items, starting with maximum value per unit items
  int  remains = capacity;

  for (auto rit  = items.crbegin(); rit != items.crend() ; ++rit) {
      Item itm = *rit;
  #if defined TEST1
      cout << "remains " << remains << endl;
      cout << "current item value " << itm.unit_value << endl;
  #endif
      int grab = min(remains, itm.quantity);
  #if defined TEST1
      cout << "grab " << grab << endl;
  #endif
      remains = remains - grab;
      value = value + grab*itm.unit_value;
      if (remains == 0)
          break;
   }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
