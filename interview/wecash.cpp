/*==================================================*\
 * title: 编写一个线程安全的红包类
 * description: 实现存钱、发钱，确保每次都有钱可发
\*==================================================*/



#include <iostream>
#include <pthread.h>
#include <stdlib.h>
using namespace std;

class Solution(){
public:
    // put money, specify total number & times
    static void put_money(double number, int times){
        money_pool = number;
        count = times;
    }
    
    static double get_money(){
        // check withdraw times
        pthread_mutex_lock( &m_mutex );
        if (count == 0)return 0;
        else if (count == 1){
            opened.push_back(money_pool);
            count--;
            val = money_pool;
        }else{
            double val = double(rand()%(money_pool*100 - count))/100;
            opened.push_back(val);
            money_pool -= val;
            count--;
        }
        pthread_mutex_unlock( &m_mutex );
        return val;
    }
    
    static vector<double> list_opened(){
        pthread_mutex_lock( &m_mutex );
        vector<double> result = opened;
        pthread_mutex_unlock( &m_mutex );
        return result;
    }

private:
    static double money_pool;
    static int count;
    static vector<double> opened;
    static pthread_mutex_t m_mutex;
}
