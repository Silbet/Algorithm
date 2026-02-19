#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int dateToDays(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    
    return day + month * 28 + year * 28 * 12;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int today_days = dateToDays(today);
    
    map<char, int> termMap;
    
    for (string term : terms) {
        stringstream ss(term);
        
        char type;
        int month;
        
        ss >> type >> month;
        
        termMap[type] = month;
    }
    
    
    for (int i = 0; i < privacies.size(); i++) {
        string date = privacies[i].substr(0, 10);
        char term = privacies[i].back();
        
        int days = dateToDays(date);
        int term_day = termMap[term] * 28;
        if (today_days >= days + term_day) {
            answer.push_back(i + 1);
        }
    }
    
    
    return answer;
}