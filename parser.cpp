//#include "parser.h"
//#include <iostream>
//#include <vector>
//#include <tuple>
//#include <string>
//#include <queue>
//#include <iomanip>
//
//using namespace std;
//
//vector<tuple<string, int, int>> processes;
//vector<int> finishTime;
//vector<int> turnAroundTime;
//vector<float> normTurn;
//vector<vector<char>> timeline;
//int process_count = 0;
//int last_instant = 0;
//
//string getProcessName(tuple<string, int, int> &a) {
//    return get<0>(a);
//}
//
//int getArrivalTime(tuple<string, int, int> &a) {
//    return get<1>(a);
//}
//
//int getServiceTime(tuple<string, int, int> &a) {
//    return get<2>(a);
//}
//
//double calculate_response_ratio(int wait_time, int service_time) {
//    return (wait_time + service_time) * 1.0 / service_time;
//}
