//
//  main.cpp
//  finalLab
//
//  Created by Олеся Мартынюк on 21.05.2020.
//  Copyright © 2020 Olesia Martinyuk. All rights reserved.
//

#include <iostream>
#include "task1.h"
#include "task2.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // task 1
    
    cout << " ============= TASK 1 ============= " << endl << endl;
    
    vector<string> array = {"i", "love", "quarantine", "so", "much", "somebody", "help", "me"};
    vector<string> res = sortBySizeUp(array);
    printVector(res);
    
    res = sortByStringUp(array);
    printVector(res);
    
    res = sortByLastLetter(array);
    printVector(res);
    
    res = sortBySizeDown(array);
    printVector(res);
    
    res = sortByStringDown(array);
    printVector(res);
    
    
    // task 2
    
    cout << endl << " ============= TASK 2 ============= " << endl << endl;
    
    res = array;
    flagDone = false;
    thread th(bubbleSortThreaded, std::ref(res), [](string a, string b){ return a > b ? true : false;});
    while(!flagDone){
        if (flagPrint){
            mtx.lock();
            printVector(res);
            flagPrint = false;
            mtx.unlock();
        }
    }
    th.join();
    
}
