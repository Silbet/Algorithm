#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

map<string, int> carAccess; // 차 번호 : 입차시간
map<string, int> carParkingTime; // 차 번호 : 누적 주차시간

struct FeeChart {
    int defaultTime;
    int defaultFee;
    int extraTime;
    int extraFee;
    
    FeeChart (int dT, int dF, int eT, int eF) {
        defaultTime = dT;
        defaultFee = dF;
        extraTime = eT;
        extraFee = eF;
    }
};

struct CarRecord {
    int time;
    string carNumber;
    string state;
    
    CarRecord (int t, string cN, string s) {
        time = t;
        carNumber = cN;
        state = s;
    }  
};

FeeChart makeFeeChart(vector<int> fees) {
    return FeeChart(fees[0], fees[1], fees[2], fees[3]);
}

CarRecord makeCarRecord(string record) {
    
    stringstream ss(record);
    
    string times;
    string carNumber;
    string state;

    ss >> times >> carNumber >> state;    
   
    
    int hour = stoi(times.substr(0, 2));
    int minute = stoi(times.substr(3, 2));
    
    int time = (hour * 60) + minute;
    
    return CarRecord(time, carNumber, state);
}

void calculateParkingTime(CarRecord carRecord) {
    
    if (carRecord.state == "IN") {
        // map에 입차 시간 기록
        carAccess[carRecord.carNumber] = carRecord.time;
    }
    
    if (carRecord.state == "OUT") {
        // 시간 누적하고 map에서 삭제
        int parkingTime = carRecord.time - carAccess[carRecord.carNumber];
        carParkingTime[carRecord.carNumber] += parkingTime;
        
        carAccess.erase(carRecord.carNumber);
    }
}

void calulateOnlyComeIn() {
    for (const auto& [carNumber, time] : carAccess) {
        carParkingTime[carNumber] += (23 * 60 + 59) - time;
    }
}

vector<int> calculateFee(FeeChart feeChart) {
    vector<int> fee;
    
    for (const auto& [carNumber, time] : carParkingTime) {
        // 기본 시간 이하인 경우
        if (time <= feeChart.defaultTime) {
            fee.push_back(feeChart.defaultFee);
            continue;
        }
        // 기본 시간 초과인 경우
        fee.push_back(feeChart.defaultFee + ceil((double)(time - feeChart.defaultTime) / feeChart.extraTime) * feeChart.extraFee);
    }
    
    return fee;
}


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    // 요금표 만들기
    FeeChart feeChart = makeFeeChart(fees);
    
    // 내역의 개수 만큼 records 순환하기
    for (int i = 0; i < records.size(); i++) {
        // records 분석해서 carRecord 만들기
        CarRecord carRecord = makeCarRecord(records[i]);
        
        // carRecord로 누적 주차 시간 계산
        calculateParkingTime(carRecord);
    }
    // 출차가 되지 않은 차량의 주차 시간 계산
    calulateOnlyComeIn();
    
    // 누적 주차 시간에 따른 요금 일괄 계산
    answer = calculateFee(feeChart);
    
    return answer;
}