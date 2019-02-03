#include <iostream>
#include <list>
#include <map>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  int sportsman_number;
  int position;
  map<int, list<int>::const_iterator> number_to_list_pointer;
  list<int> sportsmen_order;
  cin >> n;

  while(n){
    cin >> sportsman_number;
    cin >> position;

    if(number_to_list_pointer.count(position) == 0){
      sportsmen_order.push_back(sportsman_number);
      number_to_list_pointer[sportsman_number] = prev(sportsmen_order.end());
    } else{
      sportsmen_order.push_back(sportsman_number);
      auto it = number_to_list_pointer.at(position);
      sportsmen_order.splice(it, sportsmen_order, prev(sportsmen_order.end()));
      number_to_list_pointer[sportsman_number] = prev(it);
    }

    n--;
  }
  for(const auto& i: sportsmen_order){
    cout << i << " ";
  }
  cout << "\n";

  return 0;
}
