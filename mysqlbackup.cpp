/*
* filenmae:mysqlbackup.cpp
*/
#include <iostream>
#include <ctime>
#include <sstream>
#include <string.h>
#include<stdlib.h>

using namespace std;

string datetimestr( )
{
   time_t now = time(0);

    tm *ltm = localtime(&now);
    ostringstream datetimeostr;
    ostringstream osYear,osYear1;
    ostringstream osMonth,osMonth1;
    ostringstream osDay,osDay1;
    ostringstream osHour,osHour1;
    ostringstream osMin,osMin1;
    ostringstream osSec,osSec1;

    osYear<< 1900 + ltm->tm_year;
    osMonth<< 1 + ltm->tm_mon;
    osDay<<  ltm->tm_mday ;
    osHour<<   ltm->tm_hour ;
    osMin<<  ltm->tm_min ;
    osSec<<  ltm->tm_sec;
    
    //如果月、时、分、秒的位数少于2位，则在前面补0;
    if (strlen(osMonth.str().c_str())<2)
	osMonth1<<"0"<<osMonth.str().c_str();
    else
        osMonth1<<osMonth.str().c_str();
 
    if (strlen(osDay.str().c_str())<2)
	osDay1<<"0"<<osDay.str().c_str();
    else
        osDay1<<osDay.str().c_str();

    if(strlen(osHour.str().c_str())<2)
	osHour1<<"0"<<osHour.str().c_str();
    else 
	osHour1<<osHour.str().c_str();

    if(strlen(osMin.str().c_str())<2)
	osMin<<"0"<<osMin.str().c_str();
    else
        osMin1<<osMin.str().c_str();
   
    if(strlen(osSec.str().c_str())<2)
	osSec1<<"0"<<osSec.str().c_str();
    else
        osSec1<<osSec.str().c_str();
    //datetimeostr<<osYear.str().c_str()<<osMonth1.str().c_str()<<osDay1.str().c_str()<<osHour1.str().c_str()<<osMin1.str().c_str()<<osSec1.str().c_str();
    
    datetimeostr<<osYear.str().c_str()<<osMonth1.str().c_str()<<osDay1.str().c_str();
    return datetimeostr.str();//返回当前年月日的字符串，如20161109
}

int main(){
    ostringstream osfilename,oscommand;
    osfilename<<"mydb-back-auto-"<<datetimestr()<<".sql";//构造mysql备份文件的文件名；如：mydb-back-auto-20161109.sql
    oscommand<<"mysqldump -uroot -p123456 --compact mydb2 >"<<osfilename.str();
    system(oscommand.str().c_str());

}
