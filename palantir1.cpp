//
//  palantir1.cpp
//  leetcode2016
//
//  Created by Shihao Zhang on 10/6/16.
//  Copyright © 2016 David Zhang. All rights reserved.
//

#include "palantir1.hpp"
bool isTrade(string& info){
    int idx = info.find('|');
    idx = info.find('|', idx+1);
    return idx != string::npos;
}
vector<string> parseInfo(string info){
    int idx = info.find('|'), lastIdx = 0;
    vector<string> answ;
    while (idx != string::npos) {
        answ.push_back(info.substr(lastIdx, idx-lastIdx));
        lastIdx = idx+1;
        idx = info.find('|', lastIdx);
    }
    answ.push_back(info.substr(lastIdx));
    return answ;
}
bool cmp(string& a, string& b){
    vector<string> left = parseInfo(a), right = parseInfo(b);
    int day1 = atoi(left[0].c_str()), day2 = atoi(right[0].c_str());
    if (day1 != day2) {
        return day1 < day2;
    }
    else{
        return left[1] < right[1];
    }
}
vector < string > findPotentialInsiderTraders(vector < string > datafeed) {
    vector<string> suspiciousActivities;
    unordered_map<string, set<pair<int, int>>>  traderRecord;   // name -> <Day, Volume>
    unordered_map<string, unordered_map<int, int>> traderLastPrice;
    int lastPrice = 0;
    for (string info : datafeed) {
        vector<string> holder = parseInfo(info);
        if (isTrade(info)) {    // this is a trade , store it
            string name = holder[1];
            int dayNum = atoi(holder[0].c_str()), volume = atoi(holder[3].c_str());
            traderRecord[name].insert({dayNum, volume});
            traderLastPrice[name][dayNum] = lastPrice;
        }
        else{   // this is a price feed
            int dayNum = atoi(holder[0].c_str()), priceNow = atoi(holder[1].c_str());
            for (auto traderIt = traderRecord.begin(); traderIt != traderRecord.end(); traderIt++) {
                vector<pair<int, int>> toRemove;
                
                for (auto it = traderIt->second.begin(); it != traderIt->second.end(); it++) {
                    int day = it->first, volume = it->second;
                    int priceDiff = abs(priceNow - traderLastPrice[traderIt->first][day]);
                    if (dayNum - day > 3) { // discard the info
                        toRemove.push_back(*it);
                    }
                    else if(volume * priceDiff >= 5000000){
                        suspiciousActivities.push_back(to_string(day) + "|" + traderIt->first);
                        toRemove.push_back(*it);
                        ++it;
                        while (it != traderIt->second.end() and it->first == day) {// remove same day
                            toRemove.push_back(*it);    it++;
                        }
                        --it;
                    }
                }
                for (auto p : toRemove) {
                    traderIt->second.erase(p);
                }
            }
            
            lastPrice = atoi(holder[1].c_str());
        }
    }
    sort(suspiciousActivities.begin(), suspiciousActivities.end(), cmp);
    return suspiciousActivities;
}

const vector<vector<string>> _testcases = {
//    {
//        "0|20",
//        "0|Kristil|SELL|3000",
//        "0|Will|BUY|5000",
//        "0|Tom|Buy|50000",
//        "0|Shilpa|Buy|1500",
//        "1|Tom|Buy|1500000",
//        "3|25",
//        "6|40",
//    },
//    {
//        "0|20",
//        "0|Kristil|SELL|3000",
//        "0|Will|BUY|5000",
//        "0|Tom|Buy|50000",
//        "0|Shilpa|Buy|1500",
//        "1|Tom|Buy|1500000",
//        "3|25",
//        "5|Shilpa|Sell|1500",
//        "8|Kristil|Sell|600000",
//        "9|Shilpa|Buy|500",
//        "10|15",
//        "11|5",
//        "14|Will|Buy|100000",
//        "15|Will|Buy|100000",
//        "16|Will|Buy|100000",
//        "17|25",
//    },
//    {
//        "0|10",
//        "0|Kristi|BUY|250000",
//        "0|Will|BUY|50000",
//        "0|Tom|SELL|30000",
//        "0|Shilpa|BUY|210000",
//        "0|Shilpa|BUY|230000",
//        "1|25",
//        "1|Shilpa|BUY|100000",
//        "2|35",
//        "2|Kristi|SELL|200000",
//        "3|5"
//    },
    {
        "0|10",
        "0|Shilpa|BUY|200",
        "0|Shilpa|BUY|500000",
        "1|25",
        "2|10000000",
    }
};

int main(){
    for (auto test : _testcases) {
        auto ret = findPotentialInsiderTraders(test);
        dzCommon::printArray(ret, true);
    }
    
    return 0;
}