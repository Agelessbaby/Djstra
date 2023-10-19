#include<utility>
#include<math.h>
#define NETRANGE 180
#define startpoint { 102,102 }
#include<vector>
#include<iostream>
#include<fstream>
#include<array>
#include<exception>
#include<cstdio>
typedef double distance;
bool arrived[50]{ false };
std::vector<distance>distoplot(50,100000);
std::vector<std::pair<distance, distance>> plots;
distance plotData[100]{ 102,102,
387,452,
544,421,
302,205,
210,105,
271,954,
240,242,
774,375,
117,656,
691,310,
350,376,
377,708,
362,112,
713,316,
600,784,
735,252,
583,318,
456,761,
195,304,
172,635,
870,722,
429,706,
414,662,
500,648,
554,742,
428,773,
788,674,
420,191,
225,309,
648,318,
195,210,
206,780,
788,696,
393,827,
502,368,
305,623,
407,761,
637,644,
353,329,
700,500,
859,771,
881,331,
509,585,
234,463,
819,571,
307,527,
668,260,
471,803,
836,750,
500,600,
};
void readData();
distance getdis(std::pair<distance, distance>, std::pair<distance, distance>);
distance getminDis(int);
std::vector<int>predingdian(50,-1);
void getpath(int);




	


int main() {
	readData();
	std::cout<<getminDis(49)<<std::endl;
	return 0;
}

distance getdis(std::pair<distance, distance>point_a, std::pair<distance, distance>point_b) {
	return sqrt((point_a.first - point_b.first) * (point_a.first - point_b.first) + (point_a.second - point_b.second) * (point_a.second - point_b.second));
}

distance getminDis(int endindex) {
	distoplot[0] = 0;
	predingdian[0] = 0;
	arrived[0] = true;
	int dingdian = 0;
	while(!arrived[endindex])
	{
		double mindis = 100000;
		int minindex = -1;
		for (int i = 1; i < 50; i++) {
			if (!arrived[i] && getdis(plots[i], plots[dingdian]) < NETRANGE) {//没到过i点并且i在顶点的范围内
				if ((getdis(plots[i], plots[dingdian]) + distoplot[dingdian]) < distoplot[i]) {//如果顶点到i点加上顶点到原点的距离小于目前已知最小距离
					distoplot[i] = getdis(plots[i], plots[dingdian]) + distoplot[dingdian];//更新最小距离
				}
			}
		}
		for (int i = 1; i < 50; i++) {
			if (!arrived[i]&&distoplot[i] < mindis) {
				mindis = distoplot[i];
				minindex = i;
			}
		}
		
		dingdian = minindex;
		arrived[dingdian] = true;
	}
	return distoplot[endindex];
}

void readData() {
	for (int i = 0; i < 50; i++) {
		std::pair<distance, distance>a(plotData[i * 2], plotData[i * 2 + 1]);
		plots.push_back(a);
	}
}

void getpath(int node) {
	while (node != 0) {
		std::cout << node << std::endl;
		node = predingdian[node];
	}
}

