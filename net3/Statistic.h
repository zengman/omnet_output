//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#ifndef STATISTIC_H_

#define STATISTIC_H_


#include "string.h"
#include <omnetpp.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
//#include <OutPortVector.h>
using namespace std;


class Statistic {

  public:
    static Statistic *instance();
    void infoTS(simtime_t time, int numpakets, int flow_id, int size);
    void setDelay(simtime_t time, int i, int j, double d, int flow_id, int size);
    // void setJitter(simtime_t time, int i, int j, double d);
    void setTraffic(simtime_t time, int i, int j, double t);
    void setRouting(int n, int r, double p);
    void setLambda(double l);
    void setGeneration(int genType);
    void setLost(simtime_t time, int n, int p, int flow_id, int size);
    void setLost(simtime_t time);
    void setNumTx(int n);
    void setNumFlow(int n);
    void setNumNodes(int n);
    void setRoutingParaam(double r);
    void setMaxSim(double r);
    void setFolder(string folder);
    void setFlowId(int flow_id);
    void printStats(simtime_t time);
    void getRoutingById(int id, vector<vector<int> > *outPort);//根据id 获取相应routing
    void getRoutingInfo(vector<vector<vector<int>>> *outportlist);// main geting routing
    bool appShouldSend(int flow_id, int src, int dest);
    void getTrafficInfo(int flow_id, double *bandwidth, int *src, int *dest); //读取traffic文件内容并记录
    vector<vector<vector<int>>> outportlist  ;
    vector<vector<int>> trafficlist; // [flow_id] = bandwith

  protected:


    Statistic();

    virtual ~Statistic();


  private:
    static Statistic *inst;
    simtime_t INI;
    simtime_t END;
    double SIMTIME;
    bool collect;

    int numTx;
    int numNodes;
    int genT;
    double lambdaMax;
    double routingP;
    int flow_num;
    simtime_t endtime;
    bool flag_for_isReadRouting;
    bool flag_for_isReadTraffic;

    string folderName;


    int drops;
    int flow_id;
    vector< vector< vector <double> > > Traffic;
    vector< vector <double> > Routing;
    vector< vector< vector < vector <double> > > >  Delay;
//    vector< vector< vector < vector <int> > > > DelayPacketsSize;
    vector< vector< vector < vector <double> > > >   Jitter;
    vector< vector <vector <double> > >   DropsV;
    vector< vector <int> > Flow_info;
    vector< vector<int>> FLow_path;
    vector< long int> Numpackets;
    vector< long int> SendPackets;
    vector<long int> BandPakcetsSize;
    vector<vector<vector<long int>>>BandFlowPathPacketsSize;

    void initLinkID();

};



#endif /* STATISTIC_H_ */

